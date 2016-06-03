#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct data{
    int id,val;
    vector<int> ans;
};
int sortid(const void *a,const void *b){
    data c,d;
    c=*(data *)(a);
    d=*(data *)(b);
    if(c.id>d.id)
        return 1;
    else if(c.id==d.id)
        return 0;
    else
        return -1;
}
int sortval(const void *a,const void *b){
    data c,d;
    c=*(data *)a;
    d=*(data *)b;
    if(c.val>d.val)
        return 1;
    else if(c.val==d.val)
        return 0;
    else
        return -1;
}
int main(){
    ifstream fin("10249.txt");
    istream& ins(fin);
    int m,n;
    while(ins>>m>>n&&m&&n){
        data team[100],table[100];
        for (int i = 0; i < m; i++) {
            team[i].id=i+1;
            ins>>team[i].val;
        }
        for (int i = 0; i < n; i++) {
            table[i].id=i+1;
            ins>>table[i].val;
        }
        qsort(team,m,sizeof(team[0]),sortval);
        qsort(table,n,sizeof(table[0]),sortval);
        reverse(table,table+n);
        int count;
        int i;
        for (i = 0; i < m; i++) {
            count=team[i].val;
            for (int j = 0; count>0&&j < n; j++) {
                if (table[j].val>0) {
                    table[j].val--;
                    count--;
                    team[i].ans.push_back(table[j].id);
                }
            }
            if (count>0)
                break;
        }
        if (i==m) {
            qsort(team,m,sizeof(team[0]),sortid);
            cout<<1<<endl;
            for (int i = 0; i < m; i++) {
                sort(team[i].ans.begin(),team[i].ans.end());
                for (int j = 0; j < team[i].ans.size(); j++) {
                    cout<<team[i].ans[j];
                    if(j<team[i].ans.size()-1)
                        cout<<" ";
                }
                cout<<endl;
            }
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
