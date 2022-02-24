#include "MetadataDisplayVisitor.h"

void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
	string name = file->getName();
	cout << name;
	// Fill spaces
	for (int i = MAX_FILENAME_LENGTH + SEPARATION_SIZE - name.length(); i > 0; --i) {
		cout << " ";
	}
	cout << "text\t" << file->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
	string name = file->getName();
	cout << name;
	//Fill spaces
	for (int i = MAX_FILENAME_LENGTH + SEPARATION_SIZE - name.length(); i > 0; --i) {
		cout << " ";
	}
	cout << "image\t" << file->getSize() << endl;
}