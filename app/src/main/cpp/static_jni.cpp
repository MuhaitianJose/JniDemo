//
// Created by wangkang001 on 2017/7/21.
//
#include "StaticJniClass.h"
#include <android/log.h>

#define LOG_TAG "static_jni"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__);
#define STUDENT "com/muhaitian/jnidemo/jni/Student"
jobject mStudent;
JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setString(JNIEnv *env, jobject clazz, jstring str) {

    LOGD("%s: str=%s", __func__, str);
}

JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setInt(JNIEnv *env, jobject clazz, jint str) {
    LOGD("%s str=%d", __func__, str);
}

JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setBoolean(JNIEnv *env, jobject clazz, jboolean str) {
    LOGD("%s str=%d", __func__, str);
}

JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setDouble(JNIEnv *env, jobject clazz, jdouble str) {
    LOGD("%s str=%lf", __func__, str);
}

JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setFloat(JNIEnv *env, jobject clazz, jfloat str) {
    LOGD("%s str=%f", __func__, str);
}

JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setLong(JNIEnv *env, jobject clazz, jlong str) {
    LOGD("%s str=%ld", __func__, str);
}

JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setShort(JNIEnv *env, jobject clazz, jshort str) {
    LOGD("%s str=%hd", __func__, str);
}

JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setByte(JNIEnv *env, jobject clazz, jbyte str) {
    LOGD("%s str=%c", __func__, str);
}

JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setChar(JNIEnv *env, jobject clazz, jchar str) {
    LOGD("%s str=%c", __func__, str);
}

JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setIntArray(JNIEnv *env, jobject clazz,
                                                          jintArray str) {
    jint size = env->GetArrayLength(str);
    jint *array = env->GetIntArrayElements(str, false);
    LOGD("%s str=%d", __func__, size);
    for (int i = 0; i < size; i++)
        LOGD("%s str=%d", __func__, array[i]);
    env->ReleaseIntArrayElements(str, array, JNI_ABORT);
}

JNIEXPORT jstring JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getString(JNIEnv *env, jobject clazz) {
    return env->NewStringUTF("muhaitian");
}

JNIEXPORT jint JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getInt(JNIEnv *env, jobject clazz) {
    return 455;
}

JNIEXPORT jboolean JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getBoolean(JNIEnv *env, jobject clazz) {
    return true;
}

JNIEXPORT jdouble JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getDouble(JNIEnv *env, jobject clazz) {
    return 125656;
}

JNIEXPORT jfloat JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getFloat(JNIEnv *env, jobject clazz) {
    return 12323.455f;
}

JNIEXPORT jlong JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getLong(JNIEnv *env, jobject clazz) {
    return 7899978888888888L;
}

JNIEXPORT jshort JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getShort(JNIEnv *env, jobject clazz) {
    return 12;
}

JNIEXPORT jbyte JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getByte(JNIEnv *env, jobject clazz) {
    return 4545;
}

JNIEXPORT jchar JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getChar(JNIEnv *env, jobject clazz) {
    return 'a';
}

JNIEXPORT jintArray JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getIntArray(JNIEnv *env, jobject clazz) {
    jintArray array = env->NewIntArray(5);
    int length = env->GetArrayLength(array);
    jint *arr = env->GetIntArrayElements(array, false);
    for (int i = 0; i < length; i++) {
        arr[i] = i + 5;
    }

    return array;
}

JNIEXPORT jobject JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_getStudent(JNIEnv *env, jobject clazz) {
    jclass StudentClass = env->FindClass(STUDENT);
    if(mStudent!= NULL){

        jmethodID getstudent_id = env->GetMethodID(StudentClass,"getStudentName","()Ljava/lang/String;");
        jstring student = (jstring) env->CallObjectMethod(mStudent, getstudent_id);
        LOGD("%s str=%s", __func__, student);

        jmethodID setStudent_id = env->GetMethodID(StudentClass,"setStudentName","(Ljava/lang/String;)V");
        env->CallVoidMethod(StudentClass,setStudent_id,env->NewStringUTF("kkkkkkkkkkk"));
    } else{
        jmethodID init_id = env->GetMethodID(StudentClass,"<init>","()V");
        mStudent = env->NewObject(StudentClass,init_id);
        jmethodID setStudent_id = env->GetMethodID(StudentClass,"setStudentName","(Ljava/lang/String;)V");
        env->CallVoidMethod(mStudent,setStudent_id,env->NewStringUTF("wo shi muhaitian"));
    }
    return mStudent;
}



JNIEXPORT void JNICALL
Java_com_muhaitian_jnidemo_jni_StaticJniClass_setStudent(JNIEnv *env, jobject clazz, jobject student) {
    //赋值全局变量student对象
    mStudent = env->NewGlobalRef(student);
}
