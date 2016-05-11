#include <cmath>
#include "Complex.h"

#define PI acos(-1)
#define PRECISION 1e-15

Complex::Complex(const double re, const double im)
{
	this->real = re;
	this->imag = im;
}

Complex::Complex(const Complex& c)
{
	this->real = c.real;
	this->imag = c.imag;
}

Complex& Complex::operator=(const Complex& c)
{
	if (this != &c) {
		this->real = c.real;
		this->imag = c.imag;
	}

	return *this;
}

Complex Complex::Polar(const double leng, const double arg)
{
	this->real = leng * cos(arg);
	this->imag = leng * sin(arg);

	return *this;
}

double Complex::Real()
{
	return this->real;
}

double Complex::Imag()
{
	return this->imag;
}

double Complex::Norm()
{
	return pow(this->real, 2) + pow(this->imag, 2);
}

double Complex::Abs()
{
	return sqrt( pow(this->real, 2) + pow(this->imag, 2));
}

double Complex::Arg()
{
	return atan2(this->imag, this->real);
}

Complex Complex::operator++()		// ++c
{
	this->real++;
    this->imag++;

    return *this;
}

Complex Complex::operator++(int)	// c++ (c = c + 1
{
	Complex t(this->real, this->imag);

    this->real++;
    this->imag++;

    return t;
}

Complex Complex::operator--()
{
	this->real--;
    this->imag--;

    return *this;
}

Complex Complex::operator--(int)
{
	Complex t(this->real, this->imag);

    this->real--;
    this->imag--;

    return t;
}

Complex::~Complex()
{
	;
}

Complex Polar(const double leng, const double arg)
{
	return Complex(leng * cos(arg), leng * sin(arg));
}

double Norm(const Complex& x)
{
	return pow(x.real, 2) + pow(x.imag, 2);
}

double Abs(const Complex& x)
{
	return sqrt( pow(x.real, 2) + pow(x.imag, 2));
}

double Arg(const Complex& x)
{
	return atan2(x.imag, x.real);
}

Complex operator+(const Complex& x, const Complex& y)
{
	return Complex(x.real + y.real, x.imag + y.imag);
}

Complex operator-(const Complex& x, const Complex& y)
{
	return Complex(x.real - y.real, x.imag - y.imag);
}

Complex operator*(const Complex& x, const Complex& y)
{
    return Complex(x.real * y.real - x.imag * y.imag, x.real * y.imag + x.imag * y.real);
}

Complex operator/(const Complex& x, const Complex& y)
{
    return Complex((x.real * y.real + x.imag * y.imag) / (y.real * y.real + y.imag * y.imag), (x.imag * y.real - x.real * y.imag) / (y.real * y.real + y.imag * y.imag));
}

Complex operator+=(Complex& x, const Complex& y)
{
	x.real = x.real + y.real;
	x.imag = x.imag + y.imag;

	return x;
}

Complex operator-=(Complex& x, const Complex& y)
{
	x.real = x.real - y.real;
	x.imag = x.imag - y.imag;

	return x;
}

Complex operator*=(Complex& x, const Complex& y)
{
    double re = x.real * y.real - x.imag * y.imag;
	double im = x.real * y.imag + x.imag * y.real;

	x.real = re;
	x.imag = im;

	return x;
}

Complex operator/=(Complex& x, const Complex& y)
{
    double re = (x.real * y.real + x.imag * y.imag) / (y.real * y.real + y.imag * y.imag);
	double im = (x.imag * y.real - x.real * y.imag) / (y.real * y.real + y.imag * y.imag);

	x.real = re;
	x.imag = im;

	return x;
}

bool operator==(const Complex& x, const Complex& y)
{
	return ((((x.real - y.real) <= PRECISION) && ((y.real - x.real) <= PRECISION)) 
		 && (((x.imag - y.imag) <= PRECISION) && ((y.imag - x.imag) <= PRECISION)));
}

bool operator!=(const Complex& x, const Complex& y)
{
	return ((((x.real - y.real) > PRECISION) || ((y.real - x.real) > PRECISION)) 
		 || (((x.imag - y.imag) > PRECISION) || ((y.imag - x.imag) > PRECISION)));
}

ostream& operator<<(ostream& o, const Complex& x)
{
	return o << "(" << x.real << "," << x.imag << ")";
}
