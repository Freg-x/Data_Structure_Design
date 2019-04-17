#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef Graph_h
#define Graph_h


    

struct Edge{
    
    int another;//�����ߵ���һ���ڵ�����
    
    int cost;//�����ߵ�Ȩֵ
    
    Edge *link;//��һ����
    
    Edge(int num,int weight):another(num),cost(weight),link(NULL){};//���캯��
    
};//�ߵĳ�ʼ������

struct Vertex{
    
    Edge *first_edge;//����ĵ�һ����
    
    Vertex(){first_edge=NULL;}//���캯��
    
};//���ĳ�ʼ������

class Link_Graph{
    
public: Link_Graph(int p_length){length=p_length;}//���캯��
    
    bool InitEdges(int edges);//��ʼ���ڵ㣬�������ڽӱ�
    
    void InsertEdge(int v1,int v2,int cost);//���������ߵ�λ�ú�Ȩֵ��������ڽӱ�
    
    int Getlength(){return length;}//�����ڽӱ�ĳ���
    
    int GetFirstNeighbor(int v);//���һ���ڵ�ĵ�һ���߽��λ��
    
    int GetNextNeighbor(int v,int w);//��v�ڵ�ı��У����λ��Ϊw�ڵ��ұߵĽڵ�λ��
    
    int GetWeight(int v1,int v2);//�������ڵ�λ�ã��������ǵı�Ȩ��
    
    void Clear(){for(int i=0;i<length;i++)NodeTable[i].first_edge=NULL;} //����ı�ˢ��
    
    void CriticalPath();//��ؼ�·��
    
    void Debug();
    
private:Vertex NodeTable[100];//�ڽӱ������ָ��
    
    int length;//�����ڽӱ�ĳ���
};



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

void Link_Graph::InsertEdge(int v1,int v2,int cost){//��ʼ������Ҫ�����ָ��
    
    Edge *v1e=new Edge(v2,cost);
    
    if(NodeTable[v1].first_edge==NULL){NodeTable[v1].first_edge=v1e;}//���������Ȩͼִֻ��һ������
    
    else{v1e->link=NodeTable[v1].first_edge;NodeTable[v1].first_edge=v1e;}
    
    
}

bool Link_Graph::InitEdges(int edges){
    bool ok=true;
    int v1,v2,cost;
    
    for(int i=0;i<edges;i++){
        cin>>v1>>v2>>cost;
        if(v1>v2)ok=false;
        InsertEdge(v1-1,v2-1,cost);
    }
    return ok;
}

void Link_Graph::CriticalPath(){
    int Ve[length];
    int Vl[length];
    int i,j,k,weight,Ae,Al;
    
    for(i=0;i<length;i++)Ve[i]=0;
    for(i=0;i<length;i++)Vl[i]=999;
        
    for(i=0;i<length;i++){//����������翪ʼʱ��
        
        j=GetFirstNeighbor(i);
        
        
        while(j!=-1){
            weight=GetWeight(i,j);
            if(Ve[i]+weight>Ve[j])Ve[j]=Ve[i]+weight;
            j=GetNextNeighbor(i,j);
        }
        
    }
    
    Vl[length-1]=Ve[length-1];
    
    cout<<Vl[length-1]<<endl;//������һ��������翪ʼʱ�伴���ʱ��
    
    for(j=length-2;j>0;j--){//�����������ʼʱ��
        k=GetFirstNeighbor(j);
        while(k!=-1){
            weight=GetWeight(j,k);
            if(Vl[k]-weight<Vl[j])Vl[j]=Vl[k]-weight;
            k=GetNextNeighbor(j,k);
            
            
        }
        
        
    }
    
    
    
    for(i=0;i<length;i++){//������ʱ�䲢�ж����
        j=GetFirstNeighbor(i);
        while(j!=-1){
            
            Ae=Ve[i];Al=Vl[j]-GetWeight(i,j);
            if(Ae==Al){
                cout<<i+1<<"->"<<j+1<<endl;
            }
            j=GetNextNeighbor(i,j);
            
        }
    }
    
    
    
    
}








#endif /* Graph_h */
