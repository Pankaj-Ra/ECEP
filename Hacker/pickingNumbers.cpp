#include <iostream>
#include <cmath>
#include <vector>
#include <new>

using namespace std;
typedef struct d_link_list
{
    struct d_link_list* prev;
    int num;
    struct d_link_list* next;
}d_link;

int d_insert_last(d_link *&head, d_link *&tail, int info){
    d_link *new_n = new d_link_list;
    if (new_n == NULL)return -1;
    new_n->prev = NULL;
    new_n->num = info;
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
int play_game(d_link *&head){
    d_link *temp = head;
    d_link *temp1;
    int n_count, o_count, i_count, max_count = 0;
    while(temp && temp->next){
        o_count = n_count = i_count = 0;
        temp1 = temp->next;
        while(temp1){
            int num = temp->num - temp1->num;
                if((num == -1)||(num == 0)||(num == 1)){
                    temp1->prev->next = temp1->next;
                    if(temp1->next)
                        temp1->next->prev = temp1->prev;
                    d_link *temp2 = temp1;
                    temp1 = temp1->next;
                    delete temp2;
                    n_count += (num == -1)?1:0;
                    o_count += (num == 0)?1:0;
                    i_count += (num == 1)?1:0;
                    continue;
                }
                temp1 = temp1->next;
        }
        temp = temp->next;
        o_count += (n_count > i_count)?n_count:i_count;
        max_count = (max_count < o_count)?o_count:max_count;
    }
    return max_count+1;
}
int delete_link_list(d_link *&head, d_link *&tail)
{
    if (head == NULL)return 0;
    d_link *temp = head;
    while(head->next != NULL){
        head = head->next;
        delete temp;
        temp = head;
    }
    delete temp;
    head = tail = NULL;
    return 0;
}

int main(){
    int n;
    cin >> n;
    d_link *head = NULL;
    d_link *tail = NULL;
    vector<int> sequence(n);
    for(int sequence_i = 0; sequence_i < n; sequence_i++){
        cin >> sequence[sequence_i];
        if(d_insert_last(head, tail, sequence[sequence_i]))cout <<"something is wrong"<<endl;
    }
    int maxDigits = play_game(head);
    delete_link_list(head, tail);
    cout << maxDigits <<endl;
    return 0;
}
