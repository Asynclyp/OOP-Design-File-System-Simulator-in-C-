#include "RenameParsingStrategy.h"

vector<string> RenameParsingStrategy::parse(string input) {
	istringstream is(input);
	string temp;
	string copy_args;
	string remove_args;
	vector<string> arguments;

	// Put source name in both arguments
	is >> temp;
	copy_args = temp;
	remove_args = temp;

	// Put destination in copy args
	is >> temp;
	copy_args += " " + temp;

	// Add arguments to vector
	arguments.push_back(copy_args);
	arguments.push_back(remove_args);

	return arguments;
}