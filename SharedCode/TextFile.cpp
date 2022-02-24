//  Define the TextFile class here
#include "TextFile.h"
#include <iostream>

TextFile::TextFile(string name): name_(name) {
}

unsigned int TextFile::getSize() {
	return contents_.size();
}

string TextFile::getName() { 
	return name_;
}
 
int TextFile::write(vector<char> v) {
	contents_.clear();
	contents_ = v;
	return ReturnType::success;
}

int TextFile::append(vector<char> v) {
	for (size_t i = 0; i < v.size(); ++i) {
		contents_.push_back(v[i]);
	}
	return ReturnType::success;
}

vector<char> TextFile::read() {
	return contents_;
}

void TextFile::accept(AbstractFileVisitor* afv) {
	afv->visit_TextFile(this);
}

AbstractFile* TextFile::clone(string destination) {
	TextFile* copy = new TextFile(destination + ".txt");
	copy->write(this->contents_);
	return copy;
}