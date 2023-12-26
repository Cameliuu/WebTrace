#include <iostream>
#include <emscripten.h>
#include "App/app.h"

int main(int argc, char** argv) {


    App app = App();
    app.Start();
    return 0;
}
