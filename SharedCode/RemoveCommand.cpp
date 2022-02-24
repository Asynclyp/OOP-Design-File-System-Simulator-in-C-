#include "RemoveCommand.h"

RemoveCommand::RemoveCommand(AbstractFileSystem* file_system) : afs(file_system) {}

int RemoveCommand::execute(string filename) {
	return afs->deleteFile(filename);
}

void RemoveCommand::displayInfo() {
	cout << "\"rm\" removes a file. Usage:\n\trm <filename>" << endl;
}