#include <iostream>
#include "myText.h"

using namespace std;

int main() {
    myText s;
    cout<<"��ӭ����Сţ�ı��༭����"<<endl;
    while(1)
    {
        int choice=0;
        cout<<"��ѡ����Ҫ���еĲ�����"<<endl;
        cout<<"1.�������"<<endl;
        cout<<"2.ɾ������"<<endl;
        cout<<"3.�޸�����"<<endl;
        cout<<"4.��������"<<endl;
        cout<<"5.�˳�"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
            {
                s.add();
                //����
                system("cls");
                s.show();
                //�����������
                system("pause");
                break;
            }
            case 2:
            {
                int len;
                cout<<"��������Ҫɾ�����ı����ַ�������";
                cin>>len;
                s.deleteRecord(len);
                //����
                system("cls");
                s.show();
                //�����������
                system("pause");
                break;
            }
            case 3:
            {
                int pos;
                int len;
                s.show();
                cout<<"��������Ҫ���ĵ��ı���λ�ã�"<<endl;
                cin>>pos;
                cout<<"��������Ҫ�����ַ����ĳ��ȣ�"<<endl;
                cin>>len;
                cout<<"��������Ҫ�������ַ�����"<<endl;
                char* aim;
                cin>>aim;
                //����
                system("cls");
                s.show();
                //�����������
                system("pause");
                break;
            }
            case 4:
            {
                s.show();
                char *str;
                cout<<"��������Ҫ���ҵ��ַ�����";
                cin>>str;
                int flag=s.select(str);
                if(flag)
                    cout<<"���ҳɹ������ı��ĵ�"<<flag<<"���ַ�����";
                else
                        cout<<"����ʧ�ܣ��ı���û�д��ַ�����";
                break;
            }
            case 5:
            {
                cout<<"��л����ʹ�ã��ټ���";
                exit(0);
            }
            default:
                cout<<"�������ѡ���Ƿ���ȷ��";
        }
    }


}
