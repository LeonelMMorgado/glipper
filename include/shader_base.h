#ifndef _SHADER_BASE_H
#define _SHADER_BASE_H
#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>

typedef GLuint Shader;

Shader create_shader(char * vert_path, char * frag_path);
void set_uniform_int(Shader program, char * name, int value);
void get_uniform_int(Shader program, char * name, int * param);
void set_uniform_float(Shader program, char * name, float value);
void get_uniform_float(Shader program, char * name, float * param);

#endif