#ifndef _MESH_H
#define _MESH_H

#include <stdlib.h>
#include <vmm/vec3.h>

typedef struct _mesh {
  Vec3 *vertices;
  size_t vert_size;
  Vec3 *indexes;
  size_t index_size;
  Vec3 *normals;
  size_t normals_size;
} Mesh;

#endif
