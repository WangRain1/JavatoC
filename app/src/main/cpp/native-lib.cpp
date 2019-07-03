#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ts_javatoc_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


/**
 * PackageInfo packageInfo = getPackageManager().getPackageInfo(getPackageName(),PackageManager.GET_SIGNATURES);
   Signature[] signatures = packageInfo.signatures;
   signatures[0].toCharsString();
 */

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_ts_javatoc_MainActivity_checkSignal(JNIEnv *env, jobject instance, jobject context, jstring pm_)
{
    const char *pm = env->GetStringUTFChars(pm_, 0);

    jclass jclass = env->GetObjectClass(context);
    jmethodID j_mid = env->GetMethodID(jclass,"getPackageName","()Ljava/lang/String;");
    //获取报名
    jstring package_name = (jstring)env->CallObjectMethod(context,j_mid);
    const char* c_pm = env->GetStringUTFChars(package_name, 0);

    if (strcmp(c_pm,pm)==0){
        std::string result = "check success-";
        result = result.insert(result.length()-1,c_pm);
        const char * c_result = result.c_str();

        return env->NewStringUTF(c_result);
    }

    return env->NewStringUTF("check fail");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_ts_javatoc_Helper_getJavaPackage(JNIEnv *env, jobject instance, jobject context) {

    jclass jc = env->GetObjectClass(instance);
    //这里主要是方法的签名，下面说以下怎么获取方法签名
    jmethodID id = env->GetMethodID(jc,"getPackage","(Landroid/content/Context;)Ljava/lang/String;");
    //注意我们掉的getPackage()方法是有参数的，所以我们在此处要把参数传进去
    jstring pm = (jstring)env->CallObjectMethod(instance,id,context);

    const char* c_pm = env->GetStringUTFChars(pm,0);

    return env->NewStringUTF(c_pm);
}