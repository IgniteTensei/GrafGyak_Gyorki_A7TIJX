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

} Terrain;

void init_terrain(Terrain* terrain);

void set_terrain_lighting();

void set_terrain_material(const Material* material);

void update_terrain(Terrain* terrain);

void render_terrain(const Terrain* terrain);

void render_plane(const Terrain* terrain);

#endif /* TERRAIN_H */