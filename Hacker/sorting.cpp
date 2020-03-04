#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
        cin >> arr[arr_i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    while(arr.size()){
        cout << arr.size() << endl;
        int s_string = arr[arr.size() - 1];
        for(int k = 0; k < arr.size(); k++){
            arr[k] -= s_string;
        }
        while(arr.size() && !arr[arr.size()-1])arr.resize(arr.size() - 1);
    }
    return 0;
}
