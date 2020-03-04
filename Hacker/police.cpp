//#include<bits/stdc++.h>
#include <new>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned int u_int;
typedef vector<char> inner_vec;
typedef vector<inner_vec> outer_vec;

int solution (outer_vec A, int K) {
    int busted = 0;
    for(u_int i = 0; i < A[0].size(); i++){
        for(u_int j = 0; j < A[0].size();j++){
            if(A[i][j] == 'P'){
                for(u_int k = j+1; k < A[0].size() && (k-j) <= K;k++){
                    if(A[i][k] == 'T'){
                        busted++;
                        A[i][k] = 'B';
                        break;
                    }
                }

                continue;
            }
            else if(A[i][j] == 'T'){
                for(u_int l = j+1; l < A[0].size() && (l-j) <= K;l++){
                    if(A[i][l] == 'P'){
                        busted++;
                        A[i][l] = 'B';
                        break;
                    }
                }

                continue;
            }
        }
    }
    return busted;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;
        int K;
        cin >> K;
        outer_vec A(N, inner_vec(N));
        for (int i_A=0; i_A<N; i_A++)
        {
            for(int j_A=0; j_A<N; j_A++)
            {
                cin >> A[i_A][j_A];
            }
        }

        int out_;
        out_ = solution(A, K);
        cout << out_;
        cout << "\n";
    }
}
