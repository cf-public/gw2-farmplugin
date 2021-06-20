#include "FarmWindow.h"
#include "Content.h"
#include "PSNAContent.h"

#include <vector>
#include <mutex>
#include <array>
#include <Windows.h>


#include "imgui/imgui_internal.h"

FarmWindow::FarmWindow() {
	visible = false;
	altActive = false;
	shiftActive = false;
	changed = false;
	// create content


	createPage1();
	createPage2();
	createPage3();

};

void FarmWindow::openInBrowser(const char* username) {
	// from https://github.com/knoxfighter/arcdps-killproof.me-plugin
	//char buf[128];
	//snprintf(buf, 128, "https://killproof.me/proof/%s", username);
	//ShellExecuteA(nullptr, nullptr, buf, nullptr, nullptr, SW_SHOW);
}

void FarmWindow::draw(ImGuiWindowFlags flags){//(bool* p_open, ImGuiWindowFlags flags) {
	// ImGui::SetNextWindowSizeConstraints(ImVec2(150, 50), ImVec2(windowWidth, windowsHeight));
	//std::string title = lang.translate(LangKey::KpWindowName);
	std::string title = "Farm UI";

	flags |= ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
	// drawing the window
	// stuff to draw here
	std::string farming = "farm 1 \n farm 2 \n farm 3";
	//flags |= ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
	ImGui::Begin(title.c_str(), &visible, flags);
	//ImGui::Text(farming.c_str()); ImGui::SameLine(200); ImGui::Checkbox(std::string("done").c_str(, NULL);
	//ImGui::Text(farming.c_str());
	//for (std::string s : names) {
	//	ImGui::Text(s.c_str());// ImGui::SameLine(200); ImGui::Checkbox(std::string("done").c_str(), NULL);
	//}

	//for (int i = 0; i < names.size(); i++) {
	//	ImGui::PushID(i);
	//	ImGui::Text(names[i].c_str()); ImGui::SameLine(200); ImGui::Checkbox(std::string("").c_str(), & checkboxes[i]);
	//	ImGui::PopID();
	//}


	// get content from c1
	if (ImGui::Button("Page 1")) {
		currentPage = 0;
	}
	ImGui::SameLine(75);
	if (ImGui::Button("Page 2")) {
		currentPage = 1;
	}
	ImGui::SameLine(150);
	if (ImGui::Button("Page 3")) {
		currentPage = 2;
	}
	switch (currentPage) {
	case 0:
		drawPage1();
		break;
	case 1:
		drawPage2();
		break;
	case 2:
		drawPage3();
		break;
	}

	ImGui::End();
}

std::string FarmWindow::createKeyContent() {
	std::vector<std::string> keycontent = {"create character", "farm", "store equipment"};

}

// ImGui::BeginTable("kp.me", columnCount,ImGuiTableFlags_BordersInnerH | ImGuiTableFlags_Hideable | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_Sortable |ImGuiTableFlags_Reorderable | ImGuiTableFlags_RowBg))

void FarmWindow::setVisible() {
	visible = true;
}
void FarmWindow::setInvisible() {
	visible = false;
}
void FarmWindow::setShiftActive() {
	shiftActive = true;
}
void FarmWindow::setAltActive() {
	altActive = true;
}
void FarmWindow::setShiftInactive() {
	shiftActive = false;
}
void FarmWindow::setAltInactive() {
	altActive = false;
}

bool FarmWindow::isVisible() {
	return visible;
}
bool FarmWindow::isAltActive() {
	return altActive;
}

bool FarmWindow::isShiftActive() {
	return shiftActive;
}

bool FarmWindow::hasChanged() {
	return changed;
}

void FarmWindow::setChanged() {
	changed = true;
}

void FarmWindow::setUnchanged() {
	changed = false;
}

bool& FarmWindow::getVisibility() {
	return visible;
}


// page functions:
// 1 = general
// 2 = (drizzlewood)
// 3 = prov
void FarmWindow::drawPage1()
{

	std::vector<std::string>* s = c1.getContent();

	for (int i = 0; i < s->size(); i++) {
		ImGui::PushID(2 * i);
		ImGui::Text(s->at(i).c_str()); ImGui::SameLine(200); ImGui::Checkbox(std::string("").c_str(), c1.getStatus(i));

		//// TODO: add button if requested by the content
		//ImGui::SameLine(200); 
		//if (ImGui::Button("", )
		ImGui::PopID();
	}

	// PSNA and button for wps
	ImGui::Text(c2.getContent().c_str()); ImGui::SameLine(200);
	if (ImGui::Button("psna wps")) {
		// copy wps to 
		c2.copyToClipboard();
	}
}

void FarmWindow::drawPage2()
{
	std::vector<std::string>* s = c3.getContent();
	for (int i = 0; i < s->size(); i++) {
		ImGui::PushID(2 * i);
		ImGui::Text(s->at(i).c_str());

		ImGui::PopID();
	}
}

void FarmWindow::drawPage3()
{
	std::vector<std::string>* s = c4.getContent();
	for (int i = 0; i < s->size(); i++) {
		ImGui::PushID(2 * i);
		ImGui::Text(s->at(i).c_str());

		//// TODO: add button if requested by the content
		//ImGui::SameLine(200); 
		//if (ImGui::Button("", )
		ImGui::PopID();
	}
}

void FarmWindow::createPage1(){
	std::vector<std::string> v = { "Exchanges", "drizzlewood",  "psna/faction provisioner","Bjora", "Crafting", "Krait", "Khan Ur", "Home", "Southsun", "GH" }; // removed , from here
	c1 = Content(v);

	c2 = PSNAContent("psna wps");
}
void FarmWindow::createPage2() {
	std::vector<std::string> v = { "TODO: add drizzlewood content here" };
	c3 = Content();
}
void FarmWindow::createPage3(){
	std::vector<std::string> v = { "Assassins Krait Machete", "Carrion Krait Slayer", "Valkyrie Krait Shell", "Cleric's Warhammer", 
		"Valkyrie Krait Morningstar", "Rampager's Krait Battleaxe", "Berserker's Krait Shell",
		"Carrion Krait Battleaxe", "Knight's Krait Warhammer"
	};
	c4 = Content(v);

}
