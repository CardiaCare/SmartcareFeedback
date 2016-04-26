package com.petrsu.cardiacare.smartcarefeedback;

import java.util.LinkedList;

/**
 * Created by Iuliia Zavialova on 09.03.16.
 */
public class Answer {
    private String uri;
    private String type;

    LinkedList<AnswerItem> items;

    public Answer(String uri_from_sib,String type_from_sib){
        this.uri = uri_from_sib;
        this.type  = type_from_sib;
        this.items = new LinkedList<AnswerItem>();
    }

    public Answer(Answer answer){
        this.uri = answer.getUri();
        this.type = answer.getType();
        this.items =answer.items;
    }

    public String getUri(){ return uri; }
    public LinkedList<AnswerItem> getItems() {
        return items;
    }
    public String getType() {
        int i = type.indexOf("#");
        String t = type.substring(i+1);
        return t;
    }

    public void addAnswerItem(AnswerItem item){
        AnswerItem newItem = new AnswerItem(item);
        this.items.addLast(newItem);
    }

}
