// SaeedReza AlipourFard
// 9412032
#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;

struct Node // we implement stack with linked list !
{
    int val;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

void push (Stack *s ,int dsk);
int pop (Stack *s);
bool isEmptyStack (Stack *s);
void moveDecide (Stack *src ,Stack *dest ,char s ,char d);
void moveDisk (char srcPole ,char destPole ,int disk);

int main ()
{
    unsigned n;
    Stack src ,aux ,dest; // using three stacks for rods to push disks
    // make stacks empty !
    src.top = NULL;
    aux.top = NULL;
    dest.top = NULL;

    cout << "Enter number of Disks : " << endl;
    cin >> n;

    char s = 'A' ,a = 'B' ,d = 'C';
    if (n % 2 == 0)
    {
        char tmp = d;
        d = a;
        a = tmp;
    }
    int totalMove = pow (2 ,n) - 1; // number of  moves

    for (int i = n; i >= 1; i--) // little disks should move first
        push (&src ,i);
    // Non-Recursive Hanoi Solve
    for (int i = 1; i <= totalMove; i++)
    {
        if (i % 3 == 1)
            moveDecide (&src ,&dest ,s ,d);
        else if (i % 3 == 2)
            moveDecide (&src ,&aux ,s ,a);
        else
            moveDecide (&aux ,&dest ,a ,d);
    }
    return 0;
}

void push (Stack *s ,int dsk) // push element to stack
{
    Node * p = new Node;
    if ( p == NULL )
    {
        cout << " Warning !!! Memory is FULL !!! " << endl;
        return;
    }
    p -> val = dsk;
    p -> next = s -> top;
    s -> top = p;
}

int pop (Stack *s) // pop top element of stack
{
    if (isEmptyStack(s))
        return INT_MIN;
    Node *trg = s -> top;
    int r = s -> top -> val;
    s -> top = s -> top -> next;
    free (trg);
    return r;
}

bool isEmptyStack (Stack *s) // checking that stack is empty or not
{
    if (s -> top != NULL)
        return 0;
    return 1;
}

void moveDecide (Stack *src ,Stack *dest ,char s ,char d) // Decide which disk should move
{
    int srcTop = pop (src);
    int destTop = pop (dest);
    if (srcTop == INT_MIN)
    {
        push (src ,destTop);
        moveDisk (d ,s ,destTop);
    }
    else if (destTop == INT_MIN)
    {
        push (dest ,srcTop);
        moveDisk (s ,d ,srcTop);
    }
    else if (srcTop > destTop)
    {
        push (src ,srcTop);
        push (src ,destTop);
        moveDisk (d ,s ,destTop);
    }
    else
    {
        push (dest ,destTop);
        push (dest ,srcTop);
        moveDisk (s ,d ,srcTop);
    }
}

void moveDisk (char srcPole ,char destPole ,int disk) // it's print our move
{
    cout << endl << "Move the Disk #" << disk << " from " << srcPole << " to " << destPole << endl;
}
