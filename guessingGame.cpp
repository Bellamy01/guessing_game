/* Write a c++ program that has the functionality of a guessing game*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

int main(){
    fstream file;
    bool keepPlaying = true;
    while(keepPlaying){

    cout <<endl<< "\t\t\tGUESSING GAME"<<endl<<endl;
        int category;
        cout << "\t\tCategory" << endl;
        cout << "1. Animals" << endl
             << "2. Teams" << endl
             << "3. Districts" << endl
             << "4. Films" << endl
             << "5. Books" << endl;
    cat:
        cout <<endl<< "Please select a category: ";
        cin >> category;

        switch (category)
        {
        case 1:
            file.open("category/animals.txt", ios::in);
            break;
        case 2:
            file.open("category/teams.txt", ios::in);
            break;
        case 3:
            file.open("category/districts.txt", ios::in);
            break;
        case 4:
            file.open("category/films.txt",ios::in);
            break;
        case 5:
            file.open("category/books.txt", ios::in);
            break;
        default:
            if (category == 0)
            {   
                end:
                cout << endl
                     << "Terminating program..." << endl;
                return 0;
            }
            cout << "Please select a valid number!!" << endl;
            goto cat;
            break;
        }
        if (!file)
        {
            cout << endl<<"Category not found!" << endl;
            goto end;
        }
        int choice;
        bool valid = false;

        while (!valid)
        {   
            int max = 50;
            if(category == 3){
                max = 30;
            }
            srand(time(0));
            choice = (rand() % max) + 1;
            valid = true;
        }
        string word;
        bool atWord = false;
        int wordNum = 1;

        while (!atWord)
        {
            file >> word;
            if (wordNum == choice)
            {
                atWord = true;
            }
            wordNum++;
        }
        string blanks = word;
        for (char &c : blanks)
        {
            c = '_';
        }
        int guesses = word.length();  
        bool gameOver = false;
        while (!gameOver)
        {
            cout << "The word is " << blanks << endl;
            if (guesses == 1)
            {

                cout <<endl<< "Watch out!"<<endl<<"You have " << guesses << " guess left." << endl;
            }
            else
            {
                cout <<endl<< "You have " << guesses << " guesses left." << endl;
            }
            cout << endl<< "Please enter a letter to guess: ";
            char letter;
            cin >> letter;

            bool match = false;
            int i = 0;
            for (char c : word)
            {
                if (letter == c)
                {
                    blanks[i] = letter;
                    match = true;
                }
                i++;
            }
            if (!match)
            {
                cout <<endl<< "Sorry, the word does not contain the letter '" << letter << "'" << endl;
                guesses--;
            }
            if (blanks == word)
            {
                gameOver = true;
                cout << endl<<"Congratulations! You are such a great game player" << endl;
                cout <<endl<< "The word is '" << word <<"'"<< endl;
            }
            if (guesses == 0)
            {
                gameOver = true;
                cout << endl<<"You have run out of guesses. I am sure you will win next time" << endl;
                cout <<endl<<"The word is '" << word <<"'"<< endl;
            }
            if(gameOver == true){
                file.close();
            }
        }
        cout << endl<<"Would you like to continue playing? (y/n): ";
        char playagain;
        cin >> playagain;
        if(playagain == 'n'){
            keepPlaying = false;
            cout << endl<<"Farewell , kind spirit." << endl<< endl<<"\t\tThank you for playing." << endl;
        }else if(playagain == 'y'){
            keepPlaying = true;
        }else{
            cout << endl<< "Please enter a valid input(y/n): " << endl;
            cin >> playagain;
        }
    }
}