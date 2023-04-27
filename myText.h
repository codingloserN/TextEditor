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
    char *buffer;   //�ַ����͵�ָ����������ռ�
    int size;       //��ʶ�����������ж��ٸ�Ԫ��
    int maxSize;    //Ŀǰ������ڴ棬���ɲ���������ڴ�
public:
    myText();     //��������Ķ�̬�ռ������
    ~myText();    //�����ͷ��ڶ��ж�̬������ڴ�
    void add();     //��
    void deleteRecord(int len);    //ɾ���������ĺ��沿�ֵĶ���
    bool alter(int pos,int len,char* s);       //��λ��Ϊpos��ʼlen���ȵ��ı���Ϊ�ַ���s��ǰlen���ַ���s����󳤶�Ϊ20
    int select(char *s);      //��
    void show();        //��ӡ�ı�
    int getSize();      //����������ǿգ�ָ��'\0'��λ�����ڵ��±ꡣ�������õ�size
    int *getNext(char* s);  //kmp�л��next����

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
    cout<<"������Ҫ��ӵ��ı���"<<endl;
    cin.getline(&buffer[size],'\n');//��ֹ��Ϊ'\n'
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
        //�滻
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
    cout<<endl<<"����"<<size<<"���ַ���";
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
