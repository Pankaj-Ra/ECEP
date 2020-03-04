#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int magic[3][3] = {{8,1,6},{3,5,7},{4,9,2}};

int magicSquare(vector < vector<int> > s){
    int m_cost = 81;
    for(int code=0;code<8;code++) {
        bool swapij = (code & 0x4);
        bool revii = (code & 0x2);
        bool revjj = (code & 0x1);
        int cost = 0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                int ii = (swapij) ? (revii) ? 2-j : j : (revii) ? 2-i : i;
                int jj = (swapij) ? (revjj) ? 2-i : i : (revjj) ? 2-j : j;
                cost += abs(magic[ii][jj] - s[i][j]);
            }
        }
        if(cost < m_cost) {
            m_cost = cost;
        }
    }
    return m_cost;
}
/*
int magicSquare(vector < vector<int> > s){
    int m_cost = 81;
    for(int code=0;code<8;code++) {
        int cost = 0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                //To form all 8 diff types of sqaure
                int k = (code<4)?i:j;
                int l = (code<4)?j:i;
                k = (code & 0x1)?2-k:k;
                l = (code & 0x2)?2-l:l;
                cost += abs(magic[k][l] - s[i][j]);
            }
        }
        if(cost < m_cost) {
            m_cost = cost;
        }
    }
    return m_cost;
}*/

int main() {
    vector< vector<int> > s(3,vector<int>(3));
    for(int s_i = 0;s_i < 3;s_i++){
        for(int s_j = 0;s_j < 3;s_j++){
            cin >> s[s_i][s_j];
        }
    }
    int cost = magicSquare(s);
    cout << cost << endl;
    return 0;
}
