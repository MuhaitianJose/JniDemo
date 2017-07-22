package com.muhaitian.jnidemo.jni;

/**
 * Created by wangkang001 on 2017/7/21.
 */

public class Student {
    private String StudentName;
    private int StudentID;
    private boolean Male;
    private double Money;
    private float DemoFloat;
    private long DemoLong;
    private short DemoShort;
    private byte DemoByte;
    private char DemoChar;

    public String getStudentName() {
        return StudentName;
    }

    public void setStudentName(String studentName) {
        StudentName = studentName;
    }

    public int getStudentID() {
        return StudentID;
    }

    public void setStudentID(int studentID) {
        StudentID = studentID;
    }

    public boolean isMale() {
        return Male;
    }

    public void setMale(boolean male) {
        Male = male;
    }

    public double getMoney() {
        return Money;
    }

    public void setMoney(double money) {
        Money = money;
    }

    public float getDemoFloat() {
        return DemoFloat;
    }

    public void setDemoFloat(float demoFloat) {
        DemoFloat = demoFloat;
    }

    public long getDemoLong() {
        return DemoLong;
    }

    public void setDemoLong(long demoLong) {
        DemoLong = demoLong;
    }

    public short getDemoShort() {
        return DemoShort;
    }

    public void setDemoShort(short demoShort) {
        DemoShort = demoShort;
    }

    public byte getDemoByte() {
        return DemoByte;
    }

    public void setDemoByte(byte demoByte) {
        DemoByte = demoByte;
    }

    public char getDemoChar() {
        return DemoChar;
    }

    public void setDemoChar(char demoChar) {
        DemoChar = demoChar;
    }
}
