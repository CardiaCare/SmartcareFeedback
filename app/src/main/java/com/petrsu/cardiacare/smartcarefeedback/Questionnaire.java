package com.petrsu.cardiacare.smartcarefeedback;

import java.util.LinkedList;

/**
 * Created by Iuliia Zavialova on 04.03.16.
 */
public class Questionnaire {

    private String uri;
    LinkedList <Question> questions;

    public Questionnaire(String uri_from_sib){
        uri = uri_from_sib;
        questions = new LinkedList<Question>();
    }

    String getUri(){
        return uri;
    }

    public void addQuestion(Question question){
        questions.addLast(question);
    }
     LinkedList <Question> getQuestions(){
         return questions;
     }
}
