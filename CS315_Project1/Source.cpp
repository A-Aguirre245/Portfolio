#include "Sort.h"
#include <iostream>

using namespace std;

int main() {

    int* sortSmall = new int[maxSmall];
    int* sortMedium = new int [maxMed];
    int* sortLarge = new int[maxLarge];
    int* invSmall = new int[maxSmall];
    int* invMedium = new int[maxMed];
    int* invLarge = new int[maxLarge];
    int* ranSmall = new int[maxSmall];
    int* ranMedium = new int[maxMed];
    int* ranLarge = new int[maxLarge];

    string names[9] = { "pokemonSortedSmall.csv","pokemonSortedMedium.csv", "pokemonSortedLarge.csv", "pokemonReverseSortedSmall.csv",
        "pokemonReverseSortedMedium.csv","pokemonReverseSortedLarge.csv", "pokemonRandomSmall.csv",
        "pokemonRandomMedium.csv","pokemonRandomLarge.csv" };

    int* sorts[9] = { sortSmall, sortMedium, sortLarge, invSmall, invMedium, invLarge, ranSmall, ranMedium, ranLarge };

    int sizes[3] = { maxSmall, maxMed, maxLarge };

    //sortPrint(names, sorts, sizes, 9);

    int counter;
    for (int i = 0; i < 9; i++) {
        counter = 0;

        cout << "File Name : " << names[i] << endl;
        cout << "Initial Order : ";
        convertIn(names[i], sorts[i]);
        printSort(sorts[i], sizes[i % 3]);
        cout << "Order after Insertion Sort : ";
        counter = insertionSort(sorts[i], sizes[i % 3]);
        printSort(sorts[i], sizes[i % 3]);
        cout << "Number of Comparisons Insertion Sort : " << counter << endl << endl;
        cout << "Order after Merge Sort : ";
        convertIn(names[i], sorts[i]);
        counter = 0;
        mergeSort(sorts[i], 0, sizes[i % 3] - 1, counter);
        printSort(sorts[i], sizes[i % 3]);
        cout << "Number of Comparisons Merge Sort : " << counter << endl << endl;
        cout << "Order after QuickSort : ";
        counter = 0;
        convertIn(names[i], sorts[i]);
        quickSort(sorts[i], 0, sizes[i % 3] - 1, counter);
        printSort(sorts[i], sizes[i % 3]);
        cout << "Number of Comparisons QuickSort : " << counter << endl << endl;

        delete[] sorts[i];
    }
}