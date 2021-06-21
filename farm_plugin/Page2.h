#pragma once
#pragma once
#include "IPage.h"

class Page2 : public IPage {
public:
	Page2();
	void draw() override;
	void createContent();
protected:
	Content moreContent;
};