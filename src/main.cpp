#include "functions.h"  
#include <iostream>
#include <vector>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    std::cout << "Введите размер массива: ";
    if (!(std::cin >> size) || size <= 0) {
        std::cerr << "Ошибка: некорректный размер массива.\n";
        return 1;
    }

    std::vector<int> arr(size);
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        if (!(std::cin >> arr[i])) {
            std::cerr << "Ошибка: некорректный ввод.\n";
            return 1;
        }
    }

    ThreadData data = { &arr, 0, 0, 0.0 };

    HANDLE hThreadMinMax = CreateThread(NULL, 0, minMaxThread, &data, 0, NULL);
    HANDLE hThreadAvg = CreateThread(NULL, 0, averageThread, &data, 0, NULL);

    WaitForSingleObject(hThreadMinMax, INFINITE);
    WaitForSingleObject(hThreadAvg, INFINITE);

    CloseHandle(hThreadMinMax);
    CloseHandle(hThreadAvg);

    replaceMinMax(arr, data.min, data.max, data.average);

    std::cout << "Массив после замены: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
