#include <input_manager.hpp>

InputManager::InputManager(Camera* camera, GLFWwindow* window) {

	this->camera = camera;
	this->window = window;

	this->key_speed = 20.0f;
	this->mouse_speed = 0.1f;
	this->horizontal_angle = 3.14f;
	this->vertical_angle = 0.0f;

	//glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  // Hide the mouse and enable unlimited mouvement

}

InputManager::~InputManager() {

}

void InputManager::update() {
	
	static double last_time = glfwGetTime();

	double current_time = glfwGetTime();
	float delta = (float) current_time - last_time; 

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	//std::cout << xpos << " " << ypos << std::endl;
	// Reset mouse position for next frame
	//glfwSetCursorPos(window, 1024/2, 768/2);

	// Compute new orientation
	horizontal_angle += mouse_speed * float(1024/2 - xpos );
	vertical_angle   += mouse_speed * float( 768/2 - ypos );

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		glm::cos(vertical_angle) * glm::sin(horizontal_angle), 
		glm::sin(vertical_angle),
		glm::cos(vertical_angle) * glm::cos(horizontal_angle)
	);
	
	// Right vector
	glm::vec3 right = glm::vec3(
		glm::sin(horizontal_angle - 3.14f/2.0f), 
		0,
		glm::cos(horizontal_angle - 3.14f/2.0f)
	);
	
	// Up vector
	glm::vec3 up = glm::cross( right, direction );

	glm::vec3 curr_pos = camera->get_pos();

	if (glfwGetKey(window, GLFW_KEY_W ) == GLFW_PRESS) {
		curr_pos += direction * delta * key_speed;
	}
	// Move backward
	if (glfwGetKey(window, GLFW_KEY_S ) == GLFW_PRESS) {
		curr_pos -= direction * delta * key_speed;
	}
	// Strafe right
	if (glfwGetKey(window, GLFW_KEY_D ) == GLFW_PRESS) {
		curr_pos += right * delta * key_speed;
	}
	// Strafe left
	if (glfwGetKey(window, GLFW_KEY_A ) == GLFW_PRESS) {
		curr_pos -= right * delta * key_speed;
	}

	camera->set_lookat(curr_pos, curr_pos + direction, up);

	last_time = current_time;
}