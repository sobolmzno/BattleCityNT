#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int g_WindowSizeX = 640;//Window Sizes
int g_WindowSizeY = 480;//


//create func for size callback
void glfwWindowsSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    g_WindowSizeX = width;
    g_WindowSizeY = height;
    glViewport(0,0, g_WindowSizeX, g_WindowSizeY);
}
///////////////////////////////

//Create func for key putting callback
void glfwKeyCallback(GLFWwindow* pWindow, int key, int scanmode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}
///////////////////////////////////

int main(void)
{

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "glfwInit not successed" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pwindow = glfwCreateWindow(g_WindowSizeX, g_WindowSizeY, "BattleCItyNT", nullptr, nullptr);

    if (!pwindow)
    {
        std::cout << "pwindow failed" << std::endl;

        glfwTerminate();
        return -1;
    }


    glfwSetWindowSizeCallback(pwindow, glfwWindowsSizeCallback);//Register sizeCalllback
    glfwSetKeyCallback(pwindow, glfwKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pwindow);
	if(!gladLoadGL())
	{
			std::cout<<"Cant load GLAD"<<std::endl;
			return -1;
	}
	
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGl Version:" << glGetString(GL_VERSION) << std::endl;


	
	
	glClearColor(1, 1, 0,1);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pwindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pwindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}