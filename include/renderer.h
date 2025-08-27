#ifndef _RENDERER_H
#define _RENDERER_H

#include <shader.h>
#include <camera.h>
#include <texture.h>
#include <vmm/vec4.h>
#include <vmm/mat4.h>
#include <color.h>
#include <vbo.h>
#include <vao.h>

typedef struct _renderer {
    Shader *shader;
    Camera *camera;
    Vector4 clear_color;
    VBO vbo, ibo;
    VAO vao;
} Renderer;

Renderer *renderer_init(Camera *camera,
                        Shader *shader,
                        Vector4 clear_color);
void renderer_set_camera(Renderer *renderer, Camera *camera);
void renderer_set_shader(Renderer *renderer, Shader *shader);
void renderer_quad_color(Renderer *renderer, ColorRGBA color, Mat4 model);
void renderer_quad_texture(Renderer *renderer, Texture *texture, ColorRGBA color, Mat4 model);
void renderer_destroy(Renderer *renderer);

#endif
