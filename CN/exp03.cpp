#include <iostream>
#include <string>

using namespace std;

// Function to perform XOR operation
string xorOperation(string dividend, string divisor) {
    for (int i = 0; i < divisor.length(); i++)
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    return dividend;
}

// Function to perform CRC division
string divideData(string data, string generator) {
    int dataLen = data.length();
    int genLen = generator.length();

    string temp = data.substr(0, genLen);
    cout << "Before XOR Division (Padded Data): " << data << endl;

    for (int i = genLen; i <= dataLen; i++) {
        if (temp[0] == '1') 
            temp = xorOperation(temp, generator);

        temp = temp.substr(1); // Remove first bit
        
        if (i < dataLen) 
            temp += data[i]; // Append next bit
    }
    
    cout << "Remainder after XOR Division: " << temp << endl;
    return temp;
}

int main() {
    string dataBits, generator;
    
    cout << "Enter data bits: ";
    cin >> dataBits;
    
    cout << "Enter generator polynomial: ";
    cin >> generator;

    // Append zeros to data
    string paddedData = dataBits + string(generator.length() - 1, '0');
    
    // Get remainder
    string remainder = divideData(paddedData, generator);
    
    // Transmitted data
    string transmittedData = dataBits + remainder;
    cout << "Transmitted data: " << transmittedData << endl;

    // Receiving side
    string receivedData;
    cout << "Enter received data: ";
    cin >> receivedData;

    cout << "Before Checking, Received Data: " << receivedData << endl;
    
    // Compute remainder for received data
    string checkRemainder = divideData(receivedData, generator);

    if (checkRemainder.find('1') != string::npos) 
        cout << "Error detected in received data." << endl;
    else 
        cout << "No error detected. Data received correctly." << endl;

    return 0;
}
