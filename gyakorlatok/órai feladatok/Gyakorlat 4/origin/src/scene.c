#include "scene.h"

#include <math.h>

#include <GL/gl.h>

void init_scene(Scene* scene, float angle)
{
    scene->spinAngle = angle;
}

void update_scene(Scene* scene)
{
    scene->spinAngle += 0.01;

}

void render_scene(Scene* scene)
{
    draw_origin();
    draw_triangle();

    draw_sphere(&scene);
    
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(3, 0, 0);
    glVertex3f(4, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(3, 0, 0);
    glVertex3f(3, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(3, 0, 0);
    glVertex3f(3, 0, 1);

    glEnd();
}

void draw_triangle()
{
    glBegin(GL_TRIANGLES);

    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-4, 0, 0);

    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-3, 1, 0);

    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-3, 0, 1);

    glEnd();
}

void draw_sphere(Scene* scene)
{
    const int numStacks = 20; 
    const int numSlices = 20;  
    const float radius = 1.0;  

    glRotatef(scene->spinAngle, 0.0, 1.0, 0.0);

     for (int i = 0; i < numStacks; ++i)
    {
        float lat0 = M_PI * (-0.5 + (float)i / numStacks);
        float lat1 = M_PI * (-0.5 + (float)(i + 1) / numStacks);
        float sinLat0 = sin(lat0);
        float cosLat0 = cos(lat0);
        float sinLat1 = sin(lat1);
        float cosLat1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);

        for (int j = 0; j <= numSlices; ++j)
        {
            float lon = 2 * M_PI * (float)j / numSlices;
            float sinLon = sin(lon);
            float cosLon = cos(lon);

            glColor3f(0.4, 0.4, 0.4);
            glVertex3f(radius * cosLat0 * cosLon, radius * cosLat0 * sinLon, radius * sinLat0);

            glColor3f(0.5, 0.5, 0.5);
            glVertex3f(radius * cosLat1 * cosLon, radius * cosLat1 * sinLon, radius * sinLat1);
        }

        glEnd();
    }
}
