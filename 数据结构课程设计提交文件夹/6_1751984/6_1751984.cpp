

#include <iostream>
#include "FamilyTree1.h"
using namespace std;


int main() {
    Init();
    FamilyTree T1;
    T1.InitTree();
    
    char Op;
    cout<<endl<<"��ѡ��Ҫִ�еĲ�����";cin>>Op;
    while (Op!='E'){
        
        
    switch(Op){
        case 'A':T1.PerfectTree();break;
        case 'B':T1.AddMember();break;
        case 'C':T1.DeleteMember();break;
        case 'D':T1.ChangeName();break;
        default:cout<<"������Ĳ����벻���ڣ�����������!";
    }
        cout<<endl<<"��ѡ��Ҫִ�еĲ�����";cin>>Op;
    }
    
    return 0;
}
