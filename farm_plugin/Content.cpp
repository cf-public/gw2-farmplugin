#include "Content.h"
#include <array>

Content::Content() {}
Content::Content(std::vector<std::string> s) {
	content = s;
	contentLength = s.size();
	for (int i = 0; i < contentLength; i++) {
		status[i] = false;
	}
}

bool* Content::getStatus(int i) {
	return &status[i];
}

std::vector<std::string>* Content::getContent() {
	return &content;
}

int Content::getContentLength() {
	return contentLength;
}