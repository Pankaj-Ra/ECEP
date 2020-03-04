#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vec;
map<int,vec> road;

int mapCity(int u, int v,int direction = 0){
    if(direction){
        int temp = u;
        u = v;
        v =temp;
    }
    map<int,vec>::iterator it = road.find(u);
    if(it != road.end()){
        it->second[v-1] = v;
        for(it = road.begin();it != road.end();it++){
            if(it->second[u-1] == u)
                it->second[v-1] = v;
        }
    }else{
        if(direction){
            vec vect;
            it = road.find(v);
            vect = it->second;
            vect[v-1] = v;
            road.insert(pair<int,vec> (u,vect));
        }else{
            vec vect(50000);
            vect[v-1] = v;
            road.insert(pair<int,vec> (u,vect));
        }
    }
    it = road.find(v);
    if(it == road.end()){
        vec vect1(50000);
        road.insert(pair<int,vec> (v,vect1));
    }
    return 0;
}

int rout(int u, int v){
    map<int,vec>::iterator it = road.find(u);
    if(it != road.end()){
        string out = (it->second[v-1]==v)?"Yes":"No";
        cout << out << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    for(int a0 = 0; a0 < m; a0++){
        int u;
        int v;
        cin >> u >> v;
        mapCity(u,v);
    }
    int q;
    cin >> q;
    int c_count = n;
    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        if(x == 1)
            mapCity(y,++c_count,z);
        else
            rout(y,z);
    }
    return 0;
}

