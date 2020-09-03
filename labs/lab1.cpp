#include <iostream>
#include <vector>
using namespace std;

vector<int> GenerateRandomVector(int size);
void PrintVector (const vector<int> & intList); 

int main(){

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
 int n=instList.size();
 for (int i=0; i<n; i++)
 cout<<intList[i]<<“ “;
 cout <<endl;
}