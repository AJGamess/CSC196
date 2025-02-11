#include "Player.h"
#include "..\Engine\Engine.h"
#include "Bullet.h"
#include "..\Engine\Scene.h"
#include "GameData.h"
#include "MyGame.h"

#include <iostream>

void Player::Update(float dt)
{
	// movement
	Vector2 direction{ 0, 0 };
	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_W))			direction.x =  1;
	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_S))			direction.x = -1;

	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_Q))			direction.y = -1;
	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_E))			direction.y =  1;

	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_A))			m_transform.rotation -= Math::DegToRad(100) * dt;
	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_D))			m_transform.rotation += Math::DegToRad(100) * dt;

	Vector2 acceleration = direction.Rotate(m_transform.rotation) * m_speed;
	m_velocity += acceleration * dt;

	m_transform.position.x = Math::Wrap(m_transform.position.x, (float)g_engine.GetRenderer().GetWidth());
	m_transform.position.y = Math::Wrap(m_transform.position.y, (float)g_engine.GetRenderer().GetHeight());

	// fire
	m_fireTimer -= dt;
	if (g_engine.GetInput().GetMouseButtonDown(0) && m_fireTimer <= 0)// && !g_engine.GetInput().GetPreviousKeyDown(SDL_SCANCODE_SPACE))
	{
		m_fireTimer = 0.2f * m_fireModifer;

		g_engine.GetAudio().PlaySound("bass.wav");
		// shoot at mouse position
		Vector2 direction = g_engine.GetInput().GetMousePosition() - m_transform.position;
		float angle = direction.Angle();

		// actor
		Model* model = new Model{ GameData::shipPoints, Color{ 1, 1, 0 } };
		Transform transform{ m_transform.position, angle, 1.0f };

		auto bullet = std::make_unique<Bullet>(400.0f, transform, model);
		bullet->SetLifespan(1);
		bullet->SetTag("PlayerBullet");
		m_scene->AddActor(std::move(bullet));
	}


	Actor::Update(dt);
}

void Player::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Enemy")
	{
		g_engine.GetAudio().PlaySound("clap.wav");
		m_destroyed = true;
		dynamic_cast<MyGame*>(m_scene->GetGame())->OnPlayerDeath();
	}
}
