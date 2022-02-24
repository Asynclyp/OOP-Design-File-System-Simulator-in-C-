#include "TouchCommand.h"

TouchCommand::TouchCommand(AbstractFileSystem* file_system, AbstractFileFactory* file_factory) : afs(file_system), aff(file_factory) {}

int TouchCommand::execute(string arguments) {
	int flag_index = arguments.find("-p");
	string filename;
	bool proxy = false;

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

		proxy = true;
	}

	if (filename.length() > MAX_FILENAME_LENGTH) {
		return ReturnType::failed_to_create_file;
	}

	AbstractFile* file = aff->createFile(filename);

	if (file == nullptr) {
		return ReturnType::failed_to_create_file;
	}
	
	if (proxy) {
		string password;
		cout << "Please input the password for this file:\n\t";
		getline(cin, password);
		AbstractFile* proxy_file = new PasswordProxy(file, password);

		return afs->addFile(filename, proxy_file);
	}
	else {
		return afs->addFile(filename, file);
	}
}

void TouchCommand::displayInfo() {
	cout << "\"touch\" creates a file. Usage:\n\ttouch <filename> [-p]" << endl;
}