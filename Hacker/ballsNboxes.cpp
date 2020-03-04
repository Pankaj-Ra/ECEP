#include <bits/stdc++.h>

using namespace std;

typedef struct d_link_list
{
    struct d_link_list* prev;
    int info;
    int c;
    int jth;
    int penalty;
    int count;
    struct d_link_list* next;
}d_link;

void print_list(d_link* head);

int d_insert_last(d_link *&head, d_link *&tail, int info, int column){
    d_link *new_n = new d_link_list;
    if (new_n == NULL)return -1;
    new_n->prev = NULL;
    new_n->info = info;
    new_n->c = 1;
    new_n->jth = column;
    new_n->penalty = info - pow(column+1,2);
    new_n->count = 0;
    new_n->next = NULL;
    if(head == NULL){
        head = tail = new_n;
        return 0;
    }
    tail->next = new_n;
    new_n->prev = tail;
    tail = new_n;
    return 0;
}

int sortList(d_link *&head, d_link *&tail, int count, vector<int> &C){
    if(head == NULL || head->next == NULL)
        return 0;

    d_link *temp1 = head;
    d_link *temp2 = head->next;
    for(int i = 1; i < count; i++){
        for(int j = 0; j < count-i;j++){
            if((temp1->info < temp2->info)||
                    (C[temp1->jth] == 0 ||
                     C[temp2->jth] == 0)){
                if(C[temp1->jth] == 0 &&
                        C[temp2->jth] == 0){
                    if(temp1->penalty >=
                            temp2->penalty){
                        //temp1 = temp1->next;
                        temp2 = temp2->next;
                        continue;
                    }
                }
                else if(C[temp2->jth] == 0){
                    if(temp2->penalty <=
                            temp1->info){
                        //temp1 = temp1->next;
                        temp2 = temp2->next;
                        continue;
                    }
                }
                else if(C[temp1->jth] == 0){
                    if(temp2->info <=
                            temp1->penalty){
                        //temp1 = temp1->next;
                        temp2 = temp2->next;
                        continue;
                    }
                }
                d_link *temp = temp1->prev;
                temp1->prev = temp1->prev;
                //C[temp2->jth] -= (C[temp2->jth])?1:0;
                if(temp1 == head)
                    head = temp2;
                else
                    temp1->prev->next = temp2;
                if(temp2 == tail)
                    tail = temp1;
                else
                    temp2->next->prev = temp1;
                temp1->next->prev = temp2;
                temp1->next = temp2->next;
                temp2->prev->next = temp1;
                temp1->prev = temp2->prev;
                temp2->prev = temp;
                temp2->next = temp1;
                temp1 = temp2;
                temp2 = temp->next;
                continue;
            }
            //C[temp1->jth] -= (C[temp1->jth])?1:0;
            //temp1 = temp1->next;
            temp2 = temp2->next;
        }
        print_list(head);
        temp1->c = C[temp1->jth];
        C[temp1->jth] -= (C[temp1->jth])?1:0;
        temp1 = temp1->next;
        temp2 = temp1->next;
    }
    return 0;
}
void print_list(d_link* head){
    d_link *temp = head;
    while(temp->next != NULL){
        cout << temp->info;
        temp = temp->next;
    }
    cout << temp->info<<endl;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> A(n);
    long int balls = 0;
    for(int A_i = 0; A_i < n; A_i++){
        cin >> A[A_i];
        balls += A[A_i];
    }
    vector<int> C(m);
    for(int C_i = 0; C_i < m; C_i++){
        cin >> C[C_i];
    }
    d_link *hd = NULL;
    d_link *tl = NULL;
    vector< vector<int> > B(n,vector<int>(m));
    for(int B_i = 0;B_i < n;B_i++){
        for(int B_j = 0;B_j < m;B_j++){
            int temp;
            cin >> B[B_i][B_j];
            d_insert_last(hd, tl, B[B_i][B_j],B_j);
        }
    }

    long int candies = 0;
    print_list(hd);
    sortList(hd,tl,m*n,C);
    print_list(hd);
    d_link *temp = hd;
    int k = 0;
    bool pass;
    for(int j = 0; j < n && (hd); j++){
        pass = true;
        hd = temp;
        while(A[j] &&hd){
            if(pass ||(j+1 != hd->jth)){
                if(hd->c == 0){
                    candies +=hd->penalty;
                }
                else{
                    candies += hd->info;
                }
                A[j]--;
                if(temp != hd){
                    hd->prev->next = hd->next;
                    hd->next->prev = hd->prev;
                    hd->prev = temp->prev;
                    temp->prev->next = hd;
                    hd->next = temp;
                    temp->prev = hd;
                }
                hd = hd->next;
                temp = hd;
                pass = false;
                continue;
            }
            else if(j+1 != hd->jth){
                if(hd->c == 0){
                    candies +=hd->penalty;
                }
                else{
                    candies += hd->info;
                }
                A[j]--;
                if(temp != hd){
                    hd->prev->next = hd->next;
                    hd->next->prev = hd->prev;
                    hd->prev = temp->prev;
                    temp->prev->next = hd;
                    hd->next = temp;
                    temp->prev = hd;
                }
                hd = hd->next;
                temp = hd;
                continue;
            }
            hd = hd->next;
        }
    }
    cout << candies<<endl;
    return 0;
}

