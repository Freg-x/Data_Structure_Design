#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sort_Support1.h"

using namespace std;

#ifndef sort1_h
#define sort1_h




/* BUbble Sort*/


void BubbleSort(int *List,int length){
    clock_t start=clock();int tmp;
    long count=0;
    srand(time(0));
    for(int i=0;i<length;i++)List[i]=rand();
    
    for(int i=0;i<length-1;i++){
        bool exchange=false;
    for(int j=i;j<length-1;j++)
    {
        if(List[j]>List[j+1]){tmp=List[j];
            List[j]=List[j+1];
            List[j+1]=tmp;
            count+=3;
            exchange=true;
    }
    }
        if(exchange==false)break;
    }
    cout<<"冒泡排序所用时间："<<clock()-start<<endl;
    cout<<"冒泡排序交换次数："<<count<<endl;
}

/* Insert Sort*/



void InsertSort(int *List,int length){
    clock_t start=clock();int tmp;
    long count=0;
    srand(time(0));
    
    for(int i=0;i<length;i++)List[i]=rand();//赋值
    
    for(int i=1;i<length;i++){
        
        if(List[i]<List[i-1]){
            
            tmp=List[i];count++;int j=1;
            
        while(tmp<List[i-j]){List[i-j+1]=List[i-j];
            count++;
            j++;
        }
            
        List[i-j+1]=tmp;
        count++;
            
        }
    }
    cout<<"直接插入排序所用时间:"<<clock()-start<<endl;
    cout<<"直接插入排序交换次数:"<<count<<endl;
    }

/*Shell Sort*/



    
void ShellSort(int *List,int length){
    clock_t start=clock();int tmp,gap=length/3+1;
    long count=0;
    srand(time(0));
    
    for(int i=0;i<length;i++)List[i]=rand();//赋值
    
    while(gap>=1){
        for(int i=gap;i<length;i++)
            if(List[i]<List[i-gap]){
                tmp=List[i];count++;int j=gap;
                while(tmp<List[i-j]){
                    List[i-j+gap]=List[i-j];
                    count++;
                    j+=gap;
                }
                List[i-j+gap]=tmp;
                count++;
            }
        
        if(gap==1)break;
        else gap=gap/3+1;
    }
    
    cout<<"希尔排序所用时间:"<<clock()-start<<endl;
    cout<<"希尔排序交换次数:"<<count<<endl;
    
}


/* Select Sort*/



void SelectSort(int *List,int length){
    clock_t start=clock();int min,tmp;
    long count=0;
    srand(time(0));
    
     for(int i=0;i<length;i++)List[i]=rand();//赋值
    
    for(int j=0;j<length-1;j++){
        min=j;
        for(int k=j;k<length;k++){
            if(List[k]<List[min])min=k;
        }
        if(j!=min){tmp=List[j];
            List[j]=List[min];
            List[min]=tmp;
            count+=3;
        }
    }
    cout<<"选择排序所用时间："<<clock()-start<<endl;
    cout<<"选择排序交换次数："<<count<<endl;
}


/*Quick Sort*/



void QuickSort(int *List,int length){
    clock_t start=clock();
    long count=0;
    srand(time(0));
    
    for(int i=0;i<length;i++)List[i]=rand();
    
    Quick(List,0,length-1,count);
    cout<<"快速排序所用时间:"<<clock()-start<<endl;
    cout<<"快速排序交换次数:"<<count<<endl;
    
    
    
}

void HeapSort(int *List,int length){
    clock_t start=clock();
    long count=0;
    srand(time(0));

    
    for(int i=0;i<length;i++)List[i]=rand(); //赋值
    
    for(int i=(length-2)/2;i>=0;i--)SiftDown(List,i,length-1,count);//循环调整
    for(int i=length-1;i>=0;i--){swap(List[0],List[i]);count+=3;SiftDown(List,0,i-1,count);}//单独调整
    
    cout<<"堆排序所用时间:"<<clock()-start<<endl;
    cout<<"堆排序交换次数:"<<count<<endl;
    
}


void MergeSort(int *List,int length){
    clock_t start=clock();
    long count=0;
    srand(time(0));
    
    
    for(int i=0;i<length;i++)List[i]=rand(); //赋值
    
    MerSort(List,support_list,0,length-1,count);
    
    cout<<"归并排序所用时间:"<<clock()-start<<endl;
    cout<<"归并排序交换次数:"<<count<<endl;
    
    
}

void RadixSort(int *List,int length){
    clock_t start=clock();
    long count=0;
    srand(time(0));
    
     for(int i=0;i<length;i++)List[i]=rand(); //赋值
    
    RadSort(List,0,length-1,10,count);
    
    cout<<"基数排序所用时间:"<<clock()-start<<endl;
    cout<<"基数排序不涉及交换"<<endl;
    cout<<"它的值传递次数为："<<count<<endl;
}


#endif /* sort_h */
