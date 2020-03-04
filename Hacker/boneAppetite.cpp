#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int n, k, b;
    vector<int> meal(n);
    cin >> n;
    cin >> k;
    int sum = 0;
    for(int n_i = 0; n_i < n; n_i++){
        cin >> meal[n_i];
        sum += (n_i != k)?meal[n_i]:0;
    }
    cin >> b;
    int diff = b-(sum/2);
    if((sum/2)==b)
        cout << "Bon Appetit";
    else
        cout << diff;
    return 0;
}
