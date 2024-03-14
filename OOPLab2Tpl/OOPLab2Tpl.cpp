#include <iostream>

int main() {
    int a, b, c, d;

    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;
    std::cout << "Enter d: ";
    std::cin >> d;

// Обчислення виразу ((15*a + 312*b) / 64) - c*120 + d*121 без множення та ділення
    double result = (((a << 4) + (b << 8)) >> 6) - (c << 7) + (d << 7);

    std::cout << "Result: " << result << std::endl;

    system("pause");
    return 0;
}

