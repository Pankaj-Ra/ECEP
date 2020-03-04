#include <bits/stdc++.h>

using namespace std;

int assign(vector<long long> &A,int l ,int r,
           long long x){
    for(long long i = l-1; i <= r-1; i++){
        A[i] = x;
    }
    return 0;
}
long biggerArray(vector<long long>A, int l, int r){
    vector<long long> ar(r-l+1);
    long long count = 0;
    long long count1 = 0;
    for(int i = l-1; i <= r-1; i++){
        ar[i-(l-1)] = A[i];
        count1 = (count1*10)+A[i];
        //count = (i<r-1)?(count*10)+1:(count*10)+A[i];
    }
    long long max = count1%10;
    for(long i = ar.size()-1;i > 0; i--){
        max = (i == 1)?max:max+(max*ar[i-1]);
    }
    max += ar.size()-1;
    if(ar.size() == 1)max = 1;
    return max;
}

int main() {
    int n;
    int q;
    cin >> n >> q;
    vector<long long> A(n);
    for(long long A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
    }
    long arrays = 0;
    for(int a0 = 0; a0 < q; a0++){
        int t;
        int l;
        int r;
        long long x;
        int temp;
        cin >> t >> l >> r;
        if(t == 1){
            cin >> x;
            assign(A,l,r,x);
        }else{
            arrays = biggerArray(A,l,r);
            cout << arrays << endl;
        }
    }
    return 0;
}

