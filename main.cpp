#include <iostream>
#include "myText.h"

using namespace std;

int main() {
    myText s;
    cout<<"欢迎来到小牛文本编辑器："<<endl;
    while(1)
    {
        int choice=0;
        cout<<"请选择你要进行的操作："<<endl;
        cout<<"1.添加内容"<<endl;
        cout<<"2.删除内容"<<endl;
        cout<<"3.修改内容"<<endl;
        cout<<"4.查找内容"<<endl;
        cout<<"5.退出"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
            {
                s.add();
                //清屏
                system("cls");
                s.show();
                //按任意键继续
                system("pause");
                break;
            }
            case 2:
            {
                int len;
                cout<<"请输入你要删除的文本的字符个数：";
                cin>>len;
                s.deleteRecord(len);
                //清屏
                system("cls");
                s.show();
                //按任意键继续
                system("pause");
                break;
            }
            case 3:
            {
                int pos;
                int len;
                s.show();
                cout<<"请输入你要更改的文本的位置："<<endl;
                cin>>pos;
                cout<<"请输入你要更改字符串的长度："<<endl;
                cin>>len;
                cout<<"请输入你要替代后的字符串："<<endl;
                char* aim;
                cin>>aim;
                //清屏
                system("cls");
                s.show();
                //按任意键继续
                system("pause");
                break;
            }
            case 4:
            {
                s.show();
                char *str;
                cout<<"请输入你要查找的字符串：";
                cin>>str;
                int flag=s.select(str);
                if(flag)
                    cout<<"查找成功！在文本的第"<<flag<<"个字符处。";
                else
                        cout<<"查找失败！文本中没有此字符串。";
                break;
            }
            case 5:
            {
                cout<<"感谢您的使用！再见！";
                exit(0);
            }
            default:
                cout<<"请检测你的选项是否正确。";
        }
    }


}
