#include <iostream>
#include <vector>
using namespace std;

bool coinChange(vector<int> coins, int v);

int main(){
    vector<int> c;
    c.push_back(3);
    c.push_back(4);
    c.push_back(6);
    c.push_back(10);

    bool b = coinChange(c, 14);
    cout << b << endl;
}

/* Return true if v can be expressed as sums of values from coins (repetition is allowed)
@param coins is a vector of positive int values
@param v is a positive int
@return true if v can be written as a sum of values from coins, return false otherwise
*/
bool coinChange(vector<int> coins, int v){
    if(v == 0){
        return true;
    }
    for(int i = 0; i < coins.size(); i++){
        if(coins[i] == v){
            return true;
        }
        else if(coins[i] < v){
            v = v - coins[i];
            if(coinChange(coins, v)){
                return true;
            }
        }
    }
    return false;
}
/* 
[3, 4, 6, 10] to make 14. 
Tracing:
1. v = 14
2. v = 11
3. v = 8
4. v = 5
5. v = 2
Backtrack!
6. v = 1
Backtrack!
7. v = 4
8. v = 1
Backtrack!
9. v = 7
10. v = 4
11. v = 1
Backtrack!
12. v = 1
Backtrack!
13. v = 7
Exit.
The code basically goes as low as possible with one number, i.e at the beginning, it subtracted 3 from 14 4 times before
it had to backtrack until it could move on with the for loop. This repeated until we triggered a true value within the
loop.
*/
