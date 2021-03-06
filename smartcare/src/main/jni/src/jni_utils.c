//
// Created by nikolay on 20.01.16.
//
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <jni.h>
#include "jni_utils.h"
#include "globals.h"

int init_global_instances(JNIEnv* env, jobject obj) {

    GlobalMainActivityClassObject = (jobject * )(*env)->NewGlobalRef(env, obj);
    if (NULL == GlobalMainActivityClassObject) { return -1; }

    jclass localMainActivityClass = (*env)->FindClass(env, "com/petrsu/cardiacare/smartcare/SmartCareLibrary");
    if (NULL == localMainActivityClass) { return -1; }
    GlobalMainActivityClass = (jclass * )(*env)->NewGlobalRef(env, localMainActivityClass);
    if (NULL == GlobalMainActivityClass) { return -1; }


    jclass _class_questionnaire = (*env)->FindClass(env, "com/petrsu/cardiacare/smartcare/Questionnaire");
    if (_class_questionnaire == NULL) { return -1;  }
    class_questionnaire = (jclass * )(*env)->NewGlobalRef(env, _class_questionnaire);
    if (class_questionnaire == NULL) { return -1; }


    jclass _class_question = (*env)->FindClass(env, "com/petrsu/cardiacare/smartcare/Question");
    if (_class_question == NULL) { return -1; }
    class_question = (jclass * )(*env)->NewGlobalRef(env, _class_question);
    if (NULL == class_question) { return -1; }

    jclass _class_answer = (*env)->FindClass(env, "com/petrsu/cardiacare/smartcare/Answer");
    if (_class_answer == NULL) { return -1; }
    class_answer = (jclass * )(*env)->NewGlobalRef(env, _class_answer);
    if (NULL == class_answer) { return -1; }

    jclass _class_answer_item = (*env)->FindClass(env, "com/petrsu/cardiacare/smartcare/AnswerItem");
    if (_class_answer_item == NULL) { return -1; }
    class_answer_item = (jclass * )(*env)->NewGlobalRef(env, _class_answer_item);
    if (NULL == class_answer_item) { return -1; }

    jclass _class_feedback = (*env)->FindClass(env, "com/petrsu/cardiacare/smartcare/Feedback");
    if (_class_feedback == NULL) { return -1; }
    class_feedback = (jclass * )(*env)->NewGlobalRef(env, _class_feedback);
    if (NULL == class_feedback) { return -1; }

    jclass _class_response = (*env)->FindClass(env, "com/petrsu/cardiacare/smartcare/Response");
    if (_class_response == NULL) { return -1; }
    class_response = (jclass * )(*env)->NewGlobalRef(env, _class_response);
    if (NULL == class_response) { return -1; }

    jclass _class_response_item = (*env)->FindClass(env, "com/petrsu/cardiacare/smartcare/ResponseItem");
    if (_class_response_item == NULL) { return -1; }
    class_response_item = (jclass * )(*env)->NewGlobalRef(env, _class_response_item);
    if (NULL == class_response_item) { return -1; }

    questionnaire_constructor = (*env)->GetMethodID(env, class_questionnaire, "<init>", "(Ljava/lang/String;)V");
    if (questionnaire_constructor == NULL) { return -1; }

    add_question = (*env)->GetMethodID(env, class_questionnaire, "addQuestion", "(Lcom/petrsu/cardiacare/smartcare/Question;)V");
    if (add_question == NULL) { return -1; }

    question_constructor = (*env)->GetMethodID(env, class_question, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (question_constructor == NULL) { return -1; }

    answer_constructor = (*env)->GetMethodID(env, class_answer, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (answer_constructor == NULL) { return -1; }

    add_answer = (*env)->GetMethodID(env, class_question, "setAnswer", "(Lcom/petrsu/cardiacare/smartcare/Answer;)V");
    if (add_answer == NULL) { return -1; }

    add_subanswer = (*env)->GetMethodID(env, class_answer_item, "addSubAnswer", "(Lcom/petrsu/cardiacare/smartcare/Answer;)V");
    if (add_subanswer == NULL) { return -1; }

    item_constructor = (*env)->GetMethodID(env, class_answer_item, "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    if ( item_constructor == NULL) { return -1; }

    add_answer_item_i = (*env)->GetMethodID(env,  class_answer, "addAnswerItem", "(Lcom/petrsu/cardiacare/smartcare/AnswerItem;)V");
    if (add_answer_item_i == NULL) { return -1; }


    feedback_constructor = (*env)->GetMethodID(env, class_feedback, "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    if (feedback_constructor == NULL) { return -1; }

    response_constructor = (*env)->GetMethodID(env, class_response, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (response_constructor == NULL) { return -1; }

    response_item_constructor = (*env)->GetMethodID(env, class_response_item, "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    if (response_item_constructor == NULL) { return -1; }


    add_response = (*env)->GetMethodID(env,  class_feedback, "addResponse", "(Lcom/petrsu/cardiacare/smartcare/Response;)V");
    if (add_response == NULL) { return -1; }

    add_response_item = (*env)->GetMethodID(env,  class_response, "addResponseItem", "(Lcom/petrsu/cardiacare/smartcare/ResponseItem;)V");
    if (add_response_item == NULL) { return -1; }

    add_linked_answer_item = (*env)->GetMethodID(env,  class_response_item, "addLinkedAnswerItem", "(Lcom/petrsu/cardiacare/smartcare/AnswerItem;)V");
    if (add_linked_answer_item == NULL) { return -1; }

}
int init_JVM_instance(JNIEnv* env){
    if((*env)->GetJavaVM(env, &JVM) != 0){
        return -1;
    }
    return 0;
}