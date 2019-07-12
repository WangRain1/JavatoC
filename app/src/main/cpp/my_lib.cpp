//
// Created by ts on 19-7-4.
//

#include <jni.h>
#include <string>
#include <set>
#include <vector>
#include "Test.h"
#include "Testt.hpp"


#define Jin(NAME) java_jin_##NAME

std::string java_jin_wirte(char* c){

    return c;
}

std::string java_jin_read(char* c,int a){

    return c;
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_ts_javatoc_MainActivity_getJin(JNIEnv *env, jobject instance) {

//    MyTemplate *mt = new MyTemplate();
//    mt->setIndex(102);
//    int x = mt->getIndex();
//    std::string wx = std::to_string(x);
//    std::string h = "这是宏定义函数";
//    std::string hc = h.insert(0,wx);
//    char *w = const_cast<char *>(hc.c_str());
//
//    std::string hello = Jin(read)(w,2);

    MyTemplateName<std::string> *name = new MyTemplateName<std::string>();
    std::string sx = " + 测试模板类";
    name->setIndex(sx);
    name->getIndex();
    MyTemplateName<int> *age = new MyTemplateName<int>();
    age->setIndex(2222);
    std::string as = std::to_string(age->getIndex());

    std::vector<std::string> sv;
    sv.push_back("s");
    sv.pop_back();

    std::set<std::string> set1;

    return env->NewStringUTF((sx.insert(0,as).c_str()));
}