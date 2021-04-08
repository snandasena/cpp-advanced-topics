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


#ifdef GRAYSCALE
    set_pixel_data(1, &pg);
#else
    set_pixel_data(4, &pg);
#endif

    return (0);
}