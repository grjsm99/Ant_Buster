#pragma once
#include <gl/glew.h> 

#include <vector>
#include <iostream>

#include "model_3d.h"
#include "model_maker.h"
#include "state.h"

class GLManager {
	
	std::vector<State*> statelist;
	int width;
	int height;

public:
	GLManager(int, int, int, char**);
	
	void chstate(State*);
	void mainLoop();
	void pushState(State*);
};