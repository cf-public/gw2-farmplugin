#pragma once
#include "IPage.h"

class Page1 : public IPage {
public:
	Page1();
	void draw() override;
	void createContent();
protected:
	PSNAContent wps;
};