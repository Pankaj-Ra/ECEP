#include <iostream>
#include <vector>
#include <new>

using namespace std;

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main(){
    int n, i ,j;
    int k, l, m;
    cin >> n >> k;
    vector<int> r(n);
    for(int r_i = 0; r_i < n; r_i++){
        cin >> r[r_i];
    }
    int b = k+1;
    int facto = factorial(b);
    facto *= factorial(n-b);
    int collision = factorial(n);
    collision /= facto;
    cout << collision<<endl;
    int *sum = NULL;
    sum = new int[collision];
    double total = 0;
    double pie = 3.14159265358979;
    cout.precision(9);
    for (i =0; i < collision; i++){
        for(j = 0; j<= k && (i+j)<n; j++){
            sum[i] += r[i+j];
        }
        if(j<=k){
            l = k-j;
            while(l>=0){
                sum[i]+=r[l--];
            }
        }
        sum[i] *= sum[i];
        cout << fixed<<(pie*sum[i]);
        total += (pie*sum[i]);
        sum[i] = 0;
        if((j>k)&&((n-(k+1)) ==(n-(j+i)))){
            while(j<n){
                sum[i] += r[i+j];
                j++;;
            }
        }
        else if(j>k){
            while((j+i)<n){
                sum[i] += r[i+j];
                j++;;
            }
            m = i-1;
            while(m >= 0){
                sum[i] += r[m--];
            }
        }
        else{
            int m =i-1;
            while(m > (k-j))
                sum[i] += r[m--];
        }
        sum[i] *= sum[i];
        cout <<" " <<fixed<<(pie*sum[i]);
        total += (pie*sum[i]);
        cout << " "<<fixed<<total<< endl;
    }
    delete [] sum;
    sum = NULL;
    cout << fixed<<total/collision;
    return 0;
}
