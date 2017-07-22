//
// Created by wangkang001 on 2017/7/21.
//
#include "static_jni.h"
#include <android/log.h>
#define LOG_TAG "static_jni"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__);

JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setString(JNIEnv *env, jclass clazz, jstring str) {
    LOGD("%s: str=%s",__func__,str);
}

JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setInt(JNIEnv *env, jclass clazz, jint str) {
    LOGD("%s str=%d",__func__,str);
}

JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setBoolean(JNIEnv *env, jclass clazz, jboolean str) {
    LOGD("%s str=%d",__func__,str);
}

JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setDouble(JNIEnv *env, jclass clazz, jdouble str) {
    LOGD("%s str=%lf",__func__,str);
}

JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setFloat(JNIEnv *env, jclass clazz, jfloat str) {
    LOGD("%s str=%f",__func__,str);
}

JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setLong(JNIEnv *env, jclass clazz, jlong str) {
    LOGD("%s str=%ld",__func__,str);
}

JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setShort(JNIEnv *env, jclass clazz, jshort str) {
    LOGD("%s str=%hd",__func__,str);
}

JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setByte(JNIEnv *env, jclass clazz, jbyte str) {
    LOGD("%s str=%s",__func__,str);
}

JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setChar(JNIEnv *env, jclass clazz, jchar str) {
    LOGD("%s str=%c",__func__,str);
}

JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setIntArray(JNIEnv *env, jclass clazz, jintArray str) {
    jint size = env->GetArrayLength(str);
    jint *array = env->GetIntArrayElements(str,false);

    for(int i=0;i<size;i++)
        LOGD("%s str=%s",__func__,array[i]);
}

JNIEXPORT jstring JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getString(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF("muhaitian");
}

JNIEXPORT jint JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getInt(JNIEnv *env, jclass clazz) {
    return 455;
}

JNIEXPORT jboolean JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getBoolean(JNIEnv *env, jclass clazz) {
    return true;
}

JNIEXPORT jdouble JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getDouble(JNIEnv *env, jclass clazz) {
    return 125656;
}

JNIEXPORT jfloat JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getFloat(JNIEnv *env, jclass clazz) {
    return 12323.455f;
}

JNIEXPORT jlong JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getLong(JNIEnv *env, jclass clazz) {
    return 7899978888888888L;
}

JNIEXPORT jshort JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getShort(JNIEnv *env, jclass clazz) {
    return 12;
}

JNIEXPORT jbyte JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getByte(JNIEnv *env, jclass clazz) {
    return 4545;
}

JNIEXPORT jchar JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getChar(JNIEnv *env, jclass clazz) {
    return 'a';
}

JNIEXPORT jintArray JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getIntArray(JNIEnv *env, jclass clazz) {
    jintArray mk = env->NewIntArray(5);
    return mk;
}