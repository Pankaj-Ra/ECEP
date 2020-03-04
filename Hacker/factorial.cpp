#include <iostream>
#include <vector>
#include <new>
using namespace std;


int main(){
    int n;
    cin >> n;
    /*int count = 0;
    unsigned long long int factorial = 1;
    for(int i = n; i > 1; i--){
        int j = i;
        if(i%10 == 0){
            count ++;
            j = j/10;
        }
        factorial *= j;
        if (factorial%10 == 0){
            count++;
            factorial = factorial/10;
        }
    }
    cout << factorial;
    int zero = 0;
    while(count--)
        cout << zero;*/
    vector<int> f1(200);
    vector<int> f2(200);
    f1[0] = 1;
    f2[0] = 1;
    int max_length = 1;

    for(int factor = 1; factor <= n; factor++){
        int carry = 0;
        if(factor%2 == 0){
            for(int k = 0; k < max_length; k++){
                f2[k] = ((f1[k]*factor + carry)%10);
                carry = (f1[k]*factor + carry)/10;
                if((k == max_length - 1) && carry){
                    f2[k + 1] = carry;
                    max_length++;
                }
            }
        }else{
            for(int l = 0; l < max_length; l++){
                f1[l] = (f2[l]*factor + carry)%10;
                carry = (f2[l]*factor + carry)/10;
                if((l == max_length - 1) && carry){
                    f1[l + 1] = carry;
                    max_length++;
                }
            }
        }
    }
    for(int m = max_length - 1; m >= 0 ; m--){
        int temp = (n%2)?f1[m]:f2[m];
        cout << temp;
    }
    return 0;
}
