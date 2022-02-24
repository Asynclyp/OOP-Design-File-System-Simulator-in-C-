#include "LSCommand.h"

LSCommand::LSCommand(AbstractFileSystem* file_system) : afs(file_system) {}

int LSCommand::execute(string flags) {
	// Wrap file names in istringstream
	set<string> filenames = afs->getFileNames();

	// -m behavior
	if (flags.find("-m") != string::npos) {
		MetadataDisplayVisitor* mdv = new MetadataDisplayVisitor();
		for(auto it = filenames.begin(); it != filenames.end(); ++it) {
			AbstractFile* file = afs->openFile(*it);
			file->accept(mdv);
			afs->closeFile(file);
		}
	}
	else {
		// Default behavior
		bool newline = false;
		for (auto it = filenames.begin(); it != filenames.end(); ++it) {
			cout << *it;

			if (newline) {
				cout << endl;
			}
			else {
				for (int i = MAX_FILENAME_LENGTH + SEPARATION_SIZE - it->length(); i > 0; --i) {
					cout << " ";
				}
			}

			newline = !newline;
		}

		if (newline) {
			cout << endl;
		}
	}

	return ReturnType::success;
}

void LSCommand::displayInfo() {
	cout << "\"ls\" lists files in the file-system. Usage:\n\tls [-m]" << endl;
}