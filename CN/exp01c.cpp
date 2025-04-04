#include <iostream>
#include <string>
using namespace std;

string byteStuffing(string data, char flag, char esc) {
    string stuffed = "";
    stuffed += flag;
    for (size_t i = 0; i < data.length(); i++) {
        if (data[i] == flag || data[i] == esc)
            stuffed += esc;
        stuffed += data[i];
    }
    stuffed += flag;
    return stuffed;
}

int main() {
    string data;
    char flag = 'F', esc = 'E';
    cout << "Enter the data: ";
    cin >> data;
    cout << "Stuffed Data: " << byteStuffing(data, flag, esc) << endl;
    return 0;
}
