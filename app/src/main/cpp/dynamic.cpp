//
// Created by muhaitian on 2017/7/21.
//

#include <jni.h>
#include <android/log.h>


#define DYNAMIC_JNI_CLASS "com/muhaitian/jnidemo/jni/DynamicJniClass"
#define DYNAMIC "dynamic"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,DYNAMIC,__VA_ARGS__);

#define STUDENT "com/muhaitian/jnidemo/jni/Student"
jobject mStudent;

static int registerNativesMethids(JNIEnv *env, const char *className, JNINativeMethod *gMethod,
                                  int numMethods);

static int registerNatives(JNIEnv *env);

JNIEXPORT void JNICALL setString(JNIEnv *env, jclass clazz, jstring str) {
    char *mkmk = (char *) env->GetStringUTFChars(str, 0);
    LOGD("%s str=%s", __func__, mkmk);
}

JNIEXPORT void JNICALL setInt(JNIEnv *env, jclass clazz, jint str) {
    LOGD("%s str=%d", __func__, str);
}

JNIEXPORT void JNICALL setBoolean(JNIEnv *env, jclass clazz, jboolean str) {
    LOGD("%s str=%d", __func__, str);
}

JNIEXPORT void JNICALL setDouble(JNIEnv *env, jclass clazz, jdouble str) {
    LOGD("%s str=%lf", __func__, str);
}

JNIEXPORT void JNICALL setFloat(JNIEnv *env, jclass clazz, jfloat str) {
    LOGD("%s str=%f", __func__, str);
}

JNIEXPORT void JNICALL setLong(JNIEnv *env, jclass clazz, jlong str) {
    LOGD("%s str=%ld", __func__, str);
}

JNIEXPORT void JNICALL setShort(JNIEnv *env, jclass clazz, jshort str) {
    LOGD("%s str=%d", __func__, str);
}

JNIEXPORT void JNICALL setByte(JNIEnv *env, jclass clazz, jshort str) {
    LOGD("%s str=%d", __func__, str);
}

JNIEXPORT void JNICALL setChar(JNIEnv *env, jclass clazz, jchar str) {
    LOGD("%s str=%c", __func__, str);
}

JNIEXPORT void JNICALL setIntArray(JNIEnv *env, jclass clazz, jintArray str) {
    jint size = env->GetArrayLength(str);
    jint *array = env->GetIntArrayElements(str, NULL);

    for (int i = 0; i < size; i++)
        LOGD("%s str=%d", __func__, array[i]);
    env->ReleaseIntArrayElements(str, array, JNI_ABORT);
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
    jintArray array = env->NewIntArray(5);
    int length = env->GetArrayLength(array);
    jint *arr = env->GetIntArrayElements(array, NULL);
    for (int i = 0; i < length; i++) {
        arr[i] = i + 5;
    }

    return array;
}

JNIEXPORT void JNICALL setStudent(JNIEnv *env, jclass clazz,jobject student) {
    LOGD("%s",__func__);
    //赋值全局变量student对象
    mStudent = env->NewGlobalRef(student);
}

JNIEXPORT jobject JNICALL getStudent(JNIEnv *env, jclass clazz) {
    jclass StudentClass = env->FindClass(STUDENT);
    if (mStudent != NULL) {

        jmethodID getstudent_id = env->GetMethodID(StudentClass, "getStudentName",
                                                   "()Ljava/lang/String;");
        jstring student = (jstring) env->CallObjectMethod(mStudent, getstudent_id);
        LOGD("%s str=%s", __func__, student);

        jmethodID setStudent_id = env->GetMethodID(StudentClass, "setStudentName",
                                                   "(Ljava/lang/String;)V");
        env->CallVoidMethod(StudentClass, setStudent_id, env->NewStringUTF("kkkkkkkkkkk"));
    } else {
        jmethodID init_id = env->GetMethodID(StudentClass, "<init>", "()V");
        mStudent = env->NewObject(StudentClass, init_id);
        jmethodID setStudent_id = env->GetMethodID(StudentClass, "setStudentName",
                                                   "(Ljava/lang/String;)V");
        env->CallVoidMethod(mStudent, setStudent_id, env->NewStringUTF("wo shi muhaitian"));
    }
    return mStudent;
}

static JNINativeMethod gMethods[] = {{"setString",   "(Ljava/lang/String;)V",                  (void *) setString},
                                     {"setInt",      "(I)V",                                   (void *) setInt},
                                     {"setBoolean",  "(Z)V",                                   (void *) setBoolean},
                                     {"setDouble",   "(D)V",                                   (void *) setDouble},
                                     {"setFloat",    "(F)V",                                   (void *) setFloat},
                                     {"setLong",     "(J)V",                                   (void *) setLong},
                                     {"setShort",    "(S)V",                                   (void *) setShort},
                                     {"setByte",     "(B)V",                                   (void *) setByte},
                                     {"setChar",     "(C)V",                                   (void *) setChar},
                                     {"setIntArray", "([I)V",                                  (void *) setIntArray},
                                     {"setStudent",  "(Lcom/muhaitian/jnidemo/jni/Student;)V", (void *) setStudent},

                                     {"getString",   "()Ljava/lang/String;",                   (void *) getString},
                                     {"getInt",      "()I",                                    (void *) getInt},
                                     {"getBoolean",  "()Z",                                    (void *) getBoolean},
                                     {"getDouble",   "()D",                                    (void *) getDouble},
                                     {"getFloat",    "()F",                                    (void *) getFloat},
                                     {"getLong",     "()J",                                    (void *) getLong},
                                     {"getShort",    "()S",                                    (void *) getShort},
                                     {"getByte",     "()B",                                    (void *) getByte},
                                     {"getChar",     "()C",                                    (void *) getChar},
                                     {"getIntArray", "()[I",                                   (void *) getIntArray},
                                     {"getStudent",  "()Lcom/muhaitian/jnidemo/jni/Student;",  (void *) getStudent},};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *JniEvn;
    jint result = -1;
    if (vm->GetEnv((void **) &JniEvn, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }
    if (!registerNatives(JniEvn)) {
        return result;
    }
    result = JNI_VERSION_1_4;
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
    if (env->RegisterNatives(clazz, gMethod, numMethods) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}