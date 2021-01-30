#include <iostream>
#include <string> // For use of strings
#include <fstream> // For file io
#include <vector> // For vectors
// #include <cctype>
// #include <cstring>

using namespace std;

void promptForFile(string & fileName) {
	cout << "Enter the name of your file: ";
	getline(cin, fileName);
}

bool openForReading(ifstream & infile, string fileName) {
	infile.open(fileName); // Open name of the file
	if (infile.good()) // then the file opened just fine
		return true;
	else {
		perror("Can't open the specified input file");
		cout << "The file name used was: " << fileName << endl;
		cout << "Enter another file name to use (or type 'quit'): ";
		getline(cin, fileName);
		if (fileName != "quit") {
			cout << "--- The new file name is: " << fileName << endl;
			//note the use of recursion below
			return openForReading(infile, fileName);
		}
		else {
			cout << "Quitting at user's request." << endl;
			return false;
			exit(0); // Quit as fail safe
		}
	}
} //openForReading

void storeLines(ifstream & infile, vector<string> & stringVec) {
	string line = " ";

	while (getline(infile, line))
		stringVec.push_back(line); // Read every line from file
	infile.close();
}

void printDivider() {
	cout << "\n-------------------------------------------------------------------------\n";
}

void displayCounts(int words, int letters, int vowels, int consonants, int punc) {
	cout << "\nNumber of words: " << words;
	cout << "\nNumber of letters: " << letters;
	cout << "\nNumber of vowels: " << vowels;
	cout << "\nNumber of consonants: " << consonants;
	cout << "\nNumber of punctutation symbols: " << punc;
}

void displayGrammar(string line) {
	//string words;
	//vector<string> wordsInLine;
	int numWords = 0;
	int numLetters = 0;
	int numVowels = 0;
	int numConsonants = 0;
	int numPunc = 0;
	int i = 0;
	char charsInLine = ' ';

	/*	vector<char> charVec; // debug
		for (int i = 1; i <= charVec.size(); i++)
			charVec.push_back(charsInLine);
	*/

	for (i; i < line.size(); i++) {
		if (line.at(i) == ' ') { // Number of words is given by number of spaces in line + 1
			numWords++;
		}
		if (line.at(i) == 'a' || line.at(i) == 'e' || line.at(i) == 'i' || line.at(i) == 'o' || line.at(i) == 'u') {
			numVowels++;
		}
		if (line.at(i) == '.' || line.at(i) == '?' || line.at(i) == ',' || line.at(i) == '\'') {
			numPunc++;
		}
	}
	numWords++; // Add one more to count for total words in line
	numConsonants = i - numVowels - numPunc; // Calculated based off of sample output
	numLetters = i; // Degroot defines this as number of chars in sample output, so number of chars in line
	displayCounts(numWords, numLetters, numVowels, numConsonants, numPunc);

	/*	for (int i = 1; i <= wordsInLine.size(); i++)
			wordsInLine.push_back(words);

		for (auto element : wordsInLine)
			cout << "Just words: " << element;
	*/
}

void titleCase(string line) {
	cout << "\nTitle Case: ";

	for (int i = 0; i < line.size(); i++) {
		cout << line.at(i);

		if (line.at(i) == ' ') { // Space is found
			cout << (char)toupper(line.at(i + 1)); // Capitalize char right of space for title case
			i++; // Skip to next char after capitalizing
		}
	}
}

void sentenceCase(string line) {
	cout << "\nSentence Case: ";

	cout << line.at(0); // Keep first letter the same (capitalized)

	for (int i = 1; i < line.size(); i++) {
		cout << (char)tolower(line.at(i)); // Print out rest of line in lowercase

		if (line.at(i) == '.' && i < (line.size() - 1)) { // End of sentence found
			cout << " " << (char)toupper(line.at(i + 2)); // Capitalize first letter of sentence
			i += 2; // Skip to word in next sentence
		}
	}

	/*	if (line.at(i) == '.' && line.at(i + 1) == ' ') { // End of sentence
			cout << (char)toupper(line.at(i + 2)); // Capitalize char right of period and space for sentence case
			i += 2; // Skip to next char after capitalizing
		}
	*/
}

void exceptionsCase(string line) {
	cout << "\nSentence Case with Exceptions: ";
	cout << line;
}

void toggleCase(string line) {
	cout << "\nToggle Case: ";

	/*	for (int i = 0; i < line.size(); i++)
			cout << (char) toupper(line.at(i)); // Make line all uppercase
	*/

	cout << (char)tolower(line.at(0)); // First letter of line must always be lowercase

	for (int j = 1; j < line.size(); j++) {
		cout << (char)toupper(line.at(j)); // Make rest of line all uppercase

		if (line.at(j) == ' ') { // Space is found
			cout << (char)tolower(line.at(j + 1)); // Lowercase char right of space for toggle case
			j++; // Skip to next char after lowering
		}
	}
}

void longestWord(string line) {
	int start = 0, end = 0, max = 0, maxStart = 0; // Access vector elements, with start and ending index

	while (end <= line.length()) { // Read whole line
		if (end >= line.length() || line.at(end) == ' ' || line.at(end) == '.' || line.at(end) == ',') { // Word ends
			int tempLength = end - start; // Count length of string in question

			if (tempLength > max) {
				max = tempLength; // tempLength is now max until new max is found in line
				maxStart = start; // Store location of longest word
			}
			start = end; // Start on next word from where leaving off
		}
		end++;
	}
	string longestWord(line, maxStart, max); // Define word to be found in line
	cout << "\nLongest Word:" << longestWord;

	/*	int numChars = 0, maxChars = 0, foundAt = 0, sizeOfLongest = 0, counter = 0;

		for (counter = 0; counter < line.size(); counter++) {
			line.at(counter); // Go thru each char in the line
			numChars++; // Count how many letters are in a word
			// cout << "\nNumbers of chars: " << numChars << "\n";
			// cout << "i: " << i << "\n";

			if (line.at(counter) == ' ' || line.at(counter) == '.') { // Encountered space, end of word being read in line
				if (maxChars < numChars) { // New longest word found
					maxChars = numChars - 1; // Report new max length of word minus the space or period
					cout << "Max chars: " << maxChars << "\n";
					sizeOfLongest = maxChars;
					// numChars = 0; // Reset char counter for next word
					// cout << "counter in if statement: " << counter << "\n";
				}
				numChars = 0; // Reset char counter for next word
				//counter++; // Go to next word in line
			}
		}
		cout << "\nLongest Word: ";

		foundAt = (counter - sizeOfLongest); // Report where found in line
		cout << "Counter: " << counter << "\n";
		cout << "Size of longest: " << sizeOfLongest << "\n";
		cout << "Found At: " << foundAt;

		string longestWord(line, foundAt - 1, sizeOfLongest);
		cout << longestWord;

		for (foundAt; foundAt < sizeOfLongest; foundAt++) {
			cout << line.at(foundAt);
		}
	*/
}

void displayAll(vector<string> & stringVec) {
	printDivider();

	/*	for (auto element : stringVec) {
			cout << element;

			if (element == ".")
				cout << "\n";
		}
	*/
	// Work on each line of file
	for (unsigned int i = 0; i < stringVec.size(); i++) {
		cout << stringVec[i]; // Output line from file

		displayGrammar(stringVec[i]); // Report the number of vowels, consonants, etc.

		titleCase(stringVec[i]);
		sentenceCase(stringVec[i]);
		exceptionsCase(stringVec[i]);
		toggleCase(stringVec[i]);
		longestWord(stringVec[i]);

		printDivider();
	}
}

int main() {
	ifstream infile; // For input file stream
	string fileName = " "; // Name of file
	vector<string> stringVec; // Vector consisting of strings that will be read from file line by line

	promptForFile(fileName); // Initial prompt to enter file name
	openForReading(infile, fileName); // Process user's file request

	storeLines(infile, stringVec); // Each line is an element in the string vector, 1 string = 1 line of file = 1 element of vector
	displayAll(stringVec); // Designated program output
}