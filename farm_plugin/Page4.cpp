#include "IPage.h"
#include "Page3.h"

Page3::Page3() {
	createContent();
}

void Page3::draw() {
	std::vector<std::string>* s = c.getContent();
	for (int i = 0; i < s->size(); i++) {
		ImGui::PushID(2 * i);
		ImGui::Text(s->at(i).c_str());

		//// TODO: add button if requested by the content
		//ImGui::SameLine(200); 
		//if (ImGui::Button("", )
		ImGui::PopID();
	}
}

void Page3::createContent() {
	std::vector<std::string> v = { "Create Human with commoner background", 
		"Play Story", "Collect Key", "Remove Equipment", "Delete Character", "Profit"
	};
	c = Content(v);
}