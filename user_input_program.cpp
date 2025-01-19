//============================================================================
// Name        : User Input Program
// Author      : FM
// Version     :
// Copyright   :
// Description : Takes a user's input and appends it into a given text file.
//               Then it reverses all the characters in the file and stores
//               the result in another file.
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void reverseTextFile (string inputFileName, string outputFileName) {
    ifstream inFile (inputFileName);
    string content;
    string line;

    cout << "Reversing " + inputFileName + " file..." << endl;
    if (inFile.is_open()) {
        while (getline (inFile, line)) {
            content += line + "\n";
        }
        inFile.close();
    }
    else cout << "Unable to open " + inputFileName + " file." << endl;

    ofstream outFile (outputFileName);
    if (outFile.is_open()) {
        for (int i = content.size() - 1; i >= 0; i--) {
            outFile << content[i];
        }
        cout << inputFileName + " file successfully reversed." << endl;
        cout << "Reversed text is in output file " + outputFileName << endl;
    }
    else cout << "Unable to open " + outputFileName + " file." << endl;
}

int main () {
    string userInput;
    cout << "Enter your data below:" << endl;
    getline (cin, userInput);

    ofstream outFile ("CSC450_CT5_mod5.txt", ios::app);
    if (outFile.is_open()) {
        outFile << userInput + "\n";
        outFile.close();
        cout << "Your data has been successfully added to the file." << endl;
    }
    else cout << "Unable to open file." << endl;

    reverseTextFile ("CSC450_CT5_mod5.txt", "CSC450-mod5-reverse.txt");

    return 0;
}
