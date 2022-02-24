Studio 20 ReadMe.txt
1.	Kai Ang
	Kevin Oloomi
	Spark Li
2.	When we add the file to the map or set, we are adding the PasswordProxy object; the point is so that the user cannot access the file without the password. Thus, if we want to delete the file, without doing anything, we would only delete the PasswordProxy object, leaving the actual file without a pointer to it. Thus, when we deconstruct the PasswordProxy object, we also need to delete the file it is pointing to.
3.	Functions implemented.
4.	We created a TextFile and wrapped it in a PasswordProxy. Then we tested failing to write to the file. Then we tested successfully writing to that file. The test results were as expected.