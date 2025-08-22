#include <renderer.h>

Renderer *renderer_init(Camera *camera,
                        Shader *shader,
                        Vector4 clear_color
                    )
{
    Renderer *r = calloc(1, sizeof(Renderer));
    *r = {
        .camera = camera,
        .shader = shader,
        .clear_color = clear_color
    };

    r->vao = vao_create();
    r->vbo = vbo_create(GL_ARRAY_BUFFER, true);
    r->ibo = vbo_create(GL_ELEMENT_ARRAY_BUFFER, true);
    return r;
}

void renderer_set_camera(Renderer *renderer, Camera *camera) {
    renderer->camera = camera;
}

void renderer_set_shader(Renderer *renderer, Shader *shader) {
    renderer->shader = shader;
}

void renderer_destroy(Renderer *renderer) {
    //FIXME: user should call destroy on camera and shader?
    vao_delete(renderer->vao);
    vbo_delete(renderer->vbo);
    vbo_delete(renderer->ibo);
    free(renderer);
}
