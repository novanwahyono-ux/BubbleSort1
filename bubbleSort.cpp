#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

[[nodiscard]] bool saver() {
    if (std::cin.eof()) {
        std::cerr << "[!]DANGER. Closing Program For Safety.\n";
        return false;
    }

    if (std::cin.fail()) {
        std::cin.clear();
    }

    return true;
}

void bufferClear() {
    if (std::cin.fail()) {
        std::cin.clear();
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> dbNumber;
    int input;

    while (true) {
        std::cout << "Enter Number Or Enter -1 For Exit: " << std::flush;
        if (!(std::cin >> input)) {
            if (!(saver())) return 1;
            bufferClear();
            std::cerr << "Input Invalid. Please Input Integer Number.\n";
            continue;
        }
        bufferClear();

        if (input == -1) {
            break;
        }

        dbNumber.push_back(input);
    }

    std::cout << "==================================================\n";
    size_t size = dbNumber.size();
    std::cout << "Before Bubble Sort: ";
    for (size_t i = 0; i < size; i ++) {
        std::cout << dbNumber[i] << " ";
    }
    std::cout << "\n";

    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (dbNumber[j] > dbNumber[j + 1]) {
                std::swap(dbNumber[j], dbNumber[j + 1]);
            }
        }
    }

    
    std::cout << "After Bubble Sort: ";
    for (size_t i = 0; i < size; i++) {
        std::cout << dbNumber[i] << " ";
    }
    std::cout << "\n==================================================\n";
    std::cout << "\n";
    return 0;
}
