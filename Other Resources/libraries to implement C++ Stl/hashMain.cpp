#include<iostream>
#include "hashtable.h"
using namespace std;


int main(){
    hashtable<int> h(3);

    h.insert("Mango",100);
    h.insert("Apple",144);
    h.insert("Mango2",150);
    h.insert("Banana",148);
    h.insert("Apricot",140);
    h.print();

    string fruit;
    cin>>fruit;
    int *price = h.search(fruit);
    if(price!=NULL){
        cout<<"Price is "<<*price<<endl;
    }
    else{
        cout<<"Fruit doesn't exist !"<<endl;
    }


    cout<<h["Mango"];

    h["Kiwi"] = 150;
    h["Mango"] = 170;

    cout<<h["Mango"]<<endl;
    cout<<h["Kiwi"]<<endl;



    return 0;
}
