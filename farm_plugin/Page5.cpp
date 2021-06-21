#include "IPage.h"
#include "Page5.h"

Page5::Page5() {
	createContent();
	generateBossTimes();
}

void Page5::draw() {
	bool update = false;
	// update here for now
	if (update) {
		worldBossTime(-1, true);
	}


	std::vector<std::string>* s = c.getContent();
	ImGui::Text("World Bosses");
	for (int i = 0; i < s->size(); i++) {
		ImGui::PushID(2 * i);
		ImGui::Text(s->at(i).c_str());
		ImGui::SameLine(80);
		std::string spawnTime = std::to_string(worldBossTime(i, false)) + std::string(" minutes");
		ImGui::Text(spawnTime.c_str());

		//// TODO: add button if requested by the content
		//ImGui::SameLine(200); 
		//if (ImGui::Button("", )
		ImGui::PopID();
	}
}

void Page5::createContent() {
	std::vector<std::string> v = {"Pinata", "Chak Gerent", "Octovine", "DBS"};
	c = Content(v);
}

int Page5::worldBossTime(int i=-1, bool update=false){
	// compute everything in minutres from midnight
	if (update) {
		tm* current = getTime();

		cycle2h = current->tm_hour % 2 * 60 + current->tm_min;

		
	}
	int spawnTime = 0;
	switch (i) {
	case 0: // pinata compute remaining time here
		spawnTime = 20;
		if (cycle2h < spawnTime) { return spawnTime - cycle2h; }
		else { return 120 - cycle2h + spawnTime; }
		break;
	case 1: // chak
		spawnTime = 30;
		if (cycle2h < spawnTime) { return spawnTime - cycle2h; }
		else { return 120 - cycle2h + spawnTime; }
	case 2: // octo
		spawnTime = 60;
		if (cycle2h < spawnTime) { return spawnTime - cycle2h; }
		else { return 120 - cycle2h + spawnTime; }
	case 3: //dbs
		spawnTime = 75;
		if (cycle2h < spawnTime) { return spawnTime - cycle2h; }
		else { return 120 - cycle2h + spawnTime; }
	}
	return 0;
}

void Page5::generateBossTimes() {
	// TODO: make bosstimes better
}

tm* Page5::getTime() {
	// from https://www.cplusplus.com/reference/ctime/gmtime/
			// Disable warning that it is not safe
	time_t rawtime;
	struct tm* ptm;

	time(&rawtime);
#pragma warning(disable : 4996)
	ptm = gmtime(&rawtime);

	return ptm;
}