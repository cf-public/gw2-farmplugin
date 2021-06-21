#pragma once
#include "IPage.h"

class Page4 : public IPage {
public:
	Page4();
	void draw() override;
	void createContent();
};