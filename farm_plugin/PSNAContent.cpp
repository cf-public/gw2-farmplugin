#include "PSNAContent.h"
#include <ctime>

PSNAContent::PSNAContent(std::string s) {
	computeWPs();
	content = s;
}

void PSNAContent::computeWPs() {
	std::array<std::string, 7> wps;
	wps[1] = "[&BIcHAAA=][&BEwDAAA=][&BNIEAAA=][&BKYBAAA=][&BIMCAAA=][&BA8CAAA=]"; // monday
	wps[2] = "[&BH8HAAA=][&BEgAAAA=][&BKgCAAA=][&BBkAAAA=][&BGQCAAA=][&BIMBAAA=]";
	wps[3] = "[&BH4HAAA=][&BMIBAAA=][&BP0CAAA=][&BKYAAAA=][&BDgDAAA=][&BPEBAAA=]";
	wps[4] = "[&BKsHAAA=][&BE8AAAA=][&BP0DAAA=][&BIMAAAA=][&BF0GAAA=][&BOcBAAA=]";
	wps[5] = "[&BJQHAAA=][&BMMCAAA=][&BJsCAAA=][&BNUGAAA=][&BHsBAAA=][&BNMAAAA=]"; // friday
	wps[6] = "[&BH8HAAA=][&BLkCAAA=][&BBEDAAA=][&BJIBAAA=][&BEICAAA=][&BBABAAA=]";
	wps[0] = "[&BIkHAAA=][&BDoBAAA=][&BO4CAAA=][&BC0AAAA=][&BIUCAAA=][&BCECAAA=]";

	// get the day of the week and set the correct wps
	WPs = wps[getWeekday()];
}

int PSNAContent::getWeekday() {
//	// from https://www.cplusplus.com/reference/ctime/gmtime/
	// Disable warning that it is not safe
	time_t rawtime;
	struct tm* ptm;

	time(&rawtime);
#pragma warning(disable : 4996)
	ptm = gmtime(&rawtime);




	if (ptm->tm_hour < 8) {
		if (ptm->tm_wday == 0) {
			return 6;
		}
		else {
			return ptm->tm_wday - 1;
		}
	}
	return ptm->tm_wday;
}

std::string PSNAContent::getContent() {
	return content;
}

std::string PSNAContent::getWPs() {
	return WPs;
}

void PSNAContent::copyToClipboard() {
	// from http://www.cplusplus.com/forum/beginner/14349/
	OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, WPs.size()+1);
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), WPs.c_str(), WPs.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}