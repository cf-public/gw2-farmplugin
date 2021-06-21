#pragma once
#include "Content.h"
#include "PSNAContent.h"
#include <atomic>
#include <vector>
#include <string>
#include <array>
#include "Page1.h"
#include "Page2.h"
#include "Page3.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
//#include "Player.h"
#include "arcdps_exts.h"
#include <memory>

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

	std::vector<std::unique_ptr<IPage>> pages;

	bool visible;
private:
	static void openInBrowser(const char* username);
	//bool drawRow(const Alignment& alignment, const char* username, const char* characterName, const std::atomic<LoadingStatus>& status, 
	//	bool treeNode);
	bool drawRow(const char* username, const char* characterName, bool treeNode);

	char userAddBuf[1024]{};
	ImGuiTable* table = nullptr;
	
	bool altActive;
	bool shiftActive;
	bool changed;
	int currentPage = 0;
};
