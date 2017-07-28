package com.muhaitian.jnidemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.muhaitian.jnidemo.jni.DynamicJniClass;
import com.muhaitian.jnidemo.jni.StaticJniClass;
import com.muhaitian.jnidemo.jni.Student;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    private Student wangkang, muhaitian;
    private Button StaticJni, DynamicJni;
    private DynamicJniClass mDynamicJniClass;
    private StaticJniClass mStaticJniClass;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        initViewwidget();
        initData();
    }

    private void initViewwidget() {
        wangkang = new Student();
        wangkang.setStudentName("wangkang");
        wangkang.setStudentID(13101027);
        wangkang.setMoney(7613);
        wangkang.setMale(true);
        wangkang.setDemoShort((short) 12);
        wangkang.setDemoLong(123456789456464L);
        wangkang.setDemoFloat(456.4564F);
        wangkang.setDemoChar('d');
        wangkang.setDemoByte((byte) 1233);

        muhaitian = new Student();
        muhaitian.setStudentName("wangkang");
        muhaitian.setStudentID(13101029);
        muhaitian.setMoney(7697);
        muhaitian.setMale(true);
        muhaitian.setDemoShort((short) 19);
        muhaitian.setDemoLong(484654665689456464L);
        muhaitian.setDemoFloat(896.4564F);
        muhaitian.setDemoChar('f');
        muhaitian.setDemoByte((byte) 1233);

        mDynamicJniClass = new DynamicJniClass();
        mStaticJniClass = new StaticJniClass();

        StaticJni = (Button) findViewById(R.id.StaticJni);
        DynamicJni = (Button) findViewById(R.id.DynamicJni);
    }

    private void initData() {
        StaticJni.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                useStaticJni();
            }
        });

        DynamicJni.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                useDynamic();
            }
        });
    }

    private void useStaticJni() {
        //jni use with set
        mStaticJniClass.setString(wangkang.getStudentName());
        mStaticJniClass.setInt(wangkang.getStudentID());
        mStaticJniClass.setShort(wangkang.getDemoShort());
        mStaticJniClass.setLong(wangkang.getDemoLong());
        mStaticJniClass.setFloat(wangkang.getDemoFloat());
        mStaticJniClass.setDouble(wangkang.getMoney());
        mStaticJniClass.setChar(wangkang.getDemoChar());
        mStaticJniClass.setByte(wangkang.getDemoByte());
        mStaticJniClass.setBoolean(wangkang.isMale());
        int[] array = {12, 13, 14, 15, 16, 17, 18, 19};
        mStaticJniClass.setIntArray(array);
        //jni use with get
        boolean mk = mStaticJniClass.getBoolean();
        Log.d(TAG, "useStaticJni: boolearn=" + mk);
        String name = mStaticJniClass.getString();
        Log.d(TAG, "useStaticJni: String==" + name);
        short mShort = mStaticJniClass.getShort();
        Log.d(TAG, "useStaticJni: Short==" + mShort);
        long mLong = mStaticJniClass.getLong();
        Log.d(TAG, "useStaticJni: Long" + mLong);
        int[] mGetIntArray = mStaticJniClass.getIntArray();
        Log.d(TAG, "useStaticJni: IntArray==" + mGetIntArray.length);
        float mFloat = mStaticJniClass.getFloat();
        Log.d(TAG, "useStaticJni: Float==" + mFloat);
        double mDouble = mStaticJniClass.getDouble();
        Log.d(TAG, "useStaticJni: Double==" + mDouble);
        char mChar = mStaticJniClass.getChar();
        Log.d(TAG, "useStaticJni: Char==" + mChar);
        Log.d(TAG, "useStaticJni: " + mStaticJniClass.getByte());

        Student mm = mStaticJniClass.getStudent();
        Log.d(TAG, "useStaticJni: getStudentName="+mm.getStudentName());
    }

    private void useDynamic() {
        mDynamicJniClass.setString(muhaitian.getStudentName());
        mDynamicJniClass.setInt(muhaitian.getStudentID());
        mDynamicJniClass.setShort(muhaitian.getDemoShort());
        mDynamicJniClass.setLong(muhaitian.getDemoLong());
        mDynamicJniClass.setFloat(muhaitian.getDemoFloat());
        mDynamicJniClass.setDouble(muhaitian.getMoney());
        mDynamicJniClass.setChar(muhaitian.getDemoChar());
        mDynamicJniClass.setByte(muhaitian.getDemoByte());
        mDynamicJniClass.setBoolean(muhaitian.isMale());
        int[] array = {12, 13, 14, 15, 16, 17, 18, 19};
        mDynamicJniClass.setIntArray(array);
        //jni use with get
        boolean mk = mDynamicJniClass.getBoolean();
        Log.d(TAG, "useStaticJni: boolearn=" + mk);
        String name = mDynamicJniClass.getString();
        Log.d(TAG, "useStaticJni: String==" + name);
        short mShort = mDynamicJniClass.getShort();
        Log.d(TAG, "useStaticJni: Short==" + mShort);
        long mLong = mDynamicJniClass.getLong();
        Log.d(TAG, "useStaticJni: Long" + mLong);
        int[] mGetIntArray = mDynamicJniClass.getIntArray();
        Log.d(TAG, "useStaticJni: IntArray==" + mGetIntArray.length);
        float mFloat = mDynamicJniClass.getFloat();
        Log.d(TAG, "useStaticJni: Float==" + mFloat);
        double mDouble = mDynamicJniClass.getDouble();
        Log.d(TAG, "useStaticJni: Double==" + mDouble);
        char mChar = mDynamicJniClass.getChar();
        Log.d(TAG, "useStaticJni: Char==" + mChar);
        Log.d(TAG, "useStaticJni: getByte==" + mDynamicJniClass.getByte());

        mDynamicJniClass.setStudent(wangkang);
//         mDynamicJniClass.getStudent();
//        Log.d(TAG, "useDynamic: getStudentName=="+wangkang.getStudentName());
    }

    static {
        System.loadLibrary("dynamic");
        System.loadLibrary("static");
    }

}
