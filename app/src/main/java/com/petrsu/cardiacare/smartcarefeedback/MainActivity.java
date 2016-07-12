package com.petrsu.cardiacare.smartcarefeedback;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.Toast;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.common.api.GoogleApiClient;
import com.petrsu.cardiacare.smartcare.*;



public class MainActivity extends AppCompatActivity {

    private GoogleApiClient client;

    static protected String medicUri;
    static public SmartCareLibrary smart;
    static public long nodeDescriptor = -1;
    static public Feedback feedback;
    public int getPatientListButtonClickCount = 0;

    //static protected String questionnaire;

    Toolbar mToolbar;
    static public ProgressBar mProgressBar;
    public Context context = this;
//    String filename = "questionnaire.json";
    String TAG = "SS-main";

    public MainActivity() {}

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        client = new GoogleApiClient.Builder(this).addApi(AppIndex.API).build();
        smart = new SmartCareLibrary();
        ConnectToSmartSpace();
        setRegisteredActivity();
    }

//    public void writeData ( String data ){
//        try {
//            FileOutputStream fOut = openFileOutput(filename, MODE_PRIVATE);
//            OutputStreamWriter osw = new OutputStreamWriter(fOut);
//            osw.write(data);
//            osw.flush();
//            osw.close();
//        } catch (Exception e){
//            e.printStackTrace();
//        }
//    }

//    public String readSavedData(){
//        StringBuffer datax = new StringBuffer("");
//        try {
//            FileInputStream fIn = openFileInput(filename);
//            InputStreamReader isr = new InputStreamReader(fIn);
//            BufferedReader buffreader = new BufferedReader(isr);
//
//            String readString = buffreader.readLine();
//            while ( readString != null ) {
//                datax.append(readString);
//                readString = buffreader.readLine();
//            }
//            isr.close();
//        } catch ( IOException ioe) {
//            ioe.printStackTrace();
//        }
//        return datax.toString();
//    }

//    public void printQuestionnaire(Questionnaire questionnaire){
//        LinkedList<Question> q = questionnaire.getQuestions();
//
//        for (int i = 0; i < q.size(); i++) {
//            Question qst = q.get(i);
//            Log.i(TAG, qst.getDescription());
//            Answer a = qst.getAnswer();
//            //if (a.size()>0) {
//            //for(int h = 0; h < a.size(); h++) {
//            Log.i(TAG, a.getType());
//            LinkedList<AnswerItem> ai = a.getItems();
//            if (ai.size() > 0) {
//                Log.i(TAG, "AnswerItem");
//                for (int j = 0; j < ai.size(); j++) {
//                    AnswerItem item = ai.get(j);
//                    Log.i(TAG, item.getItemText());
//                    LinkedList<Answer> suba = item.getSubAnswers();
//                    if (suba.size() > 0) {
//                        for (int k = 0; k < suba.size(); k++) {
//                            Log.i(TAG, "subAnswer");
//                            Answer sitem = suba.get(k);
//                            Log.i(TAG, sitem.getType());
//                            LinkedList<AnswerItem> sai = sitem.getItems();
//                        }
//                    }
//                    // }
//                    //}
//                }
//            }
//        }
//    }

//    public void printFeedback(Feedback feedback){
//        //Log.i(TAG, feedback.getUri());
//        Log.i(TAG, feedback.getQuestionnaireUri());
//        LinkedList<Response> q = feedback.getResponses();
//        //Log.i(TAG, "Number of responses " + q.size());
//
//        for (int i = 0; i < q.size(); i++) {
//            Response resp = q.get(i);
//            Log.i(TAG, "response uri " + resp.getUri());
//            Log.i(TAG, "question uri " + resp.getQuestionUri());
//            //resp.setQuestionUri(feedback.getQuestionnaireUri());
//            //Log.i(TAG, resp.getQuestionUri());
//                    //Log.i(TAG, resp.getResponseItems());
//                    LinkedList < ResponseItem > a = resp.getResponseItems();
//            //Log.i(TAG, "Number " + a.size());
//            if (a.size()>0) {
//                for(int h = 0; h < a.size(); h++) {
//                    ResponseItem it = a.get(h);
//                    //Log.i(TAG,it.getUri());
//                    if (it.getTextItem()!= null)
//                        Log.i(TAG,"item text "+it.getTextItem());
//                    if (it.getFileUri()!= null)
//                        Log.i(TAG, "iten file " +it.getFileUri());
//                    LinkedList<AnswerItem> la = it.getLinkedItems();
//                    //Log.i(TAG, "Number of " + la.size());
//                    if (la.size()>0) {
//                        for (int r = 0; r < la.size(); r++) {
//                            AnswerItem lai = la.get(r);
//                            Log.i(TAG,"answer item uri "+ lai.getUri());
//                            Log.i(TAG, "answer item text "+lai.getItemText());
//                            Log.i(TAG,"answer item score "+ lai.getItemScore());
//                        }
//                    }
//                }
//            }
//        }
//    }

    public void setRegisteredActivity() {

        setContentView(R.layout.activity_main);
        mProgressBar = (ProgressBar) findViewById(R.id.progressBar);
        mProgressBar.setVisibility(View.INVISIBLE);
        mToolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(mToolbar);
        getSupportActionBar().setDisplayShowHomeEnabled(true);
        final Button getPatientListButton = (Button) findViewById(R.id.getPatientListButton);
        getPatientListButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //Переход на новую активити со списком пациентов

                mProgressBar.setVisibility(View.VISIBLE);
                //Log.i(TAG, "Клик" + "; Net=" + isNetworkAvailable(context) + "; nodeDescriptor=" + nodeDescriptor);
                if (isNetworkAvailable(context) && (nodeDescriptor != -1)) {
                    //Log.i(TAG, "Есть сеть, норм дескриптор" + "; Net=" + isNetworkAvailable(context) + "; nodeDescriptor=" + nodeDescriptor);
                    showPatientList();
                } else if (!isNetworkAvailable(context)) {
                    //Log.i(TAG, "Нет сети, k > 0" + "; Net = " + isNetworkAvailable(context) + "; nodeDescriptor = " + nodeDescriptor);
                    smart.disconnectSmartSpace(nodeDescriptor);
                    nodeDescriptor = -1;
                } else if ((!isNetworkAvailable(context)) && (getPatientListButtonClickCount == 0)) {
                    Toast toast = Toast.makeText(getApplicationContext(), "Отсутствует подключение к сети", Toast.LENGTH_SHORT);
                    toast.show();
                    getPatientListButtonClickCount++;
                    smart.disconnectSmartSpace(nodeDescriptor);
                    nodeDescriptor = -1;
                } else if ((isNetworkAvailable(context)) && (nodeDescriptor == -1)) {
                    boolean flag;
                    do {
                        flag = ConnectToSmartSpace();
                        Toast toast2 = Toast.makeText(getApplicationContext(), "SIB reconnect", Toast.LENGTH_SHORT);
                        toast2.show();
                    } while (!flag);
                    showPatientList();
                }
            }
        });
    }

    // Проверка подключения к сети (есть или нет)
    public static boolean isNetworkAvailable(Context context) {

        ConnectivityManager cm = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo networkInfo = cm.getActiveNetworkInfo();
        if (networkInfo != null && networkInfo.isConnected()) {
            return true;
        } else {
            return false;
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {

        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    public void onDestroy() {

        moveTaskToBack(true);
        super.onDestroy();

        smart.removeIndividual(nodeDescriptor, medicUri);
        smart.disconnectSmartSpace(nodeDescriptor);
        System.exit(0);
    }

    @Override
    public void onStart() {

        super.onStart();
        client.connect();
        Action viewAction = Action.newAction(
                Action.TYPE_VIEW, // TODO: choose an action type.
                "Main Page", // TODO: Define a title for the content shown.
                // TODO: If you have web page content that matches this app activity's content,
                // make sure this auto-generated web page URL is correct.
                // Otherwise, set the URL to null.
                Uri.parse("http://host/path"),
                // TODO: Make sure this auto-generated app deep link URI is correct.
                Uri.parse("android-app://com.petrsu.cardiacare.smartcarequestionnaire/http/host/path")
        );
        AppIndex.AppIndexApi.start(client, viewAction);
    }

    @Override
    public void onStop() {
        super.onStop();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        Action viewAction = Action.newAction(
                Action.TYPE_VIEW, // TODO: choose an action type.
                "Main Page", // TODO: Define a title for the content shown.
                // TODO: If you have web page content that matches this app activity's content,
                // make sure this auto-generated web page URL is correct.
                // Otherwise, set the URL to null.
                Uri.parse("http://host/path"),
                // TODO: Make sure this auto-generated app deep link URI is correct.
                Uri.parse("android-app://com.petrsu.cardiacare.smartcarequestionnaire/http/host/path")
        );
        AppIndex.AppIndexApi.end(client, viewAction);
        client.disconnect();
    }

    public boolean ConnectToSmartSpace() {
        nodeDescriptor = smart.connectSmartSpace("X", "78.46.130.194", 10010);
        if (nodeDescriptor == -1){
            return false;
        }

        medicUri = smart.initMedic(nodeDescriptor);
        if (medicUri == null){
            return false;
        }
        Log.i(TAG, medicUri);

//        locationUri = smart.initLocation(nodeDescriptor,patientUri);
//        if (locationUri == null) {
//            return false;
//        }

        return true;
    }

    public void showPatientList() {

        String patientInformation = smart.getPersonInformation(nodeDescriptor, "71191");
        Log.i(TAG, "patient information: " + patientInformation);

    }
}
