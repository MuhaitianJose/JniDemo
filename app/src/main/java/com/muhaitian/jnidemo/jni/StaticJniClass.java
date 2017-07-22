package com.muhaitian.jnidemo.jni;

/**
 * Created by wangkang001 on 2017/7/21.
 */

public class StaticJniClass {

    public native void setString(String str);

    public native String getString();

    public native void setInt(int Int);

    public native int getInt();

    public native void setBoolean(boolean Boolean);

    public native boolean getBoolean();

    public native void setDouble(double Double);

    public native double getDouble();

    public native void setFloat(float Float);

    public native float getFloat();

    public native void setLong(long Long);

    public native long getLong();

    public native void setShort(short Short);

    public native short getShort();

    public native void setByte(byte Byte);

    public native byte getByte();

    public native void setChar(char Char);

    public native char getChar();

    public native void setIntArray(int[] IntArray);

    public native int[] getIntArray();
}
