#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    const string fileName = "text311.txt"; // File name to process
    ifstream inputFile(fileName);       // Open the file for reading

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file '" << fileName << "'." << endl;
        return 1;
    }

    cout << "Reading and displaying contents of '" << fileName << "'...\n" << endl;

    string line;
    vector<string> lines; // Store lines for further processing if needed

    // Read each line from the file
    while (getline(inputFile, line)) {
        lines.push_back(line);
        cout << line << endl; // Display the line
    }

    inputFile.close(); // Close the file

    // Example: Additional processing (optional)
    cout << "\nProcessing complete. Total lines read: " << lines.size() << endl;

    // Example: Search for a specific keyword in the text
    string keyword = "account";
    cout << "\nLines containing the keyword '" << keyword << "':\n" << endl;
    for (const auto& l : lines) {
        if (l.find(keyword) != string::npos) {
            cout << l << endl;
        }
    }
    system("pause");
    //return 0;
}