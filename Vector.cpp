#include "Vector.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

Vector3D::Vector3D() : x(0), y(0), z(0) {};

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {};

Vector3D::Vector3D(const Vector3D& other)
{
	*this = other;
};

Vector3D::~Vector3D() {};

Vector3D& Vector3D::operator = (const Vector3D& other)
{
	if (this != &other) {
		x = other.x;
		y = other.y;
		z = other.z;
	}
	return *this;
}

Vector3D::operator string() const
{
	stringstream sout;
	sout << "( " << x << + ", " << y << ", " << z << ")";
	return sout.str();
}

istream& operator >> (istream& input, Vector3D& vec)
{
	cout << "x: ";
	input >> vec.x;
	cout << "y: ";
	input >> vec.y;
	cout << "z: ";
	input >> vec.z;
	return input;
}

ostream& operator << (ostream& output, const Vector3D& vec)
{
	output << string(vec) << endl;
	return output;
}

Vector3D Vector3D::operator+(const Vector3D& other) const
{
	return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator * (double scalar) const
{
	return Vector3D(x * scalar, y * scalar, z * scalar);
}

bool Vector3D::operator != (const Vector3D& other) const
{
	return !(*this == other);
}

double Vector3D::operator()() const {
	return sqrt(x * x + y * y + z * z);
}


bool Vector3D::operator==(const Vector3D& other) const
{
	return (*this)() == other();
}

Vector3D& Vector3D::operator++() {
	++x;
	++y;
	++z;
	return *this;
}

Vector3D& Vector3D::operator--() {
	--x;
	--y;
	--z;
	return *this;
}

Vector3D Vector3D::operator++(int) {
	Vector3D temp(*this);  
	++(*this);  
	return temp;  
}

Vector3D Vector3D::operator--(int) {
	Vector3D temp(*this);  
	--(*this);  
	return temp; 
}