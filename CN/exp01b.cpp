#include <iostream>
using namespace std;

string bitStuffing(string data) {
    string stuffed = "";
    int count = 0;

    for (size_t i = 0; i < data.size(); ++i) {
        char bit = data[i];
        stuffed += bit;
        if (bit == '1') {
            count++;
            if (count == 5) { // If 5 consecutive 1s, stuff a 0
                stuffed += '0';
                count = 0; // Reset count
            }
        } else {
            count = 0;
        }
    }
    return stuffed;
}

string bitDestuffing(string stuffed) {
    string destuffed = "";
    int count = 0;

    for (size_t i = 0; i < stuffed.size(); i++) {
        destuffed += stuffed[i];
        if (stuffed[i] == '1') {
            count++;
            if (count == 5) { // If five 1s are found, skip the next bit (stuffed 0)
                i++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return destuffed;
}

int main() {
    string bitData = "00110011010";
    cout << "Bit Data: " << bitData << endl;
    
    string stuffed = bitStuffing(bitData);
    cout << "Bit Stuffed: " << stuffed << endl;

    string destuffed = bitDestuffing(stuffed);
    cout << "Bit Destuffed: " << destuffed << endl;

    return 0;
}
