#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector< pair<string, ll> > cards;
map<char, ll> alphabet = {
    {'A',14},
    {'K',13}, 
    {'Q', 12},
    //now J is the weakest card
    {'J', 1},
    {'T',10}
};

ll get_character_val(char c){
    if(alphabet.count(c) == 0){
        return (int)(c - '0');
    }
    return alphabet[c];
}

void get_input(){
    ifstream file("input.txt");
    string line;

    while(getline(file, line)){
        string card = "", bid = "";
        ll space_pos = 0;
        for(char c : line){
            if(c == ' ')
                break;
            card += c;
            space_pos++;
        }
        for(int i = space_pos+1; i<line.size(); i++){
            bid += line[i];
        }
        cards.push_back({card, stoll(bid)});
    }
}

ll calculate_strength(string card){
    map<char, ll> freq;
    //keep a counter of jokers
    ll jokers = 0;
    for(char c : card){
        if(c == 'J'){
            jokers++;
            continue;
        }
        freq[c]++;
    }
    vector<ll> freq_values;
    for(pair<char, ll> p : freq){
        freq_values.push_back(p.second);
    }
    sort(freq_values.begin(), freq_values.end());

    //lets add jokers in the greatest freq
    if(freq_values.size() == 0){
        freq_values.push_back(5);
    } else {
        freq_values[freq_values.size()-1] += jokers;
    }

    if(freq_values == vector<ll>{5}){
        return 10;
    } else if(freq_values == vector<ll>{1, 4}){
        return 9;
    } else if(freq_values == vector<ll>{2, 3}){
        return 8;
    }else if(freq_values == vector<ll>{1, 1, 3}){
        return 7;
    }else if(freq_values == vector<ll>{1, 2, 2}){
        return 6;
    }else if(freq_values == vector<ll>{1, 1, 1, 2}){
        return 5;
    }else if(freq_values == vector<ll>{1,1,1,1,1}){
        return 4;
    }
}


ll decide_winner(string card1, string card2){
    ll strenght1 = calculate_strength(card1), strenght2 = calculate_strength(card2);
    //cout<<strenght1<< " "<<strenght2<< " ";
    if(strenght1 == strenght2){
        for(ll i = 0; i<5; i++){
            ll val1 = get_character_val(card1[i]), val2 = get_character_val(card2[i]);
            if(val1 == val2) continue;
            if( val1 > val2){
                strenght1++;
                break;
            } else {
                strenght2++;
            }
        }
    }
    return strenght1 > strenght2;
}

void sort_cards(){
    for(int i = 0; i<cards.size(); i++){
        for(int j = 0; j<cards.size()-1; j++){
            bool winner = decide_winner(cards[j].first, cards[j+1].first);
            //cout<<"\n";
            if(winner){
                swap(cards[j], cards[j+1]);
            }
        }
    }
}


int main(){
    get_input();
    sort_cards();
    ll factor = 1, sum = 0;
    for(auto elem : cards){
        sum += elem.second * factor++;
    }
    cout << sum;
    return 0;
}