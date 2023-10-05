#pragma once
#include "Framework/World.h"
#include "Renderer/Renderer.h"
#include "Core/Math/Vector2.h"

namespace nc
{
	class World02 : public World
	{
	public:
		bool Initialize() override;
		void Shutdown() override;
		void Update(float dt) override;
		void Draw(Renderer& renderer) override;

	private:
		float m_angle = 0;
		float m_time;
		vec2 m_position;

		GLuint m_vao; //Vertex Array Object
		GLuint m_vao2;
	};
}