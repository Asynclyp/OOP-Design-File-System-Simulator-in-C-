#include "PasswordProxy.h"

vector<char> PasswordProxy::read() {
	if (isPassword(passwordPrompt())) {
		return file->read();
	}
	return {};
}

int PasswordProxy::write(vector<char> v) {
	if (isPassword(passwordPrompt())) {
		return file->write(v);
	}
	return ReturnType::incorrect_password;
}

int PasswordProxy::append(vector<char> v) {
	if (isPassword(passwordPrompt())) {
		return file->append(v);
	}
	return ReturnType::incorrect_password;
}

unsigned int PasswordProxy::getSize() {
	return file->getSize();
}

string PasswordProxy::getName() {
	return file->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* afv) {
	if (isPassword(passwordPrompt())) {
		file->accept(afv);
	}
}

PasswordProxy::PasswordProxy(AbstractFile* f, string pwd) : file(f), password(pwd) {}

PasswordProxy::~PasswordProxy() {
	delete file;
}

string PasswordProxy::passwordPrompt() {
	cout << "Please Enter Password: \n\t";
	string input;
	getline(cin, input);
	return input;
}

bool PasswordProxy::isPassword(string input) {
	return input.compare(password) == 0;
}

AbstractFile* PasswordProxy::clone(string destination) {
	PasswordProxy* copy = new PasswordProxy(*this);
	copy->file = file->clone(destination);

	return copy;
}