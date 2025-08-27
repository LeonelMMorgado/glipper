#include <entity.h>

Entity *init_entity(Vector3 pos, Vector3 rot, Vector3 scale, Mesh *mesh) {
    Entity *ent = calloc(1, sizeof(Entity));
    ent->model = mat4_make_model(pos, rot, scale);
    ent->position = pos;
    ent->rotation = rot;
    ent->scale = scale;
    if(mesh) ent->mesh = mesh;
    return ent;
}

void destroy_entity() {

}
