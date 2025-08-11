#include <window.h>
#include <time.h>

Window window_create(func_window init, func_window destroy, func_window tick, func_window update, func_window render) {
    Window window;
    window.init = init;
    window.destroy = destroy;
    window.tick = tick;
    window.update = update;
    window.render = render;
    
}

void window_loop(Window *window) {
    window->init();
    while(true) {
        window->tick();
        window->update();
        window->render();
    }
    window->destroy();
}