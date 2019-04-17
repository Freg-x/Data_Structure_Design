

#include <iostream>
#include "FamilyTree1.h"
using namespace std;


int main() {
    Init();
    FamilyTree T1;
    T1.InitTree();
    
    char Op;
    cout<<endl<<"请选择要执行的操作：";cin>>Op;
    while (Op!='E'){
        
        
    switch(Op){
        case 'A':T1.PerfectTree();break;
        case 'B':T1.AddMember();break;
        case 'C':T1.DeleteMember();break;
        case 'D':T1.ChangeName();break;
        default:cout<<"您输入的操作码不存在，请重新输入!";
    }
        cout<<endl<<"请选择要执行的操作：";cin>>Op;
    }
    
    return 0;
}
