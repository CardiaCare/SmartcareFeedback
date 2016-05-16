#include "smartcare.h"



#if INCLUDE_CLASS_RANGINGSCALE
sslog_class_t *CLASS_RANGINGSCALE;
#endif
#if INCLUDE_CLASS_QUESTIONNAIRE
sslog_class_t *CLASS_QUESTIONNAIRE;
#endif
#if INCLUDE_CLASS_THING
sslog_class_t *CLASS_THING;
#endif
#if INCLUDE_CLASS_PHOTO
sslog_class_t *CLASS_PHOTO;
#endif
#if INCLUDE_CLASS_RESPONSETEXT
sslog_class_t *CLASS_RESPONSETEXT;
#endif
#if INCLUDE_CLASS_LIKERTSCALE
sslog_class_t *CLASS_LIKERTSCALE;
#endif
#if INCLUDE_CLASS_AUDIO
sslog_class_t *CLASS_AUDIO;
#endif
#if INCLUDE_CLASS_DICHOTOMOUS
sslog_class_t *CLASS_DICHOTOMOUS;
#endif
#if INCLUDE_CLASS_CONTINUOUSSCALE
sslog_class_t *CLASS_CONTINUOUSSCALE;
#endif
#if INCLUDE_CLASS_FILE
sslog_class_t *CLASS_FILE;
#endif
#if INCLUDE_CLASS_CHOISE
sslog_class_t *CLASS_CHOISE;
#endif
#if INCLUDE_CLASS_TEXT
sslog_class_t *CLASS_TEXT;
#endif
#if INCLUDE_CLASS_FEEDBACK
sslog_class_t *CLASS_FEEDBACK;
#endif
#if INCLUDE_CLASS_ANSWER
sslog_class_t *CLASS_ANSWER;
#endif
#if INCLUDE_CLASS_NOTHING
sslog_class_t *CLASS_NOTHING;
#endif
#if INCLUDE_CLASS_MULTIPLECHOISE
sslog_class_t *CLASS_MULTIPLECHOISE;
#endif
#if INCLUDE_CLASS_GUTTMANSCALE
sslog_class_t *CLASS_GUTTMANSCALE;
#endif
#if INCLUDE_CLASS_ITEM
sslog_class_t *CLASS_ITEM;
#endif
#if INCLUDE_CLASS_RESPONSEFILE
sslog_class_t *CLASS_RESPONSEFILE;
#endif
#if INCLUDE_CLASS_NUMBER
sslog_class_t *CLASS_NUMBER;
#endif
#if INCLUDE_CLASS_RESPONSE
sslog_class_t *CLASS_RESPONSE;
#endif
#if INCLUDE_CLASS_VIDEO
sslog_class_t *CLASS_VIDEO;
#endif
#if INCLUDE_CLASS_DOCUMENT
sslog_class_t *CLASS_DOCUMENT;
#endif
#if INCLUDE_CLASS_OPENANSWER
sslog_class_t *CLASS_OPENANSWER;
#endif
#if INCLUDE_CLASS_QUESTION
sslog_class_t *CLASS_QUESTION;
#endif
#if INCLUDE_CLASS_CLOSEDANSWER
sslog_class_t *CLASS_CLOSEDANSWER;
#endif
#if INCLUDE_CLASS_PHONE
sslog_class_t *CLASS_PHONE;
#endif
#if INCLUDE_CLASS_RESPONSEITEM
sslog_class_t *CLASS_RESPONSEITEM;
#endif
#if INCLUDE_CLASS_PERSON
sslog_class_t *CLASS_PERSON;
#endif
#if INCLUDE_CLASS_SINGLECHOISE
sslog_class_t *CLASS_SINGLECHOISE;
#endif
#if INCLUDE_CLASS_VALIDATED
sslog_class_t *CLASS_VALIDATED;
#endif
#if INCLUDE_CLASS_EMAIL
sslog_class_t *CLASS_EMAIL;
#endif
#if INCLUDE_CLASS_BIPOLARQUESTION
sslog_class_t *CLASS_BIPOLARQUESTION;
#endif


#if INCLUDE_PROPERTY_RESPONSEFILEURI
sslog_property_t *PROPERTY_RESPONSEFILEURI;
#endif
#if INCLUDE_PROPERTY_CONTAINSSUBRESPONSE
sslog_property_t *PROPERTY_CONTAINSSUBRESPONSE;
#endif
#if INCLUDE_PROPERTY_NEXTQUESTION
sslog_property_t *PROPERTY_NEXTQUESTION;
#endif
#if INCLUDE_PROPERTY_HASFEEDBACK
sslog_property_t *PROPERTY_HASFEEDBACK;
#endif
#if INCLUDE_PROPERTY_HASQUESTION
sslog_property_t *PROPERTY_HASQUESTION;
#endif
#if INCLUDE_PROPERTY_DESCRIPTION
sslog_property_t *PROPERTY_DESCRIPTION;
#endif
#if INCLUDE_PROPERTY_LEFTBIPOLAR
sslog_property_t *PROPERTY_LEFTBIPOLAR;
#endif
#if INCLUDE_PROPERTY_CONTAINSFILE
sslog_property_t *PROPERTY_CONTAINSFILE;
#endif
#if INCLUDE_PROPERTY_RESPONSETEXT
sslog_property_t *PROPERTY_RESPONSETEXT;
#endif
#if INCLUDE_PROPERTY_RANGINGITEM
sslog_property_t *PROPERTY_RANGINGITEM;
#endif
#if INCLUDE_PROPERTY_MULTIPLEITEM
sslog_property_t *PROPERTY_MULTIPLEITEM;
#endif
#if INCLUDE_PROPERTY_HASRESPONSE
sslog_property_t *PROPERTY_HASRESPONSE;
#endif
#if INCLUDE_PROPERTY_RESPONDEDTO
sslog_property_t *PROPERTY_RESPONDEDTO;
#endif
#if INCLUDE_PROPERTY_ANWEREDTO
sslog_property_t *PROPERTY_ANWEREDTO;
#endif
#if INCLUDE_PROPERTY_ITEMSCORE
sslog_property_t *PROPERTY_ITEMSCORE;
#endif
#if INCLUDE_PROPERTY_CODE
sslog_property_t *PROPERTY_CODE;
#endif
#if INCLUDE_PROPERTY_DICHOTOMOUSITEM
sslog_property_t *PROPERTY_DICHOTOMOUSITEM;
#endif
#if INCLUDE_PROPERTY_FIRSTQUESTION
sslog_property_t *PROPERTY_FIRSTQUESTION;
#endif
#if INCLUDE_PROPERTY_HASANSWER
sslog_property_t *PROPERTY_HASANSWER;
#endif
#if INCLUDE_PROPERTY_HASRESPONSEITEM
sslog_property_t *PROPERTY_HASRESPONSEITEM;
#endif
#if INCLUDE_PROPERTY_LINKEDWITHITEM
sslog_property_t *PROPERTY_LINKEDWITHITEM;
#endif
#if INCLUDE_PROPERTY_CONTAINSTEXT
sslog_property_t *PROPERTY_CONTAINSTEXT;
#endif
#if INCLUDE_PROPERTY_ITEMTEXT
sslog_property_t *PROPERTY_ITEMTEXT;
#endif
#if INCLUDE_PROPERTY_SINGLEITEM
sslog_property_t *PROPERTY_SINGLEITEM;
#endif
#if INCLUDE_PROPERTY_SUBANSWER
sslog_property_t *PROPERTY_SUBANSWER;
#endif
#if INCLUDE_PROPERTY_RIGHTBIPOLAR
sslog_property_t *PROPERTY_RIGHTBIPOLAR;
#endif



/**
 * @brief Register ontology.
 *
 * It creates all structures, such as classes and properties. Use it firs in your propgramm.
 */
void register_ontology()
{    
#if INCLUDE_PROPERTY_RESPONSEFILEURI
PROPERTY_RESPONSEFILEURI =  sslog_new_property("http://oss.fruct.org/smartcare#responseFileUri", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_CONTAINSSUBRESPONSE
PROPERTY_CONTAINSSUBRESPONSE =  sslog_new_property("http://oss.fruct.org/smartcare#containsSubResponse", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_NEXTQUESTION
PROPERTY_NEXTQUESTION =  sslog_new_property("http://oss.fruct.org/smartcare#nextQuestion", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASFEEDBACK
PROPERTY_HASFEEDBACK =  sslog_new_property("http://oss.fruct.org/smartcare#hasFeedback", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASQUESTION
PROPERTY_HASQUESTION =  sslog_new_property("http://oss.fruct.org/smartcare#hasQuestion", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_DESCRIPTION
PROPERTY_DESCRIPTION =  sslog_new_property("http://oss.fruct.org/smartcare#description", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_LEFTBIPOLAR
PROPERTY_LEFTBIPOLAR =  sslog_new_property("http://oss.fruct.org/smartcare#leftBipolar", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_CONTAINSFILE
PROPERTY_CONTAINSFILE =  sslog_new_property("http://oss.fruct.org/smartcare#containsFile", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_RESPONSETEXT
PROPERTY_RESPONSETEXT =  sslog_new_property("http://oss.fruct.org/smartcare#responseText", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_RANGINGITEM
PROPERTY_RANGINGITEM =  sslog_new_property("http://oss.fruct.org/smartcare#rangingItem", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_MULTIPLEITEM
PROPERTY_MULTIPLEITEM =  sslog_new_property("http://oss.fruct.org/smartcare#multipleItem", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASRESPONSE
PROPERTY_HASRESPONSE =  sslog_new_property("http://oss.fruct.org/smartcare#hasResponse", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_RESPONDEDTO
PROPERTY_RESPONDEDTO =  sslog_new_property("http://oss.fruct.org/smartcare#respondedTo", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_ANWEREDTO
PROPERTY_ANWEREDTO =  sslog_new_property("http://oss.fruct.org/smartcare#anweredTo", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_ITEMSCORE
PROPERTY_ITEMSCORE =  sslog_new_property("http://oss.fruct.org/smartcare#itemScore", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_CODE
PROPERTY_CODE =  sslog_new_property("http://oss.fruct.org/smartcare#code", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_DICHOTOMOUSITEM
PROPERTY_DICHOTOMOUSITEM =  sslog_new_property("http://oss.fruct.org/smartcare#dichotomousItem", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_FIRSTQUESTION
PROPERTY_FIRSTQUESTION =  sslog_new_property("http://oss.fruct.org/smartcare#firstQuestion", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASANSWER
PROPERTY_HASANSWER =  sslog_new_property("http://oss.fruct.org/smartcare#hasAnswer", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_HASRESPONSEITEM
PROPERTY_HASRESPONSEITEM =  sslog_new_property("http://oss.fruct.org/smartcare#hasResponseItem", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_LINKEDWITHITEM
PROPERTY_LINKEDWITHITEM =  sslog_new_property("http://oss.fruct.org/smartcare#linkedWithItem", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_CONTAINSTEXT
PROPERTY_CONTAINSTEXT =  sslog_new_property("http://oss.fruct.org/smartcare#containsText", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_ITEMTEXT
PROPERTY_ITEMTEXT =  sslog_new_property("http://oss.fruct.org/smartcare#itemText", SSLOG_PROPERTY_TYPE_DATA);
#endif
#if INCLUDE_PROPERTY_SINGLEITEM
PROPERTY_SINGLEITEM =  sslog_new_property("http://oss.fruct.org/smartcare#singleItem", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_SUBANSWER
PROPERTY_SUBANSWER =  sslog_new_property("http://oss.fruct.org/smartcare#subAnswer", SSLOG_PROPERTY_TYPE_OBJECT);
#endif
#if INCLUDE_PROPERTY_RIGHTBIPOLAR
PROPERTY_RIGHTBIPOLAR =  sslog_new_property("http://oss.fruct.org/smartcare#rightBipolar", SSLOG_PROPERTY_TYPE_OBJECT);
#endif



#if INCLUDE_CLASS_RANGINGSCALE
CLASS_RANGINGSCALE = sslog_new_class("http://oss.fruct.org/smartcare#RangingScale");
#endif
#if INCLUDE_CLASS_QUESTIONNAIRE
CLASS_QUESTIONNAIRE = sslog_new_class("http://oss.fruct.org/smartcare#Questionnaire");
#endif
#if INCLUDE_CLASS_THING
CLASS_THING = sslog_new_class("http://www.w3.org/2002/07/owl#Thing");
#endif
#if INCLUDE_CLASS_PHOTO
CLASS_PHOTO = sslog_new_class("http://oss.fruct.org/smartcare#Photo");
#endif
#if INCLUDE_CLASS_RESPONSETEXT
CLASS_RESPONSETEXT = sslog_new_class("http://oss.fruct.org/smartcare#ResponseText");
#endif
#if INCLUDE_CLASS_LIKERTSCALE
CLASS_LIKERTSCALE = sslog_new_class("http://oss.fruct.org/smartcare#LikertScale");
#endif
#if INCLUDE_CLASS_AUDIO
CLASS_AUDIO = sslog_new_class("http://oss.fruct.org/smartcare#Audio");
#endif
#if INCLUDE_CLASS_DICHOTOMOUS
CLASS_DICHOTOMOUS = sslog_new_class("http://oss.fruct.org/smartcare#Dichotomous");
#endif
#if INCLUDE_CLASS_CONTINUOUSSCALE
CLASS_CONTINUOUSSCALE = sslog_new_class("http://oss.fruct.org/smartcare#ContinuousScale");
#endif
#if INCLUDE_CLASS_FILE
CLASS_FILE = sslog_new_class("http://oss.fruct.org/smartcare#File");
#endif
#if INCLUDE_CLASS_CHOISE
CLASS_CHOISE = sslog_new_class("http://oss.fruct.org/smartcare#Choise");
#endif
#if INCLUDE_CLASS_TEXT
CLASS_TEXT = sslog_new_class("http://oss.fruct.org/smartcare#Text");
#endif
#if INCLUDE_CLASS_FEEDBACK
CLASS_FEEDBACK = sslog_new_class("http://oss.fruct.org/smartcare#Feedback");
#endif
#if INCLUDE_CLASS_ANSWER
CLASS_ANSWER = sslog_new_class("http://oss.fruct.org/smartcare#Answer");
#endif
#if INCLUDE_CLASS_NOTHING
CLASS_NOTHING = sslog_new_class("http://www.w3.org/2002/07/owl#Nothing");
#endif
#if INCLUDE_CLASS_MULTIPLECHOISE
CLASS_MULTIPLECHOISE = sslog_new_class("http://oss.fruct.org/smartcare#MultipleChoise");
#endif
#if INCLUDE_CLASS_GUTTMANSCALE
CLASS_GUTTMANSCALE = sslog_new_class("http://oss.fruct.org/smartcare#GuttmanScale");
#endif
#if INCLUDE_CLASS_ITEM
CLASS_ITEM = sslog_new_class("http://oss.fruct.org/smartcare#Item");
#endif
#if INCLUDE_CLASS_RESPONSEFILE
CLASS_RESPONSEFILE = sslog_new_class("http://oss.fruct.org/smartcare#ResponseFile");
#endif
#if INCLUDE_CLASS_NUMBER
CLASS_NUMBER = sslog_new_class("http://oss.fruct.org/smartcare#Number");
#endif
#if INCLUDE_CLASS_RESPONSE
CLASS_RESPONSE = sslog_new_class("http://oss.fruct.org/smartcare#Response");
#endif
#if INCLUDE_CLASS_VIDEO
CLASS_VIDEO = sslog_new_class("http://oss.fruct.org/smartcare#Video");
#endif
#if INCLUDE_CLASS_DOCUMENT
CLASS_DOCUMENT = sslog_new_class("http://oss.fruct.org/smartcare#Document");
#endif
#if INCLUDE_CLASS_OPENANSWER
CLASS_OPENANSWER = sslog_new_class("http://oss.fruct.org/smartcare#OpenAnswer");
#endif
#if INCLUDE_CLASS_QUESTION
CLASS_QUESTION = sslog_new_class("http://oss.fruct.org/smartcare#Question");
#endif
#if INCLUDE_CLASS_CLOSEDANSWER
CLASS_CLOSEDANSWER = sslog_new_class("http://oss.fruct.org/smartcare#ClosedAnswer");
#endif
#if INCLUDE_CLASS_PHONE
CLASS_PHONE = sslog_new_class("http://oss.fruct.org/smartcare#Phone");
#endif
#if INCLUDE_CLASS_RESPONSEITEM
CLASS_RESPONSEITEM = sslog_new_class("http://oss.fruct.org/smartcare#ResponseItem");
#endif
#if INCLUDE_CLASS_PERSON
CLASS_PERSON = sslog_new_class("http://oss.fruct.org/smartcare#Person");
#endif
#if INCLUDE_CLASS_SINGLECHOISE
CLASS_SINGLECHOISE = sslog_new_class("http://oss.fruct.org/smartcare#SingleChoise");
#endif
#if INCLUDE_CLASS_VALIDATED
CLASS_VALIDATED = sslog_new_class("http://oss.fruct.org/smartcare#Validated");
#endif
#if INCLUDE_CLASS_EMAIL
CLASS_EMAIL = sslog_new_class("http://oss.fruct.org/smartcare#Email");
#endif
#if INCLUDE_CLASS_BIPOLARQUESTION
CLASS_BIPOLARQUESTION = sslog_new_class("http://oss.fruct.org/smartcare#BipolarQuestion");
#endif



}


