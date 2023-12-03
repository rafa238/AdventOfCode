#include <bits/stdc++.h>

using namespace std;

void firstPart(){
    ifstream file("./input.txt");
    string line;
    int sum = 0;
    while(getline(file, line)){
        vector<int> nums;
        for(int i = 0; i < line.size(); i++){
            if((int)'0' <= line[i] && line[i] <= (int)'9' ){
                if(nums.size() == 2){
                    nums.pop_back();
                }
                nums.push_back(line[i] - '0');
            }
        }
        if(nums.size() == 1){
            sum += nums[0]*10 + nums[0];
        } else {
            sum += nums[0]*10 + nums[1];
        }
    }

    cout << sum << "\n";
}

void firstPart(vector<string> lines){
    int sum = 0;
    for(string line : lines){
        vector<int> nums;
        for(int i = 0; i < line.size(); i++){
            if((int)'0' <= line[i] && line[i] <= (int)'9' ){
                if(nums.size() == 2){
                    nums.pop_back();
                }
                nums.push_back(line[i] - '0');
            }
        }
        if(nums.size() == 1){
            sum += nums[0]*10 + nums[0];
        } else {
            sum += nums[0]*10 + nums[1];
        }
    }

    cout << sum << "\n";
}

void sndPart(){
    unordered_map<string, char> digits = {
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'}
    };
    ifstream file("./input.txt");
    string line;
    vector<string> newLines;
    while(getline(file, line)){
        string newLine = "";
        for(int i = 0; i < line.size(); i++){
            if((int)'0' <= line[i] && line[i] <= (int)'9' ){
                newLine.push_back(line[i]);
                continue;
            }
            string subs = "";
            for(int j = i; j < line.size(); j++){
                subs += line[j];
                if(digits.count(subs) != 0){
                    newLine.push_back(digits[subs]);
                    break;
                }
            }
        }
        newLines.push_back(newLine);
    }

    for(auto s : newLines){
        cout << s << "\n";
    }
    firstPart(newLines);
}

int main(){
    firstPart();
    sndPart();
    return 0;
}