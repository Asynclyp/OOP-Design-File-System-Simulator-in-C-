#pragma once
#include<string>

using namespace std;

class AbstractCommand {
public:
	virtual int execute(string) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};