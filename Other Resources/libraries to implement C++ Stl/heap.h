#ifndef HEAP_H
#define HEAP_H

#include<vector>
using namespace std;


class Heap{

    vector<int> v;
    bool minH;

    bool cmp(int a,int b){
        if(minH){
            return a<b;
        }
        else{
            return a>b;
        }
    }
    void heapify(int i){

        int left = 2*i;
        int right = 2*i+1;

        int minIndex = i;
        int n = v.size();
        if(left< n && cmp(v[left],v[minIndex])){
            minIndex = left;
        }
        if(right<n && cmp(v[right],v[minIndex])){
            minIndex = right;
        }
        if(minIndex!=i){
            swap(v[minIndex],v[i]);
            heapify(minIndex);
        }


    }

public:
    Heap(bool h=true){
        v.push_back(-1);
        minH = h;
    }
    void push(int data){
        v.push_back(data);
        int i = v.size()-1;

        while(i>1 && cmp(v[i],v[i/2])){
            swap(v[i],v[i/2]);
            i = i/2;
        }
    }

    int top(){
        return v[1];
    }

    bool isEmpty(){
        return v.size()==1;
    }

    ///Pops the min element
    void pop(){
            int last = v.size() -1;
            swap(v[1],v[last]);
            v.pop_back();
            heapify(1);
    }
};


#endif // HEAP_H


