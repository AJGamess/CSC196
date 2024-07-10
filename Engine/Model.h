#pragma once
#include "Vector2.h"
#include "Transform.h"
#include "color.h"
#include <vector>
#include "Renderer.h"

// * - pointer -> nullptr
// & - reference ->
class Model
{
public:
	Model() = default;
	Model(std::vector<Vector2>& points, const Color color) :
		m_points{ points },
		m_color{ color }
	{}

	void Draw(Renderer& renderer, const Vector2& position, float angle, float scale);
	void Draw(Renderer& renderer, Transform& transform);
private:
	std::vector<Vector2> m_points;
	Color m_color;
};

