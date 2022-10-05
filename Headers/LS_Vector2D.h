#pragma once

#include <iostream>

class LS_Vector2D
{
public:
	float x;
	float y;

	LS_Vector2D();
	LS_Vector2D(float inX, float inY);

	LS_Vector2D& Add(const LS_Vector2D& vec);
	LS_Vector2D& Subtract(const LS_Vector2D& vec);
	LS_Vector2D& Multiply(const LS_Vector2D& vec);
	LS_Vector2D& Divide(const LS_Vector2D& vec);

	friend LS_Vector2D& operator+(LS_Vector2D& v1, LS_Vector2D& v2);
	friend LS_Vector2D& operator-(LS_Vector2D& v1, LS_Vector2D& v2);
	friend LS_Vector2D& operator*(LS_Vector2D& v1, LS_Vector2D& v2);
	friend LS_Vector2D& operator/(LS_Vector2D& v1, LS_Vector2D& v2);

	LS_Vector2D& operator+=(LS_Vector2D& vec);
	LS_Vector2D& operator-=(LS_Vector2D& vec);
	LS_Vector2D& operator*=(LS_Vector2D& vec);
	LS_Vector2D& operator/=(LS_Vector2D& vec);

	LS_Vector2D& operator*(const int& i);
	LS_Vector2D& Zero();

	friend std::ostream& operator<<(std::ostream& stream, const LS_Vector2D& vec);
};