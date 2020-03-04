#include <iostream>
#include <vector>
#include <new>

using namespace std;

vector < long long int> solve(int n, int k, vector < long long int > a){
    vector <long long int> max(2);
    max[1] = 1;
    for(int i = 0; (i+k) <= n; i++){
        long long int sum;
        sum = a[i];
        int m = i;
        int j = 0;
        for(int l = 1; l < k; l++){
            if(0 == sum)break;
            else if(l == (k-1)){
                sum &= a[i+l+j];
                if(max[0] < sum){
                    max[0] = sum;
                    max[1] = 1;
                }
                else if(max[0] && (max[0] == sum))max[1]++;
                if((j+k) < n){
                    j++;
                    l = 0;
                }
                else if((m+k) < n)
                {
                    m++;
                    j = m;
                    l = 0;
                }
                else break;
                sum = a[i];
            }
            else
                sum &= a[i+l+m];
        }
    }
    return max;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<long long int> a;
    for(int n_i = 0; n_i < n; n_i++){
        long long int temp;
        cin >> temp;
        if(temp)a.push_back(temp);
    }
    vector < long long int> result = solve(a.size(), k, a);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << ((i != (result.size()-1)) ? "\n" : "");
    }
    cout << endl;


    return 0;
}
