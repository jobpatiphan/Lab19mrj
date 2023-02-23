#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector<string> &names, vector<int> &scores, vector<char> &grades){
    ifstream inp("name_score.txt");
    string textline;
    char name[100];
    int a;
    int b;
    int c;
    char grade[1];
    int score;
    while(getline(inp,textline)){
        sscanf(textline.c_str(),"%[^:]: %d %d %d",name,&a,&b,&c);
        score = a+b+c;
        grade[0] = score2grade(score);
        names.push_back(name);
        scores.push_back(score);
        grades.push_back(grade[0]);
    }




}

void getCommand(string &command, string &key){
    cout << "Please input your command: ";
    getline(cin,command);
    int i = command.find_first_of(" ");
    key = command.substr(i+1);
    command = command.substr(0,i);
    

}

void searchName(vector<string> names, vector<int> scores, vector<char> grades, string key){
    cout << "---------------------------------\n";
    int sum = 0;
    while(true){
        for(unsigned i = 0; i < names.size();i++){
            if(key == toUpperStr(names[i])){
                cout << names[i] << "'s score = " << scores[i] << endl;
                cout << names[i] << "'s grade = " << grades[i] << endl;
                sum++;
                
            }
            else if(i == names.size()-1){
                break;
            }
        }
        if(sum == 0){
            cout << "Cannot found.\n";
        }
     
        break;
    }
    cout << "---------------------------------\n";
    

}

void searchGrade(vector<string> names, vector<int> scores, vector<char> grades, string key){
    cout << "---------------------------------\n";
    int sum = 0;
    while(true){
        for(unsigned i = 0; i < grades.size();i++){
            if(key[0] == grades[i]){
                cout << names[i] << " (" << scores[i] << ")\n";
                sum++;
            }
            else if(i == grades.size()-1){
                
                break;
            }
        }
        if(sum == 0){
            cout << "Cannot found.\n";
        }
        break;
    }
    cout << "---------------------------------\n";
    



}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
