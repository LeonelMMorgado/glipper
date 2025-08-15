#ifndef _RENDERER_H
#define _RENDERER_H

#include <shader.h>
#include <camera.h>
#include <vmm/vec4.h>
#include <vbo.h>
#include <vao.h>

typedef struct _renderer {
    Shader program;
    Shader **shaders; size_t shaders_size;
    Texture **textures; size_t textures_size;
    Camera **cameras; size_t cameras_size;
    Vector4 clear_color;
    VBO vbo, ibo;
    VAO vao;
} Renderer;

Renderer *renderer_init(Camera *camera,
                      Shader *shaders, size_t shaders_size, 
                      Texture *textures, size_t textures_size
                    );
void renderer_set_camera(); //TODO: rethink
void renderer_destroy(Renderer *renderer);

#endif
