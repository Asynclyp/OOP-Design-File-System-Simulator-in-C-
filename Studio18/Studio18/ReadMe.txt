studio 18 answers here
1.	Kai Ang
	Kevin Oloomi
	Spark Li
2.	If we want to add a new concrete file type, we would have to modify our implementation of createFile in each of our concrete file systems, which is clunky.
3.	A new concrete file factory class may be useful in various cases. One case might be if we want to have two different concrete file systems that deal with distinct sets of concrete file types. Since file factories only create files, and file systems only manage access to files, we can mix and match any combination of factories with systems without issue. They do not rely on each other to do their functions.
4.	We tested creating our two file types, checking the initial conditions, writing to the file, and checking the conditions again. The tests gave the expected results.
5.	SimpleFileSystem only relies upon the AbstractFile interface.