//
// Created by dell on 2023/4/27.
//

#ifndef TEXTEDITOR_MYTEXT_H
#define TEXTEDITOR_MYTEXT_H

#define INITAL_SIZE 100
#define ADD_SIZE 100
#define EXPAND_RATING 0.8
#include <iostream>
#include <stdlib.h>
using namespace std;

class myText{
private:
    char *buffer;   //字符类型的指针用于申请空间
    int size;       //标识现在数组中有多少个元素
    int maxSize;    //目前申请的内存，即可操作的最大内存
public:
    myText();     //用于最初的动态空间的申请
    ~myText();    //用于释放在堆中动态分配的内存
    void add();     //增
    void deleteRecord(int len);    //删除缓冲区的后面部分的东西
    bool alter(int pos,int len,char* s);       //将位置为pos开始len长度的文本改为字符串s的前len个字符，s的最大长度为20
    int select(char *s);      //查
    void show();        //打印文本
    int getSize();      //如果缓冲区非空，指向'\0'的位置所在的下标。即遍历得到size
    int *getNext(char* s);  //kmp中获得next数组

};
myText::myText() {
    buffer=new char[INITAL_SIZE];
    size=0;
    maxSize=INITAL_SIZE;
}
myText::~myText() {
    delete []buffer;
}
void myText::add() {
    cout<<"请输入要添加的文本："<<endl;
    cin.getline(&buffer[size],'\n');//终止符为'\n'
    cout<<"over...";
    size=getSize();
    if((float)size/maxSize>0.8)
    {
        buffer=new(buffer)char[maxSize+ADD_SIZE];
        maxSize+=ADD_SIZE;
    }

}
void myText::deleteRecord(int len) {
    size=size-len;
    buffer[size]='\0';
}
bool myText::alter(int pos, int len, char* s) {
    int sLen=0;
    for(int j=0;j<20;j++)
    {
        if(s[j]=='\0')
        {
            sLen=j;
            break;
        }
    }
    if(pos<1||len<1||pos+len-2>size||sLen<len)
        return false;
    for(int i=0;i<len;i++)
    {
        //替换
        buffer[pos-1+i]=s[i];
    }
    return true;
}
int * myText::getNext(char *s) {
    int len=0;
    while(s[len]!='\0')
    {
        len++;
    }
    int* next=new int[len];
    next[0]=0,next[1]=0;
    for(int i=2, j=1;i<len;)
    {
        if(s[i-1]==s[next[j]]||j==0)
        {
            next[i]=next[j]+1;
            i++;j++;
        }
        else
        {
            j=next[j];
        }
    }
    return next;
}
int myText::select(char *s) {

}
void myText::show() {
    for (int i = 0; i < maxSize&&buffer[i]!='\0'; ++i)
    {
        cout<<buffer[i];
    }
    cout<<endl<<"共有"<<size<<"个字符。";
}
int myText::getSize() {
    for (int i = 0; i < maxSize; ++i)
    {
        if(buffer[i]=='\0')
            return i;
    }
    return -1;
}
#endif //TEXTEDITOR_MYTEXT_H
