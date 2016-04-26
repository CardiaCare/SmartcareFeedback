package com.petrsu.cardiacare.smartcarefeedback;

/**
 * Created by Iuliia Zavialova on 09.03.16.
 */
public class Question {
    private String uri;
    private String description;
    Answer answer;


    public Question(String uri_from_sib, String description_from_sib){
         this.uri = uri_from_sib;
         this.description = description_from_sib;
    }

    public void setAnswer(Answer answer_from_sib){
        answer = new Answer(answer_from_sib);
    }

    String getUri(){
        return uri;
    }
    String getDescription(){
        return description;
    }

    public Answer getAnswer() {
        return answer;
    }
}
