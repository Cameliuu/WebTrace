#include <iostream>
#include <emscripten.h>
#include "App/app.h"

int main(int argc, char** argv) {

    std::cout << "Ba dc nu mergi frate" << std::endl;
    App app = App();
    app.Start();
    return 0;
}
