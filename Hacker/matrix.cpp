#include <iostream>

using namespace std;
typedef long long l_int;

l_int matrix(l_int m, l_int n, l_int k){
    l_int rect = 0;
    rect = m*n;
    while(k < rect){
        rect = (m<n)?(m*(--n)):((--m)*n);
    }
    return rect;
}

int main()
{
    int T;
    cin >> T;
    l_int M, N, K;

    for(int i = 0; i < T; i++){
        cin >> M >> N >> K;
        l_int area = matrix(M, N, K);
        cout << area << endl;
    }

    return 0;
}
