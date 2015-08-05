#include <iostream>
using namespace std;
int main()
{
    int n,m,sum,a,b,c;
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        sum=0;
        for(j=0;j<m;j++)
        {
            cin>>a>>b>>c;
            sum+=a*c;
        }
        cout<<sum<<endl;
    }
    return 0;
}
