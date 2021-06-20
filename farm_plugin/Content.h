#pragma once

#include <string>
#include <vector>
#include <array>
class Content {
	/*
	Container for content

	public:
	getContentText,
	getContentCheckbox
	getContentSize
	getContentButton

	protected:
	Text,
	Checkbox,
	Button,
	Length

	TODO:
	Fix that length is currently limited to 10;
	*/
public:
	Content();
	Content(std::vector<std::string> s);
	bool* getStatus(int i);
	std::vector<std::string>* getContent();
	int getContentLength();
	
protected:
	std::array<bool,10> status; // max 10 checkboxes
	std::vector<std::string> content;
	int contentLength = 0;

};