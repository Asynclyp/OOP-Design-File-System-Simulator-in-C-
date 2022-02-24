#pragma once
#include "TextFile.h"
#include "ImageFile.h"
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* file);
	virtual void visit_ImageFile(ImageFile* file);
};