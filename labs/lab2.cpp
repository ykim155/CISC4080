// bubble sort illustrating:
//  (1)  How to sort a list of composite data type (e.g., struct or class type in C++), and 
//      in ascending or descending order of a key field (i.e., the member variable)?
//  (2) Stable vs unstable sorting
//  (3) Mutli-pass sorting: with primary key, secondary key, and so on
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Record{
private:
   string name;
   int b_year;
   int b_month;
   int b_day;

public:
   Record (string n, int y, int m, int d){
       name=n;

       b_year = y;
       b_month = m;
       b_day = d;
   }

   void Print(){
	cout <<name<<",  b_date:"<<b_year<<"/"<<b_month<<"/"<<b_day<<endl;

   }
//Several examples of InOrder functions for different keys and orders
friend bool InAscendingOrderByName (Record a, Record b);
friend bool InDescendingOrderByName (Record a, Record b);

friend bool InAscendingOrderByBDate (Record a, Record b);
friend bool InDescendingOrderByBDate (Record a, Record b);

friend bool ascendingBirthMonthDate(Record a, Record b);
};

void MergeSort (vector<int> & l, int left, int right);

//Sort vector of record, using InOrder function to compare and see if two records are in order 
void bubblesort (vector<Record> &  a, std::function<bool (Record,Record)> InOrder);
                                    //   ^^ InOrder is a function that takes two Record type parameters
				    //   and rethrn a bool.


//Several examples of InOrder functions for different keys and orders
bool InAscendingOrderByName (Record a, Record b);
bool InDescendingOrderByName (Record a, Record b);

bool InAscendingOrderByBDate (Record a, Record b);
bool InDescendingOrderByBDate (Record a, Record b);

/*--------------------What I Added------------------------*/
bool ascendingBirthMonthDate(Record a, Record b);




int main()
{
    /*
	vector<int> l={4,2,1,5,0,6,3,7};

	cout <<"Before sorting\n";
	for (int i=0;i<l.size();i++)
		cout <<l[i]<<" ";
	cout <<endl;

	MergeSort (l, 0, 7);
	cout <<"After sorting\n";
	for (int i=0;i<l.size();i++)
		cout <<l[i]<<" ";
	cout <<endl;

	exit(0);
    */

	vector<Record> d;
	d.push_back (Record("Alice",2000, 3, 4));
	d.push_back (Record("Jack",2001, 4, 8));
	d.push_back (Record("Abe",1999,8,21));
	d.push_back (Record("Alice", 2001, 9, 19));
	d.push_back (Record("Bob", 2001,9,3));
	d.push_back (Record("Abe",2001,4,8));
	d.push_back (Record("Jack", 2001,9,19));

	//cout <<"Sort: primary key: name (in ascending order), secondary key: age (in descending order):"<<endl;
	cout <<"Before sorting\n";
	for (int i=0;i<d.size();i++)
		d[i].Print();
	
    cout << endl;
    
    //secondary key first 
	/* sort d using bubblesort, by descending order of birthdate  */
	bubblesort (d, InDescendingOrderByBDate);
	cout <<"After sorting in descending order by birthdate\n";
	for (int i=0;i<d.size();i++)
		d[i].Print();

    cout << endl;
	
	// sort d using bubblesort, by ascending order of name
	//primary key last key 
	bubblesort (d, InAscendingOrderByName);
	cout <<"After sorting in ascending order by Name\n";
	for (int i=0;i<d.size();i++)
		d[i].Print();

    vector<Record> a;
	a.push_back (Record("Alice",2000, 3, 4));
	a.push_back (Record("Jack",2001, 4, 8));
	a.push_back (Record("Abe",1999,8,21));
	a.push_back (Record("Alice", 2001, 9, 19));
	a.push_back (Record("Bob", 2001,9,3));
	a.push_back (Record("Abe",2001,4,8));
	a.push_back (Record("Jack", 2001,9,19));

    cout << endl;
    cout << endl;

    cout <<"Before sorting\n";
	for (int i=0;i<a.size();i++)
		a[i].Print();
	
    cout << endl;

    sort(a.begin(), a.begin() + 6, InDescendingOrderByBDate);
	cout <<"After sorting in descending order by birthdate using std::sort\n";
	for (int i=0;i<a.size();i++)
		a[i].Print();

    cout << endl;

    sort(a.begin(), a.begin() + 6, InAscendingOrderByName);
	cout <<"After sorting in ascending order by name using std::sort\n";
	for (int i=0;i<a.size();i++)
		a[i].Print();

    cout << endl;

    vector<Record> b;
	b.push_back (Record("Alice",2000, 3, 4));
	b.push_back (Record("Jack",2001, 4, 8));
	b.push_back (Record("Abe",1999,8,21));
	b.push_back (Record("Alice", 2001, 9, 19));
	b.push_back (Record("Bob", 2001,9,3));
	b.push_back (Record("Abe",2001,4,8));
	b.push_back (Record("Jack", 2001,9,19));

    cout << endl;
    cout << endl;

    cout <<"Before sorting\n";
	for (int i=0;i<b.size();i++)
		b[i].Print();
	
    cout << endl;

    stable_sort(b.begin(), b.begin() + 6, InDescendingOrderByBDate);
	cout <<"After sorting in descending order by birthdate using std::stable_sort\n";
	for (int i=0;i<b.size();i++)
		b[i].Print();

    cout << endl;

    stable_sort(b.begin(), b.begin() + 6, InAscendingOrderByName);
	cout <<"After sorting in ascending order by name using std::stable_sort\n";
	for (int i=0;i<b.size();i++)
		b[i].Print();

    cout << endl;

}

/* Sort a vector of records, using the given function to compare whether two
 * records are in wrong order 
 @parapm a: vector of records
 @param Order: a function to compare two records, returns true if first record should appear
   before second record, if it returns false, then they need to be swapped
   */
void bubblesort (vector<Record> &  a, std::function<bool (Record,Record)> Order) 
{
     int end_index = a.size()-1; 

     for (; end_index>0; end_index--)
     {
		for (int i=0; i<=end_index-1;i++)
			//if a[i],  a[i+1]) are in wrong order, originally:
			// if (a[i]>a[i+1]), if (!(a[i]<=a[i+1]))
			if (!Order(a[i],a[i+1]))
				swap (a[i], a[i+1]);
     }
}

//SelectionSort stable or not? 
//  find the smallest element in the lsit, and swap it to the front 
//          ^first appearance of 
//  3 2 1 8 1 10
//      ^   ^
//      swap the first smallest element to the front 
//
//InsertionSort ?? 
// How do we need to make sure it's stable? Is your lab1 implementaton stable? 

/*--------------------What I Added------------------------*/
bool ascendingBirthMonthDate(Record a, Record b){
    if((a.b_month > b.b_month) || (a.b_month == b.b_month && a.b_day > b.b_day)){
        return false;
    }
    else{
        return true;
    }
}

//Should a apear before b if we are sorting in asecnding order of name 
bool InAscendingOrderByName (Record a, Record b)
{
    return (a.name<=b.name);
}

/* If a is >= b 
@param a, b: two records 
@return true if a.name is larger than or equal to  b.name
  */
bool InDescendingOrderByName (Record a, Record b)
{
    return (a.name>=b.name);
}


//return true if a's birthday is before or the same as b's 
bool InAscendingOrderByBDate (Record a, Record b)
{
     if (a.b_year < b.b_year ||
		      a.b_year == b.b_year && a.b_month < b.b_month ||
		      a.b_year == b.b_year && a.b_month == b.b_month &&  a.b_day <= b.b_day)
	     return true;
     else
	     return false;

}

//return true if a's birthday is after or the same as b's 
bool InDescendingOrderByBDate (Record a, Record b)
{
     if (a.b_year > b.b_year ||
		      a.b_year == b.b_year && a.b_month > b.b_month ||
		      a.b_year == b.b_year && a.b_month == b.b_month && a.b_day >= b.b_day)
	     return true;
     else
	     return false;
}

/* sort l[left...right] into ascending order
 @param l: is the vector, 
 @param left, right are the indices of the left/right of the vector
 @precondition: left<=right
 @postcondition: l[left]<=l[left+1]<=l[left+2]<=..<=l[right]
 */
void MergeSort (vector<int> & l, int left, int right)
{
	if (left==right)
	{
		cout <<"MergeSort called "<<left<<","<<right<<endl;
		return;
	}

	cout <<"MergeSort called "<<left<<","<<right<<endl;
	int mid=(left+right)/2;

	MergeSort (l, left, mid);
	MergeSort (l, mid+1, right);

	//combine: merge sorted l[left...mid] , l[mid+2...right] into one sorted list l[left...right]
	
	//vector<int> s; //s is empty, size is some default size 
	vector<int> s(right-left+1); //allocate a staging area of same size 
	
	int i=left; //used to iterate through left half 
	int j=mid+1; //used to iterate through right half 
	int k=0; //used to access s 

	//As long as both halves still have elements, we need to compare front element.... 
	while (i<=mid && j<=right){
		if (l[i]<=l[j]){
			s[k++]=l[i++];
			//s.push_back (l[i++]); //access l[i], then increment i
		} else 
			//s.push_back (l[j++]); 
			s[k++] = l[j++];

	}

	//copy elements from remaining half into s 
	while (i<=mid)
	//	s.push_back (l[i++]);
		s[k++]=l[i++];
	while (j<=right)
		//s.push_back (l[j++]);
		s[k++]=l[j++];

	//copy all elements from s back to l in-order 
	for (int i=0;i<right-left+1;i++)
		//what to do? 
		l[left+i]=s[i];  //s[0]=>l[left], s[1]=>l[left+1]....
		//last i is right-left, so l[left+right-left]=s[right-left];
	
}

/*
Number 1:
bool ascendingBirthMonthDate(Record a, Record b){
    if((a.b_month > b.b_month) || (a.b_month == b.b_month && a.b_day > b.b_day)){
        return false;
    }
    else{
        return true;
    }
}

Number 2:
void sort(vector<int> &a){
    size = a.size();
    for (int e = size - 1; e >= 1; e--){
        for(int i = e, i >= 1; i--){
            if(a[i] <= a[i-1])
                swap(a[i], a[i-1]);
        }
    }
}
This function is a bubble sort function modified to sort a vector in descending order. This is not stable
because if there is a repeated value in the vector, the place will change. i.e. vector<int> d = [3, 4, 7, 1, 1].
The two ones at the end will be swapped with each other even though they do not have to be.

Number 3:
Sorted by ascending x first.
(2, 3) (2, 1) (3, 5) (4, 5) (4, 1) (9, 3)
Sort by descending y
(3, 5) (4, 5) (2, 3) (9, 3) (2, 1) (4, 1)

Number 4:
After sorting in ascending order by name using std::sort
Abe,  b_date:1999/8/21
Abe,  b_date:2001/4/8
Alice,  b_date:2000/3/4
Alice,  b_date:2001/9/19
Bob,  b_date:2001/9/3
Jack,  b_date:2001/4/8
Jack,  b_date:2001/9/19

Not what I expected, the two Abes and Alices are switched.
*/