#include <bits/stdc++.h>

//made by Rafael JL

using namespace std;

vector<string> divideSets(string line){
    vector<string> sets;
    string currSet = "";
    for(int i = 0; i<line.size(); i++){
        if(line[i] == ':' || line[i] == ';'){
            sets.push_back(currSet);
            currSet = "";
        } else {
            currSet += line[i];
        }
    }
    sets.push_back(currSet);
    return sets;
}

vector<string> divideCubes(string set){
    vector<string> cubes;
    string currCubes = "";
    for(int i = 0; i<set.size(); i++){
        if(set[i] == ','){
            cubes.push_back(currCubes);
            currCubes = "";
        } else {
            currCubes += set[i];
        }
        
    }
    cubes.push_back(currCubes);
    return cubes;
}

pair<int, string> divideCube(string cube){
    string strnum = "";
    int num, last_position;
    for(int i = 1; i < cube.size(); i++){
        if(cube[i] == ' '){
            num = stoi(strnum);
            //avoid blank space
            last_position = i + 1;
            break;
        }
        strnum += cube[i];
    }
    return {num, cube.substr(last_position, cube.size()-1)};
}

void firstPart(){
    unordered_map<string, int> colors = {
            {"red", 12},
            {"green", 13},
            {"blue",14}
        };
    ifstream file("./input.txt");
    string line;
    int gameNumber = 1, ans = 0;
    while(getline(file, line)){
        bool valid = true;
        vector<string> sets = divideSets(line);    
        for(int j = 1; j<sets.size(); j++){
            vector<string> cubes = divideCubes(sets[j]);
            for(int i = 0; i<cubes.size(); i++){
                auto data = divideCube(cubes[i]);
                if(colors[data.second] < data.first){
                    valid = false;
                }
            }
        }
        if(valid){
            ans += gameNumber;
        }
        gameNumber++;
    }
    cout << ans << "\n";
}

void sndPart(){
    ifstream file("./input.txt");
    string line;
    int gameNumber = 1, ans = 0;
    while(getline(file, line)){
        bool valid = true;
        vector<string> sets = divideSets(line);
        int blues = 0, reds = 0, greens = 0;
        for(int j = 1; j<sets.size(); j++){
            vector<string> cubes = divideCubes(sets[j]);
            for(int i = 0; i<cubes.size(); i++){
                auto data = divideCube(cubes[i]);
                if(data.second == "blue"){
                    blues = max(blues, data.first);
                } else if(data.second == "green"){
                    greens = max(greens, data.first);
                } else if(data.second == "red"){
                    reds = max(reds, data.first);
                }
            }
        }
        ans += blues * greens * reds;
    }
    cout << ans << "\n";
}

int main(){
    firstPart();
    sndPart();
    return 0;
}