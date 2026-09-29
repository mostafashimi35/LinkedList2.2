#include <iostream>
#include <algorithm>
using namespace std;

class SortAnalyser {

public:

    void bubbleSort(int arr[], int n, long long& counter) {

        for (int i = 0; i < n-1; i++) {

            for (int j = 0; j < n-1-i; j++) {

                counter++; // count comparison

                if (arr[j] > arr[j+1])
                    swap(arr[j], arr[j+1]);
            }
        }
    }
    
    //sees where the minimum value is and throw it the beginning of the unsorted
    void selectionSort(int arr[], int n, long long& counter) {

        for (int i = 0; i < n - 1; i++) {

            int minIndex = i;

            for (int j = i + 1; j < n; j++) {

                counter++;

                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            swap(arr[i], arr[minIndex]);
        }
    }

    //takes the next element and puts it in the right position
    void insertionSort(int arr[], int n, long long& counter) {

        for (int i = 1; i < n; i++) {

            int key = arr[i];
            int j = i - 1;

            while (j >= 0) {

                counter++;

                if (arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                else {
                    break;
                }
            }

            arr[j + 1] = key;
        }
    }
};