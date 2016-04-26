//
// Created by Iuliia Zavialova on 09.03.16.
//

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <android/log.h>

#include <jni.h>

#include "agent.h"
#include "handlers.h"
#include "globals.h"

#define TAG "SS"

#define RDF_TYPE "http://www.w3.org/1999/02/22-rdf-syntax-ns#type"
/*
 * Connecting to smartspace
 */
long kp_connect_smartspace(char *hostname_,char *ip_, int port){
    sslog_node_t *node;
    sslog_init();

    //__android_log_print(ANDROID_LOG_INFO, TAG, "sslog_init");

    node = sslog_new_node("KP_Volunteer", hostname_, ip_, port);
    /*
     * Delete this line when test
     */
    GlobalNode = node;

    register_ontology(node);

    //__android_log_print(ANDROID_LOG_INFO, TAG, "register_ontology");

    if (sslog_node_join(node) != SSLOG_ERROR_NO) {
        //__android_log_print(ANDROID_LOG_INFO, TAG, "Can't join to SS");
        return -1;
    }
    else{
        //__android_log_print(ANDROID_LOG_INFO, TAG, "KP joins to SS.");
        return (long) node;
    }
}

int kp_disconnect_smartspace(long nodeDescriptor){
    sslog_node_t *node = (sslog_node_t *) nodeDescriptor;
    if (node == NULL){
        return -1;
    }

    //sslog_sbcr_unsubscribe_all(node, true);
    sslog_node_leave(node);
    sslog_shutdown();
    return 0;
}

static int uri_index = 0;
char* generate_uri(char *uri){

    uri_index++;
    int result;
    char *newstring;
    char *c;
    result = asprintf(&newstring, "%s%d", uri, uri_index);
    if (result == -1) newstring = NULL;
    return newstring;
}

/*
* Person
*/
int kp_init_person(sslog_node_t *node, char* patient_uri){

    if (node == NULL || patient_uri == NULL)
        return -1;

    sslog_individual_t *person = sslog_new_individual(CLASS_PERSON, patient_uri);

    if (person == NULL) {
        return -1;
    }
    sslog_node_insert_individual(node, person);

    return 0;
}

/*
* Patient
*/
int kp_init_patient(char **uri, sslog_node_t *node){
    list_t* patients;

    patients = sslog_node_get_individuals_by_class(node, CLASS_PERSON);

    if (list_is_null_or_empty(patients) == true) {
        __android_log_print(ANDROID_LOG_INFO, TAG,"There are no such individuals.");
        return NULL;
    }
    sslog_individual_t *patient_ss = NULL;
    list_head_t *pos = NULL;

    char* uri_ss;
    list_for_each(pos, &patients->links)
    {
        list_t *node = list_entry(pos, list_t, links);
        patient_ss = (sslog_individual_t *) node->data;
        sslog_triple_t *patient_uri_from_triple = sslog_individual_to_triple (patient_ss);
        uri_ss  = patient_uri_from_triple->subject;
        *uri =  uri_ss;
        break;
    }

    return 0;
}

sslog_individual_t* kp_get_questionnaire(sslog_node_t *node, char **questionnaire_uri){
    list_t* questionnaires;

    questionnaires = sslog_node_get_individuals_by_class(node, CLASS_QUESTIONNAIRE);

    if (list_is_null_or_empty(questionnaires) == true) {
        __android_log_print(ANDROID_LOG_INFO, TAG,"There are no such individuals.");
        return NULL;
    }
    sslog_individual_t *questionnaire_ss = NULL;
    list_head_t *pos = NULL;

    char* uri;
    list_for_each(pos, &questionnaires->links)
    {
        list_t *node = list_entry(pos, list_t, links);
        questionnaire_ss = (sslog_individual_t *) node->data;
        sslog_triple_t *questionnaire_uri_from_triple = sslog_individual_to_triple (questionnaire_ss);
        uri  = questionnaire_uri_from_triple->subject;
        *questionnaire_uri = uri;
        return questionnaire_ss;
    }

}


jobject kp_get_first_question(JNIEnv* env, jobject *questionnaire, sslog_node_t *node_ss, sslog_individual_t *questionnaire_ss, char** next_question_uri){

    sslog_individual_t *first_question = (sslog_individual_t *) sslog_node_get_property(node_ss, questionnaire_ss, PROPERTY_FIRSTQUESTION);
    if(first_question == NULL){
        return -1;
    }

    char *question_uri;
    sslog_triple_t *question_uri_from_triple = sslog_individual_to_triple (first_question);
    question_uri  =  question_uri_from_triple->subject;

    sslog_node_populate(node_ss, first_question);

    char *description_ss;
    description_ss = (char *) sslog_get_property(first_question, PROPERTY_DESCRIPTION);

    sslog_individual_t * next_question = (sslog_individual_t *) sslog_get_property(first_question, PROPERTY_NEXTQUESTION);
    if (next_question != NULL){
        sslog_triple_t * next_question_uri_from_triple = sslog_individual_to_triple (next_question);
        *next_question_uri  =  next_question_uri_from_triple->subject;
    }
    /**************/
    jobject *question;
    question = (*env)->NewObject(env, class_question, question_constructor, (*env)->NewStringUTF(env, question_uri), (*env)->NewStringUTF(env, description_ss));
    kp_get_answer(env, question, node_ss, first_question);
    /**************/

    return question;
}

jobject kp_get_next_question(JNIEnv* env, jobject *questionnaire, sslog_node_t *node_ss, sslog_individual_t *questionnaire_ss, char* question_uri, char** next_question_uri){

    sslog_individual_t *question_ss = sslog_node_get_individual_by_uri(node_ss,  question_uri);

    sslog_node_populate(node_ss, question_ss);

    char *description_ss;
    description_ss = (char *) sslog_get_property(question_ss, PROPERTY_DESCRIPTION);

    sslog_individual_t * next_question = (sslog_individual_t *) sslog_get_property(question_ss, PROPERTY_NEXTQUESTION);
    if (next_question != NULL){
        sslog_triple_t * next_question_uri_from_triple = sslog_individual_to_triple (next_question);
        *next_question_uri  =  next_question_uri_from_triple->subject;
    }
    else *next_question_uri  = NULL;

    /**************/
    jobject *question;
    question = (*env)->NewObject(env, class_question, question_constructor, (*env)->NewStringUTF(env, question_uri), (*env)->NewStringUTF(env, description_ss));
    kp_get_answer(env, question, node_ss, question_ss);
    /**************/

    return question;
}

int kp_get_answer(JNIEnv* env, jobject *question, sslog_node_t *node_ss, sslog_individual_t* question_ss){

    sslog_individual_t *answer_ss;
    answer_ss = (sslog_individual_t *)  sslog_node_get_property (node_ss, question_ss, PROPERTY_HASANSWER);

    sslog_node_populate(node_ss, answer_ss);

        char *subclass_name_uri = NULL;
        char *subclass_name = NULL;
        char* answer_uri = sslog_entity_get_uri(answer_ss);
        get_subclasses(node_ss, answer_uri, &subclass_name_uri);

        __android_log_print(ANDROID_LOG_INFO, TAG, "kp_get_answer");
        /**************/
        jobject *answer;
        answer = (*env)->NewObject(env, class_answer, answer_constructor, (*env)->NewStringUTF(env, answer_uri), (*env)->NewStringUTF(env, subclass_name_uri));
        kp_get_answer_items_by_type(env, answer, node_ss, answer_ss, subclass_name_uri);
        (*env)->CallVoidMethod(env, question, add_answer, answer);
        /**************/

        subclass_name_uri = NULL;
        answer = NULL;
        sslog_remove_individual(answer_ss);
    return 0;
}

int kp_get_subanswer(JNIEnv* env, jobject *answer_item, sslog_node_t *node_ss, sslog_individual_t* item){
    char* uri = sslog_entity_get_uri(item);
    sslog_triple_t *req_triple = sslog_new_triple_detached(
            uri,
            "http://www.semanticweb.org/cardiacare/ontologies/2016/1/untitled-ontology-35#subAnswer",
            SS_RDF_SIB_ANY,
            SS_RDF_TYPE_URI, SS_RDF_TYPE_URI);

    list_t *uris = sslog_node_query_triple(node_ss, req_triple);
    sslog_free_triple(req_triple);

    list_head_t *iterator = NULL;
    char *answer_class_uri;
    list_for_each(iterator, &uris->links)
    {
        list_t *list_node = list_entry(iterator, list_t, links);
        char *_answer_class_uri = (char *) ((sslog_triple_t *) list_node->data)->object;
        if (_answer_class_uri != NULL) {
            answer_class_uri = _answer_class_uri;
            sslog_individual_t *answer_ss = sslog_node_get_individual_by_uri(node_ss,
                                                                             answer_class_uri);
            sslog_node_populate(node_ss, answer_ss);

            char *subclass_name_uri = NULL;
            char *answer_uri = sslog_entity_get_uri(answer_ss);
            get_subclasses(node_ss, answer_uri, &subclass_name_uri);

            __android_log_print(ANDROID_LOG_INFO, TAG, "kp_get_subanswer");
            /**************/
            jobject *answer;
            answer = (*env)->NewObject(env, class_answer, answer_constructor,
                                       (*env)->NewStringUTF(env, answer_uri),
                                       (*env)->NewStringUTF(env, subclass_name_uri));
            kp_get_answer_items_by_type(env, answer, node_ss, answer_ss, subclass_name_uri);
            (*env)->CallVoidMethod(env, answer_item, add_subanswer, answer);
            /**************/

            sslog_remove_individual(answer_ss);
            subclass_name_uri = NULL;
        }
    }
    list_free_with_nodes(uris, NULL);
    return 0;
}

int get_subclasses(sslog_node_t *node, char *uri, char** subclass){
    sslog_triple_t *req_triple = sslog_new_triple_detached(
            uri,
            RDF_TYPE,
            SS_RDF_SIB_ANY,
            SS_RDF_TYPE_URI, SS_RDF_TYPE_URI);

    list_t *uris = sslog_node_query_triple(node, req_triple);
    sslog_free_triple(req_triple);

    list_head_t *iterator = NULL;
    char *answer_class_uri;
    list_for_each(iterator, &uris->links){
        list_t *list_node = list_entry(iterator, list_t, links);
        char *_answer_class_uri = (char *) ((sslog_triple_t*) list_node->data)->object;
        if(_answer_class_uri != NULL){
            answer_class_uri = _answer_class_uri;
        }
        if (check_answer_type(answer_class_uri) == 0){
            break;
        }
    }
    *subclass = answer_class_uri;
    list_free_with_nodes(uris, NULL);
}

int check_answer_type(char *answer_class){
    if (strcmp(answer_class,(char *) sslog_class_to_triple (CLASS_TEXT)->subject) == 0
        || strcmp(answer_class,(char *) sslog_class_to_triple (CLASS_SINGLECHOISE)->subject) == 0
        || strcmp(answer_class,(char *) sslog_class_to_triple (CLASS_MULTIPLECHOISE)->subject) == 0
        || strcmp(answer_class,(char *) sslog_class_to_triple (CLASS_DICHOTOMOUS)->subject) == 0
        || strcmp(answer_class,(char *) sslog_class_to_triple (CLASS_BIPOLARQUESTION)->subject) == 0
        || strcmp(answer_class,(char *) sslog_class_to_triple (CLASS_GUTTMANSCALE)->subject) == 0
        || strcmp(answer_class,(char *) sslog_class_to_triple (CLASS_LIKERTSCALE)->subject) == 0
            ){
        return 0;
    }else
        return -1;
}

int kp_get_answer_items_by_type(JNIEnv* env, jobject *answer, sslog_node_t *node_ss, sslog_individual_t *answer_ss, char*  subclass_name){
    if (strcmp(subclass_name,(char *) sslog_class_to_triple (CLASS_SINGLECHOISE)->subject) == 0){
          kp_get_answer_items(env, answer ,node_ss, answer_ss, "singleItem");
        return 0;
    }

    if (strcmp(subclass_name,(char *) sslog_class_to_triple (CLASS_MULTIPLECHOISE)->subject) == 0){
         kp_get_answer_items(env, answer,node_ss, answer_ss, "multipleItem");
        return 0;
    }
    if (strcmp(subclass_name,(char *) sslog_class_to_triple (CLASS_DICHOTOMOUS)->subject) == 0){
        kp_get_answer_items(env, answer,node_ss, answer_ss, "dichotomousItem");
        return 0;
    }

    if (strcmp(subclass_name,(char *) sslog_class_to_triple (CLASS_GUTTMANSCALE)->subject) == 0){
        kp_get_answer_items(env, answer,node_ss, answer_ss, "rangingItem");
        return 0;
    }

    if (strcmp(subclass_name,(char *) sslog_class_to_triple (CLASS_LIKERTSCALE)->subject) == 0){
        kp_get_answer_items(env, answer,node_ss, answer_ss, "rangingItem");
        return 0;
    }

    if (strcmp(subclass_name,(char *) sslog_class_to_triple (CLASS_BIPOLARQUESTION)->subject) == 0){
        kp_get_answer_items(env, answer,node_ss, answer_ss, "leftBipolar");
        kp_get_answer_items(env, answer,node_ss, answer_ss, "rightBipolar");
        return 0;
    }

    return 0;
}


int kp_get_answer_items(JNIEnv* env, jobject *answer, sslog_node_t *node_ss, sslog_individual_t *answer_ss, char* answer_type){
    //__android_log_print(ANDROID_LOG_INFO, TAG, "kp_get_answer_items");
    sslog_triple_t *answer_uri_from_triple = sslog_individual_to_triple (answer_ss);
    char* answer_uri = answer_uri_from_triple->subject;

    char* rdf_property = NULL;
    char* rdf_ontology = "http://www.semanticweb.org/cardiacare/ontologies/2016/1/untitled-ontology-35#";
    int result = asprintf(&rdf_property, "%s%s", rdf_ontology, answer_type);
    if (result == -1) rdf_property = NULL;

    sslog_triple_t *req_triple = sslog_new_triple_detached(
            answer_uri,
            rdf_property,
            SS_RDF_SIB_ANY,
            SS_RDF_TYPE_URI, SS_RDF_TYPE_URI);

    list_t *uris = sslog_node_query_triple(node_ss, req_triple);
    sslog_free_triple(req_triple);

    list_head_t *iterator = NULL;
    char *item_uri;
    list_for_each(iterator, &uris->links){
        list_t *list_node = list_entry(iterator, list_t, links);
        char *_item_uri = (char *) ((sslog_triple_t*) list_node->data)->object;
        if(_item_uri != NULL){
            item_uri = _item_uri;
        }
        sslog_individual_t *item = sslog_node_get_individual_by_uri(node_ss,  item_uri);
        sslog_node_populate(node_ss, item);
        add_answer_item(env, answer, node_ss, item,  answer_type);
    }
    list_free_with_nodes(uris, NULL);
}

int add_answer_item(JNIEnv* env, jobject *answer, sslog_node_t *node_ss, sslog_individual_t *item, char* type){

    //__android_log_print(ANDROID_LOG_INFO, TAG, "add_answer_item");
    sslog_triple_t *answer_uri_from_triple = sslog_individual_to_triple (item);
    char* answer_item_uri = answer_uri_from_triple->subject;
    char* item_score = (char *) sslog_get_property(item, PROPERTY_ITEMSCORE);
    char* item_text = (char *) sslog_get_property(item, PROPERTY_ITEMTEXT);
    sslog_individual_t *subitem = ( sslog_individual_t *) sslog_get_property(item, PROPERTY_SUBANSWER);

    /**************/
    jobject *answer_item;
    answer_item = (*env)->NewObject(env, class_answer_item,  item_constructor,
        (*env)->NewStringUTF(env, answer_item_uri),
        (*env)->NewStringUTF(env, item_score),
        (*env)->NewStringUTF(env, item_text));

    (*env)->CallVoidMethod(env, answer, add_answer_item_i, answer_item);
    /**************/
     //subanswer
    if (subitem != NULL)
        kp_get_subanswer(env, answer_item, node_ss, item);
    return 0;
}

/*
 *
 * Feedback
 *
 */

sslog_individual_t* kp_get_feedback(JNIEnv* env, sslog_node_t *node, char* patient_uri, char **feedback_uri, char **questionnaire_uri){

    sslog_individual_t* patient;
    patient = sslog_node_get_individual_by_uri(node,  patient_uri);

    sslog_individual_t *feedback = (sslog_individual_t *) sslog_node_get_property(node, patient, PROPERTY_HASFEEDBACK);
    if(feedback == NULL){
        return -1;
    }
    sslog_node_populate(node, feedback);

    char* feedback_uri_ss = sslog_entity_get_uri(feedback);
    *feedback_uri = feedback_uri_ss;

    sslog_individual_t *questionnaire = (sslog_individual_t *) sslog_node_get_property(node, feedback, PROPERTY_RESPONDEDTO);
    if(questionnaire == NULL){
        return -1;
    }
    sslog_node_populate(node, questionnaire);

    char* questionnaire_uri_ss = sslog_entity_get_uri(questionnaire);
    *questionnaire_uri = questionnaire_uri_ss;

    return feedback;
}

int kp_get_responses(JNIEnv* env,  jobject *feedback_obj, sslog_node_t *node_ss, sslog_individual_t* feedback){

    char* feedback_uri =  sslog_entity_get_uri(feedback);

    //char* rdf_property = NULL;
    //char* rdf_ontology = "http://www.semanticweb.org/cardiacare/ontologies/2016/1/untitled-ontology-35#";
    //int result = asprintf(&rdf_property, "%s%s", rdf_ontology, answer_type);
    //if (result == -1) rdf_property = NULL;

    sslog_triple_t *req_triple = sslog_new_triple_detached(
            feedback_uri,
            "http://oss.fruct.org/smartcare#hasResponse",
            SS_RDF_SIB_ANY,
            SS_RDF_TYPE_URI, SS_RDF_TYPE_URI);

    list_t *uris = sslog_node_query_triple(node_ss, req_triple);
    sslog_free_triple(req_triple);

    list_head_t *iterator = NULL;
    char *item_uri;
    list_for_each(iterator, &uris->links){
        list_t *list_node = list_entry(iterator, list_t, links);
        char *_item_uri = (char *) ((sslog_triple_t*) list_node->data)->object;
        if(_item_uri != NULL){
            item_uri = _item_uri;
        }
        sslog_individual_t *response_ss = sslog_node_get_individual_by_uri(node_ss,  item_uri);
        sslog_individual_t *question_ss  = sslog_node_get_property(node_ss, response_ss, PROPERTY_ANWEREDTO);
        char *question_uri = sslog_entity_get_uri(question_ss);
        /*
         * items
         */
        /*
         *
         */

        jobject *response;
        response = (*env)->NewObject(env, class_response,  response_constructor,
                                        (*env)->NewStringUTF(env, item_uri),
                                        (*env)->NewStringUTF(env, question_uri));
        kp_get_response_items(env,response,node_ss, response_ss);

        (*env)->CallVoidMethod(env, feedback_obj, add_response, response);
    }
    list_free_with_nodes(uris, NULL);

}

int kp_get_response_items(JNIEnv* env, jobject *response, sslog_node_t *node_ss, sslog_individual_t *response_ss) {

    sslog_individual_t *response_items_ss  = sslog_node_get_property(node_ss, response_ss, PROPERTY_HASRESPONSEITEM);
    char *response_items_ss_uri = sslog_entity_get_uri(response_items_ss);
    sslog_node_populate(node_ss, response_items_ss);

    char* text = NULL;
    sslog_individual_t *response_items_text_ss  = sslog_get_property( response_items_ss, PROPERTY_CONTAINSTEXT);
    if (response_items_text_ss != NULL){
        text = sslog_node_get_property(node_ss, response_items_text_ss, PROPERTY_RESPONSETEXT);
    }

    char* file = NULL;
    sslog_individual_t *response_items_file_ss  = sslog_get_property( response_items_ss, PROPERTY_CONTAINSFILE);
    if (response_items_file_ss != NULL){
        file = sslog_node_get_property(node_ss, response_items_file_ss, PROPERTY_RESPONSETEXT);
    }


    jobject *response_item;
    response_item = (*env)->NewObject(env, class_response_item,  response_item_constructor,
                                 (*env)->NewStringUTF(env, response_items_ss_uri),
                                 (*env)->NewStringUTF(env, text),
                                 (*env)->NewStringUTF(env, file));


    sslog_triple_t *req_triple = sslog_new_triple_detached(
            response_items_ss_uri,
            "http://oss.fruct.org/smartcare#linkedWithItem",
            SS_RDF_SIB_ANY,
            SS_RDF_TYPE_URI, SS_RDF_TYPE_URI);

    list_t *uris = sslog_node_query_triple(node_ss, req_triple);
    sslog_free_triple(req_triple);

    list_head_t *iterator = NULL;
    char *item_uri;
    list_for_each(iterator, &uris->links){
        list_t *list_node = list_entry(iterator, list_t, links);
        char *_item_uri = (char *) ((sslog_triple_t*) list_node->data)->object;
        if(_item_uri != NULL) {
            item_uri = _item_uri;
            sslog_individual_t *linked_answer_item_ss = sslog_node_get_individual_by_uri(node_ss,item_uri);
            add_linked_answer_item_to_response(env, response_item, node_ss, linked_answer_item_ss);
        }

    }
    list_free_with_nodes(uris, NULL);

    (*env)->CallVoidMethod(env, response, add_response_item, response_item);

    return 0;
}

int add_linked_answer_item_to_response(JNIEnv* env, jobject *response_item,  sslog_node_t *node_ss, sslog_individual_t *item){

        sslog_node_populate(node_ss, item);
        char* answer_item_uri = sslog_entity_get_uri(item);
        char* item_score = (char *) sslog_get_property(item, PROPERTY_ITEMSCORE);
        char* item_text = (char *) sslog_get_property(item, PROPERTY_ITEMTEXT);
        sslog_individual_t *subitem = ( sslog_individual_t *) sslog_get_property(item, PROPERTY_SUBANSWER);

        jobject *linked_answer_item;
        linked_answer_item = (*env)->NewObject(env, class_answer_item, item_constructor,
                                          (*env)->NewStringUTF(env, answer_item_uri),
                                          (*env)->NewStringUTF(env, item_score),
                                          (*env)->NewStringUTF(env, item_text));

        (*env)->CallVoidMethod(env, response_item, add_linked_answer_item, linked_answer_item);


        return 0;
    }


