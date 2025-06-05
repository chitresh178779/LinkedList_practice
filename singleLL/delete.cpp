#include<iostream>
using namespace std;

class Node{
public:
int data;
Node* next;
Node(int data1,Node* next1){
data=data1;
next=next1;
}
Node(int data1){
data=data1;
next=nullptr;
}
};
int inarray(int size){
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    return arr[size];
}
Node* convert2LL(int arr[],int n){
    Node*head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* deleteL(Node* head){
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
}
Node* deleteF(Node* head){
    Node* temp=head;
    head=temp->next;
    delete temp;
    temp=nullptr;
    return head;
}
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
        cout<<" ";
    }
}


int main(){
    int size;
    cout<<"enter the size of array :";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"enter the element "<<i<<" :";
        cin>>arr[i];
    }
    Node* head=convert2LL(arr,5);
    cout<<"before deletion: ";
    printLL(head);cout<<"\n";
    cout<<"after deletion last: ";
    deleteL(head);
    printLL(head);cout<<"\n";
    cout<<"after deletion front: ";
    Node* newhead=deleteF(head);
    printLL(newhead);
    return 0;
}
