#ifndef _RENDERER_H
#define _RENDERER_H

#include <shader.h>
#include <camera.h>

typedef struct _renderer {
    Shader program;
    Camera camera;
} Renderer;

#endif