#include <iostream>
#include <string>
#include <iomanip>

class Date {
private:
    int day;
    int month;
    int year;
    
    // Перевірка чи день коректний для даного місяця і року
    bool isValidDay(int d, int m, int y) const {
        if (d < 1 || d > 31) return false;
        if (m == 2) {
            bool isLeap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
            if (d > 28 + isLeap) return false;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d > 30) return false;
        }
        return true;
    }

public:
    // Конструктори
    Date(int d = 1, int m = 1, int y = 2000) {
        setDate(d, m, y);
    }

    Date(const Date& other) { // Конструктор копіювання
        day = other.day;
        month = other.month;
        year = other.year;
    }

    // Функції встановлення значень
    void setDay(int d) {
        if (isValidDay(d, month, year)) day = d;
        else std::cout << "Invalid day!" << std::endl;
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 12 && isValidDay(day, m, year)) month = m;
        else std::cout << "Invalid month!" << std::endl;
    }

    void setYear(int y) {
        if (isValidDay(day, month, y)) year = y;
        else std::cout << "Invalid year for this date!" << std::endl;
    }

    void setDate(int d, int m, int y) {
        if (m < 1 || m > 12 || !isValidDay(d, m, y)) {
            std::cout << "Invalid data!" << std::endl;
            return;
        }
        day = d;
        month = m;
        year = y;
    }

    // Функції отримання значень
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Функції друку
    void print() const {
        const char* months[] = {"sichnya", "liytoho", "bereznya", "kvitnya", "travnya", "chervnya",
                                "lipnya", "serpnya", "veresnya", "zhovtnya", "listopada", "hrydnya"};
        std::cout << day << " " << months[month-1] << " " << year << " року" << std::endl;
    }

    void printNumeric() const {
        std::cout << std::setfill('0') << std::setw(2) << day << "."
                  << std::setfill('0') << std::setw(2) << month << "." << year << std::endl;
    }
};

int main() {
    Date d(15, 3, 2023);
    d.print(); // 15 березня 2023 року
    d.printNumeric(); // 15.03.2023

    // Тест зміни дати
    d.setDate(29, 2, 2024); // Встановлення дати 29 лютого 2024 (високосний рік)
    d.print(); // 29 лютого 2024 року
    d.printNumeric(); // 29.02.2024

    d.setDate(31, 4, 2023); // Невалідна дата
    d.setDate(30, 4, 2023); // Валідна дата
    d.print(); // 30 квітня 2023 року
    d.printNumeric(); // 30.04.2023

    system("pause");
    return 0;
}
