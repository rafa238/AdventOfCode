#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll match(char a, char b){
    //X A Rock
    //Y B Paper
    //Z C Scissors
    unordered_map<char, int> movementsValues = {
        {'X' , 1},
        {'Y' , 2},
        {'Z' , 3} 
    };

    const int LOST = 0, WIN = 6, DRAW = 3;
    int matchScore;
    if(a == 'A'){
        if(b == 'Y') matchScore = WIN; //lose
        else if(b == 'Z')  matchScore = LOST; //win
        else matchScore = DRAW;//draw
    } else if(a == 'B'){
        if(b == 'Z') matchScore = WIN; //lose
        else if(b == 'X') matchScore = LOST; //win
        else matchScore = DRAW;//draw
    } else if(a == 'C'){
        if(b == 'X') matchScore = WIN; //lose
        else if(b == 'Y') matchScore = LOST; //win
        else matchScore = DRAW;//draw
    }

    return (matchScore + movementsValues[b]);
}

void sndQuestion(){
    string elem;
    ifstream file("./input.txt");
    ll score = 0;
    while (getline(file, elem)) {
        char myPlay;
        if(elem[2] == 'X'){
            if(elem[0] == 'A'){
                myPlay = 'Z';
            } else if(elem[0] == 'B'){
                myPlay = 'X';
            } else if(elem[0] == 'C'){
                myPlay = 'Y';
            }
        } else if(elem[2] == 'Y'){
            if(elem[0] == 'A'){
                myPlay = 'X';
            } else if(elem[0] == 'B'){
                myPlay = 'Y';
            } else if(elem[0] == 'C'){
                myPlay = 'Z';
            }
        } else {
            if(elem[0] == 'A'){
                myPlay = 'Y';
            } else if(elem[0] == 'B'){
                myPlay = 'Z';
            } else if(elem[0] == 'C'){
                myPlay = 'X';
            }
        }
        score += match(elem[0], myPlay);
    }
    cout<<score<<endl;
}

void fstQuestion(){
    string elem;
    ifstream file("./input.txt");
    ll score = 0;
    while (getline(file, elem)) {
        score += match(elem[0], elem[2]);
    }
    cout<<score<<endl;
}

int main(){
    fstQuestion();
    sndQuestion();
    return 0;
}