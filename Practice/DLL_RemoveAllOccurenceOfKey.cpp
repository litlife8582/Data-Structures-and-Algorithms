#include<iostream>

using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};

Node* deleteKey(Node* head,int target){
    Node* current=head;
    
    while(current!=NULL){
        if (current->data==target) {

            if (current==head) {
                head=current->next;
                if (head!=NULL) head->prev=NULL;
            }else {
                    current->prev->next=current->next;
                if (current->next!=NULL){
                    current->next->prev=current->prev;
                }
            }
            current=current->next;
        }else current=current->next;
    }

    return head;
}

int main(){
    int n,value;
    cout<<"Enter the size of the linked list:";
    cin>>n;

    Node* head=NULL;
    Node* tail=NULL;

    cout<<"Enter the elements of the linked List:";
    for(int i=0;i<n;i++){
        cin>>value;
        Node* newNode=new Node(value);

        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    int target;

    cout<<"Enter the target:";
    cin>>target;

    Node* deletedHead=deleteKey(head,target);

    while(deletedHead!=NULL){
        cout<<deletedHead->data<<"->";
        deletedHead=deletedHead->next;
    }

    return 0;
}