//
// Created by sajith on 7/18/21.
//

#include "Bitmap.h"
#include "BitmapProxy.h"

int main()
{
//    Image *p = new Bitmap{"../../data/Smiley.txt"};
//    p->Load();
//    p->Display();

//    delete p;

    Image *p = new BitmapProxy{"../../data/Smiley.txt"};

    p->Load();
//    p->Display();

    delete p;
    return 0;
}