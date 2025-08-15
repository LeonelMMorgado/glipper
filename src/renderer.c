#include <renderer.h>

Renderer *renderer_init(Camera *camera,
                      Shader *shaders, size_t shaders_size, 
                      Texture *textures, size_t textures_size
                    )
{
    Renderer *r = calloc(1, sizeof(Renderer));
    *r = {
        .camera = camera,
        .shaders = shaders,
        .shaders_size = shaders_size,
        .textures  = textures,
        .textures_size = textures_size
    };
}
