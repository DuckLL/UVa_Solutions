/*
It is common knowledge that the Solar System consists of the sun at its center and nine planets moving around the sun on elliptical orbits. Less well known is the fact that the planets' orbits are not at all arbitrary. In fact, the orbits obey three laws discovered by Johannes Kepler. These laws, also called ``The Laws of Planetary Motion," are the following.

The orbits of the planets are ellipses, with the sun at one focus of the ellipse. (Recall that the two foci of an ellipse are such that the sum of the distances to them is the same for all points on the ellipse.)
The line joining a planet to the sun sweeps over equal areas during equal time intervals as the planet travels around the ellipse.
The ratio of the squares of the revolutionary periods of two planets is equal to the ratio of the cubes of their semi major axes.
By Kepler's first law, the path of the planet shown in the figure on the left is an ellipse. According to Kepler's second law, if the planet goes from M to N in time tA and from P to Q in time tB and if tA = tB, then area A equals area B. Kepler's third law is illustrated next.

$\textstyle \parbox{.5\textwidth}{
\begin{center}
\mbox{}
\epsfxsize=3.25in
\epsfbox{p2729a.eps}
\end{center}}$$\textstyle \parbox{.49\textwidth}{
\begin{center}
\mbox{}
\epsfxsize=3.25in
\epsfbox{p2729b.eps}
\end{center}}$

Consider an ellipse whose center is at the origin 0 and that is symmetric with respect to the two coordinate axes. The x-axis intersects the ellipse at points A and B and the y-axis intersects the ellipse at points C and D. Set a = $ {1 \over 2}$| AB| and b = $ {1 \over 2}$| CD|. Then the ellipse is defined by the equation  $ {x^2 \over a^2}$ + $ {y^2 \over b^2}$ = 1. If a$ \ge$b, AB is called the major axis, CD the minor axis, and OA (with length a) is called the semi major axis. When two planets are revolving around the sun in times t1 and t2 respectively, and the semi major axes of their orbits have lengths a1 and a2, then according to Kepler's third law ($ {t_1 \over t_2}$)2 = ($ {a_1 \over a_2}$)3.


In this problem, you are to compute the location of a planet using Kepler's laws. You are given the description of one planet in the Solar System (i.e., the length of its semi-major axis, semi-minor axis, and its revolution time) and the description of a second planet (its semi-major axis and semi-minor axis). Assume that the second planet's orbit is aligned with the coordinate axes (as in the above figure), that it moves in counter clockwise direction, and that the sun is located at the focal point with non-negative x-coordinate. You are to compute the position of the second planet a specified amount of time after it starts at the point with maximal x-coordinate on its orbit (point B in the above figure).

Input 

The input file contains several descriptions of pairs of planets. Each line contains six integers a1, b1, t1, a2, b2, t. The first five integers are positive, and describe two planets as follows:

a1 = semi major axis of the first planet's orbit

b1 = semi minor axis of the first planet's orbit

t1 = period of revolution of the first planet (in days)

a2 = semi major axis of the second planet's orbit

b2 = semi minor axis of the second planet's orbit


The non-negative integer t is the time (in days) at which you have to determine the position of the second planet, assuming that the planet starts in position (a2, 0).

The last description is followed by a line containing six zeros.

Output 

For each pair of planets described in the input, produce one line of output. For each line, print the number of the test case. Then print the x- and y-coordinates of the position of the second planet after t days. These values must be exact to three digits to the right of the decimal point. Follow the format of the sample output provided below.
Sample Input 

10 5 10 10 5 10
10 5 10 20 10 10
0 0 0 0 0 0
Sample Output 

Solar System 1: 10.000 0.000
Solar System 2: -17.525 4.819
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(){
	ifstream fin("2729.txt");
	istream& ins(cin);
	double a1,b1,t1,a2,b2,t2,t;
	double e,space,high,low,half,tmp;
	int n=1;
	while(ins>>a1>>b1>>t1>>a2>>b2>>t&&a1){
		t2=t1/sqrt(pow(a1/a2,3));
		while(t>=t2)
			t-=t2;
		space=t/t2*a2*b2*M_PI;
		e=sqrt(a2*a2-b2*b2)/a2;
		high=2*M_PI;
		low=0;
		while(high-low>1e-6){
			half=(high+low)/2;
			tmp=0.5*a2*b2*(half-e*sin(half));
			if(tmp>space)
				high=half;
			else
				low=half;
		}
		cout.setf(ios::fixed);
		cout.precision(3);
		cout<<"Solar System "<<n<<": "<<a2*cos(half)<<" "<<b2*sin(half)<<endl;		
		n++;
	}
	return 0;
}

