#include <iostream>
#include <stack>
using namespace std;

bool CoinChangeMemo (int c[], int r[], int n, int v)
{
    if(r[v] != -1){
        return r[v];
    }
    if (v==0){
        r[0] = 1;
	    return true;
    }

    for (int i=0;i<n;i++)
    {
		if (c[i]==v){
            r[v] = 1;
			return true;
        }

		else if (c[i]<v){
			if (CoinChangeMemo (c, r, n, v-c[i])){
                r[v-c[i]] = 1;
				return true;
            }
        }
        else{
            r[i] = 0;
        }
        
    }
    return false;
}

bool CoinChangeMemoWrapper(int c[], int n, int v){
    int r[v+1]; //r[i] stores 1 if you can make change for that v == i, -1 for not solved yet, 0 for can't be solved.
    for(int i = 0; i <= v; i++){
        r[i] = -1;
    }
    return CoinChangeMemo (c, r, n, v);
}

bool CoinChangeBottomUp(int c[], int n, int v){
    bool r[v + 1];
    r[0] = 1;
    for(int k = 0; k <= v; k++){
        for(int i = 0; i < n; i++){
            if(c[i] == k)
                r[i] = 1;
            else if(c[i] < k){
                if(r[k - c[i]]){
                    r[k] = 1;
                }
            }
        }
    }
    if(r[v])
        return true;
    else
        return false;
    
}

int main()
{
	int c[4]={10,4,6,2};
	int value;

	cout <<"Enter a value:";
	cin >> value;

	if (CoinChangeMemoWrapper (c, 4, value))
		cout <<"We can make the change of "<<value<<endl;
	else
		cout <<"We cannot make the change of "<<value<<endl;

    if (CoinChangeBottomUp (c, 4, value))
		cout <<"We can make the change of "<<value<<endl;
	else
		cout <<"We cannot make the change of "<<value<<endl;


}