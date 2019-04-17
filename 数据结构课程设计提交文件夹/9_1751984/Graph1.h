#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef Graph_h
#define Graph_h


    

struct Edge{
    
    int another;//这条边的另一个节点名称
    
    int cost;//这条边的权值
    
    Edge *link;//下一条边
    
    Edge(int num,int weight):another(num),cost(weight),link(NULL){};//构造函数
    
};//边的初始化定义

struct Vertex{
    
    Edge *first_edge;//顶点的第一条边
    
    Vertex(){first_edge=NULL;}//构造函数
    
};//结点的初始化定义

class Link_Graph{
    
public: Link_Graph(int p_length){length=p_length;}//构造函数
    
    bool InitEdges(int edges);//初始化节点，即生成邻接表
    
    void InsertEdge(int v1,int v2,int cost);//给出两条边的位置和权值将其插入邻接表
    
    int Getlength(){return length;}//返回邻接表的长度
    
    int GetFirstNeighbor(int v);//获得一个节点的第一个边结点位置
    
    int GetNextNeighbor(int v,int w);//在v节点的边中，获得位置为w节点右边的节点位置
    
    int GetWeight(int v1,int v2);//给出两节点位置，返回它们的边权重
    
    void Clear(){for(int i=0;i<length;i++)NodeTable[i].first_edge=NULL;} //将表的边刷新
    
    void CriticalPath();//求关键路径
    
    void Debug();
    
private:Vertex NodeTable[100];//邻接表数组的指针
    
    int length;//代表邻接表的长度
};



int Link_Graph::GetFirstNeighbor(int v){
    
    if(v>=0&&v<length&&NodeTable[v].first_edge!=NULL)return NodeTable[v].first_edge->another;
    
    else return -1;//如果没有邻居返回-1
}



int Link_Graph::GetNextNeighbor(int v,int w){
    
    if(v>=0&&v<=length){//首先判断v合法
        
        Edge *p=NodeTable[v].first_edge;//首先让指针指向第一个邻居
        //在程序使用过程中用到这个函数时v必然有第一个邻居，故省去判断
        
        while(p!=NULL&&p->another!=w)p=p->link;
        
        if(p!=NULL&&p->link!=NULL)return p->link->another;}
    
    return -1;
}



int Link_Graph::GetWeight(int v1,int v2){
    if(v1!=-1&&v2!=-1){
        //首先判断两位置合法
        
        Edge *p=NodeTable[v1].first_edge;
        
        while(p!=NULL&&p->another!=v2)p=p->link;
        
        if(p!=NULL)return p->cost;
    }
    return 9999;//否则不存在边将两者相连，可认为无穷大
}

void Link_Graph::InsertEdge(int v1,int v2,int cost){//初始化两个要插入的指针
    
    Edge *v1e=new Edge(v2,cost);
    
    if(NodeTable[v1].first_edge==NULL){NodeTable[v1].first_edge=v1e;}//对于有向带权图只执行一个插入
    
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
        
    for(i=0;i<length;i++){//正向计算最早开始时间
        
        j=GetFirstNeighbor(i);
        
        
        while(j!=-1){
            weight=GetWeight(i,j);
            if(Ve[i]+weight>Ve[j])Ve[j]=Ve[i]+weight;
            j=GetNextNeighbor(i,j);
        }
        
    }
    
    Vl[length-1]=Ve[length-1];
    
    cout<<Vl[length-1]<<endl;//输出最后一个活动的最早开始时间即最短时间
    
    for(j=length-2;j>0;j--){//反向计算最晚开始时间
        k=GetFirstNeighbor(j);
        while(k!=-1){
            weight=GetWeight(j,k);
            if(Vl[k]-weight<Vl[j])Vl[j]=Vl[k]-weight;
            k=GetNextNeighbor(j,k);
            
            
        }
        
        
    }
    
    
    
    for(i=0;i<length;i++){//计算活动的时间并判断输出
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
