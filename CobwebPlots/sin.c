#include <iostream>
#define _USE_MATH_DEFINES

#include <math.h>

#include <iomanip>

const double r = M_PI*M_PI;

double f(double x) { //The function we are analyzing
	return r*sin(M_PI*x) ;
}


int main() {
	double x,xlast;
	int n;
	x = 0.97;
	for (n = 0; n<30; n++) {
	std::cout << std::setw(16) << x << std::setw(16) << x << std::endl; //output statement
		xlast = x;
		x = f(x);
		std::cout << std::setw(16) << xlast << std::setw(16) << x << std::endl;
	}
 return 0;
}
