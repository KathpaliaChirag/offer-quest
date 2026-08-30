#include<iostream>
#include "hashtable.h"
using namespace std;


int main(){
    hashtable<int> h;

    h.insert("Mango",100);
    h.insert("Apple",144);
    h.insert("Mango2",150);
    h.insert("Banana",148);
    h.insert("Apricot",140);

    h.print();

    return 0;
}
