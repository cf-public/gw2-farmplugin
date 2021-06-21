#include "IPage.h"
#include "Page2.h"

Page2::Page2() {
	createContent();
}

void Page2::draw() {
	std::vector<std::string>* s = c.getContent();
	ImGui::Text("Treasure Mushrooms");
	for (int i = 0; i < s->size(); i++) {
		ImGui::PushID(2 * i);
		ImGui::Text(s->at(i).c_str());
		ImGui::SameLine(40);
		ImGui::Checkbox(("#shroom"+std::to_string(i)).c_str(), c.getStatus(i));
		ImGui::PopID();
	}
}

void Page2::createContent() {
	std::vector<std::string> v = {"TD", "AB", "VB", "BF", "DM"};
	c = Content();
}