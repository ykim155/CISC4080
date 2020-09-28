#include <iostream>
#include <vector>
using namespace std;

vector<int> GenerateRandomVector(int size);
void PrintVector (const vector<int> & intList); 

void SelectionSort(vector<int> & list);
void SelectionSort(vector<int> & list, int left, int right);

void BubbleSort(vector<int> & list);
void BubbleSort(vector<int> & list, int left, int right, int swapCount);

void InsertionSort(vector<int> & list);
void InsertionSort(vector<int> & list, int left, int right);


int main(){
    vector<int> L = GenerateRandomVector(6);

    //Testing non-recursive selection sort.
    cout << "Sorting Vector: ";
    PrintVector(L);
    SelectionSort(L);
    cout << "After: ";
    PrintVector(L);

    //Testing recursive selection sort.
    L = GenerateRandomVector(6);
    cout << "Sorting Vector: ";
    PrintVector(L);
    SelectionSort(L, 0, L.size());
    cout << "After: ";
    PrintVector(L);

    //Testing non-recursive bubble sort.
    L = GenerateRandomVector(6);
    cout << "Sorting Vector: ";
    PrintVector(L);
    BubbleSort(L);
    cout << "After: ";
    PrintVector(L);

    //Testing recursive bubble sort.
    L = GenerateRandomVector(6);
    cout << "Sorting Vector: ";
    PrintVector(L);
    BubbleSort(L, 0, L.size(), 1);
    cout << "After: ";
    PrintVector(L);

    //Testing non-recursive insertion sort.
    L = GenerateRandomVector(6);
    cout << "Sorting Vector: ";
    PrintVector(L);
    InsertionSort(L);
    cout << "After: ";
    PrintVector(L);

    //Testing recursive insertion sort.
    L = GenerateRandomVector(6);
    cout << "Sorting Vector: ";
    PrintVector(L);
    InsertionSort(L, 1, L.size());
    cout << "After: ";
    PrintVector(L);
}


/* Generate and return an vector and fill it with random
integers between 1 and 100
 @param size: the size of the array to be generated
 @return the vector */
vector<int> GenerateRandomVector(int size)
{
 vector<int> list; //an empty vector
 int value;
 for (int i=0;i<size;i++)
 {
 value = rand()%100+1;
 list.push_back (value);
 
 }
 return list;
}

/* display the content of the vector */
void PrintVector (const vector<int> & intList)
{
 int n = intList.size();
 for (int i=0; i<n; i++)
 cout<<intList[i]<<' ';
 cout <<endl;
}

/* selection sort a vector of int into ascending order
 @param list: to list to be sorted, list.size() gives the
size of the list
 @pre: list has been initialized with a certain number of
elements
 @post: elements in list has been rearranged into ascending
order */
void SelectionSort(vector<int> & list){
    int n = list.size();
    int right = n;
    // Outer loop iterating through the entire list.
    for(int left = 0; left < right; left++){
        int small = left;
        /* Inner loop iterating through the list, with 
        left being updated by 1 every completion. */
        for(int i = left; i < right; i++){
            /* If the current value is smaller than the value assigned 
            to index "small", replace "small" with the new index "i". */
            if(list[i] < list[small]){
                small = i;
            }
        }
        //  If the smallest value isn't already at the left, swap.
        if(small != left){
            swap(list[small], list[left]);
        }
    }
}

/* selection sort the given part of a vector of int into
ascending order
@param list: to list to be sorted, list.size() gives the size of the list
  @param left, right: specify the range of list to be sorted
@pre: list has been initialized with a certain number of elements, left<=right
@post: elements in list[left...right] has been rearranged into ascending order */
void SelectionSort(vector<int> & list, int left, int right){
    // Base Case
    if(left == right){
        return;
    }
    // General Case
    else{
        int small = left;
        // Looping though the current list.
        for(int i = left + 1; i < right; i++){
            if(list[i] < list[small]){
                small = i;
            }
        }
        // If the smallest value isn't already at the left, swap.
        if(small != left){
            swap(list[small], list[left]);
        }
        // Make the list shorter on next iteration.
        SelectionSort(list, left + 1, right);
    }
}

/* Bubble sort the given vector of int into ascending order.
@param list: list to be sorted. list.size() gives length of the list.
@pre: list has been initialized with certain elements.
@post: list has been sorted in ascending order. */
void BubbleSort(vector<int> & list){
    // Length of list.
    int n = list.size();
    // Swap Counter. Used to break loop.
    int swapCount = 0;
    // Outer loop that decreases the size of list each iteration.
    for(int i = n - 1; i > 0; i--){
        // Reset swapCount every iteration.
        swapCount = 0;
        // Inner loop that swaps the largest value to the end of the list.
        for(int j = 0; j < i; j++){
            // If the next value is smaller than the current value, swap.
            if(list[j] > list[j+1]){
                swap(list[j], list[j+1]);
                swapCount++;
            }
        }
        // If no swap occurred this iteration, return as the list is now sorted.
        if(swapCount == 0){
            return;
        }
    }
}

/* Bubble sort the given vector of int into ascending order
@param list: list to be sorted. list.size() gives the length of the list.
@param left, right: specify range of list.
@param swapCount: track swaps at each function call. used for second base case, initialized as non zero on first call.
@pre: list has been initialized with certain elements.
@post: list has been sorted in ascending order. */
void BubbleSort(vector<int> & list, int left, int right, int swapCount){
    // Base Case
    if(left == right){
        return;
    }
    // Base Case
    if(swapCount == 0){
        return;
    }
    // List size, updated every function call.
    int n = right - 1;
    // Reset at each function call.
    swapCount = 0;
    // The "inner loop" that loops through the new list from function call.
    for(int i = 0; i < n; i++){
        // Swap when list[i+1] is less than list[i].
        if(list[i] > list[i+1]){
                swap(list[i], list[i+1]);
                swapCount++;
            }
    }
    BubbleSort(list, 0, n - 1, swapCount);
}

/* Insertion sort the given vector into ascending order.
@param list: list to be sorted. list.size() gives the length of the list.
@pre: list has been initialized with a certain elements.
@post: list has been sorted in ascending order. */
void InsertionSort(vector<int> & list){
    // List length.
    int n = list.size();
    // Placeholder variable.
    int a;
    // Inner loop iterator.
    int j;
    // Outer loop going through the whole list.
    for(int i = 1; i < n; i++){
        // Store the start value after the sorted list.
        a = list[i];
        // Inner loop iterating through the sorted list.
        for(j = i - 1; j > -1; j--){
            /* If the last value of sorted list is greater than the new value, swap their places. 
            Then, j "follows" a though the sorted list, swapping when necessary. */
            if(list[j] > a){
                list[j + 1] = list[j];
            }
            // Break if you don't swap.
            else{
                break;
            }
        }
        // Place a at the proper spot.
        list[j + 1] = a;
    }
}

/* Insertion sort the given vector into ascending order.
@param list: list to be sorted. list.size() gives the length of the list.
@param left, right: specify range of the list.
@pre: list has been initialized with a certain elements.
@post: list has been sorted in ascending order. */
void InsertionSort(vector<int> & list, int left, int right){
    // Base Case
    if(left == right){
        return;
    }
    int a = list[left];
    // Iterator for sorted list.
    int i = left;
    // Loop through the sorted list.
    for(i = left - 1; i > -1; i--){
        /* If the last value of sorted list is greater than the new value, swap their places. 
        Then, j "follows" a though the sorted list, swapping when necessary. */
        if(list[i] > a){
            list[i + 1] = list[i];
        }
        // Break if you don't swap.
        else{
            break;
        }
    }
    // Place a at the proper spot.
    list[i + 1] = a;
    InsertionSort(list, left + 1, right);
}