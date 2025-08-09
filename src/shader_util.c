#include <glad/glad.h>
#include <stdbool.h>
#include <stdlib.h>
#include <shader_base.h>
#include <file_util.h>

Shader create_shader(char * vert_path, char * frag_path) {
    int success;
    char infoLog[512];

    //vertex shader creation
    GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);
    const char * vert_txt = read_file(vert_path);
    if(!vert_txt) return 0;
    glShaderSource(vert_shader, 1, &vert_txt, NULL);
    glCompileShader(vert_shader);
    glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vert_shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
        printf("%s\n", infoLog);
        return 0;
    }
    
    //fragment shader creation
    GLuint frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    const char * frag_txt = read_file(frag_path);
    if(!frag_txt) return 0;
    glShaderSource(frag_shader, 1, &frag_txt, NULL);
    glCompileShader(frag_shader);
    glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(frag_shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
        printf("%s\n", infoLog);
        return 0;
    }
    free((char*)frag_txt);
    free((char*)vert_txt);
    // link shaders
    GLuint shader_program = glCreateProgram();
    glAttachShader(shader_program, vert_shader);
    glAttachShader(shader_program, frag_shader);
    glLinkProgram(shader_program);
    // check for linking errors
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
        printf("%s\n", infoLog);
        return 0;
    }
    glDeleteShader(vert_shader);
    glDeleteShader(frag_shader);
    return shader_program;
}

void set_uniform_int(Shader program, char * name, int value) {
    int loc = glGetUniformLocation(program, name);
    glUniform1i(loc, value);
}

void get_uniform_int(Shader program, char * name, int * param) {
    int loc = glGetUniformLocation(program, name);
    glGetUniformiv(program, loc, param);
}

void set_uniform_float(Shader program, char * name, float value) {
    int loc = glGetUniformLocation(program, name);
    glUniform1f(loc, value);
}

void get_uniform_float(Shader program, char * name, float * param) {
    int loc = glGetUniformLocation(program, name);
    glGetUniformfv(program, loc, param);
}