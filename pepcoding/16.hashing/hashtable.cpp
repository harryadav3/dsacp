#include <bits/stdc++.h>
#include "hashmap.h"
using namespace std;


int main() {

    Hashtable<int> h;
    h.insert("Dosa", 40);
    h.insert("Burger", 100);
    h.insert("Coke", 30);
    h.insert("Dosa", 60);
    h.insert("Adrak chai", 20);

    h.print();


    

    

    return 0;
}