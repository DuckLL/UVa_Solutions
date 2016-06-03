#include <iostream>
using namespace std;
int main(){
    int n;
    int now,next;
    int i;
    while(cin>>n){
        bool check[n-1];
        fill(check,check+n-1,0);
        cin>>now;
        for(i=0;i<n-1;i++){
            cin>>next;
            check[abs(next-now)-1]=1;
            now=next;
        }
        for(i=0;i<n-1;i++)
            if(!check[i])
                break;
        if(i==n-1)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
    }
    return 0;
}
