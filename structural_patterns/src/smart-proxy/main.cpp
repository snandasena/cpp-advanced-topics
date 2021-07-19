//
// Created by sajith on 7/19/21.
//

#include "Bitmap.h"

int main()
{
    Bitmap *p = new Bitmap{"../../data/Smiley.txt"};
    p->Load();
    p->Display();

    return 0;
}