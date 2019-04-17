

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

////////////////////////////////////////////////////链表节点类Student////////////////////////////////////////////////////////

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
    next(p_next){}     //用参数初始化表的形式完成构造函数
    void Set_value(string,string,string,string,string);//赋值函数
protected:string number;
    string name;
    string sex;
    string age;
    string test_type;
    Student *next;    //链表节点的指针域
};

void Student::Set_value(string p_number="",string p_name="",string p_sex="",string p_age="",string p_test_type="")
{number=p_number;name=p_name;sex=p_sex;age=p_age;test_type=p_test_type;}



//////////////////////////////////////////////////////链表类 Student_list///////////////////////////////////////////////////

class Student_list{
public:Student_list(){first=new Student;}     //构造函数，有一个附加头节点
    ~Student_list(){Make_empty();}  //与Make_empty()函数结合的构析函数，释放内存防止内存泄露
    void Set_length(int);      //设置链表的长度
    void Input_data();      //输入链表长度个数据，采用后插法
    void Make_empty();      //收回内存
    void Display()const;   //显示数据
    void Insert();         //插入一个数据
    void Delete();         //删除一个数据
    void Change();         //改变一个数据
    void Find()const;      //查找一个数据
protected:Student *first; //链表的头指针
    int list_length;      //表长
};



void Student_list::Set_length(int p_length){list_length=p_length;}  //在调用其他函数前先设置表长，保证安全性和其他函数运行的正确性

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
        newstudent->Set_value(p_number,p_name,p_sex,p_age,p_test_type);   //调用友元类的赋值函数
        newstudent->next=NULL;
        tempstudent->next=newstudent;
        tempstudent=newstudent;
    }
}

void Student_list::Insert(){string strposition;int position;Student *current=first;//string转int的输入方式保证输入字母不崩溃，下同
    cout<<"请输入你要插入的考生位置：";cin>>strposition;position=atoi(strposition.c_str());
    while(position<=0||position>list_length+1){
        cout<<"无效的插入位置！请重新输入：";cin>>strposition;position=atoi(strposition.c_str());} //不得为负数、字母或大于表长加一
    cout<<endl<<"请依次输入要插入学生的学号、姓名、性别、年龄和报考类别："<<endl;
    for(int i=1;i!=position;i++){current=current->next;} //让指针指向插入位置
    Student *newstudent=new Student;
    string p_number;
    string p_name;
    string p_sex;
    string p_age;
    string p_test_type;
    cin>>p_number>>p_name>>p_sex>>p_age>>p_test_type;
    newstudent->Set_value(p_number,p_name,p_sex,p_age,p_test_type);
    newstudent->next=current->next;     //拉链，由于有头指针，不必特殊分类
    current->next=newstudent;
    list_length++;
    Display();
    }

void Student_list::Delete(){
    if(list_length==0)cout<<"这个表已经没有可以删除的项了"<<endl; //先判断是否为空，再进行删除操作
    else{string d_number;Student *current=first;Student *d_student;
    cout<<"请输入你要删除的考生考号：";cin>>d_number;
    for(int i=1;i<=list_length;i++){     //用for循环遍历寻找，调用strcmp函数比较
        if(strcmp(current->next->number.c_str(),d_number.c_str())==0)
        {d_student=current->next;  //找到后，拉链
        current->next=d_student->next;
        cout<<"你删除的数据是："<<d_student->number<<"      "<<d_student->name<<"      "<<d_student->sex<<"      "<<d_student->age<<"      "<<d_student->test_type<<endl;
            cout<<"删除后的表为：";Display();
            delete d_student;list_length--;break; //删除后，退出循环，不参与下面的判断语句
        }
        if(i==list_length)cout<<"未找到删除学号，故本次没有删除任何数据"<<endl;
        current=current->next;
    }
    }
}

void Student_list::Find()const{
    if(list_length==0)cout<<"你要在空表里找什么呢？"<<endl; //判断有值后再查找
    else{
    string f_number;Student *current=first->next;
    cout<<"请输入你要查找的考生考号：";cin>>f_number;
    for(int i=1;i<=list_length;i++){    //for循环遍历寻找
        if(strcmp(current->number.c_str(),f_number.c_str())==0)
        { cout<<current->number<<"      "<<current->name<<"      "<<current->sex<<"      "<<current->age<<"      "<<current->test_type<<endl;
            break;  //找到后退出循环，不参与下面的判断语句
        }
        if(i==list_length)cout<<"查无此人！"<<endl;
        current=current->next;
    }
    }
}

void Student_list::Change(){
    if(list_length==0)cout<<"这个表已经没有可以修改的项了"<<endl; //先看表是否为空，有值时进行操作
    else{string c_number;Student *current=first->next;
        cout<<"请输入要修改学生的学号：";cin>>c_number;
        for(int i=1;i<=list_length;i++){if(strcmp(current->number.c_str(),c_number.c_str())==0){ //遍历寻找
            cout<<"请依次输入新的学号、姓名、性别、年龄和报考类别："<<endl;
            string p_number;
            string p_name;
            string p_sex;
            string p_age;
            string p_test_type;
            cin>>p_number>>p_name>>p_sex>>p_age>>p_test_type;
            current->Set_value(p_number,p_name,p_sex,p_age,p_test_type); //修改值
            Display();
            break;
        }
        if(i==list_length)cout<<"想要修改的考号不存在"<<endl;
        current=current->next;
}
    }
    
}



    void Student_list::Display()const{Student *current;   //一个普通的输出函数
    cout<<"考号"<<"      "<<"姓名"<<"      "<<"性别"<<"      "<<"年龄"<<"      "<<"报考类别"<<endl;
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
