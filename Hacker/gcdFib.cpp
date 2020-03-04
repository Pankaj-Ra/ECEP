#include <iostream>
using namespace std;
typedef unsigned long long ll;

void multiply(ll F[2][2], ll M[2][2]);

void power(ll F[2][2], ll n);

ll fib(ll n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}


void power(ll F[2][2], ll n)
{
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  ll y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  ll z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  ll w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}


ll findGCD(ll arr[], ll n)
{
    ll result = arr[0];
    for (ll i=1; i<n; i++)
        result = gcd(arr[i], result);

    return result;
}

int main()
{
    ll N, Q;
    cin >> N >> Q;
    ll A[N];
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    for(ll j = 0; j < Q; j++){
        ll L, R;
        cin >> L >> R;
        ll arr[R-L+1];
        for(ll k = L-1; k < R; k++){
            arr[k-(L-1)] = fib(A[k]);
            cout <<A[k]<<"  "<< arr[k-(L-1)]<<endl;
        }
        ll out = (findGCD(arr, R-L+1));
        cout << out<< endl;
        cout << out%1000000007<< endl;
    }
    return 0;
}

