#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int d){
    data =d;
    prev=NULL;
    next=NULL;
    }
};
/**
INSERT THE NODE AT THE BEGINING OF THE LINKED LIST
*/
Node* InsertAtBegining(Node* head,int data){
    Node* newNode = new Node(data);
    if(head==NULL){
        head->next= newNode;
        newNode->prev=head;
    }
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return head;
    }
}
/**
INSERT AT THE END OF THE DOUBLY LINKED LIST
*/
Node* InsertAtEnd(Node* head,int data){
    Node* newNode= new Node(data);
    Node* temp=head;
    if(head==NULL)return newNode;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev= temp;
    return head;
}
/**
REVERSE THE DOUBLY LINKED LIST
*/
Node* ReverseTheLinkedList(Node* head){
    if(head==NULL)return NULL;
    else{
        Node* prev=NULL;
        Node* curr= head;
        Node* next= head->next;
        while(curr->next!=NULL){
            curr->prev=next;
            curr->next=prev;
            prev=curr;
            curr=next;
            next= next->next;
        }
        curr->prev=next;
        curr->next= prev;
        return curr;
    }
}
/**
DELETE THE HEAD OF THE DOUBLY LINKED LIST
*/
Node* deleteHeadOfDoublyLinkedList(Node* head){
    if(head==NULL){
        return head;
    }
    else{
        Node* temp= head;
        head= head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
}
/**
DELETE THE LAST NODE OF THE DOUBLY LINKED LIST
*/

Node* deleteLastNodeOfLinkedList(Node* head){
    if(head==NULL){
        return head;
    }
    else{
        Node* temp= head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->prev->next=NULL;
        delete temp;
        return head;
    }
}
int main()
{
    Node * head = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    head->next=node2;
    node2->next=node3;
    node2->prev=head;
    node3->prev=node2;
    head=InsertAtBegining(head,0);
    head=InsertAtEnd(head,300);
    head=ReverseTheLinkedList(head);
    head= deleteHeadOfDoublyLinkedList(head);
    head= deleteLastNodeOfLinkedList(head);
    cout<<head->data<<endl;
    cout<<head->next->data<<endl;
    cout<<head->next->next->data<<endl;
    cout<<head->next->next->next->data<<endl;
    return 0;
}
