#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

void dfs(vector<vector<int> > &p, vector<char> &v, int i, int &count){
    v[i] = 't';
    for(int n = 0; n < p[i].size(); n++){
        if(v[p[i][n]] == 'f'){
            count++;
            dfs(p ,v, p[i][n], count);
        }
    }
}

int main()
{
    int N, I;
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    long long result = 0;
    vector<char> visit(N,'f');
    long long sum = 0;
    for(int i = 0; i < N; i++){
        int count = 0;
        if(visit[i] == 'f'){
            count++;
            dfs(pairs, visit, i, count);
            result += sum*count;
            sum += count;
        }
    }

    cout << result << endl;
    return 0;
}

