#pragma once
#include "transform.h"
class Object {
protected:
	Transform transfrom;
public:
	Transform* GetTransfromPtr() { return &transfrom; };
};
