//
// Created by sajith on 6/1/21.
//

#include <emscripten.h>

EM_JS(void, call_alert,(int x),
{
    alert ( "Hello world! "+ x);
//    throw "all done";
});


int main()
{
    call_alert(10);

    return 0;
}