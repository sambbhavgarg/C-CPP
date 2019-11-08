#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node * next;
};

void push(Node ** head_ref, int new_data){
  Node * temp = new Node();
  temp->data = new_data;
  temp->next = (*head_ref);
  (*head_ref) = temp;
}

void insertAfter(Node * prev_node, int new_data){
  Node * temp = new Node();
  temp->data = new_data;
  temp->next = prev_node->next;
  prev_node->next = temp;
}

void append(Node ** head_ref, int new_data){
  Node * temp = new Node;
  Node * temp2 = new Node;
  temp->data = new_data;
  temp->next = NULL;

  temp2->next = *head_ref;
  if(*head_ref == NULL){
    *head_ref = temp;
    return;
  }
  while(temp2->next != NULL){
    temp2 = temp2->next;
  }
  temp2->next = temp;
  return;
}

void printList(Node * start){
  while(start != NULL){
    cout<<" "<<start->data;
    start = start->next;
  }
}

int getCount(Node * head){
  int count = 0;
  Node * temp = head;
  if (temp == NULL){
    cout<<"List empty";
  }
  else{
    while(temp != NULL){
      count++;
      temp = temp->next;
    }
  }
  return count;
}

int main(){
  Node * head = NULL;
  append(&head, 6);
  push(&head, 7);
  push(&head, 1);``
  append(&head, 4);
  insertAfter(head->next, 8);
  insertAfter(head->next->next->next, 78);
  cout<<"Created Linked list is: ";
  printList(head);
  int count = getCount(head);
  cout<<"\n"<<count<<"\n";
  return 0;
}
