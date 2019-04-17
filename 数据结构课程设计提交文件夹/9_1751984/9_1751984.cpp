

#include <iostream>
#include <cstdlib>
#include "Graph1.h"

using namespace std;

int main() {
    int length,edges;   //分别代表表的长度和边的个数
    cin>>length>>edges;
    while(length<=2||edges<=1||length>edges){
        cout<<"非法或无意义的任务输入，请重新输入：";
        cin>>length>>edges;
    }
    
    Link_Graph G1(length);
    bool ok=G1.InitEdges(edges);
    if(ok)G1.CriticalPath();
    else cout<<ok<<endl;
    system("Pause"); 
    
    return 0;
}
