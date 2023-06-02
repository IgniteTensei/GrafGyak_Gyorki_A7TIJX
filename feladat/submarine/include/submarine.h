#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "camera.h"
#include "texture.h"
#include "scene.h"
#include <stdio.h>

#include "utils.h"

#include <stdbool.h>
#include <obj/model.h>

typedef struct Submarine
{
    Material material;

    Model sm_body;
    GLuint sm_body_texture;

    vec3 submarine_position;
    vec3 submarine_rotation;
    vec3 submarine_speed;

} Submarine;

void init_submarine(Submarine* submarine);

void set_submarine(const Submarine* submarine);

void set_submarine_lighting();

void set_submarine_material(const Material* material);

void update_submarine(Submarine* submarine, double time);

void render_submarine(const Submarine* submarine);

void render_sm_body(const Submarine* submarine);


void rotate_submarine(Submarine* submarine, double horizontal, double vertical);

void set_submarine_speed(Submarine* submarine, double speed);

#endif /* SUBMARINE_H */