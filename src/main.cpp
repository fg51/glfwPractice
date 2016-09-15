/*
 *
 * clang -std=c++11 -Wall main.cpp -lglfw
 */


#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <string>


static GLFWwindow *aWindow;
static const int kWidth  = 640;
static const int kHeight = 480;
static const std::string kTitle = "Hello, OpenGL";


int main(void) {
    if (!glfwInit()){
        std::cerr << "glfwInit failed." << std::endl;
        exit(EXIT_FAILURE);
    }
    aWindow = glfwCreateWindow(kWidth, kHeight, kTitle.c_str(), nullptr, nullptr);
    if(!aWindow) {
        std::cerr << "glfwCreateWindow failed." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(aWindow);
    std::cout << glfwGetVersionString() << std::endl;
    glClearColor(1, 1, 1, 1); // RGBA

    while (!glfwWindowShouldClose(aWindow)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(aWindow);
        glfwPollEvents();
    }
    glfwTerminate();


    return EXIT_SUCCESS;
}
