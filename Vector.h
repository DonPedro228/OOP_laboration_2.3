#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

#pragma pack(1)
class Vector3D
{
private:
	double x;
	double y;
	double z;
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D(const Vector3D& other);

	~Vector3D();

	double GetX() const { return x; }
	double GetY() const { return y; }
	double GetZ() const { return z; }

	void SetX(double value) { x = value; }
	void SetY(double value) { y = value; }
	void SetZ(double value) { z = value; }

	Vector3D& operator =(const Vector3D& other);
	friend istream& operator>>(istream& input, Vector3D& vec);
	friend ostream& operator<<(ostream& output, const Vector3D& vec);

	operator string() const;
	Vector3D operator*(double scalar) const;

	Vector3D operator+(const Vector3D& other) const;
	bool operator ==(const Vector3D& other) const;
	bool operator != (const Vector3D& other) const;

	Vector3D& operator ++();
	Vector3D& operator --();
	Vector3D operator ++(int);
	Vector3D operator --(int);

	double operator()() const;
};

