package com.petrsu.cardiacare.smartcare;

/**
 * Created by Iuliia Zavialova on 13.05.16.
 */
public class SmartCareLibrary {
    // Native code part begin
    static {
        System.loadLibrary("smartcare_native");
    }
    public native long connectSmartSpace(String name, String ip, int port);

    public native void disconnectSmartSpace(long nodeDescriptor);

    public native Questionnaire getQuestionnaire(long nodeDescriptor);

    public native String initPatient (long nodeDescriptor);

    public native Feedback getFeedback(long nodeDescriptor, String patientUri);

}
