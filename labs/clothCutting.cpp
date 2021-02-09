#include <iostream>
#include <stdlib.h> 
#include <algorithm>
using namespace std;

int wrapper(int X, int Y, int v[], int a[], int b[], int n);
int clothCutting(int X, int Y, int v[], int a[], int b[], int n, int **r);

int main(){
    // Test case. 9 x 5 rectangle.
    int X = 9;
    int Y = 5;
    // a[i] and b[i] corresponds to an a[i] x b[i] rectangle.
    int a[5] = {3, 2, 5, 8, 6};
    int b[5] = {4, 7, 3, 3, 7};
    // v[i] is the value of an a[i] x b[i] rectangle. 
    int v[5] = {10, 20, 30, 30, 35};
    int n = 5;
    // Output results.
    cout << "Maximum value for a " << X << " by " << Y << " cloth is: " << wrapper(X, Y, v, a, b, n) << endl;
}

int clothCutting(int X, int Y, int v[], int a[], int b[], int n, int **r){
    // Find the minimum element for each length array.
    int minA = *min_element(a, a + n);
    int minB = *min_element(b, b + n);

    // If the subproblem has been solved, return that.
    if(r[X][Y] != -1){
        return r[X][Y];
    }

    // If either X or Y is 0, that is the "edge" of the cloth so the value is 0.  
    if(X == 0 || Y == 0){
        r[X][Y] = 0;
        return 0;
    }

    // If the cloth width or height less than the minimum length for either list, don't bother cutting or calculating.
    if(X < minA || X < minB || Y < minA || Y < minB){
        r[X][Y] = 0;
        return 0;
    }
    else{
        // Variables needed
        int max = 0;
        int value1;
        int value2;
        // Cut vertically at every length.
        for(int x = 1; x < X; x++){
            // Calculate for the two pieces that come out from one cut.
            value1 = clothCutting(x, Y, v, a, b, n, r);
            value2 = clothCutting(X - x, Y, v, a, b, n, r);
            // If the new cut is the new max, replace the max.
            if(value1 + value2 > max){
                max = value1 + value2;
            }
        }
        // Cut horizontally at every length.
        for(int y = 1; y < Y; y++){
            // Calculate for the two pieces that come out from one cut.
            value1 = clothCutting(X, y, v, a, b, n, r);
            value2 = clothCutting(X, Y - y, v, a, b, n, r);
            // If the new cut is the new max, replace the max.
            if(value1 + value2 > max){
                max = value1 + value2;
            }
        }
        // Check if the dimensions of the cloth are equal to any dimensions in a[] b[] outright.
        // General Case.
        for(int c = 0; c < n; c++){
            if(X == a[c] && Y == b[c] || X == b[c] && Y == a[c]){
                if(v[c] > max){
                    max = v[c];
                }
            }
        }
        // Whatever value we find to be the max is the "cut" we store.
        r[X][Y] = max;
    }
    return r[X][Y];
}

// Wrapper function for memoization implementation.
int wrapper(int X, int Y, int v[], int a[], int b[], int n){
    // 2D array to store max value.
    int **results;
    results = new int*[X + 1];
    for(int i = 0; i <= X; i++){
        results[i] = new int[Y + 1];
    }
    // Fill left and top edge of cloth with 0, since a cut cannot be made at the edge.
    // Otherwise, fill with -1 for "not calculated yet."
    for(int i = 0; i <= X; i++){
        for(int j = 0; j <= Y; j++){
            if(i == 0 || j == 0){
                results[i][j] = 0;
            }
            else{
                results[i][j] = -1;
            }
        }
    }
    // Initial function call.
    clothCutting(X, Y, v, a, b, n, results);
    return results[X][Y];
}