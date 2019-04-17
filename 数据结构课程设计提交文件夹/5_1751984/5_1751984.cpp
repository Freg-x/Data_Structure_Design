#include <iostream>
#include <string.h>
#include "Quene1.h"
#define ifeven(i) i%2==0?1:0    //预定义是否为偶数



using namespace std;

int main() {int total,nums[1000];
    Quene aq,bq;
    memset(nums,0,sizeof(nums));         //设初值
    cout<<"请输入办理业务的顾客人数："<<endl;
    cin>>total;   //输入人数
    while(total<=0){cout<<"输入的人数有误，请重修输入："<<endl;cin>>total;}
    for(int i=0;i<total;i++)cin>>nums[i]; //输入编号
    
    for(int i=0;nums[i]!=0;i++)   //先排好队
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




