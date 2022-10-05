#include "../Headers/LS_Vector2D.h"

LS_Vector2D::LS_Vector2D()
{
	x = 0.0f;
	y = 0.0f;
}

LS_Vector2D::LS_Vector2D(float inX, float inY)
{
	x = inX;
	y = inY;
}

LS_Vector2D& LS_Vector2D::Add(const LS_Vector2D& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

LS_Vector2D& LS_Vector2D::Subtract(const LS_Vector2D& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

LS_Vector2D& LS_Vector2D::Multiply(const LS_Vector2D& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;

	return *this;
}

LS_Vector2D& LS_Vector2D::Divide(const LS_Vector2D& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;

	return *this;
}

LS_Vector2D& operator+(LS_Vector2D& v1, LS_Vector2D& v2)
{
	return v1.Add(v2);
}

LS_Vector2D& operator-(LS_Vector2D& v1, LS_Vector2D& v2)
{
	return v1.Subtract(v2);
}

LS_Vector2D& operator*(LS_Vector2D& v1, LS_Vector2D& v2)
{
	return v1.Multiply(v2);
}

LS_Vector2D& operator/(LS_Vector2D& v1, LS_Vector2D& v2)
{
	return v1.Divide(v2);
}

LS_Vector2D& LS_Vector2D::operator+=(LS_Vector2D& vec)
{
	return this->Add(vec);
}

LS_Vector2D& LS_Vector2D::operator-=(LS_Vector2D& vec)
{
	return this->Subtract(vec);
}

LS_Vector2D& LS_Vector2D::operator*=(LS_Vector2D& vec)
{
	return this->Multiply(vec);
}

LS_Vector2D& LS_Vector2D::operator/=(LS_Vector2D& vec)
{
	return this->Divide(vec);
}

LS_Vector2D& LS_Vector2D::operator*(const int& i)
{
	this->x *= i;
	this->y *= i;

	return *this;
}

LS_Vector2D& LS_Vector2D::Zero()
{
	this->x = 0;
	this->y = 0;

	return *this;
}

std::ostream& operator<<(std::ostream& stream, const LS_Vector2D& vec)
{
	stream << "(" << vec.x << ", " << vec.y << ")\n";
	return stream;
}
