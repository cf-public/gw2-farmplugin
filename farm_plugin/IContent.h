#pragma once

#include <string>
#include <vector>
class IContent {
public:
	// contentText i
	std::string getContentAt(int i) {};
	// contentCheckbox i
	bool* getCheckbox(int i) {};
	void buttonPressed(int i);
	
protected:
	std::vector<std::string> content;
	std::vector<bool> checkboxes;
	std::vector<
};