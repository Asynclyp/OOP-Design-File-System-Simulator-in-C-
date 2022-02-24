#include "CopyCommand.h"

CopyCommand::CopyCommand(AbstractFileSystem* file_system) : afs(file_system) {}

int CopyCommand::execute(string arguments) {
	int period_location = arguments.find(".");

	if (period_location == arguments.npos) {
		cout << "Couldn't find period" << endl;
		return ReturnType::execution_error;
	}

	// Get source filename
	string source = arguments.substr(0, period_location);
	string temp = arguments.substr(period_location, arguments.npos);

	// Add file ending
	istringstream is(temp);
	is >> temp;

	if (is.eof()) {
		cout << "No file ending" << endl;
		return ReturnType::execution_error;
	}

	source += temp;
	string ending = temp;

	// Get destination name
	string destination;
	while (!is.eof()) {
		is >> temp;
		destination += " " + temp;
	}
	if (destination.length() < 1) {
		cout << "Missing destination name" << endl;
		return ReturnType::execution_error;
	}
	destination = destination.substr(1, destination.npos);

	period_location = destination.find(".");
	if (period_location != destination.npos) {
		cout << "Too many periods" << endl;
		return ReturnType::execution_error;
	}

	// Open file
	AbstractFile* file = afs->openFile(source);
	if (file == nullptr) {
		cout << "Coudln't find file" << endl;
		return ReturnType::file_not_found;
	}

	// Copy file
	AbstractFile* copy = file->clone(destination);
	afs->closeFile(file);
	if (copy == nullptr) {
		cout << "Couldn't copy file" << endl;
		return ReturnType::execution_error;
	}

	// Adding file
	int return_value = afs->addFile(destination + ending, copy);
	if (return_value != ReturnType::success) {
		cout << "Couldn't add file" << endl;
		delete copy;
		return ReturnType::execution_error;
	}

	return ReturnType::success;
}

void CopyCommand::displayInfo() {
	cout << "\"cp\" copies the contents of one file to a new file. Usage:\n\tds <source filename> <destination name>" << endl;
}