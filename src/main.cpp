#include <iostream>
#include "glfw3.h"
#include "vulkan/vulkan_core.h"

static constexpr int WINDOW_WIDTH = 1280;
static constexpr int WINDOW_HEIGHT = 720;

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Vulkan", nullptr, nullptr);

	if (!window) {
		std::cout << "ERROR: Failed to create window\n";
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCallback);

	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::cout << extensionCount << " extensions supported\n";

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
		return;
	}
}
