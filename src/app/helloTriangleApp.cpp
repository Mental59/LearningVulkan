#include "helloTriangleApp.hpp"

HelloTriangleApplication::~HelloTriangleApplication() {
	cleanup();
}

void HelloTriangleApplication::run() {
	initVulkan();
	mainLoop();
}

void HelloTriangleApplication::initVulkan() {

}

void HelloTriangleApplication::mainLoop() {

}

void HelloTriangleApplication::cleanup() {

}
