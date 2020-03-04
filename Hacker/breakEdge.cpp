
// Sample code to perform I/O:

#include <iostream>
#include <vector>


using namespace std;

void dfs(vector <vector<int> > p, vector<long> v, vector<char> &vi, int i, int e, int &l, long &OR){
    vi[i] = 't';
     OR |= v[i];
    for(size_t s = 0;s < p[i].size(); s++){
        if(p[i][s] == e){
            l = i;
            continue;
        }
        if(vi[p[i][s]] == 'f' ){
            dfs(p, v, vi, p[i][s], e, l, OR);
        }
    }
}

int main() {
    int num;
    cin >> num;                                     // Reading input from STDIN
    vector<long int> v(num+1);
    long int max = 0;
    for(size_t i = 1;i < v.size(); i++){
        long int val;
        cin >> val;
        v[i] = val;
        max = (val > max)?val:max;
    }
    vector<vector<int> > pairs(num+1);
    for(int i = 1;i < num; i++){
        int a,b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
    long result = 0;
    for(int i = 2; i <= num; i++){
        if(!pairs[i].size() && v[i] < max){
            continue;
        }
        vector<char> visit(num+1,'f');
        long treeOR_1 = v[1];
        long treeOR_2 = v[i];
        int l = 0;
        int temp = 0;
        dfs(pairs, v, visit, 1, i, l, treeOR_1);
        dfs(pairs, v, visit, i, l, temp, treeOR_2);
        result += (treeOR_1 == treeOR_2)?1:0;
    }
    cout << result << endl;

}



