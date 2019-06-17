#include "BallCollisionApp.h"
#include <random>
#include <time.h>
int main() {

	srand((unsigned int)time(NULL));
	// allocation
	auto app = new BallCollisionApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}