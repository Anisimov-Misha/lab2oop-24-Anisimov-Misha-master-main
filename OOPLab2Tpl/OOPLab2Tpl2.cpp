#include <iostream>
#include <string>
#include <bitset>

std::string encryptChar(char c, int row, int position) {
    int ascii_code = static_cast<int>(c);
    int parity_bit = std::bitset<8>(ascii_code).count() % 2;
    int first_byte = (row << 6) | (position << 1) | (parity_bit >> 0);
    int second_byte = (parity_bit << 7) | ascii_code;

    return std::bitset<8>(first_byte).to_string() + " " + std::bitset<8>(second_byte).to_string();
}

int main() {
    std::string lines[] = {"Hel", "lo", "wor", "ld"};

    for (int i = 0; i < 4; ++i) {
        std::string line = lines[i];
        for (int j = 0; j < line.length(); ++j) {
            std::cout << encryptChar(line[j], i, j) << " ";
        }
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}
