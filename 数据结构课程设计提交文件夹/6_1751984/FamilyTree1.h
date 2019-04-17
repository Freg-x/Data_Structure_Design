#include <iostream>
#include <cstring>

using namespace std;

#ifndef FamilyTree_h
#define FamilyTree_h

void Init(){
    cout<<"**             家谱管理系统            **"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"**           请选择要执行的操作          **"<<endl;
    cout<<"**            A --- 完善家谱           **"<<endl;
    cout<<"**          B --- 添加家庭成员          **"<<endl;
    cout<<"**          C --- 解散局部家庭          **"<<endl;
    cout<<"**        D --- 更改家庭成员姓名         **"<<endl;
    cout<<"**            E --- 退出程序            **"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"首先建立一个家谱！"<<endl;
}//输出提示信息



/*declaration of FamilyMember*/



class FamilyTree;
class FamilyMember{
    
    friend class FamilyTree;
    
public:
    
    FamilyMember();//init without parameters
    
    FamilyMember(FamilyMember*,FamilyMember*,string); //init with parameters
    
    void DisplayChild();//show this member's first generation child
    
    bool HasChild(){return first_child==NULL?false:true;}//判断是否存在长子
    
    bool HasSibling(){return next_sibling==NULL?false:true;}//判断是否存在兄弟
    
protected:FamilyMember *next_sibling;//代表它的兄弟成员
    
    FamilyMember *first_child;//代表它的长子成员
    
    string name;//代表它的名字
};

FamilyMember::FamilyMember(){
    next_sibling=NULL;
    first_child=NULL;
    name="unknown";
}

FamilyMember::FamilyMember(FamilyMember *p_next_sibling,FamilyMember *p_first_child,string p_name){
    next_sibling=p_next_sibling;
    first_child=p_first_child;
    name=p_name;
}

void FamilyMember::DisplayChild(){
    if(!HasChild())cout<<"当前成员没有儿女"<<endl;
    else{FamilyMember *current=first_child;
        cout<<name<<"的第一代子孙是：";
        while(current->HasSibling()){
            cout<<current->name<<" ";
            current=current->next_sibling;
        }
        cout<<current->name<<endl;
    }
    
}

/*declaration of FamilyTree*/


class FamilyTree{
public:
    
    FamilyTree():first(NULL){}
    
    void InitTree();//Init the tree, will command to input the ancestor's name
    
    void PerfectTree();//完善树的函数
    
    bool Find(string p_name,FamilyMember **current,FamilyMember *root);//在root兄弟子女中查找pname，找到将指向它的指针送给current
    
    void AddMember();//添加成员的函数
    
    void DeleteMember();//解散家庭的函数
    
    void ChangeName();//改名的函数
    
protected:FamilyMember *first;//该家谱树的头指针
    
    
};

void FamilyTree::InitTree(){
    string anc_name;
    cout<<"请输入祖先的姓名：";
    cin>>anc_name;
    first=new FamilyMember(NULL,NULL,anc_name);
    cout<<"此家谱的祖先是："<<first->name<<endl;
    
}


bool FamilyTree::Find(string p_name,FamilyMember **current,FamilyMember *root){
    bool result=false;
    if(strcmp(root->name.c_str(),p_name.c_str())==0){*current=root;return true;}
  if(root->HasChild())result=Find(p_name,current,root->first_child);
  if(root->HasSibling()&&result==false)result=Find(p_name,current,root->next_sibling);
    return result;
}



void FamilyTree::PerfectTree(){
    string parent_name,child_name;FamilyMember *current=new FamilyMember,*current1;
    cout<<"请输入要建立家庭的人的姓名：";cin>>parent_name;
    if(Find(parent_name,&current,first)&&!current->HasChild()){
        cout<<"请输入"<<parent_name<<"的儿女人数:";
        int number;cin>>number;
        while(number<=0){cout<<"输入的人数非法，请重新输入：";cin>>number;}
        
        cout<<"请依次输入"<<parent_name<<"的儿女姓名：";
        current1=current;cin>>child_name;
        current1->first_child=new FamilyMember(NULL,NULL,child_name);
        current1=current1->first_child;
        for(int i=0;i<number-1;i++){cin>>child_name;
            current1->next_sibling=new FamilyMember(NULL,NULL,child_name);
            current1=current1->next_sibling;
        }
        current->DisplayChild();
    }
    
    else {
        if(current->HasChild()){cout<<"当前成员已经有了孩子，无法对他进行完善"<<endl;
            cout<<"如果想对当前成员的子女进行操作，请尝试其他操作";
        }
        else
        cout<<"想要建立家庭的人员不存在"<<endl;}
    
    
}

void FamilyTree::AddMember(){
    cout<<endl<<"请输入要添加儿子（或女儿）的人的姓名：";
    string parent_name,child_name;cin>>parent_name;
    
    FamilyMember *current=new FamilyMember,*current1;
    if(Find(parent_name,&current,first)){
        cout<<endl<<"请输入"<<parent_name<<"新添加的儿子（或女儿)的姓名：";
        cin>>child_name;
        current1=current;
        if(!current->HasChild())current->first_child=new FamilyMember(NULL,NULL,child_name);
        
        else {current=current->first_child;
            while(current->HasSibling())current=current->next_sibling;
            current->next_sibling=new FamilyMember(NULL,NULL,child_name);
            
        }
        current1->DisplayChild();
    }
    else cout<<"没有找到所给人员"<<endl;
}



void FamilyTree::DeleteMember(){
    cout<<endl<<"请输入要解散家庭的人的姓名:";
    string del_name;cin>>del_name;
    FamilyMember *current=new FamilyMember;
    if(Find(del_name,&current,first)&&current->HasChild()){
        cout<<"要解散家庭的人是："<<del_name<<endl;
        current->DisplayChild();
        current->first_child=NULL;
        
        
    }
    else cout<<"要解散者的姓名不存在或他没有子女"<<endl;
    
}

void FamilyTree::ChangeName(){
    cout<<"请输入要更改姓名的人的目前姓名：";
    string current_name,new_name;cin>>current_name;
    FamilyMember *current=new FamilyMember;
    if(Find(current_name,&current,first)){
        cout<<"请输入更改后的姓名：";cin>>new_name;
        current->name=new_name;
        cout<<current_name<<"已更名为"<<new_name<<endl;
    }
    else cout<<"输入的当前姓名不存在"<<endl;
}


#endif /* FamilyTree_h */
