#include<iostream>

using namespace std;

void ordenaIntercambio(int *arr) { //Complejjidad O(n^2), en este caso 10^2 = 100 operaciones

    int *pArr = arr;
    int aux;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (*(pArr + j) > *(pArr + j + 1)) {
                aux = *(pArr + j);
                *(pArr + j) = *(pArr + j + 1);
                *(pArr + j + 1) = aux;
            }
        }
    }
    
    cout << endl;
}

void bubbleSort(int *arr, int n) //Complejidad O(n^2), en este caso 10^2 = 100 operaciones
{
    int i, j;
    bool aux;
    for (i = 0; i < n - 1; i++) {
        aux = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                aux = true;
            }
        }
        if (aux == false)
            break;
    }
}

void merge(int array[], int const left, int const mid, //Lo intente hacer yo, y no salia, saque este codigo de: https://www.geeksforgeeks.org/merge-sort/
           int const right) //Complejidad O(n log n), en este caso 10 log 10 = 33 operaciones
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}


void mergeSort(int array[], int const begin, int const end) // Complejidad O(n log n), en este caso 10 log 10 = 33 operaciones
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


int busqInterpola(int *arr , int n, int x) { // Complejidad O(log log n), en este caso log log 10 = 2 operaciones
    int lo = 0, hi = (n - 1);
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        if (lo == hi) {
            if (arr[lo] == x) return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}

int busqBinaria(int *arr, int l, int r, int x) { // Complejidad O(log n), en este caso log 10 = 3 operaciones
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}   

void imprimeArray(int *arr, int n) { //Complejidad O(n), en este caso 10 operaciones, no influye en nada pero ya que estamos...
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {

    int arr[10] = { 5, 2, 4, 6, 1, 3, 9, 7, 8, 10 };
    int arr2[10] = {6,5,9,8,7,1,2,3,4,10};
    int arr3[10] = { 8,9,7,5,3,2,4,6,6,1 };

    ordenaIntercambio(arr); //Array
    bubbleSort(arr2, 10); //Array, tamaño
    merge(arr3, 0, 4, 9); //Array, inicio, mitad, final

    cout << "El resultado de ordenar con intercambio es: " << endl;
    imprimeArray(arr, 10); 
    cout << "El resultado de ordenar con bubble sort es: " << endl;
    imprimeArray(arr2, 10); 
    cout << "El resultado de ordenar con merge sort es: " << endl;
    imprimeArray(arr3, 10); 

    cout << "El indice del numero 5 con busqueda de interpolacion es: "<< busqInterpola(arr, 10, 5) << endl; // Array, tamaño, elemento a buscar
    cout << "El indice del numero 5 con busqueda binaria es: " << busqBinaria(arr2, 0, 9, 5) << endl; // Array, inicio, final, elemento a buscar
    return 0;
}