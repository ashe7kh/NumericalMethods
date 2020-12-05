#include <iostream>
#include <math.h>

#include <iomanip>

const double a = 1.2;

double f(double x) { //The function we are analyzing
	return tanh(a*x)-x;
}

double g2(double x) { //Newton-Raphson method
	return x-((tanh(a*x)-x) / ((a / (cosh(a*x)*cosh(a*x)))-1));
}

int main() {
	double x;
	int n;
	std::cout << "x = ? ";
	std::cin >> x;
	for (n = 0; n<20; n++) {
		std::cout << std::setw(4) << n << std::setw(16) << x << std::setw(16) << f(x) << std::endl; //output statement
		x = g2(x); //changing the value of x to the new value that is closer to the root
	}
}

//a = 0.8 has 1 solution at: x = 0
//a = 1.2 has 3 solutions at: x=-0.65857, x=0, x=0.65857