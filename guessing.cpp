#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
    fstream file;
    string word;
    int category;
    cout << "Category"<<endl;
    cout << "1. Animals"<<endl<< "2. Teams"<<endl << "3. Districts"<<endl<<"4. Films"<<endl<<"5. Books"<<endl;
    cat:
    cout << "Please select a category: ";
    cin >> category;
    if(category == 1){
        file.open("category/animals.txt", ios::in);
    }else if (category == 2){
        file.open("category/teams.txt", ios::in);
    }else if (category == 3){
        file.open("category/districts.txt", ios::in);
    }else if(category == 4){
        file.open("./category/films.txt", ios::in);
    }else if(category == 5){
        file.open("./category/books.txt", ios::in);
    }else{
        cout << "Please select a valid number"<<endl;
        goto cat;
    }

    while(!file.eof()){
        file >> word;
        cout << word << endl;
    }
    return 0;
}
