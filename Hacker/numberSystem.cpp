#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mask = 100000000000000000;

int multiplyList(list<ll> &x, int b = 1,list<ll> &z = NULL){
    list<int>::reverse_iterator it = x.rbegin();
    if(it != x.rend()){
        int carry = 0;
        for(;it != x.rend();it++){
            ll val = (*it+carry)*b;
            *it = val%mask;
            if(z)
              
            carry = val/mask;
        }
        if(carry){
            x.push_front(carry);
            if(z)
                z.push_front(carry);
        }
    }else
        x.push_front(b);
    return 0;
}

int divideList(){
}

int power(list<ll> &x,int b, unsigned int y)
{
    if( y == 0)
        return 1;
    power(x, b, --y);
    return multiplyList(x,b);
}

ll getMagicNumber(string s, long k, int b, int m){
    int len = s.length()-k+1;
    ll total = 0;
    list<int> lst;
    list<ll>pwr_l;
    list<ll>p_lvl;
    list<int>::reverse_iterator it = lst.rbegin();
    ll powr= 1;
    ll sum = 0;
    ll max = 1;
    for(int i = 0 ;i < len; i++){
        if(it != lst.rend()){
            sum = (sum - *it*max)*b + (s[k+i-1]-48);
            lst.push_front((s[k+i-1]-48));
            lst.pop_back();
        }
        else{
            for(long j = k-1;j >= 0;j--){
                lst.push_back(s[j]-48);
                power(pwr_l,b,j-k-1);
                if(j == k-1)
                    p_lvl
                multiplyList(p_lvl,s[j]-48);
                addList(sum,p_lvl);
            }
            it = lst.rbegin();
        }
        total += sum%m;
    }
    return total;
}

int main() {
    string s;
    cin >> s;
    int k;
    int b;
    int m;
    cin >> k >> b >> m;
    ll result = getMagicNumber(s, k, b, m);
    cout << result << endl;
    return 0;
}

