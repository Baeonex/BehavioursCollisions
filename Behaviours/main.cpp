#include "BehavioursApp.h"

int main() {
	
	// allocation
	auto app = new BehavioursApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}