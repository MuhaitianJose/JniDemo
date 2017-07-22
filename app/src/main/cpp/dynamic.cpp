//
// Created by muhaitian on 2017/7/21.
//

#include <jni.h>
#include <android/log.h>
#define LOG_TAG "dynamic"
#define DYNAMIC_JNI_CLASS "com/muhaitian/jnidemo/jni/DynamicJniClass"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__);

static int registerNativesMethids(JNIEnv *env, const char *className, JNINativeMethod *gMethod,
                                  int numMethods);

static int registerNatives(JNIEnv *env);

JNIEXPORT void JNICALL setString(JNIEnv *env, jclass clazz, jstring str) {
    char *mkmk = (char *) env->GetStringUTFChars(str, 0);
    LOGD("%s str=%s",__func__,mkmk);
}

JNIEXPORT void JNICALL setInt(JNIEnv *env, jclass clazz, jint str) {
    LOGD("%s str=%d",__func__,str);
}

JNIEXPORT void JNICALL setBoolean(JNIEnv *env, jclass clazz, jboolean str) {
    LOGD("%s str=%d",__func__,str);
}

JNIEXPORT void JNICALL setDouble(JNIEnv *env, jclass clazz, jdouble str) {
    LOGD("%s str=%lf",__func__,str);
}

JNIEXPORT void JNICALL setFloat(JNIEnv *env, jclass clazz, jfloat str) {
    LOGD("%s str=%f",__func__,str);
}

JNIEXPORT void JNICALL setLong(JNIEnv *env, jclass clazz, jlong str) {
    LOGD("%s str=%ld",__func__,str);
}

JNIEXPORT void JNICALL setShort(JNIEnv *env, jclass clazz, jshort str) {
    LOGD("%s str=%d",__func__,str);
}

JNIEXPORT void JNICALL setByte(JNIEnv *env, jclass clazz, jshort str) {
    LOGD("%s str=%d",__func__,str);
}

JNIEXPORT void JNICALL setChar(JNIEnv *env, jclass clazz, jchar str) {
    LOGD("%s str=%c",__func__,str);
}

JNIEXPORT void JNICALL setIntArray(JNIEnv *env, jclass clazz, jintArray str) {
    jint size = env->GetArrayLength(str);
    jint *array = env->GetIntArrayElements(str,false);

    for(int i=0;i<size;i++)
        LOGD("%s str=%d",__func__,array[i]);
}

JNIEXPORT jstring JNICALL getString(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF("wo shi muhaitian");
}

JNIEXPORT jint JNICALL getInt(JNIEnv *env, jclass clazz) {
    return 76;
}

JNIEXPORT jboolean JNICALL getBoolean(JNIEnv *env, jclass clazz) {
    return true;
}

JNIEXPORT jdouble JNICALL getDouble(JNIEnv *env, jclass clazz) {
    return 15.89;
}

JNIEXPORT jfloat JNICALL getFloat(JNIEnv *env, jclass clazz) {
    return 15.66f;
}

JNIEXPORT jlong JNICALL getLong(JNIEnv *env, jclass clazz) {
    return 78956652522225533l;
}

JNIEXPORT jshort JNICALL getShort(JNIEnv *env, jclass clazz) {
    return 7;
}

JNIEXPORT jbyte JNICALL getByte(JNIEnv *env, jclass clazz) {
    return 1;
}

JNIEXPORT jchar JNICALL getChar(JNIEnv *env, jclass clazz) {
    return 'o';
}

JNIEXPORT jintArray JNICALL getIntArray(JNIEnv *env, jclass clazz) {
    jint *array = (jint *) env->NewIntArray(5);
    for (int i=0;i<5;i++){
        array[i] = (jint)(i+5);
    }
    return (jintArray) array;
}

static JNINativeMethod gMethods[] = {{"setString",   "(Ljava/lang/String;)V", (void *) setString},
                                     {"setInt",      "(I)V",                  (void *) setInt},
                                     {"setBoolean",  "(Z)V",                  (void *) setBoolean},
                                     {"setDouble",   "(D)V",                  (void *) setDouble},
                                     {"setFloat",    "(F)V",                  (void *) setFloat},
                                     {"setLong",     "(J)V",                  (void *) setLong},
                                     {"setShort",    "(S)V",                  (void *) setShort},
                                     {"setByte",     "(B)V",                  (void *) setByte},
                                     {"setChar",     "(C)V",                  (void *) setChar},
                                     {"setIntArray", "([I)V",                 (void *) setIntArray},

                                     {"getString",   "()Ljava/lang/String;",  (void *) getString},
                                     {"getInt",      "()I",                   (void *) getInt},
                                     {"getBoolean",  "()Z",                   (void *) getBoolean},
                                     {"getDouble",   "()D",                   (void *) getDouble},
                                     {"getFloat",    "()F",                   (void *) getFloat},
                                     {"getLong",     "()L",                   (void *) getLong},
                                     {"getShort",    "()S",                   (void *) getShort},
                                     {"getByte",     "()B",                   (void *) getByte},
                                     {"getChar",     "()C",                   (void *) getChar},
                                     {"getIntArray", "()[I",                  (void *) getIntArray},};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    jint result = -1;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return result;
    }
    if (!registerNatives(env)) {
        return result;
    }
    result = JNI_VERSION_1_6;
    return result;
}

static int registerNatives(JNIEnv *env) {
    if (!registerNativesMethids(env, DYNAMIC_JNI_CLASS, gMethods,
                                sizeof(gMethods) / sizeof(gMethods[0]))) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}


static int registerNativesMethids(JNIEnv *env, const char *className, JNINativeMethod *gMethod,
                                  int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (!env->RegisterNatives(clazz, gMethod, numMethods)) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}