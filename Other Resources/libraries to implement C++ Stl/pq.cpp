#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

class Fruit{
public:
    string name;
    int price;
    Fruit(string n,int p){
        name = n;
        price =p;
    }

    void print(){
        cout<<name<<endl;
        cout<<price<<endl;
    }
};

class Compare{
public:
    bool operator()(int a,int b){
       // cout<<"Comparing two things"<<a<<" and "<<b<<endl;
        return a>b;

    }
};
ostream& operator<<(ostream&os,Fruit f){
    f.print();
}

class FruitCompare{
public:
    bool operator()(Fruit f1,Fruit f2){
        return f1.price < f2.price ;
    }

};

int main(){

    priority_queue<int,vector<int>,Compare> h;

    int a[] = {4,3,1,2,5,7};
    int n = sizeof(a)/sizeof(int);

    for(int i=0;i<n;i++){
        h.push(a[i]);
    }
    while(!h.empty()){
            cout<<h.top()<<" ";
            h.pop();
    }

    // Compare cmp;
    //cmp();
    Fruit f("Apple",100);
    Fruit f2("Mango",200);
    Fruit f3("Potato",150);

    priority_queue<Fruit,vector<Fruit>, FruitCompare> pf;
    pf.push(f);
    pf.push(f2);
    pf.push(f3);

    while(!pf.empty()){
        Fruit tf = pf.top();
        cout<< tf <<endl;
        pf.pop();

    }

return 0;
}
