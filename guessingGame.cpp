/* Write a c++ program that has the functionality of a guessing game*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

int main(){
    fstream file;
    file.open("words.txt", ios::in);
    cout << "Please enter a word to play:";
    int choice;
    bool valid = false;
    
    while(!valid){
        cin >> choice;
        if(choice >=0 && choice <= 20){
            valid = true;
        }else{
            cout << "Error. Please enter a number between 0  and 20: ";
        }
    }
    if (choice == 0){
        choice = rand() % 20+1;
    }
    string word;
    bool atWord = false;
    int  wordNum= 1;

    while(!atWord){
        file >> word;
        if(wordNum == choice){
            atWord = true;
        }
        wordNum++;
    }
    string blanks = word;
    for(char & c : blanks)
    cout << word;
}