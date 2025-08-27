#ifndef _ENTITY_H
#define _ENTITY_H

#include <mesh.h>
#include <vmm/vec3.h>
#include <vmm/mat4.h>

typedef struct _entity {
    Vector3 position, rotation, scale;
    Mat4 model;
    Mesh *mesh;
} Entity;

Entity *init_entity(Vector3 pos, Vector3 rot, Vector3 scale, Mesh *mesh);
void destroy_entity();

#endif
