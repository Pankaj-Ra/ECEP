#include<bits/stdc++.h>
using namespace std;

int printIndexVal(vector<int> arr, vector<int> v, int k, int c){
    int s = arr.size();
    if((s-c) < k){
        return -1;
    }
    int sum = 0;
    for(int i = 0;i < k;i++){
        sum += v[i];
    }
    if(sum){
        while(v[k-1+sum]){
            k += sum; 
        }
        return k;
    }
    return k;
}

int main(){
    int N, Q;
    
    cin >> N >> Q;

    vector<int> arr(N,1);
    vector<int>visit(N,0);
    int count = 0;
    for(int i = 0; i < Q; i++){
        int op, val;
        cin >> op >> val;
        if (!op){
            arr[val-1] = 0;
            visit[val-1] += 1; 
            count++;
        }else{
            int out = printIndexVal(arr, visit, val, count);
            cout << out <<endl;
        }
    }
    return 0;
}
