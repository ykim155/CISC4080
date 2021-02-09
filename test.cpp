#include <iostream>
using namespace std;

int main() {
    int W = 13;
    int n = 4;
    int w[4] = {5, 3, 8, 4};
    int v[4] = {10, 20, 25, 8};

    int **results;
    results = new int*[n + 1];
    for(int k = 0; k <= n; k++){
    results[k] = new int[W + 1];
    }
    // Fill up the table with smaller subproblems until we get to the end.
    for(int it = 1; it <= n; it++){
    for(int wt = 1; wt <= W; wt++){
        // The first column and row are always 0. 
        // You cannot fit anything into a backpack with 0 weight left. 
        // If you have no items, you can't have any value.
        if(it == 0 || wt == 0){
            results[it][wt] = 0;
        }
        // Pick the max val between the previous item at weight wt or
        // the new item at v[it] combined with whatever fits with the leftover weight.
        else if(w[it - 1] <= wt){
            results[it][wt] = max(results[it - 1][wt], v[it] + results[it - 1][wt - w[it - 1]]);
        }
        else{
            results[it][wt] = results[it - 1][wt];
        }
    }
    }
    for(int i = 0; i <= n; i++){
    for(int j = 0; j <= W; j++){
        cout << results[i][j] << ' ';
    }
    cout << endl;
    }
}