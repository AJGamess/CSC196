#include "PickUp.h"
#include "Player.h"
#include "..\Engine\Engine.h"

void PickUp::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Player")
	{
		g_engine.GetAudio().PlaySound("fish.mp3");
		dynamic_cast<Player*>(actor)->SetFireModifer(0.5f);
		m_destroyed = true;
	}
}