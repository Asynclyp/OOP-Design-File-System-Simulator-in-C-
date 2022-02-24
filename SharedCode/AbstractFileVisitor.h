#pragma once
#include<iostream>

// Forawrd Declaration
class TextFile;
class ImageFile;

using namespace std;

class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* file) = 0;
	virtual void visit_ImageFile(ImageFile* file) = 0;
};