#include "IPage.h"
#include "Page2.h"

Page2::Page2() {
	createContent();
}

void Page2::draw() {
	std::vector<std::string>* s = c.getContent();
	for (int i = 0; i < s->size(); i++) {
		ImGui::PushID(2 * i);
		ImGui::Text(s->at(i).c_str());

		ImGui::PopID();
	}
}

void Page2::createContent() {
	std::vector<std::string> v = { "TODO: add drizzlewood content later" };
	c = Content();
}