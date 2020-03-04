#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<char> inner_vec;
typedef vector<inner_vec> outer_vec;

bool ifPlus(outer_vec cross ,int i,int j, int n){
    if((i-n < 0)||(i+n >= cross.size())||
            (j-n < 0)||(j+n >= cross.front().size()))
        return false;
    else if(cross[i][j]   == 'G'&&
            cross[i-n][j] == 'G'&&
            cross[i+n][j] == 'G'&&
            cross[i][j-n] == 'G'&&
            cross[i][j+n] == 'G'){
        return true;
    }
    return false;
}

bool overlap(int plus,int i,int j,int c[],int l, int k){
    if(c[0]&&((c[0+l] == i)&&(k+c[2+l] >= j-c[1+l]))||
            ((c[1+l] == j)&&(k+c[2+l] >= i-c[0+l]))){
        if(c[0+l] == i || c[1+l] == j){

        }
        return false;
    }
    if(c[0]&&(max(k,c[2+l])>= j-c[1+l])&&
            (max(k,c[2+l])>= i-c[0+l]))
        return false;
    l = (l)?0:3;
    c[0+l] = i;
    c[1+l] = j;
    c[2+l] = k;
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    int count = 0;
    outer_vec cross(N,inner_vec(M,0));
    for(int i = 0;i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> cross[i][j];
            count += (cross[i][j] == 'B')?1:0;
        }
    }
    int plus1 = (count<=(M*N-2))?1:0;
    int plus2 = 1;
    int cord[6] = {0};

    for(int i = 2; i < N; i++){
        for(int j = 2; j < M; j++){
            int k = 1;
            int next = 0;
            while(ifPlus(cross, i-1, j-1, k)){
                next = 1+4*k;
                k++;
            }
            k--;
            if(next > min(plus1,plus2)){
                //cout << next<<endl;
                if(plus1 <= plus2){
                    if(overlap(plus1,i-1,j-1,cord,3,k))
                        plus1 = next;
                    else if((next > plus2) &&
                            overlap(plus2,i-1,j-1,cord,0,k))
                        plus2 = next;
                }else{
                    if(overlap(plus2,i-1,j-1,cord,0,k))
                        plus2 = next;
                    else if((next > plus1)&&
                            overlap(plus1,i-1,j-1,cord,3,k))
                        plus1 = next;
                }
            }
        }
    }
    cout << plus1*plus2<<endl;
    return 0;
}
