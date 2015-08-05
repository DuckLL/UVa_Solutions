/*
As Alan Turing and his friend David Champernowne gave the name “The All-time Champ” number (as a joke with the David surname) to the trascendental constant 0.1234567891011... obtained by concatenating the positive integers and interpreting them as decimal digits to the right of a decimal point, let us nominate “All-time Champ Integers” to the numbers constructed by concatenating the digits of a set of consecutive integers.

Given two natural numbers 0<m<=n, there is a such integer, but there are other natural numbers that contain, as substrings, all the numbers between m and n, both included. For example for m=1 and n=13, possible solutions are 12345678910111213 (the corresponding “Champ”), 1011213456789 or 1101213456789. We can see that the last two numbers have only 13 digits as against the 17 of the “Champ”.

Your task is to find out the shortest such integer.

Input
The input file contains several lines of input. Each line contains two natural numbers m and n (0<m<=n<100). Input is terminated by end of file.

Output
For each line of input produce one line of output. This line contain the shortest integer that contains as substring all the numbers between m and n (both included). There may be more than one solution. We will accept any one of the solutions.

Sample Input:
1 13
1 4
13 14
11 12

Sample Output:
1101213456789
1234
1314
112
*/
#include <iostream>
#include <fstream>
using namespace std;
struct data{
	int in;
	int out;
	int relation[10];
};
data number[10];
string ans;
void eul(int now);
int main(){
	ifstream fin("10248.txt");
	istream& ins(fin);
	int x,y;
	int i,j;
	int from,to;
	int head;
	while(ins>>x>>y){
		//init
		ans="";
		for(i=0;i<10;i++){
			number[i].in=0;
			number[i].out=0;
			fill(number[i].relation,number[i].relation+10,0);
		}
		//input
		for(i=x;i<y+1;i++){
			if(i<10)
				continue;
			from=i/10;
			to=i%10;
			number[from].relation[to]++;
			number[from].out++;
			number[to].in++;
		}
		//try until done
		while(1){
			head=-1;
			for(i=0;i<10;i++)
				if(number[i].out&&number[i].out==number[i].in)//找一樣的
					head=i;
			for(i=0;i<10;i++)
				if(number[i].out>number[i].in)//找比較多出去的
					head=i;
			if(head==-1)
				break;
			eul(head);
		}
		//fixed
		for(i=x;i<y+1&&i<10;i++)
			if(ans.find(i+48)==-1)//沒有0~9
				ans+=i+48;//補上
		cout<<ans<<endl;
	}
	return 0;
}
void eul(int now){
	int i;
	ans+=now+48;
	for(i=0;i<10;i++)
		if(number[now].relation[i]&&number[i].out){//先走後面還有路的
			number[now].relation[i]--;
			number[now].out--;
			number[i].in--;
			eul(i);
			return;
		}
	for(i=0;i<10;i++)
		if(number[now].relation[i]){//把剩下還有關係的走完
			number[now].relation[i]--;
			number[now].out--;
			number[i].in--;
			eul(i);
			return;
		}
}
