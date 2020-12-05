#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
//NOTE: This program was used to calculate lambda = 1,2.5,3

using namespace std;
const double l = 3; //this is the lambda value.
const double dt = 0.00002;
double psi(double x,double e){                    //this function is used to obtain the first 2 values to start verlet. 
  return exp(-sqrt(2*(0.25*(x*x*x*x+l*l)-0.5*l*x*x - e))*fabs(x));
}

//l (lambda) = 1.     Energies:
//E1 = 0.6226065942270935238411766476929187774658203125: norm = 3.04475e-20
//E2 = 1.1222611976592276050723739899694919586181640625: norm = 1.42706e-20
//E3 = 2.3779787477433416142957867123186588287353515625: norm = 7.69529e-21


//l (lambda) = 2.5.   Energies:
//E1 = 0.90091532872525448283340665511786937713623046875: norm = 1.09119e-19
//E2 = 1.08968334456852034008988994173705577850341796875: norm = 8.13272e-20
//E3 = 2.34988207433935514245604281313717365264892578125: norm = 5.94294e-20

//l (lambda) = 3.    Energies:
//E1 = 1.08042866930124858981798752211034297943115234375: norm = 1.75199e-19
//E2 = 1.16430374784673773547183373011648654937744140625: norm = 1.4926e-19
//E3 = 2.62422696323483961577949230559170246124267578125: norm = 1.23569e-19


int main() {
  double area = 0;    //comments below explain this, it is the normalizing factor: the norm, the area. 
  double x,e,xnext;
	x = -5; 
	e =  2.62422696323483961577949230559170246124267578125; //eigen-energy
  double norm;
  norm  = 1.23569e-19; //norm factor that scales the graphical output to a proper distribution (this is the area under the unscaled curve)
  xnext = -4.9; //from here till the for loop, we are initialising the verlet.
  cout << x << setw(16) <<  psi(x,e) << endl;
  cout << xnext << setw(16) <<  psi(xnext,e) << endl; 
  double psinext,psilast; psinext = psi(xnext, e);
  psilast = psi(x,e);


	for (int i = 0; i < 460000; i++) { //the verlet iterations are here.
    double psiplace; psiplace = psinext;
    xnext += dt;
    psinext = 2*psiplace-psilast+(0.5*(xnext*xnext*xnext*xnext+l*l)-l*xnext*xnext-2*e)*psiplace*dt*dt;
    psilast = psiplace;
    //area += fabs(psinext)*dt;   //How the area (norm) is calculated
    cout << xnext  << setw(16) << (psinext/(norm))+e << endl; //we add e to translate the datapoints, and divide by the norm to scale them
	}
 //cout << area;  //To see the area/norm
}
