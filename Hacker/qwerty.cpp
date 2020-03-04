// Name:Pankaj Rangta
// Summary:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Remove additional cin/cout before submission
string DecodeMessage(string message)
{
    string pad[10] = { " 0", ".1", "abc2", "def3",
         "ghi4","jkl5","mno6", "pqrs7", "tuv8", "wxyz9"};

    int count = 0;
    vector<char> msg;
    for(unsigned int i = 0; i < message.size(); i++){
        count = 0;
        if(message[i] != '_'){
            int num = message[i] - 48;
            while((message[i] != '_') && (i < message.size())){
                count++;
                i++;
            }
            string alphabet(pad[num]);
            int pos = count%(pad[num].size());
            pos = (pos)?pos-1:pad[num].size()-1;
            msg.push_back(alphabet[pos]);
        }
    }
    string out(msg.begin(),msg.end());

    return out;
}

/* Do not modify the main() function */
int main(void) {
    string cipherMessage;
    cin >> cipherMessage;
    cout << DecodeMessage(cipherMessage) << endl;
    return 0;
}

