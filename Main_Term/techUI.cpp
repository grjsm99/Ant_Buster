#include "techUI.h"
techUI::techUI() {

	for(int i=0; i<5; i++) myModel[i] = &GloVar::model_towerinfo[i];
};

void techUI::InitTexture(techtree* tech) {
	techtree* left = tech->getLeft();
	techtree* mid = tech->getMid();
	techtree* right = tech->getRight();
	techtree* prev = tech->getPrev();

	texture[0] = tech->getInfoTexture();

	flag[0] = true;
	for (int i = 1; i < 5; i++) flag[i] = false;
	
	if (left != NULL) {
		texture[1] = left->getInfoTexture();
		flag[1] = true;
	}
	if (mid != NULL) {
		texture[2] = mid->getInfoTexture();
		flag[2] = true;
	}
	if (right != NULL) {
		texture[3] = right->getInfoTexture();
		flag[3] = true;
	}
	if (prev != NULL) {
		texture[4] = prev->getInfoTexture();
		flag[4] = true;
	}
};

void techUI::Draw() {
	for (int i = 0; i < 5; i++) {
		if(flag[i]) myModel[i]->Draw(*texture[i]);
	}
};