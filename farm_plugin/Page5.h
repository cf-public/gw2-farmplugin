#pragma once
#include "IPage.h"
#include <ctime>

class Page5 : public IPage {
public:
	Page5();
	void draw() override;
	void createContent();
private:
	int worldBossTime(int i, bool update);
	void generateBossTimes();

	tm* getTime();
	std::vector<tm> times;
	int cycle2h;
};