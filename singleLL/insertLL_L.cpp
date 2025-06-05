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
void printLL(Node* head){
Node* temp=head;
while(temp!=NULL){
cout<<temp->data;
temp=temp->next;
cout<<endl;
}
}
Node* insertL(Node* head,int data){
    Node* temp=head;
    Node* end=new Node(data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=end;
    end->next=nullptr;
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
    Node* head=convert2LL(arr,size);
    insertL(head,60);
    printLL(head);
    return 0;
}