

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

////////////////////////////////////////////////////����ڵ���Student////////////////////////////////////////////////////////

class Student{
    friend class Student_list;
public:Student(string p_number="",
               string p_name="",
               string p_sex="",
               string p_age="",
               string p_test_type="",
               Student *p_next=NULL):
    number(p_number),
    name(p_name),
    sex(p_sex),
    age(p_age),
    test_type(p_test_type),
    next(p_next){}     //�ò�����ʼ�������ʽ��ɹ��캯��
    void Set_value(string,string,string,string,string);//��ֵ����
protected:string number;
    string name;
    string sex;
    string age;
    string test_type;
    Student *next;    //����ڵ��ָ����
};

void Student::Set_value(string p_number="",string p_name="",string p_sex="",string p_age="",string p_test_type="")
{number=p_number;name=p_name;sex=p_sex;age=p_age;test_type=p_test_type;}



//////////////////////////////////////////////////////������ Student_list///////////////////////////////////////////////////

class Student_list{
public:Student_list(){first=new Student;}     //���캯������һ������ͷ�ڵ�
    ~Student_list(){Make_empty();}  //��Make_empty()������ϵĹ����������ͷ��ڴ��ֹ�ڴ�й¶
    void Set_length(int);      //��������ĳ���
    void Input_data();      //���������ȸ����ݣ����ú�巨
    void Make_empty();      //�ջ��ڴ�
    void Display()const;   //��ʾ����
    void Insert();         //����һ������
    void Delete();         //ɾ��һ������
    void Change();         //�ı�һ������
    void Find()const;      //����һ������
protected:Student *first; //�����ͷָ��
    int list_length;      //��
};



void Student_list::Set_length(int p_length){list_length=p_length;}  //�ڵ�����������ǰ�����ñ�����֤��ȫ�Ժ������������е���ȷ��

void Student_list::Make_empty(){Student *d;
    while(first->next!=NULL){
        d=first->next;
        first->next=d->next;
        delete d;
    }
}

void Student_list::Input_data(){
    Student *tempstudent=first;
    for(int i=1;i<=list_length;i++){Student *newstudent=new Student;
        string p_number;
        string p_name;
        string p_sex;
        string p_age;
        string p_test_type;
        cin>>p_number>>p_name>>p_sex>>p_age>>p_test_type;
        newstudent->Set_value(p_number,p_name,p_sex,p_age,p_test_type);   //������Ԫ��ĸ�ֵ����
        newstudent->next=NULL;
        tempstudent->next=newstudent;
        tempstudent=newstudent;
    }
}

void Student_list::Insert(){string strposition;int position;Student *current=first;//stringתint�����뷽ʽ��֤������ĸ����������ͬ
    cout<<"��������Ҫ����Ŀ���λ�ã�";cin>>strposition;position=atoi(strposition.c_str());
    while(position<=0||position>list_length+1){
        cout<<"��Ч�Ĳ���λ�ã����������룺";cin>>strposition;position=atoi(strposition.c_str());} //����Ϊ��������ĸ����ڱ���һ
    cout<<endl<<"����������Ҫ����ѧ����ѧ�š��������Ա�����ͱ������"<<endl;
    for(int i=1;i!=position;i++){current=current->next;} //��ָ��ָ�����λ��
    Student *newstudent=new Student;
    string p_number;
    string p_name;
    string p_sex;
    string p_age;
    string p_test_type;
    cin>>p_number>>p_name>>p_sex>>p_age>>p_test_type;
    newstudent->Set_value(p_number,p_name,p_sex,p_age,p_test_type);
    newstudent->next=current->next;     //������������ͷָ�룬�����������
    current->next=newstudent;
    list_length++;
    Display();
    }

void Student_list::Delete(){
    if(list_length==0)cout<<"������Ѿ�û�п���ɾ��������"<<endl; //���ж��Ƿ�Ϊ�գ��ٽ���ɾ������
    else{string d_number;Student *current=first;Student *d_student;
    cout<<"��������Ҫɾ���Ŀ������ţ�";cin>>d_number;
    for(int i=1;i<=list_length;i++){     //��forѭ������Ѱ�ң�����strcmp�����Ƚ�
        if(strcmp(current->next->number.c_str(),d_number.c_str())==0)
        {d_student=current->next;  //�ҵ�������
        current->next=d_student->next;
        cout<<"��ɾ���������ǣ�"<<d_student->number<<"      "<<d_student->name<<"      "<<d_student->sex<<"      "<<d_student->age<<"      "<<d_student->test_type<<endl;
            cout<<"ɾ����ı�Ϊ��";Display();
            delete d_student;list_length--;break; //ɾ�����˳�ѭ����������������ж����
        }
        if(i==list_length)cout<<"δ�ҵ�ɾ��ѧ�ţ��ʱ���û��ɾ���κ�����"<<endl;
        current=current->next;
    }
    }
}

void Student_list::Find()const{
    if(list_length==0)cout<<"��Ҫ�ڿձ�����ʲô�أ�"<<endl; //�ж���ֵ���ٲ���
    else{
    string f_number;Student *current=first->next;
    cout<<"��������Ҫ���ҵĿ������ţ�";cin>>f_number;
    for(int i=1;i<=list_length;i++){    //forѭ������Ѱ��
        if(strcmp(current->number.c_str(),f_number.c_str())==0)
        { cout<<current->number<<"      "<<current->name<<"      "<<current->sex<<"      "<<current->age<<"      "<<current->test_type<<endl;
            break;  //�ҵ����˳�ѭ����������������ж����
        }
        if(i==list_length)cout<<"���޴��ˣ�"<<endl;
        current=current->next;
    }
    }
}

void Student_list::Change(){
    if(list_length==0)cout<<"������Ѿ�û�п����޸ĵ�����"<<endl; //�ȿ����Ƿ�Ϊ�գ���ֵʱ���в���
    else{string c_number;Student *current=first->next;
        cout<<"������Ҫ�޸�ѧ����ѧ�ţ�";cin>>c_number;
        for(int i=1;i<=list_length;i++){if(strcmp(current->number.c_str(),c_number.c_str())==0){ //����Ѱ��
            cout<<"�����������µ�ѧ�š��������Ա�����ͱ������"<<endl;
            string p_number;
            string p_name;
            string p_sex;
            string p_age;
            string p_test_type;
            cin>>p_number>>p_name>>p_sex>>p_age>>p_test_type;
            current->Set_value(p_number,p_name,p_sex,p_age,p_test_type); //�޸�ֵ
            Display();
            break;
        }
        if(i==list_length)cout<<"��Ҫ�޸ĵĿ��Ų�����"<<endl;
        current=current->next;
}
    }
    
}



    void Student_list::Display()const{Student *current;   //һ����ͨ���������
    cout<<"����"<<"      "<<"����"<<"      "<<"�Ա�"<<"      "<<"����"<<"      "<<"�������"<<endl;
    for(current=first->next;current!=NULL;current=current->next){
        cout<<current->number<<"      ";
        cout<<current->name<<"      ";
        cout<<current->sex<<"      ";
        cout<<current->age<<"      ";
        cout<<current->test_type<<"      ";
        cout<<endl;
    }
}



#endif /* List_hpp */
