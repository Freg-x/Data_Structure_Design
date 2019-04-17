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
}//栈内优先级

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
}//栈外优先级

bool issdigit(char pc){
    if(isdigit(pc)||pc=='.')return true;
    else return false;
}//加入小数的判断



class StackNode{friend class WorkStack;
public:
protected:char c;//存储字符
    StackNode *next;//指针域
};

//链式工作栈
class WorkStack{
public:WorkStack(){first=new StackNode;}//带附加头节点
    void Push(char pc);//将值为pc押入
    void Pop(char &pc);//将弹出的值赋给变量pc
    bool IsEmpty(){return first->next==NULL?true:false;};//判断栈是否为空
    char GetTop(){return first->next->c;};//返回获取头节点的值
private:StackNode *first;//链表的头指针
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
