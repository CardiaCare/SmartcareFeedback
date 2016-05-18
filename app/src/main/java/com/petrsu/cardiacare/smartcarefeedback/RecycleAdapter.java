package com.petrsu.cardiacare.smartcarefeedback;

import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.petrsu.cardiacare.smartcare.AnswerItem;
import com.petrsu.cardiacare.smartcare.Question;
import com.petrsu.cardiacare.smartcare.Response;
import com.petrsu.cardiacare.smartcare.ResponseItem;

import java.util.LinkedList;

/**
 * Created by Win10 on 18.05.2016.
 */
public class RecycleAdapter extends BaseAdapter {

    LinkedList<Response> Responses;
    String str, str1;

    public RecycleAdapter (LinkedList<Response> responses){
        this.Responses = responses;
    }

    @Override
    public int getCount() {
        return Responses.size();
    }

    @Override
    public Object getItem(int position) {
        return null;
    }

    @Override
    public long getItemId(int position) {
        return 0;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        Response resp = Responses.get(position);
        LinkedList<ResponseItem> a = resp.getResponseItems();
        LinkedList<Question> q = MainActivity.questionnaire.getQuestions();

        for (int i = 0; i < q.size(); i++) {
            Question qst = q.get(i);
            //Log.i("TAG", "Number " +  qst.getDescription());
            str = resp.getQuestionUri();
            str1 = qst.getUri();
            Log.i("TAG", str + "\n" + str1);
            if (str.equals(str1)) {
                Log.i("TAG", qst.getDescription());
                if (a.size() > 0) {
                    DichotomousQuestion.setText(qst.getDescription());
                    for (int h = 0; h < a.size();h++) {
                        ResponseItem it = a.get(h);
                        DichotomousQuestion2.setText(it.getTextItem());
                        LinkedList<AnswerItem> la = it.getLinkedItems();
                        if (la.size() > 0) {
                            for (int r = 0; r < la.size(); r++) {
                                AnswerItem lai = la.get(r);
                                //Log.i("TAG", "answer item uri " + lai.getUri());
                                DichotomousQuestion2.setText(lai.getItemText());
                                //Log.i("TAG", "answer item text " + lai.getItemText());
                                //Log.i("TAG", "answer item score " + lai.getItemScore());
                            }

                        }
                    }
                }
            }
        }
        for (int r = 0; r < Responses.size(); r++)
        {
            Responses lai = Responses.get(r);
            TextView answer = (TextView) convertView.findViewById(android.R.id.DichotomousQuestion2);
            answer.setText(lai.getItemText());

        }
        return null;
    }
}
