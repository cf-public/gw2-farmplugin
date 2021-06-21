#pragma once
# include "Content.h"
# include "PSNAContent.h"
# include <vector>
#include <Windows.h>

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "arcdps_exts.h"

class IPage {
public:
	IPage() {};
	virtual ~IPage() {};
	virtual void draw() = 0;
	//void createContent() {};
protected:
	Content c;
};