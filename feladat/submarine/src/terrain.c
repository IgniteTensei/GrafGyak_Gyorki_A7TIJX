#include "terrain.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_terrain(Terrain* terrain)
{
    load_model(&(terrain->plane), "assets/models/plane.obj");
    terrain->plane_texture = load_texture("assets/textures/ocean.jpg"); 

    load_model(&(terrain->rock), "assets/models/Rock.obj");
    terrain->rock_texture = load_texture("assets/textures/rock.jpg");

    terrain->material.ambient.red = 1.0;
    terrain->material.ambient.green = 1.0;
    terrain->material.ambient.blue = 1.0;

    terrain->material.diffuse.red = 0.7;
    terrain->material.diffuse.green = 0.7;
    terrain->material.diffuse.blue = 0.7;

    terrain->material.specular.red = 0.7;
    terrain->material.specular.green = 0.7;
    terrain->material.specular.blue = 0.7;

    terrain->material.shininess = 0.8;
}

void set_terrain_lighting()
{

}

void set_terrain_material(const Material* material)
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
}

void update_terrain(Terrain* terrain)
{

}

void render_terrain(const Terrain* terrain)
{
    set_terrain_material(&(terrain->material));
    render_plane(terrain);
    render_rock(terrain);
}

void render_plane(const Terrain* terrain)
{
    glPushMatrix();

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, terrain->plane_texture);

    draw_model(&(terrain->plane));
    
    glPopMatrix();
}

void render_rock(const Terrain* terrain)
{
    glPushMatrix();
    
    glBindTexture(GL_TEXTURE_2D, terrain->rock_texture);

    glTranslatef(0.0f, 10.0f, 1.0f);

    draw_model(&(terrain->rock));

    glPopMatrix();
}