studio 19 answers here
1.	Kai Ang
	Kevin Oloomi
	Spark Li
2.	We created a file and wrote "hello world" to it. We then read this back to a buffer, and printed it out. Then we overwrote the file with "goodbye" and read it back to the buffer and printed that out. The test results were as expected.
3.	When a file visitor visits a file, first it calls the file's accept function through the AbstractFile interface. This function is dynamically mapped to the dynamic type of that file, calling the concrete implementation of accept. This calls the appropriate visit function from the AbstractFileVisitor interface, which runs the appropriate concrete implementation for visitng that file type.
4.	Through delegation, we make it possible for each concrete class to be dealt with in its own way while each family of classes only interacts with the other through the respective abstract interface. This helps isolate the individual implementations from each other, maximizing flexibility in implementation.
5.	A consequence of this visitor pattern is that every time we add a new concrete class, we need to add an implementation for it in each of our concrete visitor classes. If we plan on adding many concrete file types, we may want to avoid using this visitor pattern.