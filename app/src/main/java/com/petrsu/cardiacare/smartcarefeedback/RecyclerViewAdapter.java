package com.petrsu.cardiacare.smartcarefeedback;

import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.SeekBar;
import android.widget.TextView;

import com.petrsu.cardiacare.smartcare.*;

import org.osmdroid.ResourceProxy;

import java.util.LinkedList;

public class RecyclerViewAdapter extends RecyclerView.Adapter<RecyclerViewAdapter.ViewHolder> {
    LinkedList <Question> Patients;
    LinkedList <Response> Responses;
    //int[] TypesQuestions;
    String str, str1;

   /* public RecyclerViewAdapter(LinkedList <Question> Questions) {
        this.Questions = Questions;
    }*/

    public RecyclerViewAdapter(LinkedList<Response> responses) {
        this.Responses = responses;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup viewGroup, int Type) {
        View v;
        v = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.dichotomous_card, viewGroup, false);
        return new DichotomousViewHolder(v);
    }

    @Override
    public void onBindViewHolder(ViewHolder viewHolder, final int position) {

        Response resp = Responses.get(position);
        LinkedList<ResponseItem> a = resp.getResponseItems();
        DichotomousViewHolder holder = (DichotomousViewHolder) viewHolder;
        //LinkedList<Question> q = MainActivity.questionnaire.getQuestions();
        //LinkedList<Response> m = feedback.getResponses();
        //LinkedList < ResponseItem > RI = resp.getResponseItems();
        //Response resp = q.get(i);

//        for (int i = 0; i < q.size(); i++) {
//            Question qst = q.get(i);
//            //Log.i("TAG", "Number " +  qst.getDescription());
//            str = resp.getQuestionUri();
//            str1 = qst.getUri();
//            Log.i("TAG", str + "\n" + str1);
//
//            //holder.DichotomousQuestion.setText(resp.getDescription());
//            if (str.equals(str1)) {
//                Log.i("TAG", qst.getDescription());
//                //holder.DichotomousQuestion.setText(qst.getDescription());
//                if (a.size() > 0) {
//                    holder.DichotomousQuestion.setText(qst.getDescription());
//
//                    //Item = a.get(1);
//                    //holder.DichotomousQuestion2.setText(Item.getTextItem());
//                    for (int h = 0; h < a.size();h++) {
//                        ResponseItem it = a.get(h);
//                        holder.DichotomousQuestion2.setText(it.getTextItem());
//                        LinkedList<AnswerItem> la = it.getLinkedItems();
//                        if (la.size() > 0) {
//                            for (int r = 0; r < la.size(); r++) {
//                                AnswerItem lai = la.get(r);
//                                //Log.i("TAG", "answer item uri " + lai.getUri());
//                                holder.DichotomousQuestion2.setText(lai.getItemText());
//                                //Log.i("TAG", "answer item text " + lai.getItemText());
//                                //Log.i("TAG", "answer item score " + lai.getItemScore());
//                            }
//
//                        }
//                    }
//                }
//            }
//        }
    }

    @Override
    public int getItemCount() {
        return Responses.size();
    }
/*
    @Override
    public int getItemViewType(int position) {
        return TypesQuestions[position];
    }*/

    public static class ViewHolder extends RecyclerView.ViewHolder {
        public ViewHolder(View itemView) {
            super(itemView);
        }
    }

    public class DichotomousViewHolder extends ViewHolder {
        TextView DichotomousQuestion;
        TextView DichotomousQuestion2;
        //RadioButton DichotomousAnswer1, DichotomousAnswer2;

        public DichotomousViewHolder(View v) {
            super(v);
            this.DichotomousQuestion = (TextView) v.findViewById(R.id.DichotomousQuestion);
            this.DichotomousQuestion2 = (TextView) v.findViewById(R.id.DichotomousQuestion2);
            //this.DichotomousAnswer1 = (RadioButton) v.findViewById(R.id.DichotomousAnswer1);
            //this.DichotomousAnswer2 = (RadioButton) v.findViewById(R.id.DichotomousAnswer2);
        }
    }
}