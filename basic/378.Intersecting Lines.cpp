#include <iostream>
#include <fstream>
using namespace std;
struct line{
    double slope;
    double yx0;
    double x;
};
int main(){
    ifstream fin("378.txt");
    istream& ins(cin);
    int n;
    double x,y,x1,y1,x2,y2;
    int i;
    ins>>n;
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    while(n--){
            line l[2];
            for(i=0;i<2;i++){
                    ins>>x1>>y1>>x2>>y2;
                    if(x1-x2==0){
                        l[i].x=x1;
                        l[i].slope=1e9;
                    }
                    else
                        l[i].slope=(y1-y2)/(x1-x2);
                    l[i].yx0=y1-l[i].slope*x1;
            }
            if(l[0].slope==l[1].slope)
                if(l[0].slope==1e9)
                    if(l[0].x==l[1].x)
                        cout<<"LINE"<<endl;
                    else
                        cout<<"NONE"<<endl;
                else if(l[0].yx0==l[1].yx0)
                    cout<<"LINE"<<endl;
                else
                    cout<<"NONE"<<endl;
            else{
                cout.setf(ios::fixed);
                cout.precision(2);
                if(l[0].slope==1e9)
                    cout<<"POINT "<<l[0].x<<" "<<l[0].x*l[1].slope+l[1].yx0<<endl;
                else if(l[1].slope==1e9)
                    cout<<"POINT "<<l[1].x<<" "<<l[1].x*l[0].slope+l[0].yx0<<endl;
                else{
                    x=(l[1].yx0-l[0].yx0)/(l[0].slope-l[1].slope);
                    y=l[0].slope*x+l[0].yx0;
                    cout<<"POINT "<<x<<" "<<y<<endl;
                }
            }
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
