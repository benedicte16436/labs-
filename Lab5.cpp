#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("1.tXt");
    ofstream outputFile("output.12.txt");

    if (!inputFile.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier d'entrée." << endl;

    }

    if (!outputFile.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier de sortie." << endl;
        return 1;
    }

    string line, text;
    while (getline(inputFile, line)) {
        text += line + '\n';
    }

    vector<string> sentences;
    string currentSentence;
    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            currentSentence += text[i];
            sentences.push_back(currentSentence);
            currentSentence = ";";
            if (i + 1 < text.length() && text[i + 1] != '\n') {
                currentSentence += '\n';
            }

        }
        else {
            currentSentence += text[i];
        }
    }


    for (const string& sentence : sentences) {
        outputFile << "   " << sentence << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
