/*
You are trapped in a 3D dungeon and need to find the quickest way out! The dungeon is composed of unit cubes which may or may not be filled with rock. It takes one minute to move one unit north, south, east, west, up or down. You cannot move diagonally and the maze is surrounded by solid rock on all sides.


Is an escape possible? If yes, how long will it take?

Input Specification

The input file consists of a number of dungeons. Each dungeon description starts with a line containing three integers L, R and C (all limited to 30 in size).

L is the number of levels making up the dungeon.

R and C are the number of rows and columns making up the plan of each level.


Then there will follow L blocks of R lines each containing C characters. Each character describes one cell of the dungeon. A cell full of rock is indicated by a `#' and empty cells are represented by a `.'. Your starting position is indicated by `S' and the exit by the letter 'E'. There's a single blank line after each level. Input is terminated by three zeroes for L, R and C.

Output Specification

Each maze generates one line of output. If it is possible to reach the exit, print a line of the form

Escaped in x minute(s).


where x is replaced by the shortest time it takes to escape.

If it is not possible to escape, print the line


Trapped!

Sample Input

3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
Sample Output

Escaped in 11 minute(s).
Trapped!
*/
/*
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int l,r,c,m,ex,ey,ez;
char mz[30][30][30];
void go(int x,int y,int z,int step);
int main()
{
    ifstream fin("532.txt");
    int i,j,k;
    int sx,sy,sz;
    while(fin>>l>>r>>c&&l!=0)
    {
        for(i=0;i<l;i++)
            for(j=0;j<r;j++)
                for(k=0;k<c;k++)
                {
                    fin>>mz[k][j][i];
                    if(mz[k][j][i]=='S')
                    {
                        sx=k;
                        sy=j;
                        sz=i;
                    }
                    if(mz[k][j][i]=='E')
                    {
                        ex=k;
                        ey=j;
                        ez=i;
                        mz[k][j][i]='.';
                    }
                }
        m=0;
        go(sx,sy,sz,0);
        if(m==0)
            cout<<"Trapped!";
        else
            cout<<"Escaped in "<<m<<" minute(s).";
        cout<<endl;
    }
    return 0;
}
void go(int x,int y,int z,int step)
{
    mz[x][y][z]='@';
    /*int i,j,k;
    for(i=0;i<l;i++)
    {
        for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
                cout<<mz[k][j][i];
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<x<<" "<<y<<" "<<z<<" "<<step<<endl;
    system("pause");
    if(x==ex&&y==ey&&z==ez)
    {
        mz[x][y][z]='.';
        if(m==0)
            m=step;
        if(step<m)
            m=step;
        return;
    }
    if(z+1<l&&mz[x][y][z+1]=='.')
        go(x,y,z+1,step+1);
    if(x+1<c&&mz[x+1][y][z]=='.')
        go(x+1,y,z,step+1);
    if(y+1<r&&mz[x][y+1][z]=='.')
        go(x,y+1,z,step+1);
    if(y-1>=0&&mz[x][y-1][z]=='.')
        go(x,y-1,z,step+1);
    if(x-1>=0&&mz[x-1][y][z]=='.')
        go(x-1,y,z,step+1);
    if(z-1>=0&&mz[x][y][z-1]=='.')
        go(x,y,z-1,step+1);
    mz[x][y][z]='.';
    return;
}*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("532.txt");
    bool b;
    char cm[30][30][30];
    int i,j,k;
    int l,r,c,x,y,z,startnum,endnum,num,step,ss,tmpnum;
    int q[100000],qnum;
    int mz[30][30][30];
    int tmp[100000];
    while(fin>>l>>r>>c)
    {
        if(l==0&&r==0&&c==0)
            break;
        for(i=0;i<100000;i++)
            q[i]=0;
        num=1;
        for(i=0;i<l;i++)
            for(j=0;j<r;j++)
                for(k=0;k<c;k++)
                {
                    fin>>cm[k][j][i];
                    if(cm[k][j][i]=='S')
                    {
                        mz[k][j][i]=num++;
                        startnum=mz[k][j][i];
                    }
                    if(cm[k][j][i]=='E')
                    {
                        mz[k][j][i]=num++;
                        endnum=mz[k][j][i];
                    }
                    if(cm[k][j][i]=='.')
                        mz[k][j][i]=num++;
                    if(cm[k][j][i]=='#')
                        mz[k][j][i]=0;
                }
        b=false;
        q[0]=startnum;
        tmp[0]=0;
        qnum=1;
        tmpnum=1;
        step=0;
        for(num=0;num<qnum;num++)
        {
            cout<<q[num]<<" "<<tmp[num]<<endl;
            if(q[num]==endnum)
            {
                b=true;
                break;
            }
            else
            {
                ss=qnum;
                for(i=0;i<l;i++)
                    for(j=0;j<r;j++)
                        for(k=0;k<c;k++)
                            if(mz[k][j][i]==q[num])
                            {
                                x=k;
                                y=j;
                                z=i;
                            }
                if(z+1<l&&mz[x][y][z+1]>0)
                {
                    k=0;
                    for(i=0;i<qnum;i++)
                        if(q[i]==mz[x][y][z+1])
                            k++;
                    if(k==0)
                    {
                        q[qnum]=(mz[x][y][z+1]);
                        qnum++;
                        tmp[tmpnum]=(tmp[num]+1);
                        tmpnum++;
                    }
                }
                if(y+1<r&&mz[x][y+1][z]>0)
                {
                    k=0;
                    for(i=0;i<qnum;i++)
                        if(q[i]==mz[x][y+1][z])
                            k++;
                    if(k==0)
                    {
                        q[qnum]=(mz[x][y+1][z]);
                        qnum++;
                        tmp[tmpnum]=(tmp[num]+1);
                        tmpnum++;
                    }
                }
                if(x+1<c&&mz[x+1][y][z]>0)
                {
                    k=0;
                    for(i=0;i<qnum;i++)
                        if(q[i]==mz[x+1][y][z])
                            k++;
                    if(k==0)
                    {
                        q[qnum]=(mz[x+1][y][z]);
                        qnum++;
                        tmp[tmpnum]=(tmp[num]+1);
                        tmpnum++;
                    }
                }
                if(z-1>=0&&mz[x][y][z-1]>0)
                {
                    k=0;
                    for(i=0;i<qnum;i++)
                        if(q[i]==mz[x][y][z-1])
                            k++;
                    if(k==0)
                    {
                        q[qnum]=(mz[x][y][z-1]);
                        qnum++;
                        tmp[tmpnum]=(tmp[num]+1);
                        tmpnum++;
                    }
                }
                if(y-1>=0&&mz[x][y-1][z]>0)
                {
                    k=0;
                    for(i=0;i<qnum;i++)
                        if(q[i]==mz[x][y-1][z])
                            k++;
                    if(k==0)
                    {
                        q[qnum]=(mz[x][y-1][z]);
                        qnum++;
                        tmp[tmpnum]=(tmp[num]+1);
                        tmpnum++;
                    }
                }
                if(x-1>=0&&mz[x-1][y][z]>0)
                {
                    k=0;
                    for(i=0;i<qnum;i++)
                        if(q[i]==mz[x-1][y][z])
                            k++;
                    if(k==0)
                    {
                        q[qnum]=(mz[x-1][y][z]);
                        qnum++;
                        tmp[tmpnum]=(tmp[num]+1);
                        tmpnum++;
                    }
                }
            }
        }
        if(b)
            cout<<"Escaped in "<<tmp[num]<<" minute(s).";
        else
            cout<<"Trapped!";
        cout<<endl;

    }
    return 0;
}
