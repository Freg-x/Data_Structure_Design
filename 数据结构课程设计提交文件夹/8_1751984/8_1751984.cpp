

#include <iostream>
#include <cstdlib>
#include <string.h>
#include "MST1.h"

using namespace std;

int main() {init();
    
    Link_Graph G1;
    MST M1;
    
    
    char Op;
    cout<<"��ѡ�������";
    cin>>Op;
    while(Op!='E'){
    switch (Op) {
        case 'A':G1.InitVertex();break;
        case 'B':G1.InitEdge();break;
        case 'C':Prim(G1,M1);break;
        case 'D':M1.Display();break;
        default:cout<<"������Ĳ����벻���ڣ�����������"<<endl;
            
    }
        cout<<endl<<"��ѡ�������";
        cin>>Op;
        
    }
    
    
    
    return 0;
}
