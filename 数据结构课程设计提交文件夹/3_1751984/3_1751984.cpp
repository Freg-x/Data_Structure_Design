

#include <iostream>
#include <cstdlib>


using namespace std;



struct position{
    int x;
    int y;
    int dir=0;
    position *next=NULL;
};


class WorkStack{
public:
    WorkStack(){top=NULL;}//置头为空的构造函数
    
    void Push(position *x);//将x押入栈的函数
    
    void Pop(position *px);//出栈并赋值给px的函数
    
    bool IsEmpty(){return top==NULL?true:false;}//判断是否为空的函数
    
    void Display();//输出函数
    
    position* GetTop(){return top;}//获取当前头指针
    
private:
position *top;//栈的头指针
    
    
};//链式工作栈




void WorkStack::Push(position *px){if(top!=NULL){position *in=new position;
    in->x=px->x;in->y=px->y;in->dir=px->dir;
    in->next=top;top=in;
}
else{position *in=new position;
    in->x=px->x;in->y=px->y;in->dir=px->dir;
    top=in;}
}

void WorkStack::Pop(position *px){position *t=new position;t=top;
    top=top->next;
    px->x=t->x;px->y=t->y;px->dir=t->dir;
    delete t;
}

void WorkStack::Display(){position *current=top;
    while(current!=NULL){
        cout<<"<-("<<current->x<<","<<current->y<<")";
        current=current->next;
    }
}

struct offsets{int l,r;};


void solution(char map[7][7]){offsets move[4];
    move[0].l=-1;move[0].r=0;
    move[1].l=1;move[1].r=0;
    move[2].l=0;move[2].r=-1;
    move[3].l=0;move[3].r=1;
    
    int i,j,d(0),g,h;
    
    position *tmp=new position;tmp->x=1;tmp->y=1;
    WorkStack ws;ws.Push(tmp);
    
    char mark[7][7]={'0','0','0','0','0','0','0',
        '0','#','0','0','0','0','0',
        '0','0','0','0','0','0','0',
        '0','0','0','0','0','0','0',
        '0','0','0','0','0','0','0',
        '0','0','0','0','0','0','0'
    };
    
    while(ws.IsEmpty()==false){
        ws.Pop(tmp);
        i=tmp->x;j=tmp->y;d=tmp->dir;
        while(d<4){g=i+move[d].l;h=j+move[d].r;
            if(g==5&&h==5){cout<<"(5,5)<-"<<"("<<i<<","<<j<<")";ws.Display();return;}
            if(map[g][h]=='0'&&mark[g][h]=='0'){mark[g][h]='#';tmp->x=i;tmp->y=j;tmp->dir=d;ws.Push(tmp);i=g;j=h;d=0;}
            else d++;
        }
    }
    cout<<"no path in maze"<<endl;
}


int main(){char map1[7][7]={
    {'#','#','#','#','#','#','#',},
    {'#','0','#','0','0','0','#'},
    {'#','0','#','0','#','#','#'},
    {'#','0','0','0','#','0','#'},
    {'#','0','#','0','0','0','#'},
    {'#','0','#','0','#','0','#'},
    {'#','#','#','#','#','#','#'}
};
    cout<<"迷宫地图："<<endl;
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {cout<<" "<<map1[i][j];
            if(j==6)cout<<endl;
        }
    cout<<"迷宫路径："<<endl;
    solution(map1);
    cout<<endl;
    system("Pause");
    return 0;
}










