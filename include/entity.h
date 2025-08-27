#ifndef _ENTITY_H
#define _ENTITY_H

#include <mesh.h>
#include <vmm/vec3>

typedef struct _entity {
  Vec3 position, rotation, scale;
  Mesh *mesh;
} Entity;

#endif
