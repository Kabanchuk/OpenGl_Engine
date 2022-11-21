#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int g_windowSizeX = 640;
int g_windowSizeY = 480;

void glfwWindowsSizeCallback(GLFWwindow* window, int width, int height) {
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int main(void)
{
    setlocale(LC_ALL, "RUS");
    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "Ошибка инициализации glfw!";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "TANK-42", nullptr, nullptr);
    if (!window)
    {
        std::cout << "Не удалось создать окно" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(window, glfwWindowsSizeCallback);
    glfwSetKeyCallback(window, glfwKeyCallback);


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
	
	if (!gladLoadGL()){
		std::cout << "Не возможно загрузить GLAD!" << std::endl;
		return -1;
	}
    std::cout << "Render: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Версия OpenGL: " << glGetString(GL_VERSION) << std::endl;
	
	glClearColor(0, 0, 0, 1);
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}