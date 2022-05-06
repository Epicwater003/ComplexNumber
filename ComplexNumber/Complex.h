#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H

#define USE_NORMAL 0
#define USE_POLAR 1
#define USE_TRIGONOMETRIC 2
#define USE_EULER 3

#include <iostream>
#include <fstream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
//#include <cmath>

using std::vector;
struct Polar {
	Polar();
	Polar(double abs, double arg);
	double abs;
	double arg;
};
struct Decart {
	Decart();
	Decart(double real, double imag);
	double real;
	double imag;
};
struct Complex
{
private:
	void CalcPolar();
	void JustRound();
public:
	double real, imag, arg, abs;
	//Default constructor
	Complex();

	//Constructor by coordinates
	Complex(Decart data);

	//Constructor by polar coordinates
	Complex(Polar data);

	//Just standart output
	void PrintInSTDOut(uint8_t representation = USE_NORMAL);
	
	//Returns X component of complex number
	//double GetXComponent();
	//Returns Imaginary component of complex number
	//double GetIComponent();
	//Returns main Argument(angle) of complex number
	//double GetArgument();
	//Returns Module(length) of complex number
	//double GetModule();

	//Returns complex conjugate
	Complex Get—onjugate();

	//Exponentiation in n degree
	Complex Power(int n);

	//Root Extraction of n degree
	vector<Complex> Root(int n);
	
	//Just set method
	//void Set(double real, double imag);

	friend Complex operator+ (Complex& firstComplex, Complex& secondComplex);
	friend Complex operator- (Complex& firstComplex);
	friend Complex operator- (Complex& firstComplex, Complex& secondComplex);
	friend Complex operator* (Complex& firstComplex, Complex& secondComplex);
	friend Complex operator/ (Complex& firstComplex, Complex& secondComplex);
    //Complex operator= (Complex& firstComplex);

};



#endif // !COMPLEX_H
