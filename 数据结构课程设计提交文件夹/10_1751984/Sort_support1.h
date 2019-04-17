#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


#ifndef Sort_Support1_h
#define Sort_Support1_h

/*��ʼ������*/

void Init(){
    cout<<"**         �����㷨�Ƚ�           **"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"**        1 --- ð������        **"<<endl;
    cout<<"**        2 --- ѡ������        **"<<endl;
    cout<<"**       3 --- ֱ�Ӳ�������       **"<<endl;
    cout<<"**        4 --- ϣ������        **"<<endl;
    cout<<"**        5 --- ��������        **"<<endl;
    cout<<"**        6 ---  ������         **"<<endl;
    cout<<"**       7 ---  �鲢����        **"<<endl;
    cout<<"**       8 ---  ��������        **"<<endl;
    cout<<"**        9 --- �˳�����        **"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<endl;
    cout<<"������Ҫ����������ĸ�����";
    
}


/*���볤�ȵĺ���*/


int InputLength(){int length;
    cin>>length;
    while(length<=0){cout<<endl<<"����������������������룺";cin>>length;}
    return length;
}

/*�����ĺ���*/


void swap(int &a,int &b){int temp;
    temp=a;a=b;b=temp;
}

/*�����õ��Ļ��ֺ���*/

int Partition(int *List,int low,int high,long &count){
    int pivotpos=low;
    int pivot=List[low];
    for(int i=low+1;i<=high;i++){
        if(List[i]<pivot){
            pivotpos++;
            if(pivotpos!=i)swap(List[pivotpos],List[i]);count+=3;
        }
        
        
    }
    List[low]=List[pivotpos];List[pivotpos]=pivot;count+=2;
    return pivotpos;
    
    
}

/*���ź���*/

void Quick(int *List,int left,int right,long &count){
    if(left<right){
        int pivotpos=Partition(List,left,right,count);
        Quick(List,left,pivotpos-1,count);
        Quick(List,pivotpos+1,right,count);
    }
    
}

/* �Զ����µ������㷨 */

void SiftDown(int *List,int start,int end,long &count){
    int i=start;int j=2*i+1;  //j��i������Ů
    int tmp=List[i];count++;
    while(j<=end){
        if(j<end&&List[j]<List[j+1])j++; //��jָ������Ů�еĽϴ���
        
        if(tmp>=List[j])break;
        else{
            List[i]=List[j];count++;
            i=j;j=2*j+1;
        }
        
    }
    List[i]=tmp;count++;
}

/* �ϲ����� */

int support_list[500000]; //����������ȫ������

void merge(int *List,int *support_list,int left,int mid,int right,long &count){
    for(int i=left;i<=right;i++){support_list[i]=List[i];count++;} //�������鸳��ֵ
    
    
    
    int s1=left,s2=mid+1,tmp_pos=left;
    
    while(s1<=mid&&s2<=right)
    {if(support_list[s1]<=support_list[s2])List[tmp_pos++]=support_list[s1++];
        else List[tmp_pos++]=support_list[s2++];
        count++;
    }
    
    while(s1<=mid){List[tmp_pos++]=support_list[s1++];count++;}
    while(s2<=right){List[tmp_pos++]=support_list[s2++];count++;}
}

/* �鲢������ */

void MerSort(int *List,int *support_list,int left,int right,long &count){
    if(left>=right)return;
    int mid=(left+right)/2;
    
    MerSort(List,support_list,left,mid,count);
    MerSort(List,support_list,mid+1,right,count);
    merge(List,support_list,left,mid,right,count);
    
}

/* ��������ĸ������� */

int getdigit(int n,int d){
    for(int i=1;i<d;i++){n=n/10;}
    return n%10;
}




/* MSD���������� */

void RadSort(int *List,int left,int right,int d,long &tcount){
    if(d<=0||left>=right)return;
    
    int i,j,count[10],start,end;
    int sup[right-left+1];
    
    for(j=0;j<10;j++)count[j]=0;
    
    for(i=left;i<=right;i++)count[getdigit(List[i],d)]++;
    
    
    for(j=1;j<10;j++){count[j]=count[j]+count[j-1];}
    
    
    for(i=left;i<=right;i++){
        j=getdigit(List[i],d);
        sup[count[j]-1]=List[i];
        
        count[j]--;
        tcount++;
        
    }
    
    
    for(i=left,j=0;i<=right;i++,j++){List[i]=sup[j];tcount++;}

    for(j=0;j<9;j++){
        start=count[j]+left;//����Ӧ�öԼ����λ��
        end=count[j+1]-1+left;
        RadSort(List,start,end,d-1,tcount);
    }
    RadSort(List,count[9]+left,right,d-1,tcount);//����9��Ͱʱ�յ�Ӧ��ȡ�Ҷ�λ��
}


#endif 
