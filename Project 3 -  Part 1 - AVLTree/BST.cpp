// SaeedReza AlipourFard
// 9412032
#include <iostream>
#include <malloc.h>
#include "BST.h"

using namespace std;

int treeAVL :: vertex = 0;

void treeAVL :: makeEmpty (Node * &head) // Caution --> head is reference of Pointer to Node !!
{
    head = NULL;
}

int treeAVL :: addNode (Node * &head ,int src) // Caution --> head is reference of Pointer to Node !!
{
    static int cnt = 0;
    if ( !head )
    {
        head = new Node;
        if (!head)
        {
            cout << " <--- Memory is Full !!! ---> " << endl;
        }
        head -> value = src;
        head -> left = NULL;
        head -> right = NULL;
        head -> height = 0;
        vertex ++;
    }
    else
    {
        if (head -> value > src)
        {
            addNode (head -> left ,src);
            if ((findHeight(head -> left) - findHeight(head -> right) == 2))
            {
                if (src < head -> left -> value)
                    head = simpleRRotate (head);
                else
                    head = doubleRRotate (head);
            }
        }
        else if (head -> value < src)
        {
            addNode (head -> right ,src);
            if ((findHeight(head -> right) - findHeight(head -> left)) == 2)
            {
                if (src > head -> right -> value)
                    head = simpleLRotate (head);
                else
                    head = doubleLRotate (head);
            }
        }
        else
        {
            cout << " <--- Already Element Exists !!! ---> " << endl;
        }
    }
    int m ,n ,h;
    m = findHeight(head -> left);
    n = findHeight (head -> right);
    h = maxi (m ,n);
    head -> height = h + 1;
    return cnt;
}

int treeAVL :: removeNode (Node * &p ,int src)
{
    static int cnt = 0;
    Node * tmp;
    if ( !p )
        cout << " <--- Element Not Found !!! ---> " << endl;
    if (src < p -> value)
        removeNode (p -> left ,src);
    else if (src > p -> value)
        removeNode (p -> right ,src);
    else if ( !p -> left && !p -> right)
    {
        cnt ++;
        vertex --;
        tmp = p;
        free (tmp);
        p = NULL;
        cout << " <--- Element Deleted Successfully !!! ---> " << endl;
    }
    else if ( !p -> left )
    {
        cnt ++;
        vertex --;
        tmp = p;
        p = p -> right;
        free (tmp);
        cout << " <--- Element Deleted Successfully !!! ---> " << endl;
    }
    else if ( !p -> right )
    {
        cnt ++;
        vertex --;
        tmp = p;
        p = p -> left;
        free ( tmp );
        cout << " <--- Element Deleted Successfully !!! ---> " << endl;
    }
    else
    {
        cnt ++;
        vertex --;
        if (findHeight(p -> right) > findHeight(p -> left))
            p -> value = minSubTree (p -> right);
        else
            p -> value = maxSubTree (p -> left);
    }
}

int treeAVL :: maxSubTree (Node * &p)
{
    int c;
    if ( !p -> right )
    {
        c = p -> value;
        p = p -> left;
        return c;
    }
    else
    {
        c = maxSubTree (p -> right);
        return c;
    }
}

int treeAVL :: minSubTree (Node * &p)
{
    int c;
    if ( !p -> left )
    {
        c = p -> value;
        p = p -> right;
        return c;
    }
    else
    {
        c = minSubTree (p -> left);
        return c;
    }
}

int treeAVL :: searchNode (Node * head ,int src)
{
    static int cnt = 0;
    cnt ++;
    if ( !head )
        cout << "Element Not Found !!!! " << endl;
    if (head -> value == src)
        cout << "Yeah !! Element was Found !!! " << endl;
    else if (head -> value > src)
        searchNode (head -> left ,src);
    else
        searchNode (head -> right ,src);
    return cnt;
}

int treeAVL :: findHeight (Node * p)
{
    if ( !p )
        return 0;
    return p -> height;
}

void treeAVL :: inTravel (Node *p)
{
    if ( p )
    {
        inTravel ( p -> left );
        cout << p -> value << " ";
        inTravel ( p -> right );
    }
}

void treeAVL :: preTravel (Node *p)
{
    if ( p )
    {
        cout << p -> value << " ";
        preTravel ( p -> left );
        preTravel ( p -> right );
    }
}

void treeAVL :: postTravel (Node *p)
{
    if ( p )
    {
        postTravel ( p -> left );
        postTravel ( p -> right );
        cout << p -> value << " ";
    }
}

Node * treeAVL :: simpleRRotate (Node * &p) // Caution --> p is reference to pointer to Node
{
    Node *tmp = p -> left;
    p -> left = tmp -> right;
    tmp -> right = p;
    p -> height = maxi (findHeight(p -> left) ,findHeight (p -> right)) + 1;
    tmp -> height = maxi (findHeight(tmp -> left) ,findHeight (tmp -> right)) + 1;
    return tmp;
}

Node * treeAVL :: simpleLRotate (Node * &p) // Caution --> p is reference to pointer to Node
{
    Node *tmp = p -> right;
    p -> right = tmp -> left;
    tmp -> left = p;
    p -> height = maxi (findHeight(p -> left) ,findHeight (p -> right)) + 1;
    tmp -> height = maxi (findHeight(tmp -> left) ,findHeight (tmp -> right)) + 1;
    return tmp;
}

Node * treeAVL :: doubleRRotate (Node * &p) // Caution --> p is reference to pointer to Node
{
    p -> left = simpleLRotate (p -> left);
    return simpleRRotate (p);
}

Node * treeAVL :: doubleLRotate (Node * &p) // Caution --> p is reference to pointer to Node
{
    p -> right = simpleRRotate (p -> right);
    return simpleLRotate (p);
}

void treeAVL :: remAll (Node * &p)
{
    if ( !p )
        return;
    Node *del = p;
    remAll (p -> left);
    remAll (p -> right);
    free (del);
    p = NULL;
}
