#include "CatCommand.h"

CatCommand::CatCommand(AbstractFileSystem* file_system) : afs(file_system) {}

int CatCommand::execute(string arguments) {
	int flag_index = arguments.find("-a");
	string filename;
	bool append = false;

	if (flag_index == string::npos) {
		filename = arguments;
	}
	else {
		// Remove flag
		filename = arguments.substr(0, flag_index);
		int last_index = filename.length() - 1;

		// 

		// Remove whitespace
		for (int i = last_index; i >= 0; --i) {
			if (filename.at(i) == ' ' || filename.at(i) == '\t') {
				filename = filename.substr(0, filename.length() - 1);
			}
			else {
				break;
			}
		}

		append = true;
	}

	cout << "Filename: " << filename << endl;

	string previous_contents;
	AbstractFile* file = afs->openFile(filename);

	if (file == nullptr) {
		cout << "File not found" << endl;
		return ReturnType::file_not_found;
	}

	if (append) {
		// Display unformatted file contents
		vector<char> contents = file->read();
		for (auto it = contents.begin(); it != contents.end(); ++it) {
			cout << *it;
			previous_contents += *it;
		}
		cout << endl;
	}

	// Get input from user
	cout << "Please input contents. Enter \":wq\" to save and quit, or \":q\" to quit without saving." << endl;
	string temp;
	string input;
	while (true) {
		getline(cin, temp);
		// Save and quit
		if (temp.compare(":wq") == 0) {
			input = input.substr(0, input.length() - 1);
			vector<char> input_contents(input.begin(), input.end());
			int value;

			if (append) {
				value = file->append(input_contents);
			}
			else {
				value = file->write(input_contents);
			}
			afs->closeFile(file);

			return value;
		}
		// Just quit
		if (temp.compare(":q") == 0) {
			afs->closeFile(file);
			return ReturnType::success;
		}
		input += temp + "\n";
	}
}

// -a means append, none means overwrite
void CatCommand::displayInfo() {
	cout << "\"cat\" overwrites or appends to an existing file. Usage:\n\tcat <filename> [-a]" << endl;
}