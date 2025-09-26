#include <iostream>
#include <vector>
using namespace std;

// escolhe um pivô, particiona o array em elementos < pivô (à esquerda) e > pivô (à direita) e ordena as duas partes recursivamente
// se os dados estiverem ordenados ou quase ordenados, pode ficar O(n²) porque o pivô é extremo

int partition(vector<int> &arr, int l, int r) {
    int pivot = arr[l];   // pivô é o primeiro elemento
    int i = l - 1;
    int j = r + 1;

    while (true) {
        // encontra elemento >= pivô pela esquerda (arr[i] < pivot --> crescente)
        // encontra elemento <= pivô pela esquerda (arr[i] > pivot --> decrescente)
        do {
            i++;
        } while (arr[i] > pivot);

        // encontra elemento >= ao pivô pela direita (arr[j] < pivot --> decrescente)
        // encontra elemento <= ao pivô pela direita (arr[j] > pivot --> crescente)
        do {
            j--;
        } while (arr[j] < pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p); 
        quickSort(arr, p + 1, r);
    }
}