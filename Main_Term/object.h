#pragma once
#include "transform.h"
class Object {
protected:
	Transform transform;
public:
	Transform* GetTransfromPtr() { return &transform; };
};
