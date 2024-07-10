#pragma once
#include "Vector2.h"
#include "Renderer.h"

struct Particle
{
	Vector2 position{ 0, 0 };
	Vector2 velocity{0,0};
	float lfiespan = 0;
	uint8_t r, g, b, a;

	Particle() = default;
	Particle(Vector2 position, Vector2 velocity) : position{ position }, velocity{ velocity } {}

	void Update(float dt);
	void Draw(Renderer& renderer);

};

