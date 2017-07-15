#include <input_manager.hpp>

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

void InputManager::poll() {
	glfwPollEvents();
}