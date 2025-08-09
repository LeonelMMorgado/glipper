#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stdbool.h>
#include <gl_settings.h>

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

GLFWwindow *initGL(char *window_name, bool invisible) {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();

    if(invisible)
        glfwInitHint(GLFW_TRANSPARENT_FRAMEBUFFER, GL_TRUE);
    
    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        printf("Failed to create GLFW window");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if(invisible)
        glfwSetWindowAttrib(window, GLFW_DECORATED, GL_TRUE);
    
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD");
        glfwTerminate();
        return NULL;
    }
    return window;
}