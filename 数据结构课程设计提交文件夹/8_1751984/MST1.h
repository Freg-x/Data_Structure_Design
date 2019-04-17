#include <iostream>
#include <string.h>

using namespace std;

#ifndef MST_h
#define MST_h


void init(){
    cout<<"**        �������ģ��ϵͳ         **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**       A --- �����������㡡������ **"<<endl;
    cout<<"**       B --- ��ӵ����ı�        **"<<endl;
    cout<<"**       C ---  ������С������     **"<<endl;
    cout<<"**       D --- ��ʾ��С������      **"<<endl;
    cout<<"**       E --- �˳�����           **"<<endl;
    cout<<"==================================="<<endl;
    cout<<endl;
}


struct Edge{
    
    int another;//�����ߵ���һ���ڵ�����
    
    int cost;//�����ߵ�Ȩֵ
    
    Edge *link;//��һ����
    
    Edge(int num,int weight):another(num),cost(weight),link(NULL){};//���캯��
    
};//�ߵĳ�ʼ������

struct MST_EDGE{
    
    string head;//����С�������е�ͷ�˵�����
    
    string tail;//����С�������е�β�˵�����
    
    int cost;//Ȩֵ
    
};

struct Vertex{
    string name;//���������
    
    Edge *first_edge;//����ĵ�һ����
    
    Vertex(){first_edge=NULL;}//���캯��
    
};//���ĳ�ʼ������

//ͼ�Ķ���


class Link_Graph{
    
public: Link_Graph(){NodeTable=(Vertex *)malloc(10000*sizeof(Vertex));length=0;}//���ȶ����ڽӱ�����㹻���ڴ�
    
    int GetVertexPos(string p_name);//�����ڵ����Ʒ��������ڽӱ��е�λ��
    
    string GetName(int p_number);//����λ�÷��������ڽӱ��е�����
    
    void InitVertex();//��ʼ���ڵ㣬�������ڽӱ�
    
    void InsertEdge(int v1,int v2,int cost);//���������ߵ�λ�ú�Ȩֵ��������ڽӱ�
    
    void InitEdge();//��ʼ���ڽӱ�ı�
    
    int Getlength(){return length;}//�����ڽӱ�ĳ���
    
    int GetFirstNeighbor(int v);//���һ���ڵ�ĵ�һ���߽��λ��
    
    int GetNextNeighbor(int v,int w);//��v�ڵ�ı��У����λ��Ϊw�ڵ��ұߵĽڵ�λ��
    
    int GetWeight(int v1,int v2);//�������ڵ�λ�ã��������ǵı�Ȩ��
    
    void Clear(){for(int i=0;i<length;i++)NodeTable[i].first_edge=NULL;} //����ı�ˢ��
    
private:Vertex *NodeTable;//�ڽӱ������ָ��
    
    int length;//�����ڽӱ�ĳ���
};

//��С��������Ķ���

class MST{
public:
    
    void SetLength(int p_length){length=p_length;}//������С�������ĳ���
    
    void Display(){for(int i=0;i<length;i++)cout<<E[i].head<<"-<"<<E[i].cost<<">-"<<E[i].tail<<"    ";}
    
    //���չʾ��С������
    
    
    void Insert(MST_EDGE p_MST_EDGE){
        
        E[length]=p_MST_EDGE;
        
        length++;
    }
    
    //������С������
    
private:int length;//��С�������ĳ���
    
    MST_EDGE E[1000];//�洢�ߵ�����
    
};




int Link_Graph::GetVertexPos(string p_name){
    
    for(int i=0;i<length;i++)if(strcmp(NodeTable[i].name.c_str(),p_name.c_str())==0)return i;
    
    return -1;//���û���ҵ�����-1
    }



string Link_Graph::GetName(int p_number){
    
    if(p_number>=0&&p_number<length)return NodeTable[p_number].name;
    
    else return "can not find";//���û���ҵ�������ʾ��Ϣ
}



int Link_Graph::GetFirstNeighbor(int v){
    
    if(v>=0&&v<length&&NodeTable[v].first_edge!=NULL)return NodeTable[v].first_edge->another;
    
    else return -1;//���û���ھӷ���-1
}



int Link_Graph::GetNextNeighbor(int v,int w){
    
    if(v>=0&&v<=length){//�����ж�v�Ϸ�
        
    Edge *p=NodeTable[v].first_edge;//������ָ��ָ���һ���ھ�
        //�ڳ���ʹ�ù������õ��������ʱv��Ȼ�е�һ���ھӣ���ʡȥ�ж�
        
    while(p!=NULL&&p->another!=w)p=p->link;
        
        if(p!=NULL&&p->link!=NULL)return p->link->another;}
    
    return -1;
}




int Link_Graph::GetWeight(int v1,int v2){
    if(v1!=-1&&v2!=-1){
        //�����ж���λ�úϷ�
        
        Edge *p=NodeTable[v1].first_edge;
        
        while(p!=NULL&&p->another!=v2)p=p->link;
        
        if(p!=NULL)return p->cost;
    }
    return 9999;//���򲻴��ڱ߽���������������Ϊ�����
}


//��ʼ���ڽӱ�

void Link_Graph::InitVertex(){
    
    cout<<"�����붥��ĸ�����";
    
    cin>>length;
    
    while(length<=0){
        cout<<"����Ķ���������Ϸ������������룺";
        
        cin>>length;
    }
    cout<<"�������������������ƣ�"<<endl;
    
    for(int i=0;i<length;i++)cin>>NodeTable[i].name;
}

//����һ����



void Link_Graph::InsertEdge(int v1,int v2,int cost){//��ʼ������Ҫ�����ָ��
    
    Edge *v1e=new Edge(v2,cost);
    
    Edge *v2e=new Edge(v1,cost);
    
    if(NodeTable[v1].first_edge==NULL){NodeTable[v1].first_edge=v1e;}//����ֱ�����������ͷָ����뷨
    
    else{v1e->link=NodeTable[v1].first_edge;NodeTable[v1].first_edge=v1e;}
    
    if(NodeTable[v2].first_edge==NULL){NodeTable[v2].first_edge=v2e;}
    
    else{v2e->link=NodeTable[v2].first_edge;NodeTable[v2].first_edge=v2e;}
    
}


//��ʼ���ߵĺ���


void Link_Graph::InitEdge(){//����ֱ�ӽ��в���߲���
    
    if(length<=0){cout<<"��û�г�ʼ���ڵ������²����Գ�ʼ����"<<endl;return;}
    
    else{
        cout<<"���棺��������������������ͬ��������������������ɸ���"<<endl;
        
        cout<<"�밴��ȫͼ�����������룬���ڲ����ڵı�����ϴ��Ȩֵ����"<<endl;
        
        int count=0;
        
        //����n(n-1)/2����
        while(count<length*(length-1)/2){
            
            string p1,p2;int p_cost;
            
            cout<<"�������������㼰��:";
            
            cin>>p1>>p2;cin>>p_cost;
            int v1=GetVertexPos(p1);
            int v2=GetVertexPos(p2);
            
            if(v1==-1||v2==-1){cout<<"�����ڵı�,��ȫ����������"<<endl;Clear();break;}//ˢ�º�Ҫ����������
            
            else {InsertEdge(v1,v2,p_cost);count++;}
        }
        
        
    }
    
    }

//��С�ѵĶ���
class MinHeap{
    
public:MinHeap(){length=0;}//��ʼ������Ϊ0
    
    void Renew(){length=0;}//���³���Ϊ0
    
    void Insert(MST_EDGE);//����һ����С�������ڵ�
    
    bool IsEmpty(){return length==0?true:false;}//�п�
    
    void Remove(MST_EDGE &E1);//ȡ�Ѷ�Ԫ�ش���E1��
    
private:int length;//����
    
    MST_EDGE heap[1000];//�洢������
};

void MinHeap::Insert(MST_EDGE E1){
    
    heap[length]=E1;
    
        int j=length,i=(j-1)/2;MST_EDGE temp=heap[j];//�Ե����ϵ���
    
    while(j>0){
        
        if(heap[i].cost<=temp.cost)break;
        
        else{heap[j]=heap[i];j=i;i=(i-1)/2;}
    }
    
    heap[j]=temp;
    
    length++;
    }


void MinHeap::Remove(MST_EDGE &E1){
    E1=heap[0];
    
    heap[0]=heap[length-1];
    
    length--;
    
    int i=0,j=2*i+1;//�Զ����µ���
    
    MST_EDGE temp=heap[i];
    
    while(j<=length-1){
        
        if(j<length-1&&heap[j].cost>heap[j+1].cost)j++;
        
        if(temp.cost<=heap[j].cost)break;
        
        else{heap[i]=heap[j];i=j;j=2*j+1;}
    }
    
    heap[i]=temp;
    
    
}
    
    


//�����㷨




void Prim(Link_Graph G,MST &M){
    
    M.SetLength(0);//�����㷨ǰ����Ϊ0
    
    bool Vmst[G.Getlength()];//�жϽڵ��Ƿ�����С��������
    
    for(int i=0;i<G.Getlength();i++)Vmst[i]=false;
    
    string p_point;
    
    cout<<"��������ʼ���㣺";cin>>p_point;
     int u=G.GetVertexPos(p_point);
    while(u==-1){cout<<"�����Ķ��㲻���ڣ����������룺";cin>>p_point;u=G.GetVertexPos(p_point);}
    
    int v;//�ֱ����Ҫ�õ��ı�ʾλ�õ��������洢�ߵı�������С��
    MST_EDGE ed;
    MinHeap H;
    
    
    Vmst[u]=true;//��u��ʼ��u�ڶ���
    
    int count=1;//������n-1��
    
    do{
        v=G.GetFirstNeighbor(u);
        while(v!=-1){
            if(Vmst[v]==false){//����������С����
                ed.tail=G.GetName(u);ed.head=G.GetName(v);ed.cost=G.GetWeight(u,v);
                H.Insert(ed);
            }
            v=G.GetNextNeighbor(u,v);//ѭ��д������û�ù��ı�
        }
        
        while(!H.IsEmpty()&&count<G.Getlength()){
            
            H.Remove(ed);//��ֵ��ed
            
            if(Vmst[G.GetVertexPos(ed.head)]==false){//֮ǰ������С�������ĵ㲻���ٳ���
                
                M.Insert(ed);
                
                u=G.GetVertexPos(ed.head);Vmst[u]=true;//u����
                
                count++;break;
            }
        }
        
        
    }while(count<G.Getlength());
    
    cout<<"����Prim��С��������"<<endl;
    
    
}
    
    










#endif /* MST_h */
