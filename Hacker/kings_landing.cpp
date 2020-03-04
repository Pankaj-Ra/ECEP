#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<vector<int> > pair, vector<char> &visit, int arr_num_candles[], int stock, int &min_candles){
    visit[stock] = 't';
    for(unsigned int n = 0; n < pair[stock].size(); n++){
        if(visit[pair[stock][n]] == 'f'){
            if(arr_num_candles[pair[stock][n]-1] < min_candles)
                min_candles = arr_num_candles[pair[stock][n]-1];
            dfs(pair, visit, arr_num_candles, pair[stock][n],  min_candles);
        }
    }
}

// Remove additional cin/cout before submission.
long long int FindMinimumNumberOfCandles(int num_wildfire, int num_strings, int arr_num_candles[], int arr_stringConnection[][2])
{
    vector<char> visit(num_wildfire + 1, 'f');
    vector<vector<int> > pair(num_wildfire + 1);
    for(int i = 0; i < num_strings; i++){
        pair[arr_stringConnection[i][0]].push_back(arr_stringConnection[i][1]);
        pair[arr_stringConnection[i][1]].push_back(arr_stringConnection[i][0]);
    }
    long long int total_candles = 0;
    for(int j = 1; j <= num_wildfire; j++){
        if(visit[j] == 'f'){
            int min_candles = arr_num_candles[j-1];
            dfs(pair, visit, arr_num_candles, j,  min_candles);
            total_candles += min_candles;
        }
    }
    return total_candles;
}

// Do not modify main() function.
int main()
{
    int num_wildfire, num_strings, i;
    cin>>num_wildfire;
    int arr_num_candles[num_wildfire];
    for (int i=0; i< num_wildfire; i++)
    {
        cin>>arr_num_candles[i];
    }
    cin>>num_strings;
    int arr_stringConnection[num_strings][2];
    for (i = 0; i < num_strings; i++)
    {
        cin>>arr_stringConnection[i][0]>>arr_stringConnection[i][1];
    }


    cout<<FindMinimumNumberOfCandles(num_wildfire, num_strings, arr_num_candles, arr_stringConnection)<<endl;
}

