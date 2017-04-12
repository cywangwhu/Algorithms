#include <iostream>
#define MAXSIZE 50
using namespace std;

void SIFT_UP(int h[],int i)
{
    int tmp=0;
    bool flag=true;
    while (flag==true&&i!=1)
    {
        flag=false;
        if (h[i]<h[i/2])
        {
            tmp=h[i];
            h[i]=h[i/2];
            h[i/2]=tmp;
            flag=true;
        }
        i=i/2;
    }
}

void SIFT_DOWN(int h[],int i)
{
    int tmp=0,t=0;
    bool flag=true;
    while (flag==true&&2*i+1<=h[0])
    {
        flag=false;
        t=h[2*i]<h[2*i+1]?2*i:2*i+1;
        if (h[i]>h[t])
        {
            tmp=h[i];
            h[i]=h[t];
            h[t]=tmp;
            flag=true;
        }
        i=t;
    }

}

void Insert(int h[],int t)
{
    int i=0;
    h[0]+=1;
    h[h[0]]=t;
    SIFT_UP(h,h[0]);
}

void Delete(int h[],int i)
{
    i++;
    int tmp=h[i];
    h[i]=h[h[0]];
    h[0]-=1;
    if(h[i]<tmp)
        SIFT_UP(h,i);
    else
        SIFT_DOWN(h,i);
}

void Makeheap(int h[])
{
    int i=0,t=0;
    for (i=h[0]/2;i>0;i--)
        SIFT_DOWN(h,i);
}

void Heapsort1(int h[])
{
    Makeheap(h);
    int n=h[0],tmp=0;
    for (int j=n;j>2;j--)
    {
        tmp=h[1];
        h[1]=h[j];
        h[j]=tmp;
        h[0]-=1;
        SIFT_DOWN(h,1);
    }
    h[0]=n;
}





void test()
{
    int a1[8]={7,7,8,5,2,4,1,3};
    Heapsort1(a1);
    for (int i=1;i<a1[0]+1;i++)
        cout<<a1[i]<<'\t';
        cout<<endl;
    int a2[14]={13,7,8,5,2,4,1,3,11,18,20,87,34,35};
    Heapsort1(a2);
    for (int i=1;i<a2[0]+1;i++)
        cout<<a2[i]<<'\t';
}


int main()
{
    test();
    return 0;
}
