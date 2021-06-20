#pragma once
#include "Content.h"
#include "PSNAContent.h"
#include <atomic>
#include <vector>
#include <string>
#include <array>

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
//#include "Player.h"
#include "arcdps_exts.h"

class FarmWindow {
public:

	FarmWindow();

	
	//void draw(bool* p_open, ImGuiWindowFlags flags);

	void draw(ImGuiWindowFlags flags);

	void setVisible();
	void setInvisible();
	void setShiftActive();
	void setAltActive();
	void setShiftInactive();
	void setAltInactive();
	bool isVisible();
	bool isShiftActive();
	bool isAltActive();
	bool hasChanged();
	void setChanged();
	void setUnchanged();
	bool& getVisibility();

	Content c1;
	PSNAContent c2;
	Content c3;
	Content c4;


	// hardcoded pages

	void drawPage1(); // general farm
	void drawPage2(); //drizzlewood
	void drawPage3(); // faction provisioners

	void createPage1(); // general farm
	void createPage2(); //drizzlewood
	void createPage3(); // faction provisioners


	//std::vector<std::string> names;
	//// variables for checkboxes
	//std::array<bool, 9> checkboxes;
	bool visible;
private:
	static void openInBrowser(const char* username);
	//bool drawRow(const Alignment& alignment, const char* username, const char* characterName, const std::atomic<LoadingStatus>& status, 
	//	bool treeNode);
	bool drawRow(const char* username, const char* characterName, bool treeNode);

	std::string createKeyContent();

	char userAddBuf[1024]{};
	ImGuiTable* table = nullptr;
	
	bool altActive;
	bool shiftActive;
	bool changed;
	int currentPage = 0;
};
