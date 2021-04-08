#include <stdio.h>

#define GRAYSCALE

void set_pixel_data(int depth, void *p) {}

int main()
{
    struct pixel_gray
    {
        char m;
    } pg;

    struct pixel_color
    {
        char r;
        char g;
        char b;
    } pc;

    set_pixel_data(
#ifdef GRAYSCALE
            1, &pg
#else
            3, &pg
#endif
    );

    return (0);
}