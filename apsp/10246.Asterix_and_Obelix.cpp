/*
Problem A
Asterix and Obelix
Input: standard input
Output: standard output
Time Limit: 5 seconds
Memory Limit: 32 MB

After winning a gruesome battle against the Romans in a far-away land, Asterix and his dearest friend Obelix are now returning home. However Obelix is not with Asterix now. He has left Asterix in order to deliver menhir to one of his international buyers (as you probably know, recently he has extended his trade to international markets). But he has promised to join Asterix on his way home and Asterix has promised to host a feast for Obelix (you know how fat he is!) in the city they meet. Obelix may meet Asterix in any city on his way home including the starting and the destination city.



Now Asterix is sitting with a map and trying to figure out the cheapest route home. The map shows the cities and the cost (in sestertii) of going from one city to another if there is a road connecting them directly. For each city in the map Asterix has also calculated the cost (in sestertii) of hosting a feast for Obelix in that city. There will be only one feast and for safety Asterix has decided to set aside enough sestertii to host a feast in the costliest city on the route.

Since Asterix does not have a computer, he seeks your help to find out the cheapest route home.

Input

The input may contain multiple test cases.

The first line of each test case contains three integers C (¢G 80), R (¢G 1000) and Q (¢G 6320) where C indicates the number of cities (cities are numbered using distinct integers ranging from 1 to C), R represents the number of roads and Q is the number of queries.

The next line contains C integers where the i-th integer fi is the cost (in sestertii) of hosting a feast in city i.

Each of the next R lines contains three integers: c1, c2 (1 c1) and d indicating that the cost of going from city c1 to c2 (or from c2 to c1) is d sestertii.

Each of the next Q lines contains two integers c1 and c2 (c1 1 c2) asking for the cost (in sestertii) of the cheapest route from city c1 to city c2.

The input will terminate with three zeros form C, S and Q.

Output

For each test case in the input first output the test case number (starting from 1) as shown in the sample output. Then for each query in the input print a line giving the minimum cost (in sestertii) of going from the first to the second city in the query. If there exists no path between them just print ¡§¡V1¡¨.

Print a blank line between two consecutive test cases.

Sample Input

7 8 5
2 3 5 15 4 4 6
1 2 20
1 4 20
1 5 50
2 3 10
3 4 10
3 5 10
4 5 15
6 7 10
1 5
1 6
5 1
3 1
6 7
4 4 2
2 1 8 3
1 2 7
1 3 5
2 4 8
3 4 6
1 4
2 3
0 0 0

Sample Output

Case #1
45
-1
45
35
16

Case #2
18
20

min{ path(S,T) + min{w[i]|i on path from S to T}}
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct data{
	long long int idx;
	long long int dis;
};
long long int c;
long long int cw[1000];
long long int rw[1000][1000];
long long int path(long long int a,long long int b,long long int big);
int main(){
	ifstream fin("10246.txt");
	istream& ins(fin);
	long long int casee=0;
	long long int r,q;
	long long int a,b,w;
	long long int mini,big;
	long long int p1;
	long long int i,j;
	while(ins>>c&&c){
		//init
		for(i=1;i<c+1;i++)
			fill(rw[i],rw[i]+c+1,-1);
		//input
		ins>>r>>q;
		for(i=1;i<c+1;i++)
			ins>>cw[i];
		while(r--){
			ins>>a>>b>>w;
			rw[a][b]=w;
			rw[b][a]=w;
		}
		//output
		if(casee>0)
			cout<<endl;
		cout<<"Case #"<<++casee<<endl;
		while(q--){
			ins>>a>>b;
			mini=1e18;
			for(i=1;i<c+1;i++){
				big=max(max(cw[a],cw[b]),cw[i]);
				p1=path(a,b,big);
				if(p1!=-1&&p1+big<mini)
					mini=p1+big;
			}
			if(mini==1e18)
				cout<<-1<<endl;
			else
				cout<<mini<<endl;
		}
	}
	return 0;
}
long long int path(long long int a,long long int b,long long int big){
	if(a==b)
		return 0;
	bool used[1000]={0};
	long long int mini,minx;
	long long int nowidx,nowdis;
	long long int i,j;
	vector<data> use;
	data tmp;
	tmp.dis=0;
	tmp.idx=a;
	used[a]=1;
	use.push_back(tmp);
	while(1){
		mini=1e18;
		for(i=0;i<use.size();i++){
			nowidx=use[i].idx;
			nowdis=use[i].dis;
			for(j=1;j<c+1;j++)
				if(cw[j]<=big&&rw[nowidx][j]!=-1)
					if(nowdis+rw[nowidx][j]<mini&&!used[j]){
						mini=nowdis+rw[nowidx][j];
						minx=j;
					}
		}
		if(mini==1e18)
			return -1;
		if(minx==b)
			return mini;
		tmp.dis=mini;
		tmp.idx=minx;
		use.push_back(tmp);
		used[minx]=1;
	}
}
