#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    // Lege einen leeren Vektor von Strings an
    vector<string> words;
    
    // kopiere die Kommandozeilenargumente
    for (int i{1}; i < argc; ++i) {
        words.push_back(argv[i]);
    }

    // und gib die Worte wieder aus
    for (int i{0}; i < words.size(); ++i) {
        cout << words[i] << endl;
    }
}
