#include <bits/stdc++.h>

using namespace std;
typedef struct d_link_list
{
    struct d_link_list* prev;
    long int pos;
    long int v;
    long int d;
    bool canReach;
    bool visit;
    struct d_link_list* next;
}d_link;

int d_insert_last(d_link *&head,d_link *&tail,
        long int i,long int r,
        long int t,long int n){
    d_link *new_n = new d_link_list;
    if (new_n == NULL)return -1;
    new_n->prev = NULL;
    new_n->pos = i;
    new_n->v = r;
    if(i == t){
        new_n->d = 0;
    }
    else if((i<t)&&((t-i)<=((n-t)+i))){
        new_n->d = t-i;
    }
    else if(i<t){
        new_n->d = (n-t)+i;
    }
    else if((i>t)&&((i-t)<=((n-i)+t))){
        new_n->d = i-t;
    }
    else{
        new_n->d = (n-i)+t;
    }
    new_n->canReach = (new_n->d<=new_n->v)?
        true:false;
    new_n->visit = false;
    new_n->next = NULL;
    if(head == NULL){
        head = tail = new_n;
        return 0;
    }
    tail->next = new_n;
    new_n->prev = tail;
    tail = new_n;
    if(i == n-1){
        tail->next = head;
        head->prev = tail;
    }
    return 0;
}

long int circularWalk(long int n,long int s,long int t,long int r_0,long int g,long int seed,long int p){
    d_link *hd = NULL;
    d_link *tl = NULL;
    long int r;
    if(s == t)return 0;
    if(((s == r_0)&&(r_0 == 0))||(p == 1))return -1;
    if(((r_0 == 0)&&(seed == p)))return -1;
    if((g == 0)&&(seed == p))return -1;
    for(int i = 0; i < n; i++){
        r = (i)?(r*g+seed)%p:r_0;
        d_insert_last(hd, tl, i, r, t, n);
    }
    while(hd->pos != s){
        if(s <= (n-s))
            hd = hd->next;
        else
            hd = hd->prev;
    }
    hd->visit = true;
    d_link *temp = hd;
    long int value = hd->v;
    long int V = hd->v;
    long int big = 0;
    long int pos = 0;
    if(hd->canReach)return 1;
    long int sec = 1;
    bool reached = false;
    while(value>0){
        temp = temp->next;
        if(temp->canReach){
            sec++;
            reached = true;
            break;
        }
        value--;
        if(big<=(temp->v-(V-value))){
            big = temp->v;
            pos = temp->pos;
        }
        if((value == 0)&&(big != 0)){
            long int cpos = temp->pos;
            if(cpos < pos){
                cpos = n + temp->pos;
            }
            value = big - (cpos - pos);
            sec++;
            big = 1;
            pos = 0;
        }
        big--;
    }
    temp = hd;
    value = hd->v;
    V = hd->v;
    big = 0;
    pos = 0;
    long int sec1 = 1;
    while(value>0){
        temp = temp->prev;
        if(temp->canReach){
            sec1++;
            return sec1;
        }
        value--;
        if(big<=(temp->v-(V-value))){
            big = temp->v;
            pos = temp->pos;
        }
        if((value == 0)&&(big != 0)){
            long int lpos = pos;
            if(temp->pos>lpos){
                lpos = n + lpos;
            }
            value = big - (lpos - temp->pos);
            sec1++;
            big = 1;
            pos = 0;
        }
        if(reached && (sec<sec1)){
            return sec;
        }
        big--;
    }
    return -1;
}

int main() {
    long int n;
    long int s;
    long int t;
    cin >> n >> s >> t;
    long int r_0;
    long int g;
    long int seed;
    long int p;
    cin >> r_0 >> g >> seed >> p;
    long int result = circularWalk(n, s, t, r_0, g, seed, p);
    cout << result << endl;
    return 0;
}

