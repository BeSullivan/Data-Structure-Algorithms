// SaeedReza AlipourFard
// 9412032
#include <iostream>

using namespace std;

void specialRecursiveHanoi (int , char , char , char );
void recursiveHanoi (int ,char ,char ,char);
int cntMove = 1;

int main ()
{
    char src = 'A', aux = 'B', dest = 'C';
    int n;
    cout << endl << "We move disks from A rod to C rod with using B rod !" << endl
    << "And from rod A we can't move directly to rod C !" << endl;
    cout << "Enter Number of disks ! : " << endl;
    cin >> n;
    specialRecursiveHanoi (n, src, aux, dest);
    return 0;
}

void recursiveHanoi (int n ,char src ,char aux ,char dest)
{
    if (n == 0) return;
    recursiveHanoi (n - 1 ,src ,dest ,aux);
    cout << "Move #" << cntMove++ << " : Move Dist #" << n << " from " << src << " to " << dest << " ... " << endl;
    recursiveHanoi (n - 1 ,aux ,src ,dest);
}

void specialRecursiveHanoi (int n, char src, char aux, char dest)
{
    if ( n == 1)
    {
        cout << "Move #" << cntMove++ << " : Move Disk #1 from " << src << " to " << aux << " ... " << endl;
        cout << "Move #" << cntMove++ << " : Move Disk #1 from " << aux << " to " << dest << " ... " << endl;
        return;
    }
    specialRecursiveHanoi (n - 1, src, aux, dest);
    cout << "Move #" << cntMove++ << " : Move Disk #" << n << " from " << src << " to " << aux << " ... " << endl;
    recursiveHanoi (n - 1, dest, aux, src);
    cout << "Move #" << cntMove++ << " : Move Disk #" << n << " from " << aux << " to " << dest << " ... " << endl;
    specialRecursiveHanoi (n - 1, src, aux, dest);
    // recursiveHanoi (n - 1, dest, aux, src);
    // I don't understand problem so I solve it in two ways
    // line 41 and line 40
}
