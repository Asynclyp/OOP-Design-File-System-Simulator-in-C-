#pragma once
#include "AbstractParsingStrategy.h"

class QuickCreateParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string input);
};