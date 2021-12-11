#include "attack.h"

void Attack::SetTarget(Ant* _target) {
	target = _target;
}

void Attack::SetPoison(std::pair<float, float> _poison) {
	poison = _poison;
}
void Attack::SetSnow(std::pair<float, float> _snow) {
	snow = _snow;
}