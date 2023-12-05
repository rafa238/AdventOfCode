#include <bits/stdc++.h>

//Made by Rafael JL

using namespace std;
typedef long long ll;

vector<ll> seeds;
vector<vector<ll>>  seed_to_soil, 
                soil_to_fertilizer,
                fertilizer_to_water,
                water_to_light,
                light_to_temperature,
                temperature_to_humidity,
                humidity_to_location;

void get_input(){
    ifstream file("input.txt");
    string seeds_str, line;
    getline(file, seeds_str);
    getline(file, line);

    istringstream str_in(seeds_str);
    ll seed;
    str_in >> line;
    while(str_in >> seed){
        seeds.push_back(seed);
    }

    getline(file, line);
    while(getline(file, line) && line != ""){
        istringstream str_in(line);
        ll n1, n2, n3;
        str_in >> n1 >> n2 >> n3;
        seed_to_soil.push_back({n1, n2, n3});
    }
    
    getline(file, line);
    while(getline(file, line) && line != ""){
        istringstream str_in(line);
        ll n1, n2, n3;
        str_in >> n1 >> n2 >> n3;
        soil_to_fertilizer.push_back({n1, n2, n3});
    }
    
    getline(file, line);
    while(getline(file, line) && line != ""){
        istringstream str_in(line);
        ll n1, n2, n3;
        str_in >> n1 >> n2 >> n3;
        fertilizer_to_water.push_back({n1, n2, n3});
    }
    
    getline(file, line);
    while(getline(file, line) && line != ""){
        istringstream str_in(line);
        ll n1, n2, n3;
        str_in >> n1 >> n2 >> n3;
        water_to_light.push_back({n1, n2, n3});
    }
    
    getline(file, line);
    while(getline(file, line) && line != ""){
        istringstream str_in(line);
        ll n1, n2, n3;
        str_in >> n1 >> n2 >> n3;
        light_to_temperature.push_back({n1, n2, n3});
    }
    
    getline(file, line);
    while(getline(file, line) && line != ""){
        istringstream str_in(line);
        ll n1, n2, n3;
        str_in >> n1 >> n2 >> n3;
        temperature_to_humidity.push_back({n1, n2, n3});
    }
    
    getline(file, line);
    while(getline(file, line) && line != ""){
        istringstream str_in(line);
        ll n1, n2, n3;
        str_in >> n1 >> n2 >> n3;
        humidity_to_location.push_back({n1, n2, n3});
    }
}

//Let's save 3-tuple (range start, range end, differece to reach the target)
vector<vector<ll>> 
                    seed_range,
                    soil_range,
                    fertilizer_range,
                    water_range,
                    light_range,
                    temperature_range,
                    humidity_range;

void make_ranges(){
    for(vector<ll> elem : seed_to_soil){
        seed_range.push_back({elem[1], 
                            elem[1] + elem[2] - 1, 
                            elem[0] - elem[1]});
    }
    for(auto elem : soil_to_fertilizer){
        soil_range.push_back({elem[1], 
                            elem[1] + elem[2] - 1, 
                            elem[0] - elem[1]});
    }
    for(auto elem : fertilizer_to_water){
        fertilizer_range.push_back({elem[1], 
                            elem[1] + elem[2] - 1, 
                            elem[0] - elem[1]});
    }
    for(auto elem : water_to_light){
        water_range.push_back({elem[1], 
                            elem[1] + elem[2] - 1, 
                            elem[0] - elem[1]});
    }
    for(auto elem : light_to_temperature){
        light_range.push_back({elem[1], 
                            elem[1] + elem[2] - 1, 
                            elem[0] - elem[1]});
    }
    for(auto elem : temperature_to_humidity){
        temperature_range.push_back({elem[1], 
                            elem[1] + elem[2] - 1, 
                            elem[0] - elem[1]});
    }
    for(auto elem : humidity_to_location){
        humidity_range.push_back({elem[1], 
                            elem[1] + elem[2] - 1, 
                            elem[0] - elem[1]});
    }
}

ll find_min_location(ll seed){
    //look in seed-soil
    ll newRange = seed;
    for(vector<ll> range : seed_range){
        if(range[0] <= seed && seed <= range[1]){
            newRange += range[2];
            break;
        }
    }
    
    for(vector<ll> range : soil_range){
        if(range[0] <= newRange && newRange <= range[1]){
            newRange += range[2];
            break;
        }
    }
    for(vector<ll> range : fertilizer_range){
        
        //cout <<"looked: "<<newRange<<"\n "<< range[0] << " " << range[1] << " "<<range[2]<<" ";
        if(range[0] <= newRange && newRange <= range[1]){
            //cout << "match";
            newRange += range[2]; 
            break;
        }
    }
    for(vector<ll> range : water_range){
        if(range[0] <= newRange && newRange <= range[1]){
            newRange += range[2];
            break;
        }
    }

    for(vector<ll> range : light_range){
        if(range[0] <= newRange && newRange <= range[1]){
            newRange += range[2];
            break;
        }
    }

    for(vector<ll> range : temperature_range){
        if(range[0] <= newRange && newRange <= range[1]){
            newRange += range[2];
            break;
        }
    }
    
    for(vector<ll> range : humidity_range){
        if(range[0] <= newRange && newRange <= range[1]){
            newRange += range[2];
            break;
        }
    }

    return newRange;
}

void firstPart(){
    get_input();
    make_ranges();
    ll minimum_location = LLONG_MAX;
    for(auto seed : seeds){
        minimum_location = min(find_min_location(seed), minimum_location);
    }
    cout << minimum_location;
}

int main(){
    get_input();
    make_ranges();
    
    return 0;
}