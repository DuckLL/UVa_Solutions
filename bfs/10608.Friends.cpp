/*
Problem I
FRIENDS

There is a town with N citizens. It is known that some pairs of people are friends. According to the famous saying that “The friends of my friends are my friends, too” it follows that if A and B are friends and B and C are friends then A and C are friends, too.

Your task is to count how many people there are in the largest group of friends.

Input
Input consists of several datasets. The first line of the input consists of a line with the number of test cases to follow. The first line of each dataset contains tho numbers N and M, where N is the number of town's citizens (1≤N≤30000) and M is the number of pairs of people (0≤M≤500000), which are known to be friends. Each of the following M lines consists of two integers A and B (1≤A≤N, 1≤B≤N, A≠B) which describe that A and B are friends. There could be repetitions among the given pairs.

Output
The output for each test case should contain one number denoting how many people there are in the largest group of friends.

Sample Input
2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 10
1 2
9 10
8 9
Sample Output
3
6
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
bool isexist(vector<int> vec,int x);
int main(){
    ifstream fin("10608.txt");
    istream& ins(cin);
    int n;
    ins>>n;
    int people,r_num;
    int a,b,flag,now,max;
    int i,j;
    while(n--){
        vector<int> relation[30001];
        ins>>people>>r_num;
        for(i=0;i<r_num;i++){
            ins>>a>>b;
            if(!isexist(relation[a],b))
                relation[a].push_back(b);
            if(!isexist(relation[b],a))
                relation[b].push_back(a);
        }
        /*for(i=1;i<people+1;i++){
            cout<<i<<": ";
            for(j=0;j<relation[i].size();j++)
                cout<<relation[i][j]<<" ";
            cout<<endl;
        }*/
        vector<int> pass;
        max=1;
        for(i=1;i<people+1;i++){
            if(isexist(pass,i))
                continue;
            vector<int> query;
            query.push_back(i);
            flag=0;
            while(flag<query.size()){
                now=query[flag];
                pass.push_back(now);
                for(j=0;j<relation[now].size();j++)
                    if(!isexist(query,relation[now][j]))
                        query.push_back(relation[now][j]);
                flag++;
            }
            if(query.size()>max)
            	max=query.size();
        }
        cout<<max<<endl;
    }
    return 0;
}
bool isexist(vector<int> vec,int x){
    for(int i=0;i<vec.size();i++)
        if(vec[i]==x)
            return 1;
    return 0;
}
