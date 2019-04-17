#include <iostream>
#include <string.h>

using namespace std;

#ifndef MST_h
#define MST_h


void init(){
    cout<<"**        电网造价模拟系统         **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**       A --- 创建电网顶点　　　　 **"<<endl;
    cout<<"**       B --- 添加电网的边        **"<<endl;
    cout<<"**       C ---  构造最小生成树     **"<<endl;
    cout<<"**       D --- 显示最小生成树      **"<<endl;
    cout<<"**       E --- 退出程序           **"<<endl;
    cout<<"==================================="<<endl;
    cout<<endl;
}


struct Edge{
    
    int another;//这条边的另一个节点名称
    
    int cost;//这条边的权值
    
    Edge *link;//下一条边
    
    Edge(int num,int weight):another(num),cost(weight),link(NULL){};//构造函数
    
};//边的初始化定义

struct MST_EDGE{
    
    string head;//在最小生成树中的头端点名称
    
    string tail;//在最小生成树中的尾端点名称
    
    int cost;//权值
    
};

struct Vertex{
    string name;//顶点的名称
    
    Edge *first_edge;//顶点的第一条边
    
    Vertex(){first_edge=NULL;}//构造函数
    
};//结点的初始化定义

//图的定义


class Link_Graph{
    
public: Link_Graph(){NodeTable=(Vertex *)malloc(10000*sizeof(Vertex));length=0;}//首先对于邻接表分配足够的内存
    
    int GetVertexPos(string p_name);//给出节点名称返回它在邻接表中的位置
    
    string GetName(int p_number);//给出位置返回它在邻接表中的名称
    
    void InitVertex();//初始化节点，即生成邻接表
    
    void InsertEdge(int v1,int v2,int cost);//给出两条边的位置和权值将其插入邻接表
    
    void InitEdge();//初始化邻接表的边
    
    int Getlength(){return length;}//返回邻接表的长度
    
    int GetFirstNeighbor(int v);//获得一个节点的第一个边结点位置
    
    int GetNextNeighbor(int v,int w);//在v节点的边中，获得位置为w节点右边的节点位置
    
    int GetWeight(int v1,int v2);//给出两节点位置，返回它们的边权重
    
    void Clear(){for(int i=0;i<length;i++)NodeTable[i].first_edge=NULL;} //将表的边刷新
    
private:Vertex *NodeTable;//邻接表数组的指针
    
    int length;//代表邻接表的长度
};

//最小生成树类的定义

class MST{
public:
    
    void SetLength(int p_length){length=p_length;}//设置最小生成树的长度
    
    void Display(){for(int i=0;i<length;i++)cout<<E[i].head<<"-<"<<E[i].cost<<">-"<<E[i].tail<<"    ";}
    
    //输出展示最小生成树
    
    
    void Insert(MST_EDGE p_MST_EDGE){
        
        E[length]=p_MST_EDGE;
        
        length++;
    }
    
    //插入最小生成树
    
private:int length;//最小生成树的长度
    
    MST_EDGE E[1000];//存储边的数组
    
};




int Link_Graph::GetVertexPos(string p_name){
    
    for(int i=0;i<length;i++)if(strcmp(NodeTable[i].name.c_str(),p_name.c_str())==0)return i;
    
    return -1;//如果没有找到返回-1
    }



string Link_Graph::GetName(int p_number){
    
    if(p_number>=0&&p_number<length)return NodeTable[p_number].name;
    
    else return "can not find";//如果没有找到返回提示信息
}



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


//初始化邻接表

void Link_Graph::InitVertex(){
    
    cout<<"请输入顶点的个数：";
    
    cin>>length;
    
    while(length<=0){
        cout<<"输入的顶点个数不合法，请重新输入：";
        
        cin>>length;
    }
    cout<<"请依次输入各顶点的名称："<<endl;
    
    for(int i=0;i<length;i++)cin>>NodeTable[i].name;
}

//插入一条边



void Link_Graph::InsertEdge(int v1,int v2,int cost){//初始化两个要插入的指针
    
    Edge *v1e=new Edge(v2,cost);
    
    Edge *v2e=new Edge(v1,cost);
    
    if(NodeTable[v1].first_edge==NULL){NodeTable[v1].first_edge=v1e;}//分类分别对两顶点进行头指针插入法
    
    else{v1e->link=NodeTable[v1].first_edge;NodeTable[v1].first_edge=v1e;}
    
    if(NodeTable[v2].first_edge==NULL){NodeTable[v2].first_edge=v2e;}
    
    else{v2e->link=NodeTable[v2].first_edge;NodeTable[v2].first_edge=v2e;}
    
}


//初始化边的函数


void Link_Graph::InitEdge(){//不可直接进行插入边操作
    
    if(length<=0){cout<<"在没有初始化节点的情况下不可以初始化边"<<endl;return;}
    
    else{
        cout<<"警告：在输入过程中如果出现相同顶点两次输入的情况会造成覆盖"<<endl;
        
        cout<<"请按完全图产生边数输入，对于不存在的边输入较大的权值即可"<<endl;
        
        int count=0;
        
        //共计n(n-1)/2条边
        while(count<length*(length-1)/2){
            
            string p1,p2;int p_cost;
            
            cout<<"请输入两个顶点及边:";
            
            cin>>p1>>p2;cin>>p_cost;
            int v1=GetVertexPos(p1);
            int v2=GetVertexPos(p2);
            
            if(v1==-1||v2==-1){cout<<"不存在的边,请全部重新输入"<<endl;Clear();break;}//刷新后要求重新输入
            
            else {InsertEdge(v1,v2,p_cost);count++;}
        }
        
        
    }
    
    }

//最小堆的定义
class MinHeap{
    
public:MinHeap(){length=0;}//初始化长度为0
    
    void Renew(){length=0;}//更新长度为0
    
    void Insert(MST_EDGE);//插入一个最小生成树节点
    
    bool IsEmpty(){return length==0?true:false;}//判空
    
    void Remove(MST_EDGE &E1);//取堆顶元素存于E1中
    
private:int length;//长度
    
    MST_EDGE heap[1000];//存储用数组
};

void MinHeap::Insert(MST_EDGE E1){
    
    heap[length]=E1;
    
        int j=length,i=(j-1)/2;MST_EDGE temp=heap[j];//自底向上调整
    
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
    
    int i=0,j=2*i+1;//自顶向下调整
    
    MST_EDGE temp=heap[i];
    
    while(j<=length-1){
        
        if(j<length-1&&heap[j].cost>heap[j+1].cost)j++;
        
        if(temp.cost<=heap[j].cost)break;
        
        else{heap[i]=heap[j];i=j;j=2*j+1;}
    }
    
    heap[i]=temp;
    
    
}
    
    


//核心算法




void Prim(Link_Graph G,MST &M){
    
    M.SetLength(0);//进行算法前长度为0
    
    bool Vmst[G.Getlength()];//判断节点是否在最小生成树中
    
    for(int i=0;i<G.Getlength();i++)Vmst[i]=false;
    
    string p_point;
    
    cout<<"请输入起始顶点：";cin>>p_point;
     int u=G.GetVertexPos(p_point);
    while(u==-1){cout<<"给出的顶点不存在，请重新输入：";cin>>p_point;u=G.GetVertexPos(p_point);}
    
    int v;//分别给出要用到的表示位置的整数，存储边的变量和最小堆
    MST_EDGE ed;
    MinHeap H;
    
    
    Vmst[u]=true;//从u开始故u在堆中
    
    int count=1;//共进行n-1次
    
    do{
        v=G.GetFirstNeighbor(u);
        while(v!=-1){
            if(Vmst[v]==false){//将边置入最小堆中
                ed.tail=G.GetName(u);ed.head=G.GetName(v);ed.cost=G.GetWeight(u,v);
                H.Insert(ed);
            }
            v=G.GetNextNeighbor(u,v);//循环写入所有没用过的边
        }
        
        while(!H.IsEmpty()&&count<G.Getlength()){
            
            H.Remove(ed);//退值给ed
            
            if(Vmst[G.GetVertexPos(ed.head)]==false){//之前加入最小生成树的点不能再出现
                
                M.Insert(ed);
                
                u=G.GetVertexPos(ed.head);Vmst[u]=true;//u后移
                
                count++;break;
            }
        }
        
        
    }while(count<G.Getlength());
    
    cout<<"生成Prim最小生成树！"<<endl;
    
    
}
    
    










#endif /* MST_h */
