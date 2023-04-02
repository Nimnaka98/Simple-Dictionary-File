/*
Name: Hewa Kosgodage Nimnaka Yasith Ravishan Kumaradasa
Student ID: 10580019
Subject: Object Oriented Programming with C++/Assignment Part 1 (31/03/2023)
Lecturer: Mr. Martin Masek
Tutor: Mr. Guhanathan Pooravi
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

// task 1
struct Word {
    string name;
    string definition;
    string type;
};

//void type(string typeCode) {
//    
//}

// If the user enters capital letters between word/s or whole word/s;
// Function to convert a word to lowercase
string lowercase(string word) {
    string lowercaseWord;
    for (int i = 0; i < word.length(); i++) {
        lowercaseWord += tolower(word[i]);
    }
    return lowercaseWord;
}

// If the user enteres spaces between words;
// Function to remove spaces from a word
string removeSpace(string word) {
    string wordWithNoSpaces = word;
    wordWithNoSpaces.erase(remove(wordWithNoSpaces.begin(), wordWithNoSpaces.end(), ' '), wordWithNoSpaces.end());
    return wordWithNoSpaces;
}

// task 2
void searchDictionary(const vector <Word> & dictionary, string searchWord) {
    // searchWord = lowercase(searchWord);
    searchWord = removeSpace(lowercase(searchWord));
    bool found = false;
    for (const Word & word : dictionary) {
        if (removeSpace(lowercase(word.name)) == searchWord) {
            found = true;
            //cout << "\n";
            cout << "\n- The name of the word you entered: " << word.name << endl;
            //cout << "\n";
            cout << "\n- Word type is: ";
            if (word.type == "n") {
                cout << "[Noun]" << endl;
            }
            else if (word.type == "v") {
                cout << "[Verb]" << endl;
            }
            else if (word.type == "adj") {
                cout << "[Adjective]" << endl;
            }
            else if (word.type == "adv") {
                cout << "[Adverb]" << endl;
            }
            else if (word.type == "prep") {
                cout << "[Preposition]" << endl;
            }
            else if (word.type == "misc") {
                cout << "[Miscellaneous]" << endl;
            }
            else if (word.type == "pn") {
                cout << "[Proper Noun]" << endl;
            }
            else if (word.type == "nv") {
                cout << "[Noun and Verb]" << endl;
            }
            else {
                cout << "Invalid short word type." << endl;
            }
            //cout << "\n";
            cout << "\n- Word's definition: " << word.definition << endl;
            break;
        }
    }

    if (!found) { // prompt the error message if the dictionary is not loaded;
        cout << "- Sorry.. Word not found in the dictionary." << endl;
    }
}

// task 4
// Create a new Word struct and add it to the Dictionary
void addNewWord(Word word, vector<Word>listOfWords) {
    string fileName;
    listOfWords.push_back(word); //////////
    cout << "Enter a file name to save the updated dictionary to: ";
    getline(cin, fileName);
    fileName += ".txt"; // concatenate ".txt" to the end of the file name (after user entered the name);
    ofstream newFile(fileName);

    /*for (const fileName) {
        newFile << word.name << ";" << word.type << ";" << word.definition << endl;
    }*/
    cout << "\nGreat! The word you entered will be added to the dictionary and saved to the file." << endl;

    for (int i = 0; i < listOfWords.size(); i++) {
        newFile << "<word>\n";
        newFile << listOfWords[i].name << "\n";
        newFile << listOfWords[i].definition << "\n";
        newFile << listOfWords[i].type << "\n";
        newFile << "</word>\n";
    }
    newFile.close();
}
/////////
int main() {
    const string DICTIONARY_NAME = "dictionary_2023S1.txt";
    string line;
    vector <Word> Dictionary;
    string currentLine;

    // task 1
    // ask from the user to enter the dictionary file name or use the default file;
    cout << "- Enter the file name or press the enter to use the default file: ";
    string fileName;
    getline(cin, fileName);
    if (fileName == "") {
        fileName = DICTIONARY_NAME;
    }

    // opening the dictionary file.
    ifstream dictionaryDetails(DICTIONARY_NAME);

    if (dictionaryDetails.is_open()) {

        Word word;
        int WordDetailsCount = 0;
        istringstream iss(line);

        while (!dictionaryDetails.eof()) {
            getline(dictionaryDetails, currentLine); // save the line by line

            if (currentLine == "<word>") {
                getline(dictionaryDetails, word.name);
                getline(dictionaryDetails, word.definition);
                getline(dictionaryDetails, word.type);
                Dictionary.push_back(word);
            }

            // if (line == "<word>") {
                // WordDetailsCount = 0;
        }
        ///////////
        dictionaryDetails.close();
        /*cout << listOfWords[5].name << "|" << listOfWords[5].definition << "|" << listOfWords[5].type;*/
        cout << "\n\n";
        cout << "---- H E L L O  U S E R  F R I E N D !! ----\n\n";
        cout << "- Dictionary file is successfully loaded!" << endl;
        // cout << "" << endl;
        cout << "- Dictionary file size is: " << Dictionary.size() << endl;

        bool exit = false;
        while (!exit)
        {
            // print the menu and ask from the user to enter an option;
            cout << "\n\n";
            cout << "--^-^-- W E L C O M E  T O  T H E  D I C T I O N A R Y  F I L E  S Y S T E M !! --^-^--\n\n";
            cout << " ~ Main Menu. Select Your Number ~\n";
            cout << " 1) Find a word.\n";
            cout << " 2) Find all words containing more than three letters 'z'.\n";
            cout << " 3) Add a word to the dictionary by yourself.\n";
            cout << " 4) Exit (If you want to exit the system, press enter twice after selecting option 4!).\n";
            cout << "\n";
            cout << "- Enter your choice and press the enter: ";
            char choice;
            cin >> choice; // get the choice;
            cin.ignore(); // ignore the newline character left in the buffer by cin;

            switch (choice)
            {
            case '1':
            {
                string searchWord;
                cout << "\n- Enter your word to search for: "; // ask the word from the user;
                getline(cin, searchWord);
                searchDictionary(Dictionary, searchWord);

                // ask from the user if they want to search another word or exit;
                char searchAgain;
                // just ask from the user if he/she wants to go to the main menu again to do another option or search a word;
                cout << "\n- Do you want to go to the main menu to search for another word or other options? (y/n): ";
                cin >> searchAgain;
                if (searchAgain == 'n' || searchAgain == 'N') {
                    exit = true;
                    // cout << "\nThank you for using the D I C T I O N A R Y  F I L E  S Y S T E M. Good day!" << endl;
                }
            }
            break;
            //////////////
            // task 3;
            case '2':
            {
                bool found = false;
                for (const Word & word : Dictionary) {
                    int count = 0;
                    for (char d : word.name) {
                        if (d == 'z') {
                            count++;
                        }
                    }
                    if (count > 3) {
                        found = true;
                        cout << "\n";
                        cout << "- Word/s that contain/s more than three 'z' is/are: " << word.name << endl;
                    }
                }
                if (!found) {
                    cout << "- Sorry.. No word found with more than three 'z' characters." << endl;
                }
                ////////////////
                // ask user if they want to search another word or exit
                char searchAgain;
                cout << "\n- Do you want to search for another word? (y/n): ";
                cin >> searchAgain;
                if (searchAgain == 'n' || searchAgain == 'N') {
                    exit = true; // if(searchAgain == 'y' || searchAgain == 'Y')
                }
            }
            break;
            //////////////
            // task 4
            case '3':
                cout << "Enter the word's name: ";
                cin >> word.name;

                cout << "Enter the word's type: ";
                cin.ignore();
                getline(cin, word.type);

                cout << "Enter the word's definition: ";
                cin.ignore();
                getline(cin, word.definition);

                addNewWord(word, Dictionary);

                break;
            ////////////
            case '4':
                exit = true;
                cout << "\n---^^--- Thank you for using the D I C T I O N A R Y  F I L E  S Y S T E M. Good day! ---^^---" << endl;
                break;

            default:
                cout << "\n- Sorry.. Invalid option, Try again.\n";
            }
        }
    }
    else {
        cout << "- Sorry, Failed to open the Dictionary file." << endl;
        return 1;
    }
    return 0;
}

/*
End of the Assignment
Name: Hewa Kosgodage Nimnaka Yasith Ravishan Kumaradasa
Student ID: 10580019
Subject: Object Oriented Programming with C++/Assignment Part 1 (31/03/2023)
Lecturer: Mr. Martin Masek
Tutor: Mr. Guhanathan Pooravi
*/