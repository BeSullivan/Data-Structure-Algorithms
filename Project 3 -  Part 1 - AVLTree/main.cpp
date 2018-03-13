// SaeedReza AlipourFard
// 9412032
#include <iostream>
#include "BST.h"
#include <cmath>
#include <conio.h>
#include <cstdlib>

using namespace std;

void wait ();
void logging (int ,int);

int main ()
{
    treeAVL bst;
    Node *root;
    bst.makeEmpty(root);
    int n ,k;
    char check;
    do
    {
        cout << endl <<  ".......... This is << AVL TREE >> Program ......... " << endl << endl;
        cout << "........ Enter 1 to insert a value to tree ........ " << endl;
        cout << "........ Enter 2 to delete a value to tree ........ " << endl;
        cout << "........ Enter 3 to search a value to tree ........ " << endl;
        cout << "........ Enter 4 to inorder travel of tree ........ " << endl;
        cout << "........ Enter 5 to preorder travel of tree ....... " << endl;
        cout << "........ Enter 6 to postorder travel of tree ...... " << endl;
        cout << "................. Enter 0 to exit ................. " << endl;
        check = getch ();
        system ("cls");
        switch (check)
        {
            case '1':
                cout << endl << " <--- Please Enter a Value To insert ! ---> " << endl;
                cin >> n;
                k = bst.addNode (root ,n);
                logging (k ,bst.vertex);
                wait();
                break;
            case '2':
                cout << endl << " <--- Please Enter a Value To Delete ! ---> " << endl;
                cin >> n;
                k = bst.removeNode (root ,n);
                logging (k ,bst.vertex);
                wait();
                break;
            case '3':
                cout << endl << " <--- Please Enter a Value To Search ! ---> " << endl;
                cin >> n;
                k = bst.searchNode(root ,n);
                logging (k ,bst.vertex);
                wait ();
                break;
            case '4':
                cout << endl << " <--- InOrder Travel ---> " << endl;
                bst.inTravel (root);
                wait ();
                break;
            case '5':
                cout << endl << " <--- PreOrder Travel ---> " << endl;
                bst.preTravel (root);
                wait ();
                break;
            case '6':
                cout << endl << " <--- PostOrder Travel ---> " << endl;
                bst.postTravel (root);
                wait ();
                break;
            case '0':
                cout << endl << " <--- (: (: Thank You for using out AVL Tree ;) ;) ---> " << endl;
                bst.remAll (root);
                wait();
                break;
            default :
                cout << endl << " !!!!!! Invalid Input !!! !!!!!! " << endl;
                wait ();
        }
    } while (check != '0');
    return 0;
}

void wait ()
{
    cout << endl << "Press Any Key To Continue !" << endl;
    getch();
    system ("cls");
}

void logging (int t ,int v)
{
    cout << endl << endl;
    int l = log(v);
    cout << " <<----- \tour number of checking is \t----->> " << t << endl
         << " <<----- \tAnd number of node in tree \t----->> " << v << endl
         << " <<----- \tAnd Log of Nodes of tree is \t----->> " << l << endl << endl;
}
