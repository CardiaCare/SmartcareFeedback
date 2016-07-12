package com.petrsu.cardiacare.smartcarefeedback;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;

public class PatientListActivity extends AppCompatActivity {

    RecyclerView PatientListRecyclerView;
    RecyclerView.Adapter PatientListAdapter;
    RecyclerView.LayoutManager PatientListLayoutManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_patient_list);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        PatientListRecyclerView = (RecyclerView) findViewById(R.id.recycler_view);

        //QuestionnaireRecyclerView.setHasFixedSize(true);

        PatientListLayoutManager= new LinearLayoutManager(getApplicationContext());
        PatientListRecyclerView.setLayoutManager(PatientListLayoutManager);

        /*LinkedList<Question> q = MainActivity.questionnaire.getQuestions();
        LinkedList<Response> f = MainActivity.feedback.getResponses();*/

        //int[] Types = new int[q.size()];
        String TAG = "SS-main";


        PatientListAdapter = new RecyclerViewAdapter(MainActivity.feedback.getResponses());
        PatientListRecyclerView.setAdapter(PatientListAdapter);
    }
}