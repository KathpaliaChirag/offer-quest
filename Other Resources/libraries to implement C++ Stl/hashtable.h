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

    ~node(){
        if(next!=NULL){
            delete next;
        }
    }
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
    void rehash(){
        node<T> **oldBuckets = buckets;

        int oldts = ts;
        ts = ts*2;
        cs = 0;

        buckets = new node<T>*[ts];
        for(int i=0;i<ts;i++){
            buckets[i] = NULL;
        }

        for(int i=0;i<oldts;i++){
            node<T>* temp = oldBuckets[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp = temp->next;
            }
            if(oldBuckets[i]!=NULL){
                delete oldBuckets[i];
            }
        }
        delete [] oldBuckets;

    }
    void insert(string key,T value){
        int i = hashFn(key);

        node<T>* n = new node<T>(key,value);
        n->next = buckets[i];
        buckets[i] = n;
        cs++;

        float lf = (float)cs/ts;
        if(lf>0.7){
            //cout<<"In rehash "<<lf<<endl;
            rehash();
        }
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

    T* search(string key){
        int index = hashFn(key);
        node<T>*temp = buckets[index];
        while(temp!=NULL){
            if(temp->key==key){
                return &(temp->value);

            }
            temp = temp->next;
        }

        return NULL;
    }

    void remove(string key){
        int index = hashFn(key);
        ///Iterate the index LL and delete the node with key
        ///HW
    }
    T& operator[](string key){
        T* temp = search(key);
        if(temp==NULL){
            T value;
            insert(key,value);
            temp = search(key);
            return *temp;
        }
        return *temp;
    }

    ~hashtable(){
        for(int i=0;i<ts;i++){
            if(buckets[i]!=NULL){
                delete buckets[i];
            }

        }
        delete [] buckets;
    }


};






#endif // HASHTABLE_HJ
