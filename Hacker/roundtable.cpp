#include <bits/stdc++.h>


using namespace std;

#define MAX 60000;

typedef vector<int> p;
typedef vector<p> D_vec;

int min_time(int s1, int s2, int n){
    int t1;
    int t2;
    t1 = (abs(s1 - s2))/2;
    t2 = ((n - max(s1,s2)) + min(s1,s2))/2;
    if(t1 < t2){
        return t1;
    }
    return t2;
}

int main(){
    int N, Q;
    cin >> N  >> Q;

    D_vec pairs(N+1);
    int clg;
    for(int i = 1; i <= N; i++){
        cin >> clg;
        pairs[clg].push_back(i);
    }

    int clg1, clg2;
    for(int j = 0; j < Q; j++){
        int tm = MAX;
        cin >> clg1 >> clg2;
        for(int k = 0; k < pairs[clg1].size(); k++){
            int std1 = pairs[clg1][k];
            for(int l = 0; l < pairs[clg2].size(); l++){
                int std2 = pairs[clg2][l];
                int temp = min_time(std1,std2, N);
                 tm = (temp < tm)?temp:tm;
                 if(tm == 0){
                    break;
                }
            }
            if(tm == 0){
                break;
            }
        }
        cout << tm <<endl;
    }
    return 0;
}
