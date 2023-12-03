#include <bits/stdc++.h>

using namespace std;

//made by Rafael JL

void fstPart(){
    ifstream file("./input.txt");
    string line;
    vector<string> matrix;
    while(getline(file, line)){
        matrix.push_back(line);
    }
    int sum = 0;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if('0' > matrix[i][j]  || matrix[i][j] > '9')
                continue;
            
            string num = "";
            int z = j;
            while('0' <= matrix[i][z]  && matrix[i][z] <= '9'){
                num += matrix[i][z];
                z++;
            }
            bool ans = false;

            //upper bound
            if(i-1 >= 0){
                //left corner
                if(j-1 >= 0){
                    if(matrix[i-1][j-1] != '.')
                        ans = true;
                    //cout << matrix[i-1][j-1] << " ";
                    //left side
                    if(matrix[i][j-1] != '.')
                        ans = true;
                }

                for(int b = j; b < z; b++){
                    if(matrix[i-1][b] != '.')
                        ans = true;
                    //cout << matrix[i-1][b] << " ";
                }
                
                //right corner
                if(z < matrix[j].size()){
                    if(matrix[i-1][z] != '.')
                        ans = true;
                    //cout << matrix[i-1][z] << " ";
                    //right side
                    if(matrix[i][z] != '.')
                        ans = true;
                }
            }
            //cout << num ;
            //lower bound
            if(i+1 < matrix.size()){
                
                //left corner
                if(j-1 >= 0){
                    if(matrix[i+1][j-1] != '.')
                        ans = true;
                    //cout << matrix[i+1][j-1] << " ";
                }

                for(int b = j; b < z; b++){
                    if(matrix[i+1][b] != '.')
                        ans = true;
                    //cout << matrix[i+1][b] << " ";
                }

                //right corner
                if(z < matrix[j].size()){
                    if(matrix[i+1][z] != '.')
                        ans = true;
                    //cout << matrix[i+1][z] << " ";
                }
            }
            if(ans){
                sum += stoi(num);
            }
            j = z;
            //cout << endl;
        }
    }
    cout << sum << "\n";
}

int checkGear(map<pair<int, int>, string> &gears, string num, int x, int y){
    pair<int, int> coords = make_pair(x, y);
    if(gears.count(coords) != 0){
        return stoi(num) * stoi(gears[coords]);
    } else {
        gears[coords] = num;
    }
    return 0;
}

void sndPart(){
    ifstream file("./input.txt");
    string line;
    vector<string> matrix;
    map<pair<int, int>, string> gearsUsed;
    while(getline(file, line)){
        matrix.push_back(line);
    }
    int sum = 0;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if('0' > matrix[i][j]  || matrix[i][j] > '9')
                continue;
            
            string num = "";
            int z = j;
            while('0' <= matrix[i][z]  && matrix[i][z] <= '9'){
                num += matrix[i][z];
                z++;
            }
            int size = z - j;
            bool ans = false;

            //upper bound
            if(i-1 >= 0){
                //left corner
                if(j-1 >= 0){
                    if(matrix[i-1][j-1] == '*'){
                        int checked = checkGear(gearsUsed, num, i-1, j-1);
                        sum += checked;
                    }
                    //cout << matrix[i-1][j-1] << " ";
                    //left side
                    if(matrix[i][j-1] == '*'){
                        int checked = checkGear(gearsUsed, num, i, j-1);
                        sum += checked;
                    }
                }

                for(int b = j; b < z; b++){
                    if(matrix[i-1][b] == '*'){
                        int checked = checkGear(gearsUsed, num, i-1, b);
                        sum += checked;
                    }
                    //cout << matrix[i-1][b] << " ";
                }
                
                //right corner
                if(z < matrix[j].size()){
                    if(matrix[i-1][z] == '*'){
                        int checked = checkGear(gearsUsed, num, i-1, z);
                        sum += checked;
                    }
                    //cout << matrix[i-1][z] << " ";
                    //right side
                    if(matrix[i][z] == '*'){
                        int checked = checkGear(gearsUsed, num, i, z);
                        sum += checked;
                    }
                }
            }
            //cout << num ;
            //lower bound
            if(i+1 < matrix.size()){
                
                //left corner
                if(j-1 >= 0){
                    if(matrix[i+1][j-1] == '*'){
                        int checked = checkGear(gearsUsed, num, i+1, j-1);
                        sum += checked;
                    }
                    //cout << matrix[i+1][j-1] << " ";
                }

                for(int b = j; b < z; b++){
                    if(matrix[i+1][b] == '*'){
                        int checked = checkGear(gearsUsed, num, i+1, b);
                        sum += checked;
                    }
                    //cout << matrix[i+1][b] << " ";
                }

                //right corner
                if(z < matrix[j].size()){
                    if(matrix[i+1][z] == '*'){
                        int checked = checkGear(gearsUsed, num, i+1, z);
                        sum += checked;
                    }
                    //cout << matrix[i+1][z] << " ";
                }
            }
            if(ans){
                sum += stoi(num);
            }
            j = z;
            //cout << endl;
        }
    }

    cout << sum << "\n";
}

int main(){
    fstPart();
    sndPart();
    return 0;
}