// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"

void BasicDisplayVisitor::visit_TextFile(TextFile* file) {
	vector<char> buffer = file->read();
	for (auto it = buffer.begin(); it != buffer.end(); ++it) {
		cout << *it;
	}
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {
	// For each line
	int dimension = (int)sqrt(file->getSize());
	vector<char> buffer = file->read();
	for (int y = 0; y < dimension; ++y) {
		// Print each element
		for (int x = 0; x < dimension; ++x) { 
			cout << buffer[indexHelper(y, x, dimension)];
		}
		// Print a new-line
		cout << endl;
	} 
}

int BasicDisplayVisitor::indexHelper(int y, int x, int dim) {
	return y * dim + x;
}