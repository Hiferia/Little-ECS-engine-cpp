#pragma once

#include "Components.h"
#include "..\LS_Vector2D.h"

class TransformComponent : public Component
{
public:
	LS_Vector2D position;
	LS_Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;
	TransformComponent()
	{
		//.Zero() is equal to do:
		//position.x = 0.0f;
		//position.y = 0.0f;
		position.Zero();
	}
	TransformComponent(int inScale)
	{
		position.Zero();
		scale = inScale;
	}
	TransformComponent(int inX, int inY)
	{
		position.x = inX;
		position.y = inY;
	}
	TransformComponent(int inX, int inY, int inW, int inH, int inScale)
	{
		position.x = inX;
		position.y = inY;
		width = inW;
		height = inH;
		scale = inScale;
	}
	void Init() override
	{
		velocity.Zero();
	}
	void Update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};
