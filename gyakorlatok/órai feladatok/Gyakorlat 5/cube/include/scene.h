#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include <stdio.h>

#include <obj/model.h>

typedef struct Scene
{
    Model monkey;
    Model cube;
    Material material;
    GLuint texture_id1;
    GLuint texture_id2;
    float rotation;
    float max_extent;
    vec3 cube_position;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void render_cube(const Scene* scene);

void render_monkey(const Scene* scene);

void draw_around_model(Scene* scene, Model* model);

void set_cube_speed_x(Scene* scene, float speed);

void set_cube_speed_y(Scene* scene, float speed);

void set_cube_speed_z(Scene* scene, float speed);

#endif /* SCENE_H */
