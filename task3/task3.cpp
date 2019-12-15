/*
 * Write a bubble sort algorithm in C++ sorting an array of numbers, 
 * values[], with a size of elementCount.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

void flip(int *elemA, int *elemB) {
  int temp = *elemA;
  *elemA = *elemB;
  *elemB = temp;
}

void sortArray(int array[], int length) {
  int i, j;
  for (i = 0; i < length - 1; i++)

  for (j = 0; j < length - i - 1; j++) {
    if (array[j] > array[j + 1])
        flip(&array[j], &array[j + 1]);
  }

}

void buildArray(int array[], int length) {
  srand((unsigned)time(0));
  // old-school for loop to populate array
  for (int i = 0; i < length; i++)
    array[i] = (rand()%100)+1;

}

int main() {
  int elementCount = 10;
  int array[elementCount];

  buildArray(array,elementCount);

  std::cout << "=== Random ==" << std::endl;

  for (int n : array)
    std::cout << n << std::endl;

  sortArray(array,elementCount);

  std::cout << "=== Sorted ==" << std::endl;
  for (int n : array)
    std::cout << n << std::endl;

}
