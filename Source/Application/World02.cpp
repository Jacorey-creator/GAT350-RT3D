#include "World02.h"
#include "Framework/Framework.h"
#include "Input/InputSystem.h"

namespace nc
{
    bool World02::Initialize()
    {
        //shaders
        const char* vertexShader =
            "#version 430\n"
            "layout (location=0) in vec3 position;"
            "layout (location=1) in vec3 color;"
            "layout (location=0) out vec3 ocolor;"
            "void main() {"
            "  ocolor = color;"
            "  gl_Position = vec4(position, 1.0);"
            "}";

        const char* fragmentShader =
            "#version 430\n"
            "layout (location=0) in vec3 color;"
            "out vec4 ocolor;"
            "void main() {"
            "  ocolor = vec4(color, 1);"
            "}";

        GLuint vs = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vs, 1, &vertexShader, NULL);
        glCompileShader(vs);

        GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fs, 1, &fragmentShader, NULL);
        glCompileShader(fs);

        GLuint program = glCreateProgram();
        glAttachShader(program,vs);
        glAttachShader(program,fs);
        glLinkProgram(program);

        glUseProgram(program);

        //vertex Data
        float positionData[] = 
        {
        -0.8f, -0.8f, 0.0f,
        0.0f, -0.8f, 0.0f,
        0.0f,  0.8f, 0.0f
        };

        float colorData[] =
        {
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f
        };

        GLuint vbo[2]; // Vertex Buffer Object
        glGenBuffers(2, vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(positionData), positionData, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colorData), colorData, GL_STATIC_DRAW);
        
        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);

        //position
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindVertexBuffer(0, vbo[0], 0, 3 * sizeof(GLfloat));

        //color
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindVertexBuffer(1, vbo[1], 0, 3 * sizeof(GLfloat));

        //Triangle2

        const char* vertexShader2 =
            "#version 430\n"
            "layout (location=0) in vec3 position;"
            "layout (location=1) in vec3 color;"
            "layout (location=0) out vec3 ocolor;"
            "void main() {"
            "  ocolor = color;"
            "  gl_Position = vec4(position, 1.0);"
            "}";



        const char* fragmentShader2 =
            "#version 430\n"
            "layout (location=0) in vec3 color;"
            "out vec4 ocolor;"
            "void main() {"
            "  ocolor = vec4(color, 1);"
            "}";

        GLuint vs2 = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vs2, 1, &vertexShader2, NULL);
        glCompileShader(vs2);

        GLuint fs2 = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fs2, 1, &fragmentShader2, NULL);
        glCompileShader(fs2);

        GLuint program2 = glCreateProgram();
        glAttachShader(program2, vs2);
        glAttachShader(program2, fs2);
        glLinkProgram(program2);

        glUseProgram(program2);

        //Triangle2
        float positionData2[] =
        {
        0.9f, 0.8f, 0.0f,
        0.0f, 0.8f, 0.0f,
        0.0f,  -0.8f, 0.9f
        };
        //--------

 //Triangle2
        float colorData2[] =
        {
            1.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f
        };
        //-------

//---Triangle2
        GLuint vbo2[2];
        glGenBuffers(2, vbo2);
        glBindBuffer(GL_ARRAY_BUFFER, vbo2[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(positionData2), positionData2, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, vbo2[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colorData2), colorData2, GL_STATIC_DRAW);

        glGenVertexArrays(1, &m_vao2);
        glBindVertexArray(m_vao2);
        //-----------

//Triangle2
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindVertexBuffer(0, vbo2[0], 0, 3 * sizeof(GLfloat));

        //Triangle2
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindVertexBuffer(1, vbo2[1], 0, 3 * sizeof(GLfloat));
        return true;
    }

    void World02::Shutdown()
    {
    }

    void World02::Update(float dt)
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

    void World02::Draw(Renderer& renderer)
    {
        // pre-render
        renderer.BeginFrame();

        // render
        glBindVertexArray(m_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(m_vao2);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // post-render
        renderer.EndFrame();
    }
}
