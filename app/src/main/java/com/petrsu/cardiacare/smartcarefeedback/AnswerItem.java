package com.petrsu.cardiacare.smartcarefeedback;

import java.util.LinkedList;

/**
 * Created by Iuliia Zavialova on 09.03.16.
 */
public class AnswerItem {
    private String uri;
    private String itemScore;
    private String itemText;
    LinkedList<Answer> subAnswers;


    public AnswerItem(String uri_from_sib,String itemScore_from_sib, String itemText_from_sib){
        uri = uri_from_sib;
        itemScore = itemScore_from_sib;
        itemText = itemText_from_sib;
        subAnswers = new LinkedList<Answer>();
    }

    public AnswerItem(AnswerItem item){
        this.uri = item.uri;
        this.itemScore = item.itemScore;
        this.itemText = item.itemText;
        this.subAnswers = item.subAnswers;
    }

    public void addSubAnswer(Answer answer){
        Answer subAnswer = new Answer(answer);
        subAnswers.addLast(subAnswer);
    }

    public LinkedList<Answer> getSubAnswers() {
        return subAnswers;
    }

    public String getUri() {
        return uri;
    }

    public String getItemScore() {
        return itemScore;
    }

    public String getItemText() {
        return itemText;
    }
}
