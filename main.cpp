#include <iostream>
#include <Windows.h>
#include <string>

class Counter {
private:
    int value;

public:
    // Конструктор по умолчанию (значение = 1)
    Counter() : value(1) {}

    // Конструктор с параметром
    Counter(int initialValue) : value(initialValue) {}

    void increment() {
        value++;
    }

    void decrement() {
        value--;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::string answer;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> answer;

    Counter counter;  // Временный объект

    if (answer == "да" || answer == "Да") {
        int initialValue;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initialValue;
        counter = Counter(initialValue);  // Просто присваиваем новое значение
    }

    char command;

    while (true) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        switch (command) {
        case '+':
            counter.increment();
            break;
        case '-':
            counter.decrement();
            break;
        case '=':
            std::cout << counter.getValue() << std::endl;
            break;
        case 'x':
            std::cout << "До свидания!" << std::endl;
            return 0;
        default:
            std::cout << "Неизвестная команда!" << std::endl;
            break;
        }
    }

    return 0;
}  // Память освободится автоматически при выходе из функции
}