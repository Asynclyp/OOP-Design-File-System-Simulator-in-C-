#include "DisplayCommand.h"

DisplayCommand::DisplayCommand(AbstractFileSystem* file_system) : afs(file_system) {}

int DisplayCommand::execute(string arguments) {
	int flag_index = arguments.find("-d");
	string filename;
	bool formatted = true;

	if (flag_index == string::npos) {
		filename = arguments;
	}
	else {
		// Remove flag
		filename = arguments.substr(0, flag_index);

		// Remove whitespace
		for (int i = filename.length() - 1; i >= 0; --i) {
			if (filename.at(i) == ' ' || filename.at(i) == '\t') {
				filename = filename.substr(0, filename.length() - 1);
			}
			else {
				break;
			}
		}

		formatted = false;
	}

	AbstractFile* file = afs->openFile(filename);

	if (file == nullptr) {
		cout << "File not found" << endl;
		return ReturnType::file_not_found;
	}

	if (formatted) {
		BasicDisplayVisitor* bdv = new BasicDisplayVisitor();
		file->accept(bdv);
		cout << endl;
	}
	else {
		vector<char> contents = file->read();
		for (auto it = contents.begin(); it != contents.end(); ++it) {
			cout << *it;
		}
		cout << endl;
	}

	afs->closeFile(file);

	return ReturnType::success;
}

void DisplayCommand::displayInfo() {
	cout << "\"ds\" displays the contents of a file. Usage:\n\tds <filename> [-d]" << endl;
}