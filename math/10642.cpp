#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char *argv[])
{
    ifstream fin("10642.txt");
    istream& ins(fin);
    int n;
    ins>>n;
    int i;
    long long int x1,y1,x2,y2;
    long long int a,b,d;
    for (i = 0; i < n; i++) {
        ins>>x1>>y1>>x2>>y2;
        a=x1+y1;
        b=x2+y2;
        d=(a+b+1)*(b-a)/2+x2-x1;
        cout<<"Case "<<i+1<<": "<<d<<endl;
    }
    return 0;
}
