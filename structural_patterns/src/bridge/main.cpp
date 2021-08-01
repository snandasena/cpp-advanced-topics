//
// Created by sajith on 8/1/21.
//

#include <simple2d.h>

void DrawCircle()
{
    S2D_DrawCircle(100, 100, 200, 100, 1, 1, 0, 1);
}

int main(int args, char *arvs[])
{

    S2D_Window *pWind = S2D_CreateWindow("MainWindow", 800, 600, nullptr, &DrawCircle,
                                         S2D_RESIZABLE);
    S2D_Show(pWind);
    S2D_FreeWindow(pWind);

    return 0;
}