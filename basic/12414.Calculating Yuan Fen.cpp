/*
Problem C

Calculating Yuan Fen

Yuanfen is a Chinese term that is hard to understand for people in other countries. Roughly speaking, yuanfen means the pre-determined "binding force" that links two people (usually two lovers) together. Although it is a blind faith, many people, especially girls like to calculate it.

Unfortunately, my girlfriend is one of them. One day, she asked me, "Sweetie, shall we find out our yuanfen?" Oh, I really hate that question, but I cannot reject it... Luckily, I'm a programmer, so the only thing I need to do is to find a seemingly good algorithm and write a yuanfen calculator. After several hours' searching in the web, I decided to implement the following popular yuanfen algorithm:

Step 1: Pick up the name abbreviations of the couple and concatenate them. For example, if the couple named Jiang Yun Fan and Tang Yu Rou, the concatenation of abbreviations is JYFTYR.

Step 2: Replace each letter with a number string. For some predefined positive integer ST, replace A with ST, and B with ST+1, C with ST+2, ..., Z with ST+25. For example, if ST=81, A should be replaced with 81, B should be replaced with 82, ..., Z will be replaced by 106. In the case above, JYFTYR will be replaced by 901058610010598.

Step 3: Repeat the following: add up each pair of consecutive digits, and write down the last digit of each sum. It's not difficult to see that each time we perform this action, the number of digits is decreased by 1. When the number string is exactly 100, or has no more than 2 digits, the process ends. The current number is the yuanfen between the couple. In the case above, the process is as follows:

901058610010598
91153471011547
0268718112691
284589923850
02937815135
2120596648
332545202
65799722
1268694
384453
12898
3077
374
01
So if ST=81, Jiang Yun Fan and Tang Yu Rou's yuanfen is only 1!

Too bad! I know my girlfriend very well. I know that even the result is as high as 99, she'll still be unhappy. Could you find the value of ST such that the yuanfen between my sweetheart and I is 100?

Input

There will be at most 50 test cases. Each case contains a string of at least four and at most ten capital letters.

Output

For each test case, print the smallest positive integer ST (note that ST should not be zero). If it does not exist or larger than 10000, print a string ":(" (without quotes.

Sample Input

JYFTYR
ABCDEF
YTHHLS
YTHLML
LYXM
JYFLY
CBTZX
LXYZLE
LXYLYR
QWERTY
Output for Sample Input

148
634
:(
910
96
4284
631
850
149
2277
Disclaimer

Don't be sad if the result of you and your sweetie is larger than 10000. That's no big deal.
Rujia Liu's Present 5: Developing Simplified Softwares
Special Thanks: Youzhi Bao
*/
#include <iostream>
using namespace std;
int main()
{
    int tmp,ans,vecsize,tmpvecsize,newvecsize;
    int i,j,k;
    string st;
    while(cin>>st)
    {
        ans=0;
        for(i=1;i<10001;i++)
        {
            int vec[100];
            vecsize=0;
            for(j=0;j<st.size();j++)
            {
                tmp=st[j]-'A'+i;
                int tmpvec[100];
                tmpvecsize=0;
                while(tmp>0)
                {
                    tmpvec[tmpvecsize]=tmp%10;
                    tmpvecsize++;
                    tmp/=10;
                }
                for(k=0;k<tmpvecsize;k++)
                {
                    vec[vecsize]=tmpvec[tmpvecsize-1-k];
                    vecsize++;
                }
            }
            while(vecsize>3)
            {
                int newvec[100];
                newvecsize=0;
                for(j=0;j<vecsize-1;j++)
                {
                    newvec[newvecsize]=(vec[j]+vec[j+1])%10;
                    newvecsize++;
                }
                for(j=0;j<newvecsize;j++)
                    vec[j]=newvec[j];
                vecsize=newvecsize;
            }
            if(vec[0]==1&&vec[1]==0&&vec[2]==0)
            {
                ans=i;
                break;
            }
        }
        if(ans)
            cout<<ans;
        else
            cout<<":(";
        cout<<endl;
    }
    return 0;
}
