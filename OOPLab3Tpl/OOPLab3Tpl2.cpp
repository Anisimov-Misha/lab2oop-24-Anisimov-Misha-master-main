#include <iostream>
#include <cassert>

class Vector {
private:
    int* data;
    size_t size;
    int state; 
    static int object_count;

public:

    Vector() : size(1), state(0) {
        data = new (std::nothrow) int[1];
        if (data) {
            data[0] = 0;
        } else {
            state = 1;
        }
        object_count++;
    }

    Vector(size_t n) : size(n), state(0) {
        data = new (std::nothrow) int[n];
        if (data) {
            for (size_t i = 0; i < n; ++i) {
                data[i] = 0;
            }
        } else {
            state = 1;
        }
        object_count++;
    }

    Vector(size_t n, int init) : size(n), state(0) {
        data = new (std::nothrow) int[n];
        if (data) {
            for (size_t i = 0; i < n; ++i) {
                data[i] = init;
            }
        } else {
            state = 1;
        }
        object_count++;
    }

    Vector(const Vector& other) : size(other.size), state(other.state) {
        data = new (std::nothrow) int[size];
        if (data) {
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        } else {
            state = 1;
        }
        object_count++;
    }

    // Оператор присвоєння
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            state = other.state;
            data = new (std::nothrow) int[size];
            if (data) {
                for (size_t i = 0; i < size; ++i) {
                    data[i] = other.data[i];
                }
            } else {
                state = 1;
            }
        }
        return *this;
    }

    ~Vector() {
        delete[] data;
        object_count--;
    }

    // Присвоєння елементу масиву значення
    void set(size_t index, int value = 0) {
        if (index >= size) {
            state = 2;
            return;
        }
        data[index] = value;
    }

    // Отримання елементу масиву
    int get(size_t index) const {
        if (index >= size) {
            return 0; 
        }
        return data[index];
    }

    // Вивід вектора
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Додавання векторів
    Vector operator+(const Vector& rhs) const {
        assert(size == rhs.size); // Мають бути однакової довжини
        Vector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] + rhs.data[i];
        }
        return result;
    }

    // Віднімання векторів
    Vector operator-(const Vector& rhs) const {
        assert(size == rhs.size);
        Vector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] - rhs.data[i];
        }
        return result;
    }

    // Множення вектора на ціле число
    Vector operator*(short scalar) const {
        Vector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    // Порівняння векторів
    bool operator==(const Vector& rhs) const {
        if (size != rhs.size) return false;
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != rhs.data[i]) return false;
        }
        return true;
    }

    bool operator<(const Vector& rhs) const {
        if (size != rhs.size) return false;
        for (size_t i = 0; i < size; ++i) {
            if (data[i] >= rhs.data[i]) return false;
        }
        return true;
    }

    bool operator>(const Vector& rhs) const {
        if (size != rhs.size) return false;
        for (size_t i = 0; i < size; ++i) {
            if (data[i] <= rhs.data[i]) return false;
        }
        return true;
    }

    // Функція для перевірки стану
    int getState() const {
        return state;
    }

    // Підрахунок числа об'єктів класу
    static int getObjectCount() {
        return object_count;
    }
};

int Vector::object_count = 0;

int main() {
    // Тестування класу Vector
    Vector v1(5, 2);
    Vector v2(5, 3);
    Vector v3;

    v1.print(); // 2 2 2 2 2
    v2.print(); // 3 3 3 3 3
    v3.print(); // 0

    Vector v4 = v1 + v2;
    v4.print(); // 5 5 5 5 5

    Vector v5 = v1 - v2;
    v5.print(); // -1 -1 -1 -1 -1

    Vector v6 = v1 * 2;
    v6.print(); // 4 4 4 4 4

    std::cout << "Objects count: " << Vector::getObjectCount() << std::endl; // 6

    system("pause");
    return 0;
}
