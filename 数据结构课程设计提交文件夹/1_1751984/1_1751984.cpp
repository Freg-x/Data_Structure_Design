
#include <iostream>
#include <stdlib.h>
#include <string>
#include "List1.hpp"

using namespace std;



int main(){
    Student_list s1;    //����ʱ�Զ�ִ�й��캯��������ʱִ�й�����������ֹ�ڴ�й¶
    cout<<"�����뿼��������"<<endl;
    string strlength;cin>>strlength;
    int length=atoi(strlength.c_str());       //�������string�������������ͨ��atoi()����תΪint��ֵ�����Է�ֹ������ĸʱ����ѭ����bug
    while(length<=0){cout<<"���������û�����壡���������룺"<<endl;cin>>strlength;length=atoi(strlength.c_str());}
    s1.Set_length(length);
    cout<<"���������뿼���Ŀ��ţ��������Ա����估�������"<<endl;
    s1.Input_data();   //�������뺯��
    s1.Display();      //չʾ��ǰ��
    cout<<"��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ������)"<<endl;
    char operate_code;cin>>operate_code;
    while(operate_code!='0')     //��������Ϊ0ʱ���������
    {switch(operate_code)        //�Բ��������ɸѡ�����ö�Ӧ�ĺ���
        {   case '1':s1.Insert();break;
            case '2':s1.Delete();break;
            case '3':s1.Find();break;
            case '4':s1.Change();break;
            case '5':s1.Display();break;
            default:cout<<"��Ǹ������Ҫ���еĲ��������ڣ����������룡"<<endl;break;
        }
     cout<<"��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ������)"<<endl;
        cin>>operate_code;
    }
    
    return 0;
}
