package com.petrsu.cardiacare.smartcare;

/**
 * Created by Iuliia Zavialova on 28.06.16.
 */
public class SmartCareLibrary {
    // Native code part begin
    static {
        System.loadLibrary("smartcare_native");
    }

    public native long connectSmartSpace(String name, String ip, int port);

    public native void disconnectSmartSpace(long nodeDescriptor);

    public native String getQuestionnaire(long nodeDescriptor);
    public native String getQuestionnaireVersion(long nodeDescriptor,String questionnaireUri);
    public native String getQuestionnaireSeverUri(long nodeDescriptor,String questionnaireUri);
    public native String getPersonInformation(long nodeDescriptor,String personUri);
    public native String getFeedbackDate(long nodeDescriptor,String personUri);


    public native String initPatient (long nodeDescriptor);
    public native String initMedic (long nodeDescriptor);
    public native String initAuthRequest (long nodeDescriptor, String patientUri);
    public native String initLocation (long nodeDescriptor, String patientUri);
    public native void removeIndividual (long nodeDescriptor, String individualUri);
    public native void removeAlarm (long nodeDescriptor, String individualUri);
    public native String  sendAlarm(long nodeDescriptor, String patientUri);
    static public native int sendLocation(long nodeDescriptor, String patientUri, String locationUri ,String latitude, String longitude);
    static public native int sendFeedback(long nodeDescriptor, String patientUri, String feedbackDate);
    public native String getPatientList(long nodeDescriptor);


    static public native int insertPersonName(long nodeDescriptor, String patientUri, String name);
    static public native int updatePersonName(long nodeDescriptor, String patientUri, String name);

    public native int getAuthResponce(long nodeDescriptor, String authUri);
}
