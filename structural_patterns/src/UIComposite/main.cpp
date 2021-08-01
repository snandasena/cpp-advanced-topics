//
// Created by sajith on 7/29/21.
//

#include <iostream>
#include "Frame.h"
#include "Button.h"


void Display(Widget *pWidget)
{
    pWidget->Paint();
}


int main()
{
    Frame mainWindow{};
    Button btnOk{};
    mainWindow.Add(&btnOk);
    mainWindow.Paint();

    Frame childWindow{};
    Button btnFind{};
    childWindow.Add(&btnFind);

    mainWindow.Add(&childWindow);
    mainWindow.Paint();

//    std::cout << "Changing visibility\n\n";
//    mainWindow.SetVisibility(false);
//    mainWindow.Paint();

    Display(&btnOk);
    Display(&mainWindow);
    return 0;
}