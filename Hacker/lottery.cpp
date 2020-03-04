#include <bits/stdc++.h>
#include <string>

using namespace std;

/*string removeDups(string str)
{
  bool bin_hash[256] = {0};
  int i = 0, j = 0;
  char temp;

  while (i < str.size())
  {
    temp = str[i];
    if (bin_hash[temp] == 0)
    {
        bin_hash[temp] = 1;
        str[j] = str[i];
        j++;
    }
    i++;
  }

  string substring = str.substr(0,j);
  return substring;
}


int winningLotteryTicket(vector <string> t, int wp) {
    string num = "0123456789";
    for(int j = 0; j < t.size()-1; j++){
        for(int i = j+1; i < t.size(); i++){
            string temp = t[j] + t[i];
            sort(temp.begin(), temp.end());
            temp = removeDups(temp);
            if(temp == num)
                wp++;
        }
    }
    return wp;
}

int main() {
    int n;
    cin >> n;
    vector<string> t;
    int wp = 0;
    int tnt = n-1;
    string num = "0123456789";
    for(int t_i = 0; t_i < n; t_i++){
        string temp;
       cin >> temp;
        sort(temp.begin(), temp.end());
        int i = 0;
        int j = 0;
        temp = removeDups(temp);
        if(temp.size() < 10){
            t.push_back(temp);
            continue;
        }
        else{
           wp += tnt;;
            tnt--;
        }
    }
    int result = winningLotteryTicket(t, wp);
    cout << result << endl;
    return 0;
}
*/
string sorted(string str){
    vector<int> arr(10);
    int count  = 10;
    string s;
    for(int i = 0 ; i < str.size(); i++){
        if(count == 0)
            break;
        else if(str[i] == '\0')
            continue;
        else if(arr[str[i]-48] == 0){
            count--;
            arr[str[i]-48] = 1;
            s += str[i];
        }
    }
    if(count == 0){
        return "0123456789";
    }
    return s;
}

int winningLotteryTicket(vector <string> t, int wp) {

    for(int j = 0; j < t.size()-1; j++){
        for(int i = j+1; i < t.size(); i++){
            /*if(t[i] == t[j])
                continue;*/
            string temp = t[j] + t[i];
            temp = sorted(temp);
            if(temp == "0123456789")
                wp++;
        }
    }
    return wp;
}

int main() {
    int n;
    cin >> n;
    vector<string> t;
    int wp = 0;
    int tnt = n-1;
    for(int t_i = 0; t_i < n; t_i++){
        string temp;
       cin >> temp;        
       
        temp = sorted(temp);        
        if(temp.size() < 10){
            sort(temp.begin(),temp.end());
            t.push_back(temp);
            continue;
        }
        else {
            wp += tnt;         
            tnt--;
        }
    }
    int result = winningLotteryTicket(t, wp);
    cout << result << endl;
    return 0;
}
