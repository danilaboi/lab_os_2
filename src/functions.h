#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <windows.h>

struct ThreadData {
    std::vector<int>* arr;
    double average;
    int min, max;
};

void findMinMax(const std::vector<int>& arr, int& min, int& max);
double computeAverage(const std::vector<int>& arr);
void replaceMinMax(std::vector<int>& arr, int min, int max, double avg);


DWORD WINAPI minMaxThread(LPVOID lpParam);
DWORD WINAPI averageThread(LPVOID lpParam);

#endif
