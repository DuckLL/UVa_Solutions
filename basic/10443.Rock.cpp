/*
Problem E: Rock, Scissors, Paper
Bart's sister Lisa has created a new civilization on a two-dimensional grid. At the outset each grid location may be occupied by one of three life forms: Rocks, Scissors, or Papers. Each day, differing life forms occupying horizontally or vertically adjacent grid locations wage war. In each war, Rocks always defeat Scissors, Scissors always defeat Papers, and Papers always defeat Rocks. At the end of the day, the victor expands its territory to include the loser's grid position. The loser vacates the position.
Your job is to determine the territory occupied by each life form after n days. The first line of input contains t, the number of test cases. Each test case begins with three integers not greater than 100: r and c, the number of rows and columns in the grid, and n. The grid is represented by the r lines that follow, each with c characters. Each character in the grid is R, S, or P, indicating that it is occupied by Rocks, Scissors, or Papers respectively.

For each test case, print the grid as it appears at the end of the nth day. Leave an empty line between the output for successive test cases.

Sample Input
2
3 3 1
RRR
RSR
RRR
3 4 2
RSPR
SPRS
PRSP


Output for Sample Input
RRR
RRR
RRR

RRRS
RRSP
RSPR

*/
#include <iostream>
using namespace std;
bool win(int a,int b);
int main()
{
    char ans[3]={'P','S','R'};
    char c;
    int map[100][100],map2[100][100];
    int n,x,y,day;
    int i,j,k;
    cin>>n;
    while(n>0)
    {
        cin>>y>>x>>day;
        for(i=0;i<y;i++)
            for(j=0;j<x;j++)
            {
                cin>>c;
                switch(c)
                {
                    case 'R':
                        map[j][i]=1;
                        break;
                    case 'S':
                        map[j][i]=0;
                        break;
                    case 'P':
                        map[j][i]=-1;
                        break;
                }
            }
        for(i=0;i<day;i++)
        {
            for(j=0;j<y;j++)
                for(k=0;k<x;k++)
                {
                    map2[k][j]=map[k][j];
                    if(k>0&&win(map[k-1][j],map[k][j]))
                        map2[k][j]=map[k-1][j];
                    if(j>0&&win(map[k][j-1],map[k][j]))
                        map2[k][j]=map[k][j-1];
                    if(k<x-1&&win(map[k+1][j],map[k][j]))
                        map2[k][j]=map[k+1][j];
                    if(j<y-1&&win(map[k][j+1],map[k][j]))
                        map2[k][j]=map[k][j+1];
                }
            for(j=0;j<y;j++)
                for(k=0;k<x;k++)
                    map[k][j]=map2[k][j];
        }
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
                cout<<ans[map[j][i]+1];
            cout<<endl;
        }
        if(n>1)
            cout<<endl;
        n--;
    }
    return 0;
}
bool win(int a,int b)
{
    if(a==-1&&b==1)
        return true;
    if(a==1&&b==-1)
        return false;
    if(a>b)
        return true;
    return false;
}
