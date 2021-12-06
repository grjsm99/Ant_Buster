#include "techtree.h"
void techtree::setLeft(techtree* child) {
	left = child;
	child->setPrev(this);
}
void techtree::setRight(techtree* child) {
	right = child;
	child->setPrev(this);
}
void techtree::setMid(techtree* child) {
	mid = child;
	child->setPrev(this);
}
void techtree:: setPrev(techtree* parent) {
	prev = parent;
}