#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
     int data;
     Node *next;
     Node *back;

     Node(int data1)
     {
          data = data1;
          next = nullptr;
          back = nullptr;
     }
     Node(int data1, Node *next1, Node *back1)
     {
          data = data1;
          next = next1;
          back = back1;
     }
};

bool checkPalindrome(Node *head)
{
     if (head == NULL || head->next == NULL)
          return true;

     Node *start = head;
     Node *end = head;
     // Moving end to tail
     while (end->next != nullptr)
     {
          end = end->next;
     }

     while (start != end && start->back != end)
     {

          if (start->data != end->data)
          {
               return false;
          }

          if (start->next == end)
          {
               // MIDDLE OF ODD LL
               break;
          }
          start = start->next;
          end = end->back;
     }
     return true;
}
