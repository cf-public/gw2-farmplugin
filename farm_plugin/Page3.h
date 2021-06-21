#pragma once
#pragma once
#include "IPage.h"

class Page3 : public IPage {
public:
	Page3();
	void draw() override;
	void createContent();
};