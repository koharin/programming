package com.cookandroid.self4_3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    EditText edit1, edit2;
    Button btnAdd, btnSub, btnMul,btnDiv, btnMod;
    TextView textResult;
    Double result;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setTitle("초간단 계산기(수정)");
        edit1 = (EditText)findViewById(R.id.editText1);
        edit2 = (EditText)findViewById(R.id.editText2);
        btnAdd = (Button)findViewById(R.id.BtnAdd);
        btnSub = (Button)findViewById(R.id.BtnSub);
        btnMul = (Button)findViewById(R.id.BtnMul);
        btnDiv = (Button)findViewById(R.id.BtnDiv);
        btnMod = (Button)findViewById(R.id.BtnMod);
        textResult = (TextView)findViewById(R.id.TextResult);

        btnAdd.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){

                if((edit1.getText().toString().equals("")) || (edit2.getText().toString().equals(""))) {
                    Toast.makeText(getApplicationContext(), "입력 값이 비었습니다.", Toast.LENGTH_SHORT).show();
                }
                else{
                    result = Double.parseDouble(edit1.getText().toString()) + Double.parseDouble(edit2.getText().toString());
                    textResult.setText("계산 결과:" + result.toString());
                }
            }
        });
        btnSub.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){

                if((edit1.getText().toString().trim().equals("")) || (edit2.getText().toString().trim().equals(""))) {
                    Toast.makeText(getApplicationContext(), "입력 값이 비었습니다.", Toast.LENGTH_SHORT).show();
                }
                else{
                    result = Double.parseDouble(edit1.getText().toString()) - Double.parseDouble(edit2.getText().toString());
                    textResult.setText("계산 결과:" + result.toString());
                }
            }
        });
        btnMul.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){

                if((edit1.getText().toString().trim().equals("")) || (edit2.getText().toString().trim().equals(""))) {
                    Toast.makeText(getApplicationContext(), "입력 값이 비었습니다.", Toast.LENGTH_SHORT).show();
                }
                else{
                    result = Double.parseDouble(edit1.getText().toString()) * Double.parseDouble(edit2.getText().toString());
                    textResult.setText("계산 결과:" + result.toString());
                }
            }
        });
        btnDiv.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){

                if((edit1.getText().toString().trim().equals("")) || (edit2.getText().toString().trim().equals(""))) {
                    Toast.makeText(getApplicationContext(), "입력 값이 비었습니다.", Toast.LENGTH_SHORT).show();
                }
                else if(Double.parseDouble(edit2.getText().toString().trim()) == 0)
                    Toast.makeText(getApplicationContext(), "0으로 나누면 안 됩니다!", Toast.LENGTH_SHORT).show();
                else{
                    result = Double.parseDouble(edit1.getText().toString()) / Double.parseDouble(edit2.getText().toString());
                    textResult.setText("계산 결과:" + result.toString());
                }
            }
        });
        btnMod.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){

                if((edit1.getText().toString().trim().equals("")) || (edit2.getText().toString().trim().equals(""))) {
                    Toast.makeText(getApplicationContext(), "입력 값이 비었습니다.", Toast.LENGTH_SHORT).show();
                }
                else if(Double.parseDouble(edit2.getText().toString().trim()) == 0) // num2.trim().equals("0")
                    Toast.makeText(getApplicationContext(), "0으로 나머지 값 안 됩니다!", Toast.LENGTH_SHORT).show();
                else{
                    result = Double.parseDouble(edit1.getText().toString()) % Double.parseDouble(edit2.getText().toString());
                    textResult.setText("계산 결과:" + result.toString());
                }
            }
        });

    }
}