//
// Created by wangkang001 on 2017/7/21.
//

#ifndef JNIDEMO_STATIC_JNI_H
#define JNIDEMO_STATIC_JNI_H

#include <jni.h>

#ifdef __cplusplus
extern "C"
{
#endif
JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setString(JNIEnv *env, jclass clazz, jstring str);
JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setInt(JNIEnv *env, jclass clazz, jint str);
JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setBoolean(JNIEnv *env, jclass clazz, jboolean str);
JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setDouble(JNIEnv *env, jclass clazz, jdouble str);
JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setFloat(JNIEnv *env, jclass clazz, jfloat str);
JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setLong(JNIEnv *env, jclass clazz, jlong str);
JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setShort(JNIEnv *env, jclass clazz, jshort str);
JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setByte(JNIEnv *env, jclass clazz, jbyte str);
JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setChar(JNIEnv *env, jclass clazz, jchar str);
JNIEXPORT void JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_setIntArray(JNIEnv *env, jclass clazz, jintArray str);

JNIEXPORT jstring JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getString(JNIEnv *env, jclass clazz);
JNIEXPORT jint JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getInt(JNIEnv *env, jclass clazz);
JNIEXPORT jboolean JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getBoolean(JNIEnv *env, jclass clazz);
JNIEXPORT jdouble JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getDouble(JNIEnv *env, jclass clazz);
JNIEXPORT jfloat JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getFloat(JNIEnv *env, jclass clazz);
JNIEXPORT jlong JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getLong(JNIEnv *env, jclass clazz);
JNIEXPORT jshort JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getShort(JNIEnv *env, jclass clazz);
JNIEXPORT jbyte JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getByte(JNIEnv *env, jclass clazz);
JNIEXPORT jchar JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getChar(JNIEnv *env, jclass clazz);
JNIEXPORT jintArray JNICALL
com_muhaitian_jnidemo_jni_StaticJniClass_getIntArray(JNIEnv *env, jclass clazz);

#ifdef __cplusplus
}
#endif

#endif //JNIDEMO_STATIC_JNI_H
