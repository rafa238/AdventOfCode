#include <bits/stdc++.h>

using namespace std;

vector< pair<string, int> > cards;
map<char, int> alphabet = {
    {'A',14},
    {'K',13}, 
    {'Q', 12},
    {'J', 11},
    {'T',10}
};

int get_character_val(char c){
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
        int space_pos = 0;
        for(char c : line){
            if(c == ' ')
                break;
            card += c;
            space_pos++;
        }
        for(int i = space_pos+1; i<line.size(); i++){
            bid += line[i];
        }
        cards.push_back({card, stoi(bid)});
    }
}

int calculate_strength(string card){
    map<char, int> freq;
    for(char c : card){
        freq[c]++;
    }
    vector<int> freq_values;
    for(pair<char, int> p : freq){
        freq_values.push_back(p.second);
    }
    sort(freq_values.begin(), freq_values.end());
    if(freq_values == vector<int>{5}){
        return 10;
    } else if(freq_values == vector<int>{1, 4}){
        return 9;
    } else if(freq_values == vector<int>{2, 3}){
        return 8;
    }else if(freq_values == vector<int>{1, 1, 3}){
        return 7;
    }else if(freq_values == vector<int>{1, 2, 2}){
        return 6;
    }else if(freq_values == vector<int>{1, 1, 1, 2}){
        return 5;
    }else if(freq_values == vector<int>{1,1,1,1,1}){
        return 4;
    } else {
        for(auto elem : freq_values){
            cout << elem << " ";
        }
        throw new logic_error("no se pudo");
    }

}


int decide_winner(string card1, string card2){
    int strenght1 = calculate_strength(card1), strenght2 = calculate_strength(card2);
    //cout<<strenght1<< " "<<strenght2<< " ";
    if(strenght1 == strenght2){
        for(int i = 0; i<5; i++){
            int val1 = get_character_val(card1[i]), val2 = get_character_val(card2[i]);
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

void firstPart(){
    get_input();
    sort_cards();
    int factor = 1, sum = 0;
    for(auto elem : cards){
        sum += elem.second * factor++;
    }
    cout << sum;
}

int main(){
    
    return 0;
}