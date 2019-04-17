
#include <iostream>
#include <stdlib.h>
#include <string>
#include "List1.hpp"

using namespace std;



int main(){
    Student_list s1;    //创建时自动执行构造函数，结束时执行构析函数，防止内存泄露
    cout<<"请输入考生人数："<<endl;
    string strlength;cin>>strlength;
    int length=atoi(strlength.c_str());       //这里采用string类型输入表长，再通过atoi()函数转为int赋值，可以防止输入字母时无限循环的bug
    while(length<=0){cout<<"输入的人数没有意义！请重新输入："<<endl;cin>>strlength;length=atoi(strlength.c_str());}
    s1.Set_length(length);
    cout<<"请依次输入考生的考号，姓名，性别，年龄及报考类别："<<endl;
    s1.Input_data();   //调用输入函数
    s1.Display();      //展示当前表
    cout<<"请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作)"<<endl;
    char operate_code;cin>>operate_code;
    while(operate_code!='0')     //当操作码为0时，程序结束
    {switch(operate_code)        //对操作码进行筛选，调用对应的函数
        {   case '1':s1.Insert();break;
            case '2':s1.Delete();break;
            case '3':s1.Find();break;
            case '4':s1.Change();break;
            case '5':s1.Display();break;
            default:cout<<"抱歉，您想要进行的操作不存在，请重新输入！"<<endl;break;
        }
     cout<<"请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作)"<<endl;
        cin>>operate_code;
    }
    
    return 0;
}
