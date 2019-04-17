#ifndef Quene_h
#define Quene_h

#include <iostream>
#include <string.h>

using namespace std;

class Quene{public:
Quene(){ReState();rear=0;front=0;memset(person,0,sizeof(person));};//构造函数，初始值置0
bool IsEmpty(){return front==rear?true:false;}//当首位指针相同时判断队列为空
void EnQuene(int);//将所给的人员编号插入队列中
void DeQuene();//退队函数，退队的同时进行一次输出
    void AddState(){state++;}//当前状态加一
    void ReState(){state=0;}//状态清零
    int GetState(){return state;}//获取当前状态
 
protected:
    int person[1000];//用于存储人员编号
    int rear,front;//队列的头尾指针
    int state; //因为本题特殊需求而创建，用于判断处理较慢的一个队列是否可以输出
};

void Quene::EnQuene(int x){
    person[rear]=x;
    rear=rear+1;
}

void Quene::DeQuene(){
    
    cout<<person[front];
    person[front]=0;
    front=front+1;
}




#endif /* Quene_h */
