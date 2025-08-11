#ifndef _WINDOW_H
#define _WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <button.h>
#include <mouse.h>

typedef void (*func_window)();

typedef struct _window {
    GLFWwindow *window;

    func_window init, destroy, tick, update, render;

    Mouse mouse;
    Button keyboard_keys[GLFW_KEY_LAST];

    uint64_t last_second, frames, fps, last_frame, frame_delta, ticks, tps, tick_remainder;
} Window;

Window window_create(func_window init, func_window destroy, func_window tick, func_window update, func_window render);
void window_loop(Window window);

#endif