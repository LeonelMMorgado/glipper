#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <gl_settings.h>
#include <input.h>
#include <shader_base.h>

int main(void) {
    
    GLFWwindow *window = initGL("Hello World", false);
    if(!window) return -1;

    // build and compile our shader program
    // ------------------------------------
    Shader program = create_shader("shaders/vertex.glsl", "shaders/fragment.glsl");
    if(!program) {
        printf("Stopping execution after shader program error\n");
        return -1;
    }
    glUseProgram(program);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)) {
        // input
        //=
        processInput(window/*, program*/);
        
        // render
        //=
        glClearColor(0.25f, 0.25f, 0.25f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteProgram(program);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}