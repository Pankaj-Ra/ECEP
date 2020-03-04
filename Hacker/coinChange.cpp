#include <bits/stdc++.h>

using namespace std;
typedef vector<long long> V;
typedef map<int,V> Map;

long long getWays(Map &mapWays, int amount, vector<long> &c,unsigned int denom_pos = 0){

    long long ways = 0;
    Map::iterator it;
    if(amount == 0)
        return 1;
    if(amount < 0)
        return 0;
    if( denom_pos == c.size()-1){
        ways = (amount%c[denom_pos]==0)?1:0;
        it = mapWays.find(amount);
        if(it != mapWays.end()){
            it->second[denom_pos] = ways;
        }else{
            V vec(c.size(),-1);
            vec[denom_pos] = ways;
            mapWays.insert(pair<int,V> (amount,vec));
        }
        return ways;
    }
    int denom = c[denom_pos];
    denom_pos++;
    int no_coins = 0;
    int new_amount;
    for(;no_coins*denom <= amount;no_coins++){
        new_amount = amount - no_coins*denom;
        it = mapWays.find(new_amount);
        if(it != mapWays.end() &&
           it->second[denom_pos-1] != -1){
            ways += it->second[denom_pos-1];
        }else{
            ways += getWays(mapWays,new_amount, c,denom_pos);
        }
    }
    it = mapWays.find(amount);
    if(it != mapWays.end()){
        it->second[denom_pos-1] = ways;
    }
    else{
        V vec(c.size(),-1);
        vec[denom_pos-1] = ways;
        mapWays.insert(pair<int,V> (amount,vec));
    }
    return ways;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    Map mapWays;
    long long ways = getWays(mapWays,n, c);
    cout << ways;
    return 0;
}

