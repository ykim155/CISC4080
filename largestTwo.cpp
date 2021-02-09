#include <iostream>
#include <vector>
using namespace std;

void largestTwo(vector<int> l, int left, int right, int &largest, int &secondLargest);

int main(){
    vector<int> l;
    l.push_back(3);
    l.push_back(3);
    vector<int> r;
    r.push_back(1);
    r.push_back(5);
    r.push_back(2);
    vector<int> q;
    q.push_back(1);
    q.push_back(7);
    q.push_back(3);
    q.push_back(3);

    int largest = -1;
    int secondLargest = -1;
    largestTwo(l, 0, 6, largest, secondLargest);
    cout << largest << ' ' << secondLargest << endl;

    largest = -1;
    secondLargest = -1;
    largestTwo(r, 0, 6, largest, secondLargest);
    cout << largest << ' ' << secondLargest << endl;

    largest = -1;
    secondLargest = -1;
    largestTwo(q, 0, 6, largest, secondLargest);
    cout << largest << ' ' << secondLargest << endl;
}

/* return largest and second largest element in list l[left...right]
precondition: left+1<=right, i.e., the list contains at least two elements
postcondition: the largest and secondLargest will be set to the largest element and
second largest element respectively */
void largestTwo(vector<int> l, int left, int right, int &largest, int &secondLargest){
    int leftL, rightL = largest;
    int leftSL, rightSL = secondLargest;
    /* Base cases for if list is size 2 or 3. 
    For size 2, compare the values and assign accordingly.
    For size 3, manually go through the list and assign accordingly.*/
    if(left + 1 == right){
        if(l[left] > l[right]){
            largest = l[left];
            secondLargest = l[right];
        }
        else{
            largest = l[right];
            secondLargest = l[left];
        }
        return;
    }
    if(left + 2 == right){
        for(int i = left; i < right; i++){
            if(l[i] > largest){
                largest = l[i];
            }
            else if(l[i] > secondLargest){
                secondLargest = l[i];
            }
            else{}
        }
        return;
    }
    int mid = (left + right) / 2;
    // After these two recursive calls, the list is now split in half. 
    /* Smaller Caller Question. Assuming the general case works, the recursive calls do indeed shrink the
    size of the problem, eventually leading to the base cases. The calls split the list in half.*/
    largestTwo(l, left, mid, leftL, leftSL);
    largestTwo(l, mid + 1, right, rightL, rightSL);
    /* General Case works? Yes, it covers all cases. If leftL is largest, we need to compare leftSL to right L to assign
    secondLargest. The same logic applies to when rightL is largest.*/
    if(leftL > rightL){
        largest = leftL;
        if(leftSL > rightL){
            secondLargest = leftSL;
        }
        else{
            secondLargest = rightL;
        }
    }
    else{
        largest = rightL;
        if(rightSL > leftL){
            secondLargest = rightSL;
        }
        else{
            secondLargest = leftL;
        }
    }
    return;
}

