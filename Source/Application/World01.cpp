#include "World01.h"
#include "Framework/Framework.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"

namespace nc
{
    bool World01::Initialize()
    {
        return true;
    }

    void World01::Shutdown()
    {
    }

    void World01::Update(float dt)
    {
        m_angle += 90 * dt;
        
        m_position.y += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_S) ? -dt : 0;
        m_position.y += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_W) ? +dt : 0;
        m_position.x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_A) ? -dt : 0;
        m_position.x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_D) ? +dt : 0;
        if (ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_Q))
        {
            glRotatef(m_angle, 0, 1, 0);
        }
        m_time += dt;

    }

    void World01::Draw(Renderer& renderer)
    {
        // pre-render
        renderer.BeginFrame();

        // render
        glPushMatrix();
        glTranslatef(m_position.x,m_position.y,0);

        //Auto TRANSFORMS
        
        //glRotatef(m_angle, 0, 1, 0);
        //glScalef((sin(m_time * 5) + 1) * 0.5f, 1, 1);

        glBegin(GL_QUADS); 

        glColor3f(1, 0, 0);
        glVertex2f(-0.5f, -0.5f);

        glColor3f(0, 1, 0);
        glVertex2f(0, 0.5f);

        glColor3f(0, 0, 1);
        glVertex2f(0.5f, -0.5f);

        glColor3f(0, 0, 1);
        glVertex2f(0.5f, 0.5f);

        glEnd();
        glPopMatrix();
        // post-render
        renderer.EndFrame();
    }
}
