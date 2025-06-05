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
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
        cout<<" ";
    }
Node* deleteF(Node* head){
    Node* temp=head;
    head=temp->next;
    delete temp;
    temp=nullptr;
}



};



int main(){
    return 0;
}