

#include <iostream>
#include <cstdlib>
#include "Graph1.h"

using namespace std;

int main() {
    int length,edges;   //�ֱ�����ĳ��Ⱥͱߵĸ���
    cin>>length>>edges;
    while(length<=2||edges<=1||length>edges){
        cout<<"�Ƿ�����������������룬���������룺";
        cin>>length>>edges;
    }
    
    Link_Graph G1(length);
    bool ok=G1.InitEdges(edges);
    if(ok)G1.CriticalPath();
    else cout<<ok<<endl;
    system("Pause"); 
    
    return 0;
}
