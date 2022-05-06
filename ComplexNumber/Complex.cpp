#include "Complex.h"
Polar::Polar():abs(0.), arg(0.){}
Polar::Polar(double abs, double arg){
	this->abs = abs;
	this->arg = arg;
}
Decart::Decart() :real(0.), imag(0.){}
Decart::Decart(double real, double imag){
	this->real = real;
	this->imag = imag;
}

Complex::Complex():real(0.),imag(0.),abs(0.),arg(0.) {}
Complex::Complex(Decart data) {
	
	this->real = data.real;
	this->imag = data.imag;
	JustRound();
	CalcPolar();
}
Complex::Complex(Polar data) {
	this->arg = data.arg;
	this->abs = data.abs;
	this->real = abs * cos(arg);
	this->imag = abs * sin(arg);
	JustRound();
	
}
void Complex::JustRound() {
	if (real > 0 && real < 0.0001) {
		this->real = 0;
	}
	if (imag > 0 && imag < 0.0001) {
		this->imag = 0;
	}
	if (real < 0 && real > -0.0001) {
		this->real = 0;
	}
	if (imag < 0 && imag > -0.0001) {
		this->imag = 0;
	}
}

void Complex::CalcPolar() {
	this->abs = pow(real * real + imag * imag, 0.5);
	//this->arg = atan((double)imag / (double)real);
	this->arg = atan2((double)imag, (double)real);
}
void Complex::PrintInSTDOut(uint8_t representation) {
	switch (representation){
	case USE_NORMAL:
		std::cout << "z = " << this->real << " + " << this->imag << "*i" << std::endl;
		break;
	case USE_POLAR:
		std::cout << "Module:" <<this->abs << " | Angle:" << this->arg << std::endl;
		break;
	case USE_TRIGONOMETRIC:
		std::cout << "z = " << this->abs << " * (cos(" << this->arg <<") + i*sin(" << this->arg << ")" << std::endl;
		break;
	case USE_EULER:
		std::cout << "z = " << this->abs << "*exp(i*" << this->arg << ")" << std::endl;
		break;
	default:
		// Some error cases here
		break;
	}
}

//Returns complex conjugate
Complex Complex::GetÑonjugate() {
	Decart data(real, -imag);
	/*data.real = real;
	data.imag = -imag;*/
	return Complex(data);
};
//Returns exponentiation in n degree
Complex Complex::Power(int n) {
	
	Decart ddata(0.,0.);

	if (n < 0) {
		std::cout << "ERROR::COMPLEX::POWER::N<0" << std::endl;
		return Complex(ddata);
	}
	if (n == 0) {
		return Complex(ddata);
	}
	else if (n == 1) return *this;
	else {
		Polar pdata(pow(abs, n), n * arg);
		return Complex(pdata);
	};
	
};
//Returns a array of root extraction of n degree
vector<Complex> Complex::Root(int n) {
	vector<Complex> A;
	
	Decart ddata(0.,0.);
	if (n <= 1) {
		std::cout << "ERROR::COMPLEX::SQUARE::N<=1" << std::endl;
		A.push_back(Complex(ddata));
		return A;
	}
	double r = pow(abs, (double)1 / (double)n);
	for (int o = 0; o < n; o++) {
		double phi = double(arg + 2*M_PI*o)/(double)n;
		Polar pdata(r,phi);
		A.push_back(Complex(pdata));
	}
	return A;
};


Complex operator+ (Complex& firstComplex, Complex& secondComplex) {
	Decart data;
	data.real = firstComplex.real + secondComplex.real;
	data.imag = firstComplex.imag + secondComplex.imag;
	return Complex(data);
};
Complex operator- (Complex& firstComplex) {
	firstComplex.real = -firstComplex.real;
	firstComplex.imag = -firstComplex.imag;
	return firstComplex;
};
Complex operator- (Complex& firstComplex, Complex& secondComplex) {
	Decart data;
	data.real = firstComplex.real - secondComplex.real;
	data.imag = firstComplex.imag - secondComplex.imag;
	return Complex(data);
};
Complex operator* (Complex& firstComplex, Complex& secondComplex) {
	Decart data;
	data.real = firstComplex.real * secondComplex.real - firstComplex.imag * secondComplex.imag;
	data.imag = firstComplex.real * secondComplex.imag + firstComplex.imag * secondComplex.real;
	return Complex(data);
};
Complex operator/ (Complex& firstComplex, Complex& secondComplex) {
	Decart data;
	data.real = 0.0;
	data.imag = 0.0;
	if (secondComplex.real == 0 && secondComplex.imag == 0) {
		std::cout << "ERROR::COMPLEX::DIVIDER::DIVIDEBYZERO" << std::endl;
		return Complex(data);
	}
	double divider = secondComplex.real * secondComplex.real + secondComplex.imag * secondComplex.imag;
	if (divider == 0) {
		std::cout << "ERROR::COMPLEX::DIVIDER::DIVIDEBYZERO" << std::endl;
		return Complex(data);
	}
	data.real = firstComplex.real * secondComplex.real + firstComplex.imag * secondComplex.imag;
	data.real /= divider;
	data.imag = -firstComplex.real * secondComplex.imag + firstComplex.imag * secondComplex.real;
	data.imag /= divider;
	return Complex(data);
};

