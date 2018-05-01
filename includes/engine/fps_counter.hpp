#ifndef FPS_COUNTER_HPP
#define FPS_COUNTER_HPP

#include <iostream>

#include <GLFW/glfw3.h>

class FpsCounter {

private:

	double init_time, curr_time;
	int frames;

public:

	FpsCounter() {

		curr_time = 0.0;
		frames    = 0;

		init_time = glfwGetTime();
	}

	~FpsCounter() {}

	void update() {

		curr_time = glfwGetTime();
		frames++;
	}

	void count_fps() {
    
    	if(curr_time - init_time >= 1.0) {
	        printf("%.1f ms per frame | %d frames\n", 1000.0/double(frames), frames);

	        frames = 0;
	        init_time++;
	    }
	}
};

#endif