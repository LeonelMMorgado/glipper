#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <stdint.h>
#include <GLFW/glfw3.h>
#include <vmm/vec2.h>

typedef struct _texture {
    GLuint handle;
    uint32_t x, y;
    Vector2 uv_unit;
} Texture;

Texture *texture_create_mem(uint8_t *data);
Texture *texture_create_path(const char *path);
void texture_bind(Texture texture);
void texture_destroy(Texture texture);

typedef struct _atlas {
    Texture texture;
    uint16_t spr_width, spr_height;
    Vector2 sprite_unit, pixel_unit;
} Atlas;

Atlas *atlas_create_text(Texture texture, uint16_t spr_width, uint16_t spr_height);
Atlas *atlas_create_mem(uint8_t *data, uint16_t spr_width, uint16_t spr_height);
Atlas *atlas_create_path(const char *path, uint16_t spr_width, uint16_t spr_height);
void atlas_destroy(Atlas atlas);

#endif