#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

int main() {
    int logs[10001],first,second,N,i,firstid,secondid,sum(0);
    memset(logs,0,sizeof(logs));
    
    cin>>N;getchar();
    
    for(int i=0;i<N;i++)cin>>logs[i];
    
    while(N!=1){first=logs[0]<logs[1]?logs[0]:logs[1];
        firstid=logs[0]<logs[1]?0:1;
        second=logs[0]<logs[1]?logs[1]:logs[0];
        secondid=logs[0]<logs[1]?1:0;
        
        for(i=2;i<N;i++)
        {
            if(logs[i]<first){second=first;secondid=firstid;first=logs[i];firstid=i;}
            else if(logs[i]<second){second=logs[i];secondid=i;}
            
        }
        
        
        if(secondid==N-1){logs[firstid]=first+second;}
        else{logs[firstid]=logs[N-1];
            logs[secondid]=first+second;}
        cout<<first<<" "<<second<<endl;
        sum=first+second+sum;
        N--;}
    
    
    
    cout<<sum<<endl;
    system("Pause");
    return 0;
}

