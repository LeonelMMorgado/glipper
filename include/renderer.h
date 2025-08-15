#ifndef _RENDERER_H
#define _RENDERER_H

#include <shader.h>
#include <camera.h>

typedef struct _renderer {
    Shader program;
    //Shader [] size_t
    Camera camera;
    //Texture [] size_t
} Renderer;

Shader *renderer_init(); //TODO: textures

#endif