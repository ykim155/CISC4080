#include <iostream>
using namespace std;

void printArr(int L[], int n);
void selectionSortNested(int L[], int n);
void selectionSortRecursive(int L[], int left, int right);

int main(){
    int A[] = {3, 1, 5, 2, 7, 0};
    int B[] = {3, 1, 5, 2, 7, 0};
    int n = sizeof(A) / sizeof(A[0]);

    selectionSortNested(A, n);
    printArr(A, n);
    cout << '\n';
    selectionSortRecursive(B, 0, n);
    printArr(B, n);

    return 0;
}

void printArr(int L[], int n){
    for(int i = 0; i < n; i++){
        cout << L[i] << ' ';
    }
}

void selectionSortNested(int L[], int n){
    int right = n;
    // Outer loop
    for(int left = 0; left < right; left++){
        int s = left;
        // Inner loop
        for(int i = left + 1; i < right; i++){
            // Look for smallest.
            if(L[i] < L[s]){
                s = i;
            }
        }
        if(s != left){
            swap(L[s], L[left]);
        }
    }
}

void selectionSortRecursive(int L[], int left, int right){
    if(left == right){
        return;
    }
    int s = left;
    for(int i = left + 1; i < right; i++){
        if(L[i] < L[s]){
            s = i;
        }
    }
    if(s != left){
        swap(L[s], L[left]);
    }
    selectionSortRecursive(L, left + 1, right);
}