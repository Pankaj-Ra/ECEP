#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<sstream>
#include<fstream>
#include<cstdlib>

#define MAX 3

using namespace std;

typedef struct Stud_info
{
    int s_id;
    int marks;
    string sub;
}Field;

void processData(map<string,pair<int,int> > &S_board, Field *f){
    //If map is empty, insert the new field where subject name acts as key
    if(S_board.empty()){
        S_board.insert(make_pair(f->sub,make_pair(f->s_id,f->marks)));
    }
    map<string,pair<int,int> >::iterator it = S_board.find(f->sub);
    //If subject already exist in map, compare the student Ids and replace with
    //samller Id
    if(it != S_board.end()){
        if(f->s_id < (it->second).first){
            (it->second).first = f->s_id;
            (it->second).second = f->marks;
        }
    }else{
        //Add new subject deatils to map
        S_board.insert(make_pair(f->sub,make_pair(f->s_id,f->marks)));
    }
}

int main(){
    ifstream file("input.txt");
    string line;
    map<string,pair<int,int> > S_board;
    while(getline(file,line)){
        istringstream istring(line);
        string token[MAX];
        int i = 0;
        while(i < MAX){
            if(!getline(istring, token[i++] ,'|')){
                cout<<"Input is not in the format 22|English|45"<<endl;
                return 0;
            }
        }
        Field f;
        f.s_id = atoi(token[0].c_str());
        f.marks = atoi(token[2].c_str());
        f.sub = token[1].c_str();
        processData(S_board,&f);

    }
    ofstream out("output.txt");
    map<string,pair<int,int> >::iterator it = S_board.begin();
    for(;it != S_board.end(); it++){
        out << it->first << ": "<< (it->second).second<<endl;
    }
    return 0;
}
