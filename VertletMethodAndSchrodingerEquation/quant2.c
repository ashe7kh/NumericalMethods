#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
//NOTE: this program was the one used to generate the lambda = 0 graphs. I apologize.

using namespace std;

const double dt = 0.00005;
double psi(double x,double e){
  return exp(-sqrt(2*(0.25*x*x*x*x - e))*fabs(x));
}
//4th order potentials: lambda = 0.
//0.42080497440704378586673328754841350018978  E1 first(ground) eigen-energy  
//1.5079012404130338609320460818707942962646   E2 second eigen-energy
//2.9587956852228529669446288608014583587646   E3 you-get-the-idea (third) eigen-energy 


//E1 normalizing factor: 4.71729e-21
//E2 normalizing factor: 1.79796e-21
//E3 normalizing factor: 8.50307e-22 


int main() {
  double x,e,xnext,area; area = 0;
	x = -5;
	e = 2.9587956852228529669446288608014583587646; //The eigen-energy.
  xnext = -4.9;     //from here till the for loop, we are initialising the verlet.
  cout << x << setw(16) <<  psi(x,e) << endl;
  cout << xnext << setw(16) <<  psi(xnext,e) << endl; 
  double psinext,psilast; psinext = psi(xnext, e);
  psilast = psi(x,e);


	for (int i = 0; i < 190000; i++) { //The verlet iterations are below here.
    double psiplace; psiplace = psinext;
    double norm; norm = 8.50307e-22; //this is explained in detail in the "quant3.c" file. 
    xnext += dt;
    psinext = 2*psiplace-psilast+(0.5*xnext*xnext*xnext*xnext-2*e)*psiplace*dt*dt;
    psilast = psiplace;
    cout << xnext  << setw(16) << psinext/(norm) + e << endl;
	}
}
