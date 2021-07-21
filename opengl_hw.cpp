#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

float g_red_color = 0.3f;
float g_green_color = 0.3f;
float g_blue_color = 0.3f;

#define COLOR_CHANGE_ITERATION 0.01f

// Function prototypes
void key_callback(GLFWwindow *window, int key, int scancode, int action,
		int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop
int main(int argc, char **argv) {
	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr,
			nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	// Define the viewport dimensions
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	// Game loop
	while (!glfwWindowShouldClose(window)) {
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(g_red_color, g_green_color, g_blue_color, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}

	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow *window, int key, int scancode, int action,
		int mode) {
	//81 - q
	//87 - a

	std::cout << key << "|" << action << "|" << mode << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action == GLFW_PRESS || action == GLFW_REPEAT)
		switch (key) {
		//81 - q
		case 81:
			g_red_color -= COLOR_CHANGE_ITERATION;
			if (g_red_color < 0)
				g_red_color = 0.f;
			break;
			//65 - a
		case 65:
			g_red_color += COLOR_CHANGE_ITERATION;
			if (g_red_color > 1.f)
				g_red_color = 1.f;
			break;
			//87 - w
		case 87:
			g_green_color -= COLOR_CHANGE_ITERATION;
			if (g_green_color < 0)
				g_green_color = 0.f;
			break;
			//83 - s
		case 83:
			g_green_color += COLOR_CHANGE_ITERATION;
			if (g_green_color > 1.f)
				g_green_color = 1.f;
			break;
			//69 - e
		case 69:
			g_blue_color -= COLOR_CHANGE_ITERATION;
			if (g_blue_color < 0)
				g_blue_color = 0.f;
			break;
			//68 - d
		case 68:
			g_blue_color += COLOR_CHANGE_ITERATION;
			if (g_blue_color > 1.f)
				g_blue_color = 1.f;
			break;
			//80 - p
		case 80:
			std::cout << "RGB: " << g_red_color << "|" << g_green_color << "|"
					<< g_blue_color << std::endl;
			break;
		}

	// Initialize GLFW
	glfwInit();
	// Setup GLFW
	// Minumum required version of OpenGL.
	// major
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//	minor
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Setup profile to create context for
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Resize window off
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}
