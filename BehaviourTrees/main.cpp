#include "BehaviourTreesApp.h"

int main() {
	
	// allocation
	auto app = new BehaviourTreesApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}