#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    list<int> l;
    vector<int> v;

    for (int i = 0; i < 100000; i++) {
        l.push_back(i + 1);
        v.push_back(i + 1);
    }
	
// 0.01 sec

    cout << "list insert start" << endl;
    for (int i = 0; i < 100000; i++) {
        l.insert(l.begin(), 5);
    }
    cout << "list insert end" << endl;
	
// > 5 sec

    /*cout << "vector insert start" << endl;
    for (int i = 0; i < 100000; i++) {
        v.insert(v.begin(), 5);
    }
    cout << "vector insert end" << endl;*/

    return 0;
}