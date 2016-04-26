package com.petrsu.cardiacare.smartcarefeedback;

import java.util.LinkedList;

/**
 * Created by CardiaCareTeam on 20.04.2016.
 */
public class Response {

    private String uri;
    private String questionUri;

    public void setUri(String uri) {
        this.uri = uri;
    }

    public Response(String uri, String questionUri) {
        this.uri = uri;
        this.questionUri = questionUri;
        this.responseItems = new LinkedList<ResponseItem>();
    }

    LinkedList<ResponseItem> responseItems;

    public void addResponseItem(ResponseItem newResponseItem) {
        this.responseItems.addLast(newResponseItem);
    }

    public LinkedList<ResponseItem> getResponseItems() {
        return responseItems;
    }

    public String getUri() {
        return uri;
    }

    public String getQuestionUri() {
        return questionUri;
    }
}
