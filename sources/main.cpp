#include <iostream>
#include <map>

#include "HashMap.h"

using namespace std;

// ================== Hash Function ===================

struct MyKeyHash {
    unsigned long operator()(const int &k) const { return k % 100; }
};



int main() {

    cout << "================================  Testing MultiMap =================================== " << endl;

    HashMap<int, string, MyKeyHash> map;

    map.insert(make_pair(34, "hello"));
    map.insert(make_pair(117, "amigo"));
    map.insert(make_pair(57, "salut"));
    map.insert(make_pair(67, "blank"));
    map.insert(make_pair(117, "salom"));
    map.insert(make_pair(67, "morning"));
    map.insert(make_pair(67, "juicy"));
    map.insert(make_pair(57, "salut"));

    map.display();

    cout  << "***************** Iterating through Map (not sorted) ***********************" << endl;

    for (HashMap<int, string, MyKeyHash>::iterator it1 = map.begin(); it1 != map.end(); it1++) {
        cout << it1->getKey() << ": " << it1->getValue() << endl;
    }

    cout << "************************ Testing equal_range(key) ****************************" << endl;

    pair<HashMap<int, string, MyKeyHash>::iterator, HashMap<int, string, MyKeyHash>::iterator> itss = map.equal_range(67);

    for (HashMap<int, string, MyKeyHash>::iterator it1 = itss.first; it1 != itss.second; it1++) {
        cout << it1->getKey() << ": " << it1->getValue() << endl;
    }

    cout << "*****************************************************************************" << endl;


    HashMap<int, string, MyKeyHash>::iterator it = map.begin();
    cout << it->getKey() << ": " << it->getValue() << endl;
    it++;


    cout << "After deleting elements with key 67:" << endl;

    map.erase(67);
    map.display();

    return 0;
}
