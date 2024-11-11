#pragma once

class HelloTriangleApplication {
public:
	HelloTriangleApplication() = default;
	~HelloTriangleApplication();

	void run();

private:
	void initVulkan();

	void mainLoop();

	void cleanup();
};
