#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void sndQuestion(){
    string elem;
    ll maxium = INT_MIN;
    ll elveKal = 0;
    ll calories = 0;
    priority_queue<ll> pq;

    ifstream file("./input.txt");
    while(getline(file, elem)){
        if (elem != ""){
            calories = stoi(elem);
            elveKal += calories;
        }else{
            maxium = max(maxium, elveKal);
            pq.push(elveKal);
            elveKal = 0;
        }
    }
    
    ll topThree = 0;
    for(int i=0; i<3; i++){
        topThree += pq.top();
        pq.pop();
    }

    cout<<"snd: "<<topThree<<endl;
}

void fstQuestion(){
    string elem;
    ll maxium = INT_MIN;
    ll elveKal=0;
    ll calories = 0;

    ifstream file("./input.txt");
    while( getline(file, elem) ){
        if (elem!=""){
            calories = stoi(elem);
            elveKal += calories;
        }else{
            maxium = max(maxium, elveKal);
            elveKal = 0;
        }
    }
    cout<<"fst: "<< maxium <<endl;
}

int main(){
    fstQuestion();
    sndQuestion();
    return 0;
}
