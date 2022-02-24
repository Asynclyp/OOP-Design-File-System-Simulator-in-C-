#include "QuickCreateParsingStrategy.h"

vector<string> QuickCreateParsingStrategy::parse(string input) {
	istringstream is(input);
	string temp;
	vector<string> arguments;

	// Filename is the only argument for both 
	is >> temp;

	arguments.push_back(temp);
	arguments.push_back(temp);

	return arguments;
}