#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main(){
    unordered_map<string,int> m;
    //m.reserve(100);
//    cout<<m.bucket_count()<<endl;

    pair<string,int> p("Guava",80);
    pair<string,int> p2;
    //cin>>p2.first;
    //cin>>p2.second;

    m.insert(p);
    //m.insert(p2);
    m.insert(make_pair("Mango",100));
    m["Apple"] = 150;

//    cout<<m.bucket_count()<<endl;
//    cout<<m.load_factor()<<endl;
//    cout<<m.max_load_factor()<<endl;
//

    if(m.count("Apple")){
        cout<<m["Apple"]<<endl;
    }
    else{
        cout<<"Not found "<<endl;
    }

    //unordered_map<string,int>::iterator
    auto f = m.find("Apple");
    if(f!=m.end()){
        cout<<"Apple found "<<f->second<<endl;
    }

    for(auto j:m){
        cout<<j.first<<" "<<j.second<<endl;
    }
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    auto pi = 3.14;
    auto x  = 10;

return 0;
}
