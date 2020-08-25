#include <iostream>
#include <functional>

#ifndef sorting
#define sorting

using namespace std;

int hello_init();

int* quicksort(int* arr, int l, int r);
int partition(int* arr, int l, int r);

#endif