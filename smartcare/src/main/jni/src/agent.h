//
// Created by nikolay on 13.01.16.
//
#ifdef	__cplusplus
extern "C" {
#endif

#ifndef SMARTCARE_QUESTIONNAIRE_AGENT_H
#define SMARTCARE_QUESTIONNAIRE_AGENT_H

#endif //SMARTCARE_VOLUNTEER_AGENT_H
#include "ontology/smartcare.h"
#include <jni.h>

char* generate_uri(char *);

int kp_init_person(sslog_node_t *, char *);

int kp_init_patient(char **, sslog_node_t *);

jobject kp_get_next_question(JNIEnv* , jobject *, sslog_node_t *, sslog_individual_t *, char* , char** );
jobject kp_get_first_question(JNIEnv* , jobject *, sslog_node_t *, sslog_individual_t *, char** );

sslog_individual_t * kp_get_questionnaire(sslog_node_t *node_ss, char**);

int kp_get_answer(JNIEnv* , jobject *, sslog_node_t *, sslog_individual_t*);
int kp_get_subanswer(JNIEnv* , jobject *, sslog_node_t *, sslog_individual_t* );
int get_subclasses(sslog_node_t *, char *, char** );
int check_answer_type(char *);
int kp_get_answer_items_by_type(JNIEnv* , jobject *, sslog_node_t *, sslog_individual_t *, char*  );
int kp_get_answer_items(JNIEnv* , jobject *, sslog_node_t *, sslog_individual_t *, char* );
int add_answer_item(JNIEnv* , jobject *, sslog_node_t *, sslog_individual_t *, char* );

long kp_connect_smartspace(char*, char*, int);
int kp_disconnect_smartpace(long);


sslog_individual_t* kp_get_feedback(JNIEnv* env, sslog_node_t *node, char* patient_uri, char **feedback_uri, char **questionnaire_uri);
int kp_get_responses(JNIEnv* env,  jobject *feedback_obj, sslog_node_t *node_ss, sslog_individual_t* feedback);
int kp_get_response_items(JNIEnv* env, jobject *response, sslog_node_t *node_ss, sslog_individual_t *response_ss);
int add_linked_answer_item_to_response(JNIEnv* env, jobject *response_item,   sslog_node_t *node_ss, sslog_individual_t *item);


#ifdef	__cplusplus
}
#endif