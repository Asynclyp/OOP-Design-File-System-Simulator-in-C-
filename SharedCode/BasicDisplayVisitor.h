#pragma once
#include "TextFile.h"
#include "ImageFile.h"
#include "AbstractFileVisitor.h"
#include <math.h>

class BasicDisplayVisitor : public AbstractFileVisitor {
	int indexHelper(int y, int x, int dim);
public:
	virtual void visit_TextFile(TextFile* file);
	virtual void visit_ImageFile(ImageFile* file);
};