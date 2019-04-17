
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort1.h"
#include "Sort_Support1.h"
using namespace std;


int main() {Init();
    
    int length=InputLength();
    
    int *List,Op=0;
    List=(int*)malloc(length*sizeof(int));
    
    cout<<endl<<"��ѡ�������㷨��";cin>>Op;
    while(Op!=9){
        
    switch(Op){
        case 1:BubbleSort(List,length);break;
        case 2:SelectSort(List,length);break;
        case 3:InsertSort(List,length);break;
        case 4:ShellSort(List,length);break;
        case 5:QuickSort(List,length);break;
        case 6:HeapSort(List,length);break;
        case 7:MergeSort(List,length);break;
        case 8:RadixSort(List,length);break;
        default:cout<<"��ѡ����������"<<endl;
    }
        cout<<endl<<"��ѡ�������㷨��";cin>>Op;
    }
    
    
    free(List);
    
    
    return 0;
}
