#ifndef TERRAIN_H
#define TERRAIN_H

#include "camera.h"
#include "texture.h"
#include "scene.h"
#include <stdio.h>

#include <obj/model.h>

typedef struct Terrain
{
    Material material;

    Model plane;
    GLuint plane_texture;

    Model rock;
    GLuint rock_texture;

} Terrain;

void init_terrain(Terrain* terrain);

void set_terrain_lighting();

void set_terrain_material(const Material* material);

void update_terrain(Terrain* terrain);

void render_terrain(const Terrain* terrain);

void render_plane(const Terrain* terrain);

void render_rock(const Terrain* terrain);

#endif /* TERRAIN_H */