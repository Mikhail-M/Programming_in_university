#include "myset.h"
#include "test.h"

#include <iostream>

using namespace std;

int main()
{
    Test test;
    QTest::qExec(&test);
    MySet<int> *set = new MySet<int>;
    set->add(1);
    set->add(2);
    MySet<int> set2;
    set2.add(2);
    set2.add(3);
    set = set2.merge(set);
    cout << set->exist(1);

    delete set;
}