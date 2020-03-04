#include<string>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        string res("Impossible");
        vector< vector<int> > M(n,vector<int>(n));
        vector <int> type(n);
        vector <int> c_size(n);
        for(int M_i = 0;M_i < n;M_i++){
            for(int M_j = 0;M_j < n;M_j++){
                cin >> M[M_i][M_j];
                type[M_j] += M[M_i][M_j];
                c_size[M_i] += M[M_i][M_j];
            }
        }
        for(int i = 0; i < n; i++){
            res.replace(res.begin(),res.end(),"Imnpossible");
            for(int j = 0; j < n; j++){
                if(type[i] == c_size[j]){
                    res.replace(res.begin(),res.end(),"Possible");
                    c_size[j] = -1;
                    break;
                }
            }
            if(!res.compare("Impossible"))break;
        }
        cout << res << endl;
    }
    return 0;
}

