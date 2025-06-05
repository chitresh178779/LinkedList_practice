#include<iostream>
using namespace std;

class Node{
        public:
        int data;
        Node* next;
        
        Node(int data1, Node*next1){
                    data=data1;
                    next=next1;
        }
        
        Node(int data1){
            data=data1;
            next=nullptr;
            
        } 
 };
 
 Node* convert2LL(int arr[],int size){
     Node* head= new Node(arr[0]);
     Node*temp= head;
     for( int i=1; i<size;i++){
         Node* mover= new Node(arr[i]);
         temp->next= mover;
         temp= mover;
     }
     return head;
 }
 
int middle(Node* head){
     int count=0;
     Node* slow=head;
     Node* fast=head;
     while(fast!=NULL && fast->next!=nullptr){
             slow=slow->next;
             fast=fast->next->next;
     }
     return slow->data;
}
             
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size;i++){
        cout<<"enter the element "<<i<<": ";
        cin>>arr[i];
    }
    Node* head= convert2LL(arr,size);
    int mid= middle(head);
    cout<<mid;
    return 0;
}