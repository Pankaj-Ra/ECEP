#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int> > &p, vector<char> &v, int j, int w, bool &f){
    if(j == w){
        f = true;
        cout << "YES" <<endl;
        return 0;
    }
    v[j] = 't';
    for(int n = 0; n < p[j].size(); n++){
        if(f)
            return 0;
        if(v[p[j][n]] == 'f'){
            if(p[j][n] == w){
                f = true;
                cout << "YES"<<endl;
                return 0;
            }
            dfs(p ,v, p[j][n], w ,f);
        }
    }
    return 0;
}

int dfs(vector<vector<int> > &p, vector<char> &u, vector<char> &v, int i, int j, int w, bool &f){
    if(i == w){
        dfs(p, v, j, w, f);
        return 0;
    }
    u[i] = 't';
    v[i] = 't';

    for(int n = 0; n < p[i].size(); n++){
        if(f)
            return 0;
        if(u[p[i][n]] == 'f'){
            if(p[i][n] == w){
                dfs(p, v, j, w, f);
                if(f)
                    return 0;
                continue;
            }
            dfs(p ,u, v, p[i][n], j, w, f);
        }
    }
    v[i] = 'f';
    return 0;
}

int main() {
    int n;
    int m;
    int q;
    cin >> n >> m >> q;
    vector<vector<int> > nodes(n+1);
    for(int a0 = 0; a0 < m; a0++){
        int u;
        int v;
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    for(int a0 = 0; a0 < q; a0++){
        int u;
        int v;
        int w;
        vector<char> visit_1(n+1,'f');
        vector<char> visit_2(n+1,'f');
        cin >> u >> v >> w;
        if(u == v){
            cout << "NO" << endl;
            continue;
        }
        bool f = false;
        visit_1[v] = (v != w)?'t':'f';
        visit_2[u] = (u != w)?'t':'f';
        dfs(nodes, visit_1, visit_2, u, v, w, f);
        if(f == false){
            cout << "NO" <<endl;
        }
    }
    return 0;
}

