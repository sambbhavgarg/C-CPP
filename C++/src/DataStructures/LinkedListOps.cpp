#include<iostream>
#include<unordered_set>
#include<stack>
using namespace std;

class Node{
public:
  // int data;
  int data;
  Node * next;
};

void push(Node ** head_ref, char new_data){
  Node * temp = new Node();
  temp->data = new_data;
  temp->next = *head_ref;
  *head_ref = temp;
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
  cout<<endl;
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

// int getCountRecursively(Node * temp){
//   if(temp == NULL){
//     return 0;
//   }
//   return 1 + innerFunc(temp->next);
// } This restricts me to head.
//   the function below can have many node * type variables without
//   having to compile them on every recursion
int getCountRecursively(Node * head){
  int innerFunc(Node *);
  Node * temp = head;
  struct X{
    static int innerFunc(Node * temp){
      if(temp == NULL){
        return 0;
      }
      return 1 + innerFunc(temp->next);
    }
  };
  int count = X::innerFunc(temp);
  return count;
}

int search(Node * head, int key){
  int index = 0, count = 0;
  Node * temp = head;
  if(head == NULL){
    cout<<"List Empty";
    return 0;
  }
  while(temp != NULL){
    // cout<<"test";
    if(temp->data == key){
      // cout<<"test";
      cout<<"Element found at index "<<index<<"\n";
      count++;
    }
    temp = temp->next;
    index++;
  }
  if(count == 0){
    cout<<"Element not found\n";
    return 0;
  }
  return count;
}

void nThFromLast(Node * head, int n){
  Node * primary = head;
  Node * ref = head;
  int count = 0;
  if(head != NULL){
    while(count < n){
      if(ref->next == NULL){
        cout<<"Entered number overflows.\n";
        return;
      }
      ref = ref->next;
      count++;
    }
    while(ref != NULL){
      ref = ref->next;
      primary = primary->next;
    }
    cout<<n<<"th Element from Last is "<<primary->data<<endl;
  }
}// Moves a pointer far from main ptr n places. then moves both together like a window.
// so when ref pointer reaches null. main ptr is n places from the end.

void midElement(Node * head){
  // cout<<"test";
  Node * t1 = head;
  Node * t2 = head;
  while(t2 != NULL && t2->next != NULL){
    t1 = t1->next;
    t2 = t2->next->next;
  }
  cout<<"Mid Element: "<<t1->data<<endl;
}

// bool detectLoop(Node * head){
//   unordered_set<Node *> s;
//   while(head != NULL){
//     //if the current iteration in list is not end,
//     //return true since it is looped.
//     if (s.find(head) != s.end())
//       return true;
//     s.insert(head);
//     head = head->next;
//   }
//   return false;
// }

int detectLoop(Node * head){
  Node * slow_ptr = head, * fast_ptr = head;

  // while (slow_p && fast_p && fast_p->next) { why confuse me bro?
  while(1){
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;
    if(slow_ptr == fast_ptr){
      cout<<"Found Loop";
      return 1;
    }
  }
  return 0;
}

bool isPalin(Node * head){
  Node * temp = head;
  int i;
  stack<int> s;
  while(temp != NULL){
    s.push(temp->data);
    temp = temp->next;
  }
  while(head != NULL){
    i = s.top(); s.pop();
    if(head->data != i)
      return false;
    head = head->next;
  }
  return true;
}

bool isRecursivePalindrome(Node ** left, Node * right){
  if(right == NULL)
    return true;
  bool isp = isRecursivePalindrome(left, right->next);
  /*
  Recursively go to end of list using isRecursivePalindrome(left, right->next)
  Check if right = null
  if right is null, isp becomes true and skips the first if (isp == false)
  check the data for both pointers.
  if theyre the same, move left ptr forward and return true(isp1)
  if theyre not, move left ptr ahead and return isp1 as false to isRecursivePalindrome(left, right->next)
  isp comes out to be false in this case and returns false for all upcoming outfolds.

  */
  if(isp == false)
    return false;
  bool isp1 = (right->data == (*left)->data);
  *left = (*left)->next;
  return isp1;
}
//Time Complexity: O(n)
//Auxiliary Space: O(n) if Function Call Stack size is considered, otherwise O(1).

bool isPalindromeDriver(Node * head){
  isRecursivePalindrome(&head, head);
}

void lisToSetSorted(Node * head){
  Node * current = head;
  Node * next_next;
  if(current==NULL){
    return;
  }
  while(current->next != NULL){
    if(current->data == current->next->data){
      next_next = current->next->next;
      free(current->next);
      current->next = next_next;
    }
    else{
      current = current->next;
    }
  }
}

void lisToSetSortedRecursive(Node * head){
  Node * to_free;
  if(head == NULL)
    return;
  if(head->next != NULL){
    if(head->data == head->next->data){
      to_free = head->next;
      head->next = head->next->next;
      free(to_free);
      lisToSetUnsorted(head);//keep deleting from head until deletion
    }
    else{
      lisToSetUnsorted(head->next);//move ahead if no deletion
    }
  }
}

int main(){
  // cout<<"test";
  Node * head = NULL;
  append(&head, 6);
  push(&head, 7);
  insertAfter(head->next, 8);
  append(&head, 8);
  append(&head, 6);
  append(&head, 7);

  // insertAfter(head->next->next->next, 78);
  // cout<<"test";
  // cout<<"Created Linked list is: ";
  printList(head);
  lisToSetSortedRecursive(head);

  printList(head);
  // int count = getCountRecursively(head);
  // cout<<"\n"<<count<<"\n";
  // count = search(head, 1);
  // cout<<"78 appeared "<<count<<" number of times\n";
  // nThFromLast(head, 2);
  // midElement(head);
  // int result = isPalin(head);
  // if(result)
  //   cout<<"Palindrome"<<endl;
  // else
  //   cout<<"Not Palindrome"<<endl;
  // head->next->next->next->next = head;
  //
  // if(detectLoop(head))
  //   cout<<"Looped!";


  // Node * head = NULL;
  // char str[] = "RacecaR";
  // int i;
  //
  // for(i=0; str[i] != '\0'; i++){
  //   push(&head, str[i]);
  // }
  // printList(head);

  // isPalindromeDriver(head) ? cout<<"Palindrome"<<endl : cout<<"Not Palindrome"<<endl;
  // return 0;
}
