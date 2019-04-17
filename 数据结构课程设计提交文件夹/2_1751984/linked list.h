

#ifndef linked_list_h
#define linked_list_h

#include <iostream>
#include <cstdlib>

using namespace std;


char Compare(int a,int b){
    if(a>b)return '>';
    if(a==b)return '=';
    if(a<b)return '<';
    return '?';}

class LinkedList;
class ListNode{friend class LinkedList;
public:ListNode(int p_number=0,ListNode *p_next=NULL){number=p_number;next=p_next;}
    int GetNumber(){return number;}
    ListNode* GetNext(){return next;}
protected:ListNode *next;
    int number;
};



class LinkedList{
public:LinkedList(int p_length=0){first=new ListNode;length=p_length;}
    void InputData();
    void Display()const;
    void Addnumber(int p_number);
    ListNode* GetFirst(){return first;}
protected:ListNode *first;
    int length;
};




void LinkedList::InputData(){int p_number;cin>>p_number;ListNode *current=first;
    while(p_number!=-1){ListNode *NewNode=new ListNode;
        current->next=NewNode;
        NewNode->number=p_number;
        current=NewNode;length++;
        cin>>p_number;
    }
}

void LinkedList::Display()const{if(length==0)cout<<"NULL"<<endl;
    else{
    ListNode *current=first;
    for(int i=1;i<=length;i++){cout<<current->next->number;
        if(i!=length)cout<<" ";
        current=current->next;
    }
        cout<<endl;}
}

void LinkedList::Addnumber(int p_number){ListNode *current=first;
    for(int i=0;i<length;i++)
    {current=current->next;
    }
    current->next=new ListNode;
    current->next->number=p_number;
    length++;
}

LinkedList Merge(LinkedList s1,LinkedList s2){LinkedList s3;
    ListNode *s1_current=s1.GetFirst();ListNode *s2_current=s2.GetFirst();
    while(s1_current->GetNext()!=NULL&&s2_current->GetNext()!=NULL){
        switch (Compare(s1_current->GetNext()->GetNumber(),s2_current->GetNext()->GetNumber()))
        {case '>':s2_current=s2_current->GetNext();break;
            case '=':s3.Addnumber(s1_current->GetNext()->GetNumber());s1_current=s1_current->GetNext();s2_current=s2_current->GetNext();break;
            case '<':s1_current=s1_current->GetNext();break;
        }
    }
    return s3;
}





#endif /* linked_list_h */
