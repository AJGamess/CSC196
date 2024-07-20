#include "Actor.h"
#include "Model.h"

void Actor::Update(float dt)
{
	m_transform.position += (m_velocity * dt);
}

void Actor::Draw(Renderer& renderer)
{
	if (m_model) {
		m_model->Draw(renderer, m_transform);
	}
}
