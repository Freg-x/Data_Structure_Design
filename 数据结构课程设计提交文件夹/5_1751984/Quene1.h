#ifndef Quene_h
#define Quene_h

#include <iostream>
#include <string.h>

using namespace std;

class Quene{public:
Quene(){ReState();rear=0;front=0;memset(person,0,sizeof(person));};//���캯������ʼֵ��0
bool IsEmpty(){return front==rear?true:false;}//����λָ����ͬʱ�ж϶���Ϊ��
void EnQuene(int);//����������Ա��Ų��������
void DeQuene();//�˶Ӻ������˶ӵ�ͬʱ����һ�����
    void AddState(){state++;}//��ǰ״̬��һ
    void ReState(){state=0;}//״̬����
    int GetState(){return state;}//��ȡ��ǰ״̬
 
protected:
    int person[1000];//���ڴ洢��Ա���
    int rear,front;//���е�ͷβָ��
    int state; //��Ϊ������������������������жϴ��������һ�������Ƿ�������
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
