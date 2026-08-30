#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>
#include<cstring>
using namespace std;


template<typename T>
class hashtable;

template<typename T>
class node{
private:
    string key;
    T value;
    node<T>*next;

public:
    node(string k,T v){
        key = k;
        value = v;
        next = NULL;
    }
    friend class hashtable<T>;
};

template<typename T>
class hashtable{
    int cs;
    int ts;
    node<T>** buckets;

    int hashFn(string key){
        int p=1;
        int ans = 0;
        int L = key.size();
        for(int i=0;i<L;i++){
                ans += key[L-i-1]*p;
                p *= 37;
                p %= ts;
                ans = (ans+ts)%ts;
        }
        return ans;

    }

public:
    hashtable(int ds=7){
        cs = 0;
        ts = ds;
        buckets = new node<T>*[ts];
        for(int i=0;i<ts;i++){
            buckets[i] = NULL;
        }
    }
    void insert(string key,T value){
        int i = hashFn(key);

        node<T>* n = new node<T>(key,value);
        n->next = buckets[i];
        buckets[i] = n;
        cs++;
    }

    void print(){
        for(int i=0;i<ts;i++){
                cout<<"Bucket "<<i<<"=>";

                for(node<T>*temp = buckets[i];temp!=NULL;temp=temp->next){
                    cout<<temp->key<<",";
                }
                cout<<endl;
        }
    }


};






#endif // HASHTABLE_HJ
