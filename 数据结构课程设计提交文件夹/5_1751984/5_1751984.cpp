#include <iostream>
#include <string.h>
#include "Quene1.h"
#define ifeven(i) i%2==0?1:0    //Ԥ�����Ƿ�Ϊż��



using namespace std;

int main() {int total,nums[1000];
    Quene aq,bq;
    memset(nums,0,sizeof(nums));         //���ֵ
    cout<<"���������ҵ��Ĺ˿�������"<<endl;
    cin>>total;   //��������
    while(total<=0){cout<<"����������������������룺"<<endl;cin>>total;}
    for(int i=0;i<total;i++)cin>>nums[i]; //������
    
    for(int i=0;nums[i]!=0;i++)   //���źö�
    {if(ifeven(nums[i]))bq.EnQuene(nums[i]);
    else aq.EnQuene(nums[i]);
    }
    
    while(!aq.IsEmpty()){
        
        aq.DeQuene();
        if(!aq.IsEmpty()||!bq.IsEmpty())cout<<" ";
        bq.AddState();
        if(bq.GetState()==2&&!bq.IsEmpty()){
            bq.DeQuene();
            if(!aq.IsEmpty()||!bq.IsEmpty())cout<<" ";
            bq.ReState();}
    }
    
    while(!bq.IsEmpty()){bq.DeQuene();if(!bq.IsEmpty())cout<<" ";}
    system("Pause"); 
    return 0;
}




