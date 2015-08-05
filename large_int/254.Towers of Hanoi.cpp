/*

Towers of Hanoi

In 1883, Edouard Lucas invented, or perhaps reinvented, one of the most popular puzzles of all times - the Tower of Hanoi, as he called it - which is still used today in many computer science textbooks to demonstrate how to write a recursive algorithm or program. First of all, we will make a list of the rules of the puzzle:


• There are three pegs: A, B and C.
• There are n disks. The number n is constant while working the puzzle.
• All disks are different in size.
• The disks are initially stacked on peg A so that they increase in size from the top to the bottom.
• The goal of the puzzle is to transfer the entire tower from the A peg to one of the others pegs.
• One disk at a time can be moved from the top of a stack either to an empty peg or to a peg with a larger disk than itself on the top of its stack.

A good way to get a feeling for the puzzle is to write a program which will show a copy of the puzzle on the screen and let you simulate moving the disks around. The next step could be to write a program for solving the puzzle in a efficient way. You don't have to do neither, but only know the actual situation after a given number of moves by using a determinate algorithm.



The Algorithm

It is well known and rather easy to prove that the minimum number of moves needed to complete the puzzle with n disks is tex2html_wrap_inline44 . A simple algorithm which allows us to reach this optimum is as follows: for odd moves, take the smallest disk (number 1) from the peg where it lies to the next one in the circular sequence tex2html_wrap_inline46 ; for even moves, make the only possible move not involving disk 1.



Input

The input file will consist of a series of lines. Each line will contain two integers n, m: n, lying within the range [0,100], will denote the number of disks and m, belonging to [0, tex2html_wrap_inline44 ], will be the number of the last move. The file will end at a line formed by two zeros.



Output

The output will consist again of a series of lines, one for each line of the input. Each of them will be formed by three integers indicating the number of disks in the pegs A, B and C respectively, when using the algorithm described above.



Sample Input


3 5
64 2
8 45
0 0



Sample Output


1 1 1
62 1 1
4 2 2

*/
#include <iostream>
#include <cstdlib>
using namespace std;
class big
{
    public:
        big();
        bool biger(big x);
        int getdig(int x);
        int gethigh();
        void setdig(int d,int x);
        void sethigh(int x);
        void input(istream& in);
        void output(ostream& out);
        void addint(int x);
        void mulint(int x);
        void subbig(big x);
    private:
        int dig[100];
        int high;
};
big::big()
{
    int i;
    for(i=0;i<100;i++)
        dig[i]=0;
    high=0;
}
bool big::biger(big x)
{
    int i;
    if(x.gethigh()>high)
        return true;
    else if(x.gethigh()<high)
        return false;
    else
        for(i=high-1;i>-1;i--)
            if(x.getdig(i)>dig[i])
                return true;
    return false;
}
int big::getdig(int x)
{
    return dig[x];
}
int big::gethigh()
{
    return high;
}
void big::setdig(int d,int x)
{
    dig[d]=x;
}
void big::sethigh(int x)
{
    high=x;
}
void big::input(istream& in)
{
    int i;
    string tmp;
    cin>>tmp;
    high=tmp.size();
    for(i=0;i<high;i++)
        dig[i]=tmp[high-1-i]-48;
}
void big::output(ostream& out)
{
    cout<<"high="<<high<<endl;
    int i;
    if(high!=0)
    {
        for(i=0;i<abs(high);i++)
            cout<<dig[abs(high)-1-i];
        cout<<endl;
    }

}
void big::addint(int x)
{
    int i;
    dig[0]+=x;
    for(i=0;i<=high;i++)
    {
        while(dig[i]>9)
        {
            dig[i]-=10;
            dig[i+1]++;
        }
        if(dig[high]>0)
            high++;
    }
}
void big::mulint(int x)
{
    int i;
    for(i=0;i<high;i++)
        dig[i]*=x;
    for(i=0;i<=high;i++)
    {
        while(dig[i]>9)
        {
            dig[i]-=10;
            dig[i+1]++;
        }
        if(dig[high]>0)
            high++;
    }
}
void big::subbig(big x)
{
    int i;
    if(biger(x))
    {
        big tmp;
        tmp=x;
        for(i=0;i<100;i++)
            x.setdig(i,dig[i]);
        x.sethigh(high);
        for(i=0;i<100;i++)
            dig[i]=tmp.getdig(i);
        high=tmp.gethigh();

        for(i=0;i<x.high;i++)
            dig[i]-=x.dig[i];
        for(i=0;i<high;i++)
        {
            while(dig[i]<0)
            {
                dig[i]+=10;
                dig[i+1]--;
            }
            if(high>0&&dig[high-1]==0)
                high--;
        }
        high=-high;
    }
    else
    {
        for(i=0;i<x.high;i++)
            dig[i]-=x.dig[i];
        for(i=0;i<high;i++)
        {
            while(dig[i]<0)
            {
                dig[i]+=10;
                dig[i+1]--;
            }
            if(high>0&&dig[high-1]==0)
                high--;
        }
    }
    bool b=true;
    for(i=0;i<100&&b;i++)
        if(dig[i]!=0)
            b=false;
    if(b)
        high=0;
}
int main()
{
    int ping[3];
    int sum,tmp,start,end;
    int i;
    big time,one,tmptmp;
    one.addint(1);
    while(cin>>sum&&sum)
    {
        ping[0]=sum;
        ping[1]=0;
        ping[2]=0;
        time.input(cin);
        start=0;
        end=0;
        while(time.gethigh()>0)
        {
            //time.output(cout);
            big sub;
            sub.addint(1);
            tmptmp=time;
            tmp=0;
            while(tmptmp.gethigh()>=0)
            {
                sub.mulint(2);
                tmptmp=time;
                tmptmp.addint(1);
                tmptmp.subbig(sub);
                tmp++;
            }
            tmp--;
            big tmpsub;
            tmpsub.addint(1);
            for(i=0;i<tmp;i++)
                tmpsub.mulint(2);
            time.addint(1);
            time.subbig(tmpsub);
            //tmpsub.output(cout);
            //time.output(cout);
            ping[start]-=tmp;
            if(tmp%2==0)
                end=start+2;
            else
                end=start+1;
            if(end>2)
                end-=3;
            ping[end]+=tmp;
            if(time.gethigh()>0)
            {
                ping[start]-=1;
                if(tmp%2==0)
                    tmp=start+1;
                else
                    tmp=start+2;
                if(tmp>2)
                    tmp-=3;
                ping[tmp]+=1;
                time.subbig(one);
                //time.output(cout);
            }
            start=end;
        }
        for(i=0;i<3;i++)
        {
            cout<<ping[i];
            if(i<2)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
