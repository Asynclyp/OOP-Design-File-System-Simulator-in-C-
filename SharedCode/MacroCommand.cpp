#include"MacroCommand.h"

MacroCommand::MacroCommand(AbstractFileSystem* afs) {}

int MacroCommand::execute(string input) {
	vector<string> arguments = strategy->parse(input);
	auto argument = arguments.begin();
	for (auto command = commands.begin(); command != commands.end(); ++command) {
		int return_value = (*command)->execute(*argument);
		++argument;
		if (return_value != ReturnType::success) {
			return return_value;
		}
	}
	return ReturnType::success;
}

void MacroCommand::displayInfo() {
	cout << "This is a macro command" << endl;
}

void MacroCommand::addCommand(AbstractCommand* command) {
	commands.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* s) {
	strategy = s;
}