#include <iostream>
#include <vector>
using namespace std;

vector<int> GenerateRandomVector(int size);
void PrintVector (const vector<int> & intList); 
void BubbleSort(vector<int> & list, int left, int right, int swapCount);

int main(){
    vector<int> L = GenerateRandomVector(6);

    //Testing recursive bubble sort.
    L = GenerateRandomVector(5);
    cout << "Sorting Vector: ";
    PrintVector(L);
    BubbleSort(L, 0, L.size(), 1);
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

/* Bubble sort the given vector of int into ascending order
@param list: list to be sorted. list.size() gives the length of the list.
@param left, right: specify range of list.
@param swapCount: track swaps at each function call. used for second base 
case, initialized as non zero on first call.
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
    int n = right;
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