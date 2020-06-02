#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char* vertexShaderSource = "";
const char* fragmentShaderSource = "";

int main() {
	if (glfwInit() == GLFW_FALSE) {
		std::cout << "Failed to create GLFW window" << std::endl;
		return EXIT_FAILURE;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif	// __APPLE__

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL",
										  nullptr, nullptr);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

}