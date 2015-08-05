#include <iostream>
using namespace std;
int f(int x,int i);
int main()
{
    int n,x,i;
    while(cin>>x&&x!=0)
    {
        i=1;
        while(true)
        {
            if(f(x,i)==13)
                break;
            i++;
        }
        cout<<i<<endl;
    }
    return 0;
}
int f(int x,int i)
{
    int j,sum,num;
    bool b[101]={false};
    for(j=2;j<=x;j++)
        b[j]=true;
    num=0;
    j=2;
    while(num<x-1)
    {
        sum=0;
        while(sum<i)
        {
            if(b[j])
                sum++;
            if(sum<i)
                j++;
            if(j>x)
                j=2;
        }
        b[j]=false;
        j++;
        num++;
    }
    return j-1;
}
