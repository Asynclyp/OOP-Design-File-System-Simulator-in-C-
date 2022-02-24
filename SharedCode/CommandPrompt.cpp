#include "CommandPrompt.h"

CommandPrompt::CommandPrompt() : afs(nullptr), aff(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem* file_system) {
	afs = file_system;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* file_factory) {
	aff = file_factory;
}

int CommandPrompt::addCommand(string str, AbstractCommand* command) {
	pair<map<string, AbstractCommand*>::iterator, bool> insertion = command_map.insert(pair<string, AbstractCommand*>(str, command));
	if (insertion.second) {
		return ReturnType::success;
	}
	return ReturnType::command_already_exists;
}

void CommandPrompt::listCommands() {
	for (map<string, AbstractCommand*>::iterator it = command_map.begin(); it != command_map.end(); ++it) {
		cout << it->first << endl;
	}
}

string CommandPrompt::prompt() {
	string input;
	cout << "Please input a valid command. Type \"q\" to quit. Type \"help\" for a list of commands. Type \"help <command name>\" for details about a specific command\n$\t";
	getline(cin, input);
	return input;
}

int CommandPrompt::run() {
	string input = prompt();
	if (input.compare("q") == 0) {
		return ReturnType::quit;
	}

	if (input.compare("help") == 0) {
		listCommands();
		return ReturnType::list_all;
	}

	// If the input was one word long
	if (input.find(' ') == input.npos) {
		map<string, AbstractCommand*>::iterator search = command_map.find(input);

		// If the matching command was found
		if (search != command_map.end()) {
			int execution_status = search->second->execute("");
			if (execution_status != 0) {
				cout << "Encountered an error" << endl;
				return ReturnType::execution_error;
			}
			return ReturnType::executed_command;
		}
		else {
			cout << "Command not found" << endl;
			return ReturnType::command_not_found;
		}
	}

	istringstream is(input);
	is >> input;
	
	// If the first word is "help"
	if (input.compare("help") == 0) {
		is >> input;
		map<string, AbstractCommand*>::iterator search = command_map.find(input);

		// If the matching command was found
		if (search != command_map.end()) {
			search->second->displayInfo();
			return ReturnType::list_one;
		}
		else {
			cout << "Command not found" << endl;
			return ReturnType::command_not_found;
		}
	}
	else {
		map<string, AbstractCommand*>::iterator search = command_map.find(input);

		// If the matching command was found
		if (search != command_map.end()) {
			string buffer;
			getline(is, input);
			istringstream is2(input);
			is2 >> buffer;
			if (!is2.eof()) {
				getline(is2, input);
				input = buffer + input;
			}
			else {
				input = buffer;
			}
			int execution_status = search->second->execute(input);
			if (execution_status != 0) {
				cout << "Encountered an error" << endl;
				return ReturnType::execution_error;
			}
			return ReturnType::executed_command;
		}
		else {
			cout << "Command not found" << endl;
			return ReturnType::command_not_found;
		}
	}
}