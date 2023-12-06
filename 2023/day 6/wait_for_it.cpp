#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
vector<int> distances, times;
ll distance_join, time_join;

void get_input(){
    ifstream file("input.txt");
    string line;

    getline(file, line);
    istringstream iss(line);
    
    iss >> line;
    while(iss >> line){
        times.push_back(stoi(line));
    }

    getline(file, line);
    istringstream iss2(line);
    iss2 >> line;
    while(iss2 >> line){
        distances.push_back(stoi(line));
    }
}

void get_input2(){
    ifstream file("input.txt");
    string line;

    getline(file, line);
    istringstream iss(line);
    
    iss >> line;
    string total_num = "";
    while(iss >> line){
        total_num += line;
    }
    time_join = stoll(total_num);

    getline(file, line);
    istringstream iss2(line);
    iss2 >> line;
    total_num = "";
    while(iss2 >> line){
        total_num += line;
    }
    distance_join = stoll(total_num);
}

void firstPart(){
    get_input();
    int ans = 1;
    for(int i = 0; i < times.size(); i++){
        int targetDistance = distances[i];
        int ways_to_reach = 0;
        for(int j = 0; j <= times[i]; j++){
            int distanceTraveled = j * (times[i]-j);
            if(targetDistance < distanceTraveled){
                ways_to_reach++;
            }
        }
        ans *= ways_to_reach;
    }
    cout << ans << "\n";
}

void sndPart(){
    get_input2();
    ll ans = 1;
    ll ways_to_reach = 0;
    for(ll j = 0; j <= time_join; j++){
        ll distanceTraveled = j * (time_join-j);
        if(distance_join < distanceTraveled){
            ways_to_reach++;
        }
    }
    ans *= ways_to_reach;
    cout << ans << "\n";
}

int main(){
    firstPart();
    sndPart();
    return 0;
}