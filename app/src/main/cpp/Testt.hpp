//
// Created by ts on 19-7-11.
//

#ifndef JAVATOC_TESTT_HPP
#define JAVATOC_TESTT_HPP

template <class T>
class MyTemplateName{
private:
    T index;
    char *x;
public:
    MyTemplateName();
    T getIndex();
    void setIndex(T dex);
    // 析构函数
    ~MyTemplateName();
};

#endif //JAVATOC_TESTT_HPP

template <class T>
//此处必须加上<T> -- MyTemplateName<T>
MyTemplateName<T>::MyTemplateName() {
}

template <class T>
void MyTemplateName<T>::setIndex(T dex) {
    this->index = dex;
}

template <class T>
T MyTemplateName<T>::getIndex() {
    return this->index;
}