#include "submarine.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_submarine(Submarine* submarine)
{
    load_model(&(submarine->sm_body), "assets/models/submarine.obj");
    submarine->sm_body_texture = load_texture("assets/textures/body.png"); 

    submarine->material.ambient.red = 1.0;
    submarine->material.ambient.green = 1.0;
    submarine->material.ambient.blue = 1.0;

    submarine->material.diffuse.red = 0.7;
    submarine->material.diffuse.green = 0.7;
    submarine->material.diffuse.blue = 0.7;

    submarine->material.specular.red = 0.7;
    submarine->material.specular.green = 0.7;
    submarine->material.specular.blue = 0.7;

    submarine->material.shininess = 0.8;

    submarine->submarine_position.x = 0.0;
    submarine->submarine_position.y = 4.0;
    submarine->submarine_position.z = 0.0;

    submarine->submarine_rotation.x = 0.0;
    submarine->submarine_rotation.y = 0.0;
    submarine->submarine_rotation.z = 0.0;

    submarine->submarine_speed.x = 0.0;
    submarine->submarine_speed.y = 0.0;
    submarine->submarine_speed.z = 0.0;
}

void set_submarine(const Submarine* submarine)
{
    //glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    //glRotatef((submarine->submarine_rotation.z), 0, 0, 1.0);
    //glTranslatef(submarine->submarine_position.x, submarine->submarine_position.y, submarine->submarine_position.z);
}

void set_submarine_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 0.8, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.2f, 1.0f };
    float position[] = { 0.0f, 0.0f, 4.0f, 1.0f };

    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT1, GL_POSITION, position);

    GLfloat spotDirection[] = { 0.0f, 1.0f, -0.7f };  
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0f);  
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.0f);  

    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.1f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.01f);
    //glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.01f);
}

void set_submarine_material(const Material* material)
{
    
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_submarine(Submarine* submarine, double time)
{
    //double angle;
    //angle = degree_to_radian(submarine->submarine_rotation.z);

    //submarine->submarine_position.x += submarine->submarine_speed.x * time;
    //submarine->submarine_position.y += sin(angle) * submarine->submarine_speed.y * time;
}

void render_submarine(const Submarine* submarine)
{
    set_submarine(submarine);
    set_submarine_lighting();
    set_submarine_material(&(submarine->material));
    render_sm_body(submarine);
}

void render_sm_body(const Submarine* submarine)
{
    glPushMatrix();

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 3.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, submarine->sm_body_texture);
    draw_model(&(submarine->sm_body));

    glPopMatrix();
}

void set_submarine_speed(Submarine* submarine, double speed)
{
    //submarine->submarine_position.x += speed * 0.1;
}