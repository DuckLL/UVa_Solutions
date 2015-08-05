/*
Problem D
The Grand Dinner
Input: standard input
Output: standard output
Time Limit: 15 seconds
Memory Limit: 32 MB

Each team participating in this year’s ACM World Finals contest is expected to join the grand dinner to be arranged after the prize giving ceremony ends. In order to maximize the interaction among the members of different teams, it is expected that no two members of the same team sit at the same table.

Now, given the number of members in each team (including contestants, coaches, reserves, guests etc.) and the seating capacity of each available table, you are to determine whether it is possible for the teams to sit as described in the previous paragraph. If such an arrangement is possible you must also output one possible seating arrangement. If there are multiple possible arrangements, any one is acceptable.

Input
 The input file may contain multiple test cases. The first line of each test case contains two integers M (1 £ M £ 70) and N (1 £ N £ 50) denoting the number of teams and the number of tables respectively. The second line of the test case contains M integers where the i-th (1 £ i £ M) integer mi (1 £ mi £ 100) indicates the number of members of team i. The third line contains N integers where the j-th (1 £ j £ N) integer nj (2 £ nj £ 100) indicates the seating capacity of table j.

A test case containing two zeros for M and N terminates the input.

Output
For each test case in the input print a line containing either 1 or 0 depending on whether or not there exists a valid seating arrangement of the team members. In case of a successful arrangement print M additional lines where the i-th (1 £ i £ M) of these lines contains a table number (an integer from 1 to N) for each of the members of team i.

Sample Input
4 5
4 5 3 5
3 5 2 6 4
4 5
4 5 3 5
3 5 2 6 3
0 0


Sample Output
1
1 2 4 5
1 2 3 4 5
2 4 5
1 2 3 4 5
0
*/
#include <iostream>
#include <set>
using namespace std;
int main()
{
    bool b;
    int x,y,team[100],table[100],max,ans[100][100],maxteam,maxtable;
    int i,j,k;
    while(cin>>x>>y&&x&&y)
    {
        b=true;
        for(i=0;i<x;i++)
            cin>>team[i];
        for(i=0;i<y;i++)
            cin>>table[i];
        bool t[100]={false};
        for(i=0;i<x;i++)
        {
            max=0;
            for(j=0;j<x;j++)
            {
                if(!t[j]&&team[j]>max)
                {
                    max=team[j];
                    maxteam=j;
                }
            }
            t[maxteam]=true;
            //cout<<maxteam<<endl;
            bool t2[100]={false};
            for(j=0;j<team[maxteam];j++)
            {
                max=0;
                for(k=0;k<y;k++)
                    if(!t2[k]&&table[k]>max)
                    {
                        max=table[k];
                        maxtable=k;
                    }
                t2[maxtable]=true;
                if(max==0)
                    b=false;
                table[maxtable]--;
                ans[maxteam][j]=maxtable;
            }
        }
        if(b)
        {
            cout<<1<<endl;
            for(i=0;i<x;i++)
            {
                for(j=0;j<team[i]-1;j++)
                    for(k=0;k<team[i]-1-j;k++)
                        if(ans[i][k]>ans[i][k+1])
                            swap(ans[i][k],ans[i][k+1]);
                for(j=0;j<team[i];j++)
                {
                    cout<<ans[i][j]+1;
                    if(j!=team[i]-1)
                        cout<<" ";
                }
                cout<<endl;
            }
        }
        else
            cout<<0<<endl;
    }
    return 0;
}
