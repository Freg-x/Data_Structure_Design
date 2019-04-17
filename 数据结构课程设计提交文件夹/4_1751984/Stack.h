#include <ctype.h>

#ifndef Stack_h
#define Stack_h

int isp(char c){
    switch(c){
        case '(':return 1;break;
        case '*':return 5;break;
        case '/':return 5;break;
        case '%':return 5;break;
        case '+':return 3;break;
        case '-':return 3;break;
        case ')':return 6;break;
        default:return 0;break;
    }
    return 0;
}//ջ�����ȼ�

int icp(char c){
    switch(c){
        case '(':return 6;break;
        case '*':return 4;break;
        case '/':return 4;break;
        case '%':return 4;break;
        case '+':return 2;break;
        case '-':return 2;break;
        case ')':return 1;break;
        default:return 0;break;
    }
    return 0;
}//ջ�����ȼ�

bool issdigit(char pc){
    if(isdigit(pc)||pc=='.')return true;
    else return false;
}//����С�����ж�



class StackNode{friend class WorkStack;
public:
protected:char c;//�洢�ַ�
    StackNode *next;//ָ����
};

//��ʽ����ջ
class WorkStack{
public:WorkStack(){first=new StackNode;}//������ͷ�ڵ�
    void Push(char pc);//��ֵΪpcѺ��
    void Pop(char &pc);//��������ֵ��������pc
    bool IsEmpty(){return first->next==NULL?true:false;};//�ж�ջ�Ƿ�Ϊ��
    char GetTop(){return first->next->c;};//���ػ�ȡͷ�ڵ��ֵ
private:StackNode *first;//�����ͷָ��
};

void WorkStack::Push(char pc){
    StackNode *newnode=new StackNode;
    newnode->c=pc;
    if(!IsEmpty()){newnode->next=first->next;}
    first->next=newnode;
}

void WorkStack::Pop(char &pc){
    if(!IsEmpty()){pc=first->next->c;
        StackNode *del=first->next;
        if(first->next->next!=NULL)first->next=first->next->next;
        else first->next=NULL;
        delete del;
    }
}


    
    
    





#endif 
