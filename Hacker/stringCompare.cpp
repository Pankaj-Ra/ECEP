#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
    int s_size = s.size();
    int t_size = t.size();
    bool pass;

    if ((k - s_size) >= t_size){
        s = t;
        pass = true;
    }
    else{
        int size = s_size - t_size;
        int diff = (s_size > t_size)?s_size - t_size:t_size - s_size;
        pass = ((!diff && (k%2 == 0)) || (k%2 == diff%2))?true:false;
        bool s_is_big = false;
        if(size > 0){
            s.resize(s_size - diff);
            k -= diff;
            s_is_big = true;
        }
        else if(size){
            string temp(diff, 'A');
            s = s + temp;
        }
        int c_diff = diff;
        int operation_1 = 0;
        int operation_2 = 0;

        for(int i = t_size - 1; i >= 0 && k > 0; i--){

            if(!s.compare(t))break;
            else if((s[i] != t[i]) && k > 0 && (s_is_big || diff)){
                s[i] = t[i];
                k -= (s_is_big)?(2*(t_size - i) - operation_1):1;
                operation_1 = 2*(t_size - i);
                diff--;
            }
            else if((s[i] != t[i]) && k > 0 && !diff){
                s[i] = t[i];
                k -= 2*(t_size - c_diff - i) - operation_2;
                operation_2 = 2*(t_size - c_diff - i);
            }
        }
    }
    string res = ((k >= 0) && pass && !s.compare(t))?"Yes":"No";
    cout << res;
    return 0;
}
