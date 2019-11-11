#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
};

Node * getTail(Node * cur){
  while(cur != NULL && cur->next != NULL)
    cur = cur->next;
  return cur;
}

Node * partition(Node *head, Node * end, Node ** presentHead, Node ** presentEnd){
  Node *pivot = end;
  Node *prev = NULL, *cur = head, *tail = pivot;
  while(cur != pivot){
    if(cur->data < pivot->data){
      if((*presentHead) == NULL)
        (*presentHead) = cur;
      prev = cur;
      cur = cur->next;
    } else{
      if(prev)
        prev->next = cur->next;
      Node * temp = cur->next;
      cur->next = NULL;
      tail->next = cur;
      tail = cur;
      cur = temp;
    }
  }
  if((*presentHead) == NULL)
    (*presentHead) = pivot;
  (*presentEnd) = tail;
  return pivot;
}

Node * quickSortRecursive(Node * head, Node * end){
  if(!head || head == end)
    return head;
  Node * presentHead = NULL, * presentEnd = NULL;
  Node * alwaysPivot = partition(head, end, &presentHead, &presentEnd);
  if (presentHead != alwaysPivot){
    Node * temp = presentHead;
    while(temp->next != alwaysPivot)
      temp = temp->next;
    temp->next = NULL;
    presentHead = quickSortRecursive(presentHead, temp);
    temp = getTail(presentHead);
    temp->next = alwaysPivot;
  }
  alwaysPivot->next = quickSortRecursive(alwaysPivot->next, presentEnd);
  return presentHead;
}

void quickSort(Node ** head){
  (*head) = quickSortRecursive(*head, getTail(*head));
  return;
}

void push(Node ** head, int new_data){
  Node * temp = new Node();
  temp->data = new_data;
  if((*head) != NULL){
    temp->next = (*head);
    (*head) = temp;
  }
  else{
    (*head) = temp;
    temp->next = NULL;
  }
}

void printList(Node * head){
  Node * temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

int main(){
  Node * head = NULL;
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);
  printList(head);
  quickSort(&head);
  printList(head);
  return 0;
}
