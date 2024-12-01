#include "Sort.h"

using namespace std;

int insertionSort(int* a, int size) {
    int count = 0;

    for (int i = 1; i < size; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            count++;
            
        }
        a[j + 1] = key;
        count++;
    }

    return count;
}

void quickSort(int* a, int p, int r, int &count) {
    if (p < r) {
        int q = partition(a, p, r, count);
        quickSort(a, p, q - 1, count);
        quickSort(a, q + 1, r, count);
    }
}

int partition(int* a, int p, int r, int &count){
    int pivot = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j] <= pivot) {
            count++;
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i+ 1] = a[r];
    a[r] = temp;
    return (i + 1);
}

void mergeSort(int* a, int p, int r, int &count) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(a, p, q, count);
        mergeSort(a, q + 1, r, count);
        count += daMerge(a, p, q, r);
    }
}

int daMerge(int* a, int p, int q, int r){
    int count = 0;
    int leftS = q - p + 1;
    int rightS = r - q;
    int* leftA = new int[leftS];
    int* rightA = new int[rightS];

    for (int i = 0; i < leftS; i++) {
        leftA[i] = a[p + i];
    }
    for (int i = 0; i < rightS; i++) {
        rightA[i] = a[q + i + 1];
    }

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (i < leftS && (j >= rightS || leftA[i] <= rightA[j])) {
            a[k] = leftA[i];
            i++;
        }
        else {
            a[k] = rightA[j];
            j++;
        }
        count++;
    }

    delete[] leftA;
    delete[] rightA;
    return count;
}

void convertIn(string s, int* array) {
    ifstream infile;
    infile.open(s);

    int size = 0;

    if (infile.is_open()) {
        string line;
        getline(infile, line);
        while (getline(infile, line)) {
            stringstream temp(line);
            string hold;
            while (getline(temp, hold, ',')) {
                getline(temp, hold, ',');
                array[size] = stoi(hold);
                size++;
            }
        }

        infile.close();

    }
    else {
        cout << "Error: File not found!?!?!" << endl;
    }
    
}

void printSort(int* a, int size){
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl << endl;
}
