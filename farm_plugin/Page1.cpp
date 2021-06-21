#include "IPage.h"
#include "Page1.h"

Page1::Page1() {
	createContent();
}

void Page1::draw() {
	std::vector<std::string>* s = c.getContent();

	for (int i = 0; i < s->size(); i++) {
		ImGui::PushID(2 * i);
		ImGui::Text(s->at(i).c_str()); ImGui::SameLine(200); ImGui::Checkbox(std::string("").c_str(), c.getStatus(i));

		//// TODO: add button if requested by the content
		//ImGui::SameLine(200); 
		//if (ImGui::Button("", )
		ImGui::PopID();
	}

	// PSNA and button for wps
	ImGui::Text(wps.getContent().c_str()); ImGui::SameLine(200);
	if (ImGui::Button("psna wps")) {
		// copy wps to 
		wps.copyToClipboard();
	}
}

void Page1::createContent() {
	std::vector<std::string> v = { "Exchanges", "drizzlewood",  "psna/faction provisioner","Bjora", "Crafting", "Krait", "Khan Ur", "Home", "Southsun", "GH" }; // removed , from here
	c = Content(v);

	wps = PSNAContent("psna wps");
}