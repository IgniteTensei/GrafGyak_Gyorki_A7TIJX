#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

typedef struct Scene
{
    float spinAngle;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene, float angle);

/**
 * Update the scene.
 */
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void draw_triangle();

void draw_sphere();

#endif /* SCENE_H */
