/*
    My first idea, is to get the head pointer, then iterate through the entire linked list
    until a null ptr has been reached. I will create a temporary buffer that will check 
    whether or not we have already seen the same node. The iteration for all nodes will take 
    O(N)(N is the # of nodes). Checking the buffer will also take O(N) time. Leaving us with a 
    runtime of O(N^2).

*/

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    void printNodes()
    {
        Node *curr = this;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        delete curr;
        cout << endl;
    };
    Node *removeDups()
    {
        vector<int> linkedList;
        Node *curr = this;

        while (curr != NULL)
        {
            if (find(linkedList.begin(), linkedList.end(), curr->data) != linkedList.end())
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            curr = curr->next;
        }
        return curr;
    };
};

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 7;
    head->next = second;
    head->prev = NULL;

    second->data = 7;
    second->next = third;
    second->prev = head;

    third->data = 777;
    third->next = NULL;
    third->prev = second;

    head->printNodes();
    head->removeDups();
    head->printNodes();
}