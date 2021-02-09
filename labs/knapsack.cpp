#include <iostream>
#include <assert.h>
#include <time.h>
using namespace std;

#define BILLION 1E9

int knapsack(int W, int n, int w[], int v[]);

int knapsackWrapper(int W, int w[], int v[], int n);
int knapsackMemo(int W, int n, int w[], int v[], int **results, int **include);

int knapsackTab(int W, int w[], int v[], int n);

int main(){
    struct timespec funcStart,funcEnd; 
    double elapsed;

    int W = 13;
    int n = 4;
    int w[4] = {5, 3, 8, 4};
    int v[4] = {10, 20, 25, 8};

    clock_gettime (CLOCK_REALTIME, &funcStart);
    cout << "Maximum value returned by pure recursive function: " << knapsack(W, n, w, v) << endl;
    clock_gettime (CLOCK_REALTIME, &funcEnd);
    elapsed = (funcEnd.tv_sec - funcStart.tv_sec) + (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
    cout << "Running Time: " << elapsed << " seconds" << endl;

    clock_gettime (CLOCK_REALTIME, &funcStart);
    cout << "Maximum value returned by recursive/memoization: " << knapsackWrapper(W, w, v, n) << endl;
    clock_gettime (CLOCK_REALTIME, &funcEnd);
    elapsed = (funcEnd.tv_sec - funcStart.tv_sec) + (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
    cout << "Running Time: " << elapsed << " seconds" << endl;

    clock_gettime (CLOCK_REALTIME, &funcStart);
    cout << "Maximum value returned by bottom-up tabulation: " << knapsackTab(W, w, v, n) << endl;
    clock_gettime (CLOCK_REALTIME, &funcEnd);
    elapsed = (funcEnd.tv_sec - funcStart.tv_sec) + (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
    cout << "Running Time: " << elapsed << " seconds" << endl;

    int A = 20;
    int b = 5;
    int x[5] = {5, 3, 8, 4, 7};
    int y[5] = {10, 20, 25, 8, 24};

    clock_gettime (CLOCK_REALTIME, &funcStart);
    cout << "Maximum value returned by pure recursive function: " << knapsack(A, b, x, y) << endl;
    clock_gettime (CLOCK_REALTIME, &funcEnd);
    elapsed = (funcEnd.tv_sec - funcStart.tv_sec) + (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
    cout << "Running Time: " << elapsed << " seconds" << endl;

    clock_gettime (CLOCK_REALTIME, &funcStart);
    cout << "Maximum value returned by recursive/memoization: " << knapsackWrapper(A, x, y, b) << endl;
    clock_gettime (CLOCK_REALTIME, &funcEnd);
    elapsed = (funcEnd.tv_sec - funcStart.tv_sec) + (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
    cout << "Running Time: " << elapsed << " seconds" << endl;

    clock_gettime (CLOCK_REALTIME, &funcStart);
    cout << "Maximum value returned by bottom-up tabulation: " << knapsackTab(A, x, y, b) << endl;
    clock_gettime (CLOCK_REALTIME, &funcEnd);
    elapsed = (funcEnd.tv_sec - funcStart.tv_sec) + (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
    cout << "Running Time: " << elapsed << " seconds" << endl;

    int S = 30;
    int d = 6;
    int z[6] = {5, 3, 8, 4, 7, 6};
    int a[6] = {10, 20, 25, 8, 24, 22};

    clock_gettime (CLOCK_REALTIME, &funcStart);
    cout << "Maximum value returned by pure recursive function: " << knapsack(S, d, z, a) << endl;
    clock_gettime (CLOCK_REALTIME, &funcEnd);
    elapsed = (funcEnd.tv_sec - funcStart.tv_sec) + (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
    cout << "Running Time: " << elapsed << " seconds" << endl;

    clock_gettime (CLOCK_REALTIME, &funcStart);
    cout << "Maximum value returned by recursive/memoization: " << knapsackWrapper(S, z, a, d) << endl;
    clock_gettime (CLOCK_REALTIME, &funcEnd);
    elapsed = (funcEnd.tv_sec - funcStart.tv_sec) + (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
    cout << "Running Time: " << elapsed << " seconds" << endl;

    clock_gettime (CLOCK_REALTIME, &funcStart);
    cout << "Maximum value returned by bottom-up tabulation: " << knapsackTab(S, z, a, d) << endl;
    clock_gettime (CLOCK_REALTIME, &funcEnd);
    elapsed = (funcEnd.tv_sec - funcStart.tv_sec) + (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
    cout << "Running Time: " << elapsed << " seconds" << endl;
}

int knapsack(int W, int n, int w[], int v[]){
    // Base Case
    if(W <= 0 ||  n == 0)
        return 0;
    // General Case
    if(w[n - 1] <= W){
        // Take the n-1th object
        int value1 = v[n - 1] + knapsack(W - w[n - 1], n - 1, w, v);
        // Don't take the n - 1th object
        int value2 = knapsack(W, n - 1, w, v);
        // Compare the two
        if(value1 >= value2)
            return value1;
        else
            return value2;
    }
    else{
        // Try the next (n - 2) object.
        return knapsack(W, n - 1, w, v);
    }
}

int knapsackMemo(int W, int n, int w[], int v[], int **results, int **include){
    // Same as the normal recursive function, but saves each subproblem and checks every recursive call.

    // Base case      
    if(results[n][W] != -1){
        cout << endl << "Overlap at: " << "W = " << W << " n = " << n;
        return results[n][W];
    }
    if(W <= 0 || n == 0){
        results[n][W] = 0;
        return results[n][W];
    }
    if(w[n - 1] <= W){
        // Take the n-1th object
        int value1 = v[n - 1] + knapsackMemo(W - w[n - 1], n - 1, w, v, results, include);
        // Don't take the n - 1th object
        int value2 = knapsackMemo(W, n - 1, w, v, results, include);
        // Compare the two
        if(value1 >= value2){
            results[n][W] = value1;
            include[n][W] = 1;
            return results[n][W];
        }
        else{
            results[n][W] = value2;
            include[n][W] = 0;
            return results[n][W];
        }
    }
    else{
        results[n][W] = knapsackMemo(W, n - 1, w, v, results, include);
        return results[n][W];
    }
}
int knapsackWrapper(int W, int w[], int v[], int n){
    int capacity = W;

    // Forming the table and filling it with -1.
    int **results;
    results = new int*[n + 1];
    for(int k = 0; k <= n; k++){
        results[k] = new int[W + 1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            results[i][j] = -1;
        }
    }

    // 2D array for seeing which values were used.
    int **include;
    include = new int*[n + 1];
    for(int k = 0; k <= n; k++){
        include[k] = new int[W + 1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            include[i][j] = -1;
        }
    }

    // Call to main function.
    knapsackMemo(W, n, w, v, results, include);
    cout << endl;
    for(int it = 1; it <= n; it++){
        for(int wt = 1; wt <= W; wt++){
            cout << results[it][wt] << ' ';
        }
        cout << endl;
    }

    // Print values used.
    int totalVal = 0;
    cout << "Items used: ";
    for(int i = n; i > 0; i--){
        if(include[i][capacity] == 1){
                cout << i - 1 << ' ';
                totalVal = totalVal + v[i - 1];
                capacity = capacity - w[i - 1];
        }
    }

    cout << endl << "Total value from items used: " << totalVal << endl;
    return results[n][W];
}

int knapsackTab(int W, int w[], int v[], int n){
    // Forming the table and filling it with -1.
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
                results[it][wt] = max(results[it - 1][wt], v[it - 1] + results[it - 1][wt - w[it - 1]]);
            }
            else{
                results[it][wt] = results[it - 1][wt];
            }
        }
    }
    return results[n][W];
}
