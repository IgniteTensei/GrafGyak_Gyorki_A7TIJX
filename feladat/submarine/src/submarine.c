#include "submarine.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_submarine(Submarine* submarine)
{
    load_model(&(submarine->sm_body), "assets/models/submarine.obj");

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
}

void set_submarine_lighting()
{

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

void update_submarine(Submarine* submarine)
{

}

void render_submarine(const Submarine* submarine)
{
    //set_submarine_material(&(submarine->material));
    render_sm_body(submarine);
}

void render_sm_body(const Submarine* submarine)
{
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    draw_model(&(submarine->sm_body));
    glPopMatrix();
}