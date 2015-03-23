/*
 * LinkedList.h
 *
 *  Created on: Mar 22, 2013
 *      Author: Faisal
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;
struct Node { int data; Node* next; };

 /*To add a node at the end of existing list.*/
void append(struct Node *head, int n) {
 Node *newNode = new Node;
newNode->data = n;
 newNode->next = NULL;
Node *cur = head;
 while(cur)
{
if(cur->next == NULL)
{
cur->next = newNode;
 return;
}
cur = cur->next;
 }
}

/*creating a linked list with one node.*/
void initialize(struct Node *head,int n){
head->data = n;
head->next =NULL;
}

/**/
void addTail(struct Node **head, int n)
{
Node *newNode = new Node;
 newNode->data = n;
newNode->next = *head;
 *head = newNode;
}

struct Node *search(struct Node *head, int n) {
 Node *cur = head;
while(cur)
{
if(cur->data == n)
return cur;
 cur = cur->next;
 }
cout << "No Node " << n << " in list.\n";
 }
bool delete(struct Node **head, Node *ptrDel)
 {
Node *cur = *head; if(ptrDel == *head)
{
*head = cur->next;
delete ptrDel;
return true;
}
while(cur) {
 if(cur->next == ptrDel)
{
 cur->next = ptrDel->next;
 delete ptrDel; return true;
}
cur = cur->next;
}
return false;
}
/* reverse the list */
struct Node* reverse(struct Node** head) {
 Node *parent = *head;
Node *me = parent->next;
 Node *child = me->next;
 /* make parent as tail */
parent->next = NULL;
while(child) { me->next = parent; parent = me;
 me = child; child = child->next;
 } me->next = parent;
*head = me;
 return *head;
}
/* Creating a copy of a linked list */
 void cloneList(struct Node *node, struct Node **pNew) {
if(node != NULL)
{ *pNew = new Node;
 (*pNew)->data = node->data;
 (*pNew)->next = NULL;
cloneList(node->next, &((*pNew)->next));
 }
}
/* Compare two linked list */
/* return value: same(1), different(0) */
int compareList(struct Node *node1, struct Node *node2)
 {
static int flag;
 /* both lists are NULL */
if(node1 == NULL && node2 == NULL)
 {
flag = 1;
 }
else {
if(node1 == NULL || node2 == NULL)
 flag = 0;
 else if(node1->data != node2->data)
 flag = 0;
else compareList(node1->next, node2->next);
 }
return flag;
}
void deleteList(struct Node **node)
{
struct Node *tmpNode;
while(*node) { tmpNode = *node;
 *node = tmpNode->next;
 delete tmpNode;
 }
 }
void display(struct Node *head) {
Node *list = head;
while(list) {
 cout << list->data << " ";
 list = list->next;
}
cout << endl; cout << endl;
}
int main() { struct Node *newHead;
 struct Node *head = new Node;
 initialize(head,45);  display(head);
 append(head,18); display(head);
append(head,91); display(head);
 append(head,73); display(head);
  append(head,4);  display(head);
 addTail(&head,1);  display(head);

int delNum = 5;
Node *ptrDelete = search(head,delNum);
 if(delete(&head,ptrDelete))

cout << "Comparing lists\n";
cout << "Are the two lists same?\n";
if(compareList(head,newHead))
cout << "Yes, they are same!\n";
 else cout << "No, they are different!\n";
 cout << endl;

cout << "Node "<< delNum << " deleted!\n";
 display(head);

cout << "Copying List\n";
cloneList(head,&newHead);
display(newHead);

cout << "reversed List\n";
 reverse(&head);
 display(head);


delNum = 73;
ptrDelete = search(newHead,delNum);
 if(delete(&newHead,ptrDelete)) {
 cout << "Node "<< delNum << " deleted!\n";
cout << "New list after deletion\n";
 display(newHead);
}

cout << "Comparing the two lists again...\n";
 cout << "Are the two lists same?\n";
if(compareList(head,newHead))
 cout << "Yes, they are same!\n";
else cout << "No, they are different!\n";
cout << endl;
cout << "Deleting the copied list\n";
deleteList(&newHead);
display(newHead);
return 0;
}


#endif /* LINKEDLIST_H_ */
