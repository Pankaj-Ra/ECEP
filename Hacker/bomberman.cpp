#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(char* mines, int R, int C){
    for(int i = 0; i < R; i++){
        for(int j =0; j < C; j++){
            cout << *((mines+i*C)+j);
        }
        cout << endl;
    }
    return;
}

int main() {
    int R,C;
    long long N;
    cin >> R >> C >> N;
    char mine[R][C] = {"0"};
    char blast[R][C] = {"0"};
    char field[R][C] = {"0"};
    for(int i = 0;i < R; i++){
        for(int j= 0;j < C; j++){
            cin >> mine[i][j];
            if(mine[i][j] == 'O'){
                blast[i][j] = '.';
                blast[(i)?i-1:i][j] = '.';
                blast[(i!=(R-1))?i+1:i][j] = '.';
                blast[i][(j)?j-1:j] = '.';
                blast[i][(j !=(C-1))?j+1:j] = '.';
            }else
                blast[i][j] = (blast[i][j]!='.')?'O':'.';
            field[i][j] = 'O';
        }
    }
    switch(4+N%4){
        case 4:{
                   print((char *)field, R, C);
                   break;
               }
        case 5:{
                   print((char *)mine, R, C);
                   break;
               }
        case 6:{
                   print((char *)field, R, C);
                   break;
               }
        case 7:{
                   print((char *)blast, R, C);
                   break;
               }
    }
    return 0;
}

