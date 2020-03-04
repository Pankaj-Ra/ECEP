#include <bits/stdc++.h>

using namespace std;

typedef list<int> lst;
map<string,lst> files;

int filesystem(string &s){
    char *cmd = strdup(s.c_str());
    char *its = strtok(cmd," ");
    switch(*its){
        case 'c':{
            its = strtok(NULL,"(");
            map<string,lst>::iterator it =
                files.find(its);
            int pos = 0;
            if(it != files.end()){
                list<int>::iterator it_l =
                    it->second.begin();
                if(it->second.size() > 1){
                    *it_l += 1;
                    pos = *(++it_l);
                    it->second.erase(it_l);
                }
                else{
                    *it_l += 1;
                    pos = *it_l;
                }
            }else{
                lst list;
                list.push_back(0);
                files.insert(pair<string,lst> (its,list));
                it = files.find(its);
            }
            cout <<"+ "<<it->first;
            if(pos)
                cout <<"("<<pos<<")";
            cout<<endl;
            break;
        }
        case 'd':{
            its = strtok(NULL,"(");
            map<string,lst>::iterator it =
                files.find(its);
            list<int>::iterator it_l =
                it->second.begin();
            its = strtok(NULL,")");
            int val = 0;
            if(its){
                val = atoi(its);
            }
            *it_l -= 1;
            it_l++;
            for(it_l;it_l != it->second.end();it_l++){
                if(val < *it_l){
                    it->second.insert(it_l,val);
                    break;
                }
            }
            if(it_l == it->second.end()){
                it->second.insert(it_l,val);
            }
            cout <<"- "<<it->first;
            if(val)
                cout<<"("<<val<<")";
            cout<<endl;
            break;
        }
        case 'r':{
            its = strtok(NULL,"( ");
            map<string,lst>::iterator it =
                files.find(its);
            list<int>::iterator it_l=
                it->second.begin();
            its = strtok(NULL,") ");
            char *sub = strtok(NULL," ");
            int val = 0;
            if(sub){
                val = atoi(its);
            }else
                sub = its;
            *it_l -= 1;
            it_l++;
            for(it_l;it_l !=  it->second.end();it_l++){
                if(val < *it_l){
                    it->second.insert(it_l,val);
                    break;
                }
            }
            if(it_l == it->second.end()){
                it->second.insert(it_l,val);
            }
            cout <<"r "<<it->first;
            if(val)
                cout<<"("<<val<<")";
            cout<<" -> ";
            it = files.find(sub);
            int pos = 0;
            if(it != files.end()){
                it_l =it->second.begin();
                if(it->second.size() > 1){
                    *it_l += 1;
                    pos = *(++it_l);
                    it->second.erase(it_l);
                }
                else{
                    *it_l += 1;
                    pos = *it_l;
                }
            }else{
                lst list;
                list.push_back(0);
                files.insert(pair<string,lst> (its,list));
                it = files.find(its);
            }
            cout <<it->first;
            if(pos)
                cout <<"("<<pos<<")";
            cout<<endl;
            break;
        }
    }
    return 0;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string command;
        std::getline(std::cin >> std::ws,command);
        filesystem(command);
    }
    return 0;
}


