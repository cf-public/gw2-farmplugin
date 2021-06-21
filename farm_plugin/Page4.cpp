#include "IPage.h"
#include "Page4.h"

Page4::Page4() {
	createContent();
}

void Page4::draw() {
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

void Page4::createContent() {
	std::vector<std::string> v = { "Create Human with commoner background", 
		"Play Story", "Collect Key", "Remove Equipment", "Delete Character", "Profit"
	};
	c = Content(v);
}