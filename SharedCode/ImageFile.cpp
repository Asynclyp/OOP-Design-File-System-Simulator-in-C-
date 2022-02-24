// definition of ImageFile class here
#include "ImageFile.h"
#include <iostream>

using namespace std;


ImageFile::ImageFile(std::string str) : name_(str), size(0) {}

unsigned int ImageFile::getSize() {
	return contents_.size();
}

std::string ImageFile::getName() {
	return name_;
}

int ImageFile::write(vector<char> v) {
	size = v[v.size() - 1] - '0';					// Convert size to its integer value
	int dimension = (int)size;						// Integer type of size for math
	contents_.clear();								// Clear file contents

	// If there is a size mismatch
	if ((dimension * dimension) != v.size() - 1) {
		size = 0;
		return ReturnType::write_failure;
	}

	// Check that the characters are all valid
	bool valid = true;
	for (size_t i = 0; i < v.size() - 1; ++i) {
		if (v[i] != 'X' && v[i] != ' ') {
			valid = false;
			break;
		}
	}

	// If a character was not valid
	if (!valid) {
		size = 0;
		return ReturnType::write_failure;
	}

	// Copy vector to contents_
	v.erase(v.end() - 1);	// Remove the last element in the vector (size)
	contents_ = v;

	return ReturnType::success;
}

int ImageFile::append(vector<char> v) {
	return ReturnType::operation_not_supported;
}

vector<char> ImageFile::read() {
	return contents_;
}

void ImageFile::accept(AbstractFileVisitor* afv) {
	afv->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(string destination) {
	ImageFile* copy = new ImageFile(destination + ".img");
	copy->write(this->contents_);
	return copy;
}