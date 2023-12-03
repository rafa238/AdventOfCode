#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll getPriority(char c){
    if( (int)c > 90){
        return c - 'a' + 1;
    } else {
        return c - 'A' + 27;
    }
}

ll solveSnd(){

}

void sndQuestion(){
    string elem;
    ifstream file("./input.txt");
    ll sum, cont;
    sum = cont = 0;
    vector<string> rucksacks;

    //Get all the rucksacks
    while (getline(file, elem)) {
        rucksacks.push_back(elem);
    }
    
    ll i = 0;
    while(i<rucksacks.size()){
        string bag1 = rucksacks[i];
        string bag2 = rucksacks[i + 1];
        string bag3 = rucksacks[i + 2];
        unordered_set<char> sbag1;
        set<char> elements;
        for(char e: bag1){
            if ((find(bag2.begin(), bag2.end(), e) != bag2.end()) && (find(bag3.begin(), bag3.end(), e) != bag3.end())){ 
                //cout<<e<<endl;
                sum += getPriority(e);
                break;
            }
        }
        i += 3;
    }
    cout<<"Second questions answer is: "<<sum<<endl;
}

void fstQuestion(){
    string elem;
    ifstream file("./input.txt");
    ll sum=0;
    while (getline(file, elem)) {
        unordered_set<char> fstHalf;
        char included;

        ll m = elem.size() / 2;
        for(int i=0; i<m; i++){
            fstHalf.insert(elem[i]);
        }
        ll mitad = elem.size() - m;
        for(int i=mitad; i<elem.size(); i++){
            if( fstHalf.count(elem[i]) == 1 ){
                included = elem[i];
                break;
            }
        }
        sum += getPriority(included);
    }
    cout<<"First questions answer is: "<<sum<<endl;
}

int main(){
    fstQuestion();
    sndQuestion();
    return 0;
}