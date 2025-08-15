#include <stdint.h>
#include <texture.h>
#include <vmm/vec2.h>

Texture *texture_create_mem(uint8_t *data, uint32_t x, uint32_t y) {
    Texture *t = malloc(sizeof(Texture));
    *t = {
        .x = x,
        .y = y
    };
    glGenTextures(1, &t->handle);
    glBindTexture(GL_TEXTURE_2D, t->handle);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    return t;
}

void texture_bind(Texture *texture) {
    glBindTexture(GL_TEXTURE_2D, texture->handle);
}

void texture_destroy(Texture *texture) {
    glDeleteTextures(1, &texture->handle);
    free(texture);
}

Atlas *atlas_create_mem(uint8_t *data, uint32_t x, uint32_t y, uint32_t spr_width, uint32_t spr_height) {
    Atlas *a = atlas_create_text(texture_create_mem(data, x, y), spr_width, spr_height);
    return a;
}

Atlas *atlas_create_text(Texture *texture, uint32_t spr_width, uint32_t spr_height) {
    Atlas *a = malloc(sizeof(Atlas));
    *a = {
        .texture = texture,
        .spr_width = spr_width,
        .spr_height = spr_height,
        .sprite_unit = vec2_div((Vector2){(float)spr_width, (float)spr_height}, (Vector2){(float).texture.x, (float).texture.y}),
        .pixel_unit = vec2_div((Vector2){1, 1}, (Vector2){(float).texture.x, (float).texture.y}),
    };
    return a;
}

void atlas_destroy(Atlas *atlas) {
    texture_destroy(atlas->texture);
    free(atlas);
}
