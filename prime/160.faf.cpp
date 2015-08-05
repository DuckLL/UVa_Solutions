#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
vector<int> prime;
bool isprime(int x);
int main(){
    int i,j;
    //prime table
    prime.push_back(2);
    for(i=3;i<100;i++)
        if(isprime(i))
            prime.push_back(i);
    int x;
    int tmp;
    while(cin>>x&&x){
        int prime_num[25]={0};
        for(i=2;i<=x;i++){
            tmp=i;
            for(j=0;tmp>1&&j<25;j++)
                while(tmp%prime[j]==0){
                    prime_num[j]++;
                    tmp/=prime[j];
                }
        }
        cout<<setw(3)<<x<<"! =";
        for(i=0;i<25&&prime_num[i];i++){
            if(i==15)
                cout<<endl<<"      ";
            cout<<setw(3)<<prime_num[i];
        }
        cout<<endl;
    }
    return 0;
}
bool isprime(int x){
    if(x<2)
        return 0;
    for(int i=0;i<prime.size()&&sqrt(x)>=prime[i];i++)
        if(x%prime[i]==0)
            return 0;
    return 1;
}
