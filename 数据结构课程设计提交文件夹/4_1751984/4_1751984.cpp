
#include <iostream>
#include <cstring>
#include "Stack.h"
#include <ctype.h>

using namespace std;

int main(){WorkStack s;
    char ch,op,beforech='#';
    s.Push('#');
    cin.get(ch);
    
    while(!s.IsEmpty()&&ch!='\n')
    {if( issdigit(ch)||(ch=='-'&&!isdigit(beforech))) {cout<<ch;beforech=ch;cin.get(ch);if( !issdigit(ch))cout<<" ";}
    else{
        if(isp(s.GetTop())<icp(ch)){s.Push(ch);beforech=ch;cin.get(ch);}
        else if(isp(s.GetTop())>icp(ch)){s.Pop(op);cout<<op<<" ";}
        else{s.Pop(op);
            if(op=='(')beforech=ch;cin.get(ch);
        }
        
        
    }
    }
    while(s.GetTop()!='#'){s.Pop(op);cout<<op<<" ";}
    system("Pause"); 
    return 0;
}
