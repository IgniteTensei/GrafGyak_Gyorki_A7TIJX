#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "camera.h"
#include "texture.h"
#include "scene.h"
#include <stdio.h>

#include <obj/model.h>

typedef struct Submarine
{
    Material material;
    Model sm_body;

} Submarine;

void init_submarine(Submarine* submarine);

void set_submarine_lighting();

void set_submarine_material(const Material* material);

void update_submarine(Submarine* submarine);

void render_submarine(const Submarine* submarine);

void render_sm_body(const Submarine* submarine);

#endif /* SUBMARINE_H */