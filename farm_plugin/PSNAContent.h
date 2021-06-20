#pragma once
#include "Content.h"
#include <Windows.h>

class PSNAContent : public Content {
	/*
	Content implementation for psna
	*/
public:
	PSNAContent() {};
	PSNAContent(std::string s);
	std::string getContent();
	std::string getWPs();
	void copyToClipboard();
private:
	void computeWPs();
	std::string WPs;
	int getWeekday();
	std::string content;
};