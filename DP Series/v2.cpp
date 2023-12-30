#include <bits/stdc++.h>
using namespace std;

string removeNonAlphabetic(string& input) {
    string result = "";
    for (char ch : input) {
        if (isalpha(ch)) {
            result += ch;
        }
        else if(isspace(ch)){
            result += ' ';
        }
    }
    return result;
}

string capitalizeWords(string& input) {
    string result = input;

    for(int i = 0; i < result.size(); i++){
        if(i == 0 || result[i-1] == ' '){
            result[i] = toupper(result[i]);
        }
    }

    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    // Remove non-alphabetic characters
    string alphabeticOnly = removeNonAlphabetic(input);

    // Capitalize the first letter of each word
    string result = capitalizeWords(alphabeticOnly);

    cout << "Modified string: " << result << endl;

    return 0;
}
