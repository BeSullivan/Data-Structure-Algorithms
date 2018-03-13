// SaeedReza AlipourFard
// 9412032
#ifndef BST_H
#define BST_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    int height;
};

class treeAVL
{
    public:
        void makeEmpty (Node * &); // make empty tree
        int addNode (Node * &,int); // adding value
        int removeNode (Node * &,int); // removing Node with special value
        int minSubTree (Node * &); // minimum value of right SubTree
        int maxSubTree (Node * &); // maximum value of left SubTree
        int searchNode (Node * ,int); // searching Node with special value and returning its pointer
        int findHeight (Node *); // Finding Height of Tree
        // Travels
        void inTravel (Node *); // InOrder
        void preTravel (Node *); // PreOrder
        void postTravel (Node *); // PostOrder
        // Rotations
        Node * simpleLRotate (Node * &);
        Node * simpleRRotate (Node * &);
        Node * doubleLRotate (Node * &);
        Node * doubleRRotate (Node * &);
        // Tool
        int maxi (int a ,int b)
        {
            return (a < b ? b : a);
        }
        // Remove All Tree
        void remAll (Node * &);
        static int vertex;
};

#endif // BST_H
