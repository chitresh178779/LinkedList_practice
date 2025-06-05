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
 
int search(Node* head, int data1){
     Node* temp=head;
     int i=1;
     while(temp!=NULL){
             if(temp->data==data1){
                     return i;
             }
             temp=temp->next;
             i++;
     }
     return -1;
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
    int data;
    cout<<"enter the calue to search: ";
    cin>>data;
    int positionofNode= search(head,data);
    cout<<"the position of Node is: "<<positionofNode;
    return 0;
}