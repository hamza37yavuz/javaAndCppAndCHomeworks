package com.hamza.simple_calculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    EditText num_in;
    EditText num_in2;
    TextView result_text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        num_in = findViewById(R.id.num_in);
        num_in2 = findViewById(R.id.numin2);
        result_text = findViewById(R.id.result_text);
    }
    public void sum(View view){
        boolean isnull = num_in.getText().toString().matches("");
        boolean isnull2 = num_in2.getText().toString().matches("");
        if(isnull || isnull2){
            result_text.setText("PLEASE ENTER NUMBER");
        }else {
            int num1 = Integer.parseInt(num_in.getText().toString());
            int num2 = Integer.parseInt(num_in2.getText().toString());
            int result = num1 + num2;
            result_text.setText("Result:" + result);
        }
    }
    public void deduct(View view){
        boolean isnull = num_in.getText().toString().matches("");
        boolean isnull2 = num_in2.getText().toString().matches("");
        if(isnull || isnull2){
            result_text.setText("PLEASE ENTER NUMBER");
        }else {
            int num1 = Integer.parseInt(num_in.getText().toString());
            int num2 = Integer.parseInt(num_in2.getText().toString());
            int result = num1 - num2;
            result_text.setText("Result:" + result);
        }
    }
    public void multiply(View view){
        boolean isnull = num_in.getText().toString().matches("");
        boolean isnull2 = num_in2.getText().toString().matches("");
        if(isnull || isnull2){
            result_text.setText("PLEASE ENTER NUMBER");
        }else {
            int num1 = Integer.parseInt(num_in.getText().toString());
            int num2 = Integer.parseInt(num_in2.getText().toString());
            int result = num1 * num2;
            result_text.setText("Result:" + result);
        }
    }
    public void divide(View view){
        boolean isnull = num_in.getText().toString().matches("");
        boolean isnull2 = num_in2.getText().toString().matches("");
        if(isnull || isnull2){
            result_text.setText("PLEASE ENTER NUMBER");
        }else {
            int num1 = Integer.parseInt(num_in.getText().toString());
            int num2 = Integer.parseInt(num_in2.getText().toString());
            if(num2==0) {
                result_text.setText("DIVIDE BY ZERO ERROR");
            }else {
                int result = num1 / num2;
                result_text.setText("Result:" + result);
            }
        }
    }

}