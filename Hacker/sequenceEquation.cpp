#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, j;
    cin >> n;
    vector <int> p(n);
    for(int i= 0; i < n; i++){
        cin >> p[i];
    }
    vector <int> pp(n);
    for(j = 0; j < n; j++){
        pp[p[p[j] - 1] - 1] = j + 1;
    }
    for(int k = 0; k < n; k++){
        cout << pp[k] <<endl;
    }
    return 0;
}
