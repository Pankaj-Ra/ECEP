#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int steps = 0;
    int valley = 0;
    int temp;
    vector<char> hike(n);
    for(int h_i = 0; h_i < n; h_i++){
        temp = steps;
        cin >> hike[h_i];
        steps += (hike[h_i]=='U')?1:-1;
        valley += ((temp==0)&&(steps<temp))?1:0;
    }
    valley -= (steps<0)?1:0;
    cout << valley <<endl;
    return 0;
}
