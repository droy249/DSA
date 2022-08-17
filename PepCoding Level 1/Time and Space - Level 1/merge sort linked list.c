#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Takes two lists sorted in increasing order and merge their nodes
// to make one big sorted list, which is returned
struct Node* sortedMerge(struct Node* a, struct Node* b)
{
    // base cases
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    struct Node* result = NULL;
 
    // pick either `a` or `b`, and recur
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
 
    return result;
}
 
/*
    Split the given list's nodes into front and back halves
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    It uses the fast/slow pointer strategy
*/
void frontBackSplit(struct Node* source, struct Node** frontRef,
                    struct Node** backRef)
{
    // if the length is less than 2, handle it separately
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
 
    struct Node* slow = source;
    struct Node* fast = source->next;
 
    // advance `fast` two nodes, and advance `slow` one node
    while (fast != NULL && fast->next != NULL)
    {
        // fast = fast->next;
        // if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
 
    // `slow` is before the midpoint in the list, so split it in two
    // at that point.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
 
// Sort a given linked list using the merge sort algorithm
void mergesort(struct Node** head)
{
    // base case — length 0 or 1
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
 
    struct Node* a;
    struct Node* b;
 
    // split `head` into `a` and `b` sublists
    frontBackSplit(*head, &a, &b);
 
    // recursively sort the sublists
    mergesort(&a);
    mergesort(&b);
 
    // answer = merge the two sorted lists
    *head = sortedMerge(a, b);
}
 
int main(void)
{
    // input keys
    int keys[] = { 6, 8, 4, 3, 1, 9 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        push(&head, keys[i]);
    }
 
    // sort the list
    mergesort(&head);
 
    // print the sorted list
    printList(head);
 
    return 0;
}