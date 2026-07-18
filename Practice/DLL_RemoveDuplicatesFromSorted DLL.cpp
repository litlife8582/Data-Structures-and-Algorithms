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

Node* deleteDuplicateKey(Node* head){
    Node* current=head;
    while (current->next!=NULL) {
        if (current->data==current->next->data) {
            Node* duplicate=current->next;
            current->next=duplicate->next;

            if (duplicate->next!=NULL) {
                duplicate->next->prev=current;
            }
            delete duplicate;

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
    for(int i=0;i<n;i++) {
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

    Node* newHead=deleteDuplicateKey(head);

    while(newHead!=NULL){
        if (newHead->next!=NULL) cout<<newHead->data<<"->";
        else cout<<newHead->data;
        newHead=newHead->next;
    }

    return 0;
}