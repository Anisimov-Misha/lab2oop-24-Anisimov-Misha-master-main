#include <iostream>
#include <string>
#include <bitset>

using namespace std;

const int MAX_LENGTH = 32;

string addSpaces(const string& input) {
    if (input.length() < MAX_LENGTH) {
        return input + string(MAX_LENGTH - input.length(), ' ');
    }
    return input.substr(0, MAX_LENGTH);
}

string encrypt(const string& input, int row) {
    string encryptedText = "";
    
    for (int i = 0; i < input.length(); ++i) {
        char currentChar = input[i];
        
        // Calculate parity bit
        int parityBit = 0;
        for (int j = 0; j < 7; ++j) {
            parityBit ^= ((currentChar >> j) & 1);
        }
        
        // Construct two-byte representation
        char firstByte = static_cast<char>((row << 6) | (i << 1) | (parityBit << 7));
        char secondByte = currentChar;
        
        encryptedText += firstByte;
        encryptedText += secondByte;
    }
    
    return encryptedText;
}

int main() {
    // Задані 4 рядки тексту
    string text[4];
    
    // Введення рядків тексту
    cout << "Enter text (up to 32 characters each):" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Row " << i + 1 << ": ";
        getline(cin, text[i]);
        text[i] = addSpaces(text[i]);
    }
    
    // Шифрування та вивід результату
    for (int i = 0; i < 4; ++i) {
        string encryptedRow = encrypt(text[i], i);
        
        cout << "Encrypted Row " << i + 1 << ": ";
        for (int j = 0; j < encryptedRow.length(); ++j) {
            cout << bitset<8>(encryptedRow[j]) << " ";
        }
        cout << endl;
    }
    
    system("pause");
    return 0;
}
