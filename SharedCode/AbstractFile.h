#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include <string>
#include "AbstractFileVisitor.h"

using namespace std;

enum ReturnType { success = 0, write_failure, operation_not_supported, incorrect_password, file_already_exists, file_pointer_is_nullptr, unsupported_file_type, file_not_found, file_in_use, failed_to_create_file, command_already_exists, command_not_found, execution_error, quit, list_all, list_one, executed_command };
static const int MAX_FILENAME_LENGTH = 20;
static const int SEPARATION_SIZE = 4;

class AbstractFile {
public:
	virtual vector<char> read() = 0;
	virtual int write(vector<char> v) = 0;
	virtual int append(vector<char> v) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor* afv) = 0;
	virtual AbstractFile* clone(string destination) = 0;
};
