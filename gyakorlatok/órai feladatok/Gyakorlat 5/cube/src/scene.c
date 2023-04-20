#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "assets/models/cube.obj");
    scene->texture_id1 = load_rgba_texture("assets/textures/solar.tif"); 

    load_model(&(scene->monkey), "assets/models/Pale_Monkey.obj");
    scene->texture_id2 = load_rgba_texture("assets/textures/gore.tif");
    

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 0.7;
    scene->material.diffuse.green = 0.7;
    scene->material.diffuse.blue = 0.7;

    scene->material.specular.red = 0.7;
    scene->material.specular.green = 0.7;
    scene->material.specular.blue = 0.7;

    scene->material.shininess = 0.8;

    scene->rotation = 0.0f;

    scene->cube_position.x = 0.0f;
    scene->cube_position.y = 0.0f;
    scene->cube_position.z = 0.0f;
    
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
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

void update_scene(Scene* scene)
{   
    scene->rotation += 0.2f;
}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    draw_origin();
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void render_cube(const Scene* scene)
{   
    glPushMatrix();
    glTranslatef(scene->cube_position.x, scene->cube_position.y, scene->cube_position.z);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id1);
    draw_model(&(scene->cube));
    glPopMatrix();
}

void render_monkey(const Scene* scene)
{
    //valszeg érdemes lenne külön headert (structot és saját függvényeket) meg c fájlt csinálni ezeknek itt a sceneben pedig összefűzni
    glPushMatrix();
    glTranslatef(2.0f, 3.0f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(scene->rotation, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id2);
    draw_model(&(scene->monkey));
    glPopMatrix();
}

void draw_around_model(Scene* scene, Model* model)
{

    float max_x = 0, max_y = 0, max_z = 0;
    float min_x = 0, min_y = 0, min_z = 0;

    for (int i = 0; i < model->n_vertices; i++) {
        float x = model->vertices[i].x;
        float y = model->vertices[i].y;
        float z = model->vertices[i].z;

        if (x > max_x)
        {
            max_x = x;
        }

        if (z > max_z)
        {
            max_z = z;
        }

        if (x < min_x)
        {
            min_x = x;
        }

        if (y < min_y)
        {
            min_y = y;
        }

        if (z < min_z)
        {
            min_z = z;
        }
    }

    max_x -= min_x;
    max_y -= min_y;
    max_z -= min_z;

    float max_extents[] = {max_x, max_y, max_z};

    float max_extent = 0;

    for (int i = 0; i < 3; i++)
    {
        if (max_extent < max_extents[i])
        {
            max_extent = max_extents[i];
        }
    }

    glTranslatef(2.0f, 3.0f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(scene->rotation, 0.0f, 1.0f, 0.0f);

    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            glVertex3f(0 - (max_extent/2), j*0.25*max_extent - (max_extent/2), i*0.25*max_extent - (max_extent/2));
            glVertex3f(max_extent - (max_extent/2), j*0.25*max_extent - (max_extent/2), i*0.25*max_extent - (max_extent/2));
        }   
    }

    glColor3f(0, 1, 0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            glVertex3f(j*0.25*max_extent - (max_extent/2), 0 - (max_extent/2), i*0.25*max_extent - (max_extent/2));
            glVertex3f(j*0.25*max_extent - (max_extent/2), max_extent - (max_extent/2), i*0.25*max_extent - (max_extent/2));        
        }   
    }


    glColor3f(0, 0, 1);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            glVertex3f(j*0.25*max_extent - (max_extent/2), i*0.25*max_extent - (max_extent/2), 0 - (max_extent/2));
            glVertex3f(j*0.25*max_extent - (max_extent/2), i*0.25*max_extent - (max_extent/2), max_extent - (max_extent/2));
        }   
    }


    glEnd();
    
}

void set_cube_speed_x(Scene* scene, float speed)
{
    scene->cube_position.x += speed * 0.4f;
}

void set_cube_speed_y(Scene* scene, float speed)
{
    scene->cube_position.y += speed * 0.4f;
}

void set_cube_speed_z(Scene* scene, float speed)
{
    scene->cube_position.z += speed * 0.4f;
}




