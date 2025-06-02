#include "functions.h"
#include <iostream>
#include <windows.h>

void findMinMax(const std::vector<int>& arr, int& min, int& max) {
    min = max = arr[0];
    for (int num : arr) {
        if (num < min) min = num;
        Sleep(7);
        if (num > max) max = num;
        Sleep(7);
    }
}

double computeAverage(const std::vector<int>& arr) {
    double sum = 0;
    for (int num : arr)
    {
        sum += num;
        Sleep(12);
    }
    return sum / arr.size();
}

void replaceMinMax(std::vector<int>& arr, int min, int max, double avg) {
    for (int& num : arr) {
        if (num == min || num == max) num = static_cast<int>(avg);
    }
}

DWORD WINAPI minMaxThread(LPVOID lpParam) {
    ThreadData* data = static_cast<ThreadData*>(lpParam);
    findMinMax(*data->arr, data->min, data->max);
    std::cout << "Минимальный элемент: " << data->min << "\n";
    std::cout << "Максимальный элемент: " << data->max << "\n";
    return 0;
}

DWORD WINAPI averageThread(LPVOID lpParam) {
    ThreadData* data = static_cast<ThreadData*>(lpParam);
    data->average = computeAverage(*data->arr);
    std::cout << "Среднее значение: " << data->average << "\n";
    return 0;
}
