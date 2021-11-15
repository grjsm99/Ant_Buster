#pragma once
#include "transform.h"
#include "model_3d.h"
class Object {
	Transform trans;
public:
	Transform GetTrans() { return trans; };
};
