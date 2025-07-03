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
    cout<<"->";
}
cout<<"NULL"<<endl;
}

Node* rotateleft(Node* head,int k){
    if(head==NULL || head->next==NULL) return head;
    else{
        for(int i=1;i<=k;i++){
            Node* temp=head;
            while(temp->next!=nullptr){
                Node* mover=temp->next;
                swap(temp->data,mover->data);
                temp=temp->next;
            }
        }
    }
    return head;
}

Node* rotateright(Node* head,int k){
    if(head==NULL || head->next==NULL) return head;
    else{
        for(int i=1;i<=k;i++){
            Node* temp=head;
            while(temp->next!=nullptr){
                Node* mover=temp->next;
                swap(temp->data,mover->data);
                temp=temp->next;
            }
        }
    }
    return head;
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
    Node* head2= rotateleft(head,2);
    printLL(head2);
    return 0;
}