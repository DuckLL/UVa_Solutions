#include <iostream>
#include <vector>
using namespace std;
int main()
{
    char c;
    int n,num;
    int i,j;
    vector<char> vec;
    cin>>n;
    cin.get(c);
    for(i=0;i<n;i++)
    {
        vec.clear();
        while(cin.get(c)&&c!=10)
        {
            cin>>num;
            for(j=0;j<num;j++)
                vec.push_back(c);

        }
        cout<<"Case "<<i+1<<": ";
        for(j=0;j<vec.size();j++)
            cout<<vec[j];
        cout<<endl;
    }
    return 0;
}
