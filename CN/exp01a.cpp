#include <iostream>
#include <string>
using namespace std;

string characterStuffing(string data, char flag = 'F', char esc = 'E') {
    string stuffed = "";
    stuffed += flag; // Start flag

    for (char ch : data) {
        if (ch == flag || ch == esc) {
            stuffed += esc; // Add ESC before FLAG or ESC
        }
        stuffed += ch;
    }
    
    stuffed += flag; // End flag
    return stuffed;
}

string characterDestuffing(string stuffed, char flag = 'F', char esc = 'E') {
    if (stuffed.front() != flag || stuffed.back() != flag) {
        throw invalid_argument("Invalid frame");
    }

    string destuffed = "";
    for (size_t i = 1; i < stuffed.size() - 1; i++) { // Skip flags
        if (stuffed[i] == esc) {
            i++; // Skip ESC and take the next character as is
        }
        destuffed += stuffed[i];
    }
    return destuffed;
}

int main() {
    string data = "AABFBBE";
    cout << "Data: " << data << endl;
    
    string stuffed = characterStuffing(data);
    cout << "Stuffed: " << stuffed << endl;

    string destuffed = characterDestuffing(stuffed);
    cout << "Destuffed: " << destuffed << endl;

    return 0;
}
