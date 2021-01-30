# stringProcessing
A simple program that utilizes C/C++ str functions

	Summary: A file of sentences will be read in and the lines will be stored into a vector of strings.
	For each string, print it, then report the number of chars in the string/sentence (string's length)
	Then, count the number if words in each sentence
	Then, count the number of vowels, the number of consonants, and number of punctutation or other chars in the string
	Then convert the text in each line to Title Case, Sentence Case and Toggle Case

	Changelog:
	Updated file reading function with use of recursion (most efficient and effective) (3/10/2020)
	Added dividers between each line (3/10/2020)
	Changed from editing all lines at once to just one at a time (3/11/2020)
	Improved logic for finding the longest word (3/11/2020)
	Restarted longestWord function for efficiency (3/12/2020)

	Comments:
	Something interesting to note with this line of code:
	cout << (char) toupper(line.at(i + 1));
	When not including the casting (char), the first letter of each word is the ASCII value of the capitalized letter (Title Case)
	This is interesting and needs to be casted to char first as it will return the capitalized ASCII integer
