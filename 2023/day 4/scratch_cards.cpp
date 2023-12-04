#include <bits/stdc++.h>

using namespace std;

//made by Rafael JL

vector<string> split(string s){
    string number="";
    vector<string> numbers;
    for(char c : s){
        if(c == ' '){
            if(number == "") continue;
            numbers.push_back(number);
            number = "";
            continue;
        }
        number += c;
    }
    numbers.push_back(number);
    return numbers;
}

void firstPart(){
    string line;
    ifstream file("input.txt");
    int sum = 0;
    while(getline(file, line)){
        string winning = "", myNumbers = "";
        int cardPoints = 0;
        bool happened = false;

        for(int i = 8; i<line.size(); i++){
            if(line[i] == '|') {
                happened = !happened;
                continue;
            }
            if(happened){
                myNumbers += line[i];
            } else {
                winning += line[i];
            }
        }
        vector<string> winningNumbers = split(winning);
        vector<string> cardNumbers = split(myNumbers);
        unordered_set<string> matches;
        for(string number : winningNumbers){
            matches.insert(number);
        }

        for(string number : cardNumbers){
            if(matches.count(number) != 0){
                cardPoints++;
            }
        }
        sum += pow(2, cardPoints-1);
    }
    cout << sum <<"\n";
}

void sndPart(){
    string line;
    ifstream file("input.txt");
    vector<int> cardWinnings;
    while(getline(file, line)){
        string winning = "", myNumbers = "";
        int cardPoints = 0;
        bool happened = false;

        for(int i = 8; i<line.size(); i++){
            if(line[i] == '|') {
                happened = !happened;
                continue;
            }
            if(happened){
                myNumbers += line[i];
            } else {
                winning += line[i];
            }
        }
        vector<string> winningNumbers = split(winning);
        vector<string> cardNumbers = split(myNumbers);
        unordered_set<string> matches;
        for(string number : winningNumbers){
            matches.insert(number);
        }

        for(string number : cardNumbers){
            if(matches.count(number) != 0){
                cardPoints++;
            }
        }
        cardWinnings.push_back(cardPoints);
    }
    vector<int> totalCopies(cardWinnings.size(), 1);
    for(int i = 0; i<cardWinnings.size(); i++){
        for(int j = i+1; j < min(i+1+cardWinnings[i], (int)cardWinnings.size()); j++){
            totalCopies[j] += totalCopies[i];
        }
    }
    int sum = 0;
    for(auto copies : totalCopies){
        sum += copies;
    }
    cout << sum << "\n";
}

int main(){
    firstPart();
    sndPart();
    return 0;
}