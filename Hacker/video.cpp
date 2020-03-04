#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> data(n+1);
    int da;
    for(int i = 0; i <= n; i++){
        cin >> da;
        data[i] = da;
    }
    int t = d;
    int tm = 0;
    for(int j = 0; j <= n; j++){
        tm += data[j];
        int temp = tm;
        if(temp >= t){
            int k;
            for(k = j+1; j <= n && temp >= d; k++){
                temp -= d;
                temp += data[k];
            }
            if(k >= n){
                tm = j+1;
                break;
            }
            t++;
        }
    }
    cout << tm << endl;
    return 0;
}
