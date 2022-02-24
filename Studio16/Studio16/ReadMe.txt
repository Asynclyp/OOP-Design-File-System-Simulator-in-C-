Answer studio 16 questions here
1.	Kai Ang
	Kevin Oloomi
	Spark Li

2.	There is a base class which comprises of pure virtual functions. These functions serve as the interface for the derived class which can then define the virtual function to suit the need of the specific object that is created
3.	a. This is interface inheritance. TextFile inherets only the function signatures. AbstractFile is an interface, and has no implementations for TextFile to inheret
	b. These member variables should be private. We only want to expose the minimal interface, and have this already through our public functions; the name can be set using the constructor, the name can be read using its getter, the contents can be altered using write() or append(), and can be read using read().
4.	The test cases that were utilized was creating a new TextFile name called "One". Then there was a cout statement of getName(). The next test case was to insert the characters '2','3','4','5' into the file. They were checked using write(), and there was also a check for the size using getSize(). Then the same characters were appended to the contents using append(). The contents and size of contents were checked in the same way as before. Finally the contents were overridden with the original characters using write(). The contents and size of contents were again checked in the same way. All of these statements printed the correct statements.
5.	int main()
	{
		vector<char> v = { '2','3','4','5' };		// Test contents
		AbstractFile * abs = new TextFile("One");	// Create AbstractFile Object
		cout << abs->getName() << endl;				// Expect "One"
		abs->write(v);
		abs->read();								// Expect "2345"
		cout << endl;
		cout << abs->getSize() << endl;				// Expect "4"
		abs->append(v);
		abs->read();								// Expect "23452345"
		cout << endl;
		cout << abs->getSize() << endl;				// Expect "8"
		abs->write(v);
		abs->read();								// Expect "2345"
		cout << endl;
		cout << abs->getSize() << endl;				// Expect "4"
	}


	First, we initialize a vector of chars, "v", which contains some test characters. Then, we initialize a new TextFile object with the name "One" to the AbstractFile pointer "abs." Then the various tests are conducted through abs.