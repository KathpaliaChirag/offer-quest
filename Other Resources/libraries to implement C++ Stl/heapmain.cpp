#include<iostream>
#include "heap.h"
#include "heap.h"
using namespace std;


int main(){

    Heap h(false); ///Max Heap

    int a[] = {4,3,1,2,5,7};
    int n = sizeof(a)/sizeof(int);

    for(int i=0;i<n;i++){
        h.push(a[i]);
    }
    while(!h.isEmpty()){
            cout<<h.top()<<" ";
            h.pop();
    }


}
