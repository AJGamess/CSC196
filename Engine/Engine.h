#pragma once
#include "Renderer.h"
#include "Audio.h"
#include "ETime.h"
#include "Random.h"
#include "MathUtils.h"
#include "Particle.h"
#include "Model.h"
#include "Transform.h"
#include "Input.h"
#include <SDL.h>
class Engine
{

public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown();

	void Update();
public:
	Renderer* m_renderer;
	Input* m_input{ nullptr };
	Audio* m_audio{ nullptr };
};

