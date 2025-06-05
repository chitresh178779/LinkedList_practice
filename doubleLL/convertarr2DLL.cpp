#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
Node* convert2dLL(int arr[],int size){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<size;i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
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
    Node* head=convert2dLL(arr,size);
    printLL(head);
    return 0;
}
