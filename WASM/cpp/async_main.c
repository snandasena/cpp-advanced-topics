/**
 * To build and run with emscripten
 *
 * emcc async_main.c -o async_main.html
 *
 */

#include <emscripten.h>
#include <emscripten/html5.h>
#include <stdio.h>

// Our "main loop" function. This callback receives the current time as
// reported by the browser, and the user data we provide in the call to
// emscripten_request_animation_frame_loop().
EM_BOOL one_iter(double time, void *userData)
{
    // Can render to the screen here, etc.
    puts("one iteration");
    // Return true to keep the loop running.
    return EM_TRUE;
}

int main()
{
#ifdef __EMSCRIPTEN__
    // Receives a function to call and some user data to provide it.
  emscripten_request_animation_frame_loop(one_iter, 0);
#else
    while (1)
    {
        one_iter();
        // Delay to keep frame rate constant (using SDL).
        SDL_Delay(time_to_next_frame());
    }
#endif
}
