#include <controls.hpp>

// STATIC DEFINITIONS.
float Controls::AWSD_SPEED = AWSD_LOWER_LIMIT;

Controls::Controls(Camera *camera, GLFWwindow* window) 
{
	this->camera = camera;
	this->window = window;

	this->mouseRot_speed = 0.0018f;
	this->horizontal_angle = 3.14f;
	this->vertical_angle = 0.0f;

	// GLFW input settings.
	//glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  // Hide the mouse and enable unlimited mouvement
	glfwGetWindowSize(window, &this->width, &this->height);
	glfwSetKeyCallback(this->window, key_callback);
	glfwSetScrollCallback(this->window, scroll_callback);
}

Controls::~Controls() 
{
}

void Controls::update() 
{
	static double last_time = glfwGetTime();

	double current_time = glfwGetTime();
	float delta = float(current_time - last_time); 

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	//std::cout << xpos << " " << ypos << std::endl;
	// Reset mouse position for next frame
	glfwSetCursorPos(window, width/2, height/2);

	// Compute new orientation
	horizontal_angle += mouseRot_speed * float(width/2 - xpos );
	vertical_angle   += mouseRot_speed * float(height/2 - ypos );

	// Limit vertical rotation.
	if(vertical_angle > ROT_LIMIT) 
		vertical_angle = ROT_LIMIT;
	else if(vertical_angle < -ROT_LIMIT)
		vertical_angle = -ROT_LIMIT;

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
	glm::vec3 curr_pos = camera->get_pos();
	glm::vec3 up = glm::cross(right, direction);

	// poll real-time inputs.
	float fov = camera->get_fov();
	bool f = false;
	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) 
	{
		curr_pos += direction * delta * Controls::AWSD_SPEED;
		f =true;
	}
	// Move backward
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) 
	{
		curr_pos -= direction * delta * Controls::AWSD_SPEED;
		f =true;
	}
	// Strafe right
	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) 
	{
		curr_pos += right * delta * Controls::AWSD_SPEED;
		f =true;
	}
	// Strafe left
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) 
	{
		curr_pos -= right * delta * Controls::AWSD_SPEED;
		f =true;
	}
	if(glfwGetKey(window, GLFW_KEY_KP_ADD) == GLFW_PRESS) 
	{
		f =true;
 		fov += 0.01f;
	}	
	if(glfwGetKey(window, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS) 
	{
		f =true;
		fov -= 0.01f;
	}

	//std::cerr << curr_pos.x <<  " " << curr_pos.y << " " << curr_pos.z << std::endl;

	camera->set_fov(fov);
	camera->set_lookat(curr_pos, curr_pos + direction, up);

	//if(f) std::cout << curr_pos.x << " " << curr_pos.y << " " << curr_pos.z << std::endl;
		//std::cerr << key_speed << std::endl;
	last_time = current_time;
}