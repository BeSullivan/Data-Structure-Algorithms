// SaeedReza AlipourFard
// 9412032
#include <iostream>

using namespace std;

void recursiveHanoi (int n ,char src ,char aux ,char dest);

int main ()
{
    int n;
    char src = 'A', aux = 'B', dest = 'C';
    cout << endl << "We move disks from A rod to C rod with using B rod !" << endl;
    cout << "Enter Number of Disks ! : " << endl;
    cin >> n;
    recursiveHanoi (n ,src ,aux ,dest);
    return 0;
}

void recursiveHanoi (int n ,char src ,char aux ,char dest)
{
    static int cntMove = 1;
    if (n == 0) return;
    recursiveHanoi (n - 1 ,src ,dest ,aux);
    cout << "\nMove #" << cntMove++ << " : Dist#" << n << " from " << src << " to " << dest << " ... " << endl;
    recursiveHanoi (n - 1 ,aux ,src ,dest);
}
