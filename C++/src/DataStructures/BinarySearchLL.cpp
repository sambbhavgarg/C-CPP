#include<iostream>
using namespace std;

class Node{
public:

  int data;
  Node * nxt;
};

void push(Node ** head, int new_data){
  Node * temp = new Node;
  temp->data = new_data;
  temp->nxt = NULL;
  if((*head) != NULL){
    temp->nxt = *head;
  }
  *head = temp;
}

void printList(Node * head){
  Node * temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->nxt;
  }
  cout<<endl;
}

Node * getTail(Node * cur){
  while(cur != NULL && cur->nxt != NULL){
    cur = cur->nxt;
  }
  return cur;
}

Node * partition(Node * head, Node * end, Node ** thisHead, Node ** thisEnd){
  Node * pivot = end;
  Node  * prev = NULL, * cur = head, * tail = pivot;
  while(cur != pivot){
    if(cur->data < pivot->data){
      if((*thisHead) == NULL)
        (*thisHead) = cur;
      prev = cur;
      cur = cur->nxt;
    } else{
      if(prev)
        prev->nxt = cur->nxt;
        Node * tmp = cur->nxt;
        cur->nxt = NULL;
        tail->nxt = cur;
        tail = cur;
        cur = tmp;
    }
  }
  if((*thisHead) == NULL)
    *thisHead = pivot;
  *thisEnd = tail;
  return pivot;
}

Node * quickSortRecursive(Node * head, Node * end){
  if(!head || head==end)
    return head;
  Node * thisHead = NULL, * thisEnd = NULL;
  Node * alwaysPivot = partition(head, end, &thisHead, &thisEnd);
  if(thisHead != alwaysPivot){
    Node * tmp = thisHead;
    while(tmp->nxt != alwaysPivot)
      tmp = tmp->nxt;
    tmp->nxt = NULL;
    thisHead = quickSortRecursive(thisHead, tmp);
    tmp = getTail(thisHead);
    tmp->nxt = alwaysPivot;
  }
  alwaysPivot->nxt = quickSortRecursive(alwaysPivot->nxt, thisEnd);
  return thisHead;
}

void quickSort(Node ** head){
  (*head) = quickSortRecursive(*head, getTail(*head));
  return;
}
 Node * getMid(Node * head, Node * end){
   Node * slow = head, * fast = head;
   while(fast != end && fast->nxt != end){
     slow = slow->nxt;
     fast = fast->nxt->nxt;
   }
   return slow;
 }

void binarySearchLL(Node * head, Node * last, int key){
  Node * start = head, * end = last;
  Node * mid = getMid(start, end);
  if(start == end){
    cout<<"Not Found"<<endl;
  }
  else{
    if(getMid(start, end)->data == key)
      cout<<"Found";
    else if(getMid(start, end)->data > key){
      end = mid;
      binarySearchLL(start, end, key);
    }
    else if(getMid(start, end)->data < key){
      start = mid->nxt;
      binarySearchLL(start, end, key);
    }
  }
}
int main(){
  Node * head = NULL;
  push(&head, 4);
  push(&head, 2);
  push(&head, 9);
  push(&head, 1);
  push(&head, 8);
  printList(head);
  quickSort(&head);
  printList(head);
  binarySearchLL(head, getTail(head), 1);
}
