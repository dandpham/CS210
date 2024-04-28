/*
Dan Pham
CS210
April 27, 2024
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class FrequencyAnalyzer {
private:
	map<string, int> frequencies;

public:
	void readInputFile(const string& filename) {
		ifstream inputFile(filename);
		if (!inputFile.is_open()) {
			cout << "Error: Unable to open file" << filename << endl;
			return;
		}
		string item;
		int frequency;
		while (inputFile >> item >> frequency) {
			frequencies[item] = frequency;
		}
		inputFile.close();
	}

	int getFrequency(const string& item) {
		// Return frequency of a specific item
		if (frequencies.count(item)) {
			return frequencies[item];
		}
		else {
			return -1; // Item not found
		}
	}

	void printAllFrequencies() {
		// Print frequencies of all items
		for (const auto& pair : frequencies) {
			cout << pair.first << " " << pair.second << endl;
		}
	}

	void printHistogram() {
		// Print histogram of frequencies
		for (const auto& pair : frequencies) {
			cout << pair.first << " ";
			for (int i = 0; i < pair.second; ++i) {
			cout << "*";
			}
			cout << endl;
		}
	}

	void writeBackupFile() {
		// Write frequencies to backup file
		ofstream backupFile("frequency.dat");
		for (const auto& pair : frequencies) {
			backupFile << pair.first << " " << pair.second << endl;
		}
		backupFile.close();
	}
};

int main() {
	FrequencyAnalyzer analyzer;
	analyzer.readInputFile("CS210_Project_Three_Input_File.txt");

	int option;
	do {
		cout << "Menu Options:\n";
		cout << "1. Look up an item's frequency\n";
		cout << "2. Print all item frequencies\n";
		cout << "3. Print histogram of item frequencies\n";
		cout << "4. Exit\n";
		cout << "Enter your selection (1-4): ";
		cin >> option;

		switch (option) {
		case 1:
			{
				string item;
				cout << "Enter item to search for:";
				cin >> item;
				int frequency = analyzer.getFrequency(item);
				if (frequency != -1) {
				cout << frequency << endl;
				}
				else {
					cout << "Item not found." << endl;
				}
				break;
			}
		case 2:
			analyzer.printAllFrequencies();
			break;
		case 3:
			analyzer.printHistogram();
			break;
		case 4:
			analyzer.writeBackupFile();
			cout << "File backed up. Exiting program." << endl;
			break;
		default:
			cout << "Invalid option. Please enter a valid input." << endl;
		}
	} while (option != 4);

	return 0;
}



