#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <int> subset(k);
    for(int a_i = 0; a_i < n; a_i++){
        cin >> a[a_i];
        subset[a[a_i]%k]++;
    }
    int count = 0;
    for(int i = 1; i <= k/2; i++){
        if((2*i == k) && subset[k/2]){
            count++;
            break;
        }
        count += (subset[i] >i= subset[k-i])?subset[i]:subset[k-i];
    }
    count += (subset[0])?1:0;
    cout << count;
    return 0;
}
