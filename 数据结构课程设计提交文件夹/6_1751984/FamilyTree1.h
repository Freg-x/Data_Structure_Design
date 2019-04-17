#include <iostream>
#include <cstring>

using namespace std;

#ifndef FamilyTree_h
#define FamilyTree_h

void Init(){
    cout<<"**             ���׹���ϵͳ            **"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"**           ��ѡ��Ҫִ�еĲ���          **"<<endl;
    cout<<"**            A --- ���Ƽ���           **"<<endl;
    cout<<"**          B --- ��Ӽ�ͥ��Ա          **"<<endl;
    cout<<"**          C --- ��ɢ�ֲ���ͥ          **"<<endl;
    cout<<"**        D --- ���ļ�ͥ��Ա����         **"<<endl;
    cout<<"**            E --- �˳�����            **"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"���Ƚ���һ�����ף�"<<endl;
}//�����ʾ��Ϣ



/*declaration of FamilyMember*/



class FamilyTree;
class FamilyMember{
    
    friend class FamilyTree;
    
public:
    
    FamilyMember();//init without parameters
    
    FamilyMember(FamilyMember*,FamilyMember*,string); //init with parameters
    
    void DisplayChild();//show this member's first generation child
    
    bool HasChild(){return first_child==NULL?false:true;}//�ж��Ƿ���ڳ���
    
    bool HasSibling(){return next_sibling==NULL?false:true;}//�ж��Ƿ�����ֵ�
    
protected:FamilyMember *next_sibling;//���������ֵܳ�Ա
    
    FamilyMember *first_child;//�������ĳ��ӳ�Ա
    
    string name;//������������
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
    if(!HasChild())cout<<"��ǰ��Աû�ж�Ů"<<endl;
    else{FamilyMember *current=first_child;
        cout<<name<<"�ĵ�һ�������ǣ�";
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
    
    void PerfectTree();//�������ĺ���
    
    bool Find(string p_name,FamilyMember **current,FamilyMember *root);//��root�ֵ���Ů�в���pname���ҵ���ָ������ָ���͸�current
    
    void AddMember();//��ӳ�Ա�ĺ���
    
    void DeleteMember();//��ɢ��ͥ�ĺ���
    
    void ChangeName();//�����ĺ���
    
protected:FamilyMember *first;//�ü�������ͷָ��
    
    
};

void FamilyTree::InitTree(){
    string anc_name;
    cout<<"���������ȵ�������";
    cin>>anc_name;
    first=new FamilyMember(NULL,NULL,anc_name);
    cout<<"�˼��׵������ǣ�"<<first->name<<endl;
    
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
    cout<<"������Ҫ������ͥ���˵�������";cin>>parent_name;
    if(Find(parent_name,&current,first)&&!current->HasChild()){
        cout<<"������"<<parent_name<<"�Ķ�Ů����:";
        int number;cin>>number;
        while(number<=0){cout<<"����������Ƿ������������룺";cin>>number;}
        
        cout<<"����������"<<parent_name<<"�Ķ�Ů������";
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
        if(current->HasChild()){cout<<"��ǰ��Ա�Ѿ����˺��ӣ��޷�������������"<<endl;
            cout<<"�����Ե�ǰ��Ա����Ů���в������볢����������";
        }
        else
        cout<<"��Ҫ������ͥ����Ա������"<<endl;}
    
    
}

void FamilyTree::AddMember(){
    cout<<endl<<"������Ҫ��Ӷ��ӣ���Ů�������˵�������";
    string parent_name,child_name;cin>>parent_name;
    
    FamilyMember *current=new FamilyMember,*current1;
    if(Find(parent_name,&current,first)){
        cout<<endl<<"������"<<parent_name<<"����ӵĶ��ӣ���Ů��)��������";
        cin>>child_name;
        current1=current;
        if(!current->HasChild())current->first_child=new FamilyMember(NULL,NULL,child_name);
        
        else {current=current->first_child;
            while(current->HasSibling())current=current->next_sibling;
            current->next_sibling=new FamilyMember(NULL,NULL,child_name);
            
        }
        current1->DisplayChild();
    }
    else cout<<"û���ҵ�������Ա"<<endl;
}



void FamilyTree::DeleteMember(){
    cout<<endl<<"������Ҫ��ɢ��ͥ���˵�����:";
    string del_name;cin>>del_name;
    FamilyMember *current=new FamilyMember;
    if(Find(del_name,&current,first)&&current->HasChild()){
        cout<<"Ҫ��ɢ��ͥ�����ǣ�"<<del_name<<endl;
        current->DisplayChild();
        current->first_child=NULL;
        
        
    }
    else cout<<"Ҫ��ɢ�ߵ����������ڻ���û����Ů"<<endl;
    
}

void FamilyTree::ChangeName(){
    cout<<"������Ҫ�����������˵�Ŀǰ������";
    string current_name,new_name;cin>>current_name;
    FamilyMember *current=new FamilyMember;
    if(Find(current_name,&current,first)){
        cout<<"��������ĺ��������";cin>>new_name;
        current->name=new_name;
        cout<<current_name<<"�Ѹ���Ϊ"<<new_name<<endl;
    }
    else cout<<"����ĵ�ǰ����������"<<endl;
}


#endif /* FamilyTree_h */
