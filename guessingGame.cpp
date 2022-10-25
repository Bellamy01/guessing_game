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
    bool atWord = false;
    int  wordNum= 0;

    while(!atWord){
        file >> word;
        if(wordNum == choice){
            atWord = true;
        }
        wordNum++;
    }
}