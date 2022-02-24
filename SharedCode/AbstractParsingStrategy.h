#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string input) = 0;
	virtual ~AbstractParsingStrategy() = default;
};