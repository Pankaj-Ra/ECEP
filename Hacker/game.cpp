#include <iostream>
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
void print_list(d_link* head){
    d_link *temp = head;
    while(temp->next != NULL){
        cout << temp->num;
        temp = temp->next;
    }
    cout << temp->num<<endl;
}

int play_game(d_link *&head){
    d_link *temp = head;
    d_link *temp1 = (temp->next)?temp->next:NULL;
    int count = 0;
    while(temp1 && (temp1->next != NULL)){
        if ((temp->num == 0)&&(temp1->next->num == 0)){
            temp->next = temp->next->next;
            temp->next->prev = temp;
            if(temp->prev != NULL){
                delete temp1;
                temp= temp->prev;
                temp1 = temp->next;
                count++;
                print_list(head);
                continue;
            }
            delete temp1;
            temp1 = temp->next;
            count++;
            print_list(head);
            continue;
        }
        temp = temp->next;
        temp1 = temp->next;
        print_list(head);
    }
    string res = (count%2 == 0)?"Bob":"Alice";
    cout << res << endl;
    return 0;
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
    int g;
    int n;
    d_link *head = NULL;
    d_link *tail = NULL;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        cin >> n;
        vector<int> sequence(n);
        for(int sequence_i = 0; sequence_i < n; sequence_i++){
            cin >> sequence[sequence_i];
            if(d_insert_last(head, tail, sequence[sequence_i]))cout <<"something is wrong"<<endl;
        }
        play_game(head);
        delete_link_list(head, tail);
    }
    return 0;
}
