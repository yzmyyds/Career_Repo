#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=nullptr;
    }
};
//disordered linked list
node* create_list(vector<int> vals){
    node*head=new node(vals[0]);
    node*curr=head;
    for (int i=1; i<vals.size();i++){
        node* new_node=new node(vals[i]);
        curr->next=new_node;
        curr=curr->next;
    }
    return head;
}
void list_output(node* head){
    node* curr=head;
    while (curr!=nullptr){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
//swap function
void swap(node*a,node*b){
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}

node* bubble_sort(node*head,bool ascending=true){
    if (head==nullptr || head->next==nullptr) return head;
    bool flag=false;
    node* curr_node=nullptr;
    node* next_node=nullptr;
    while(!flag){
        flag=true;
        curr_node=head;
        next_node=curr_node->next;
        while(next_node!=nullptr){
            if ((ascending && curr_node->data>next_node->data) || (!ascending && curr_node->data<next_node->data)){
                swap(curr_node,next_node);
                flag=false;
            }
            curr_node=next_node;
            next_node=next_node->next;
            }
        }
    return head;
}

int main(){
    //use random values
    vector<int> vals={5,3,8,6,4,2,5,7,1};
    node* head=create_list(vals);
    for (int i=0; i<vals.size(); i++) {
        printf("%d ", vals[i]);
    }
    printf("\n");
    node* new_head=bubble_sort(head,1);
    list_output(new_head);
    return 0;
}