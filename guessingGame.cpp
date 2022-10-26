/* Write a c++ program that has the functionality of a guessing game*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

int main(){
    fstream file;
    char play = 'n';
    file.open("words.txt", ios::in);
    start:
    cout << "GUESSING GAME"<<endl<<endl;
    fstream file;
    string word;
    int category;
    cout << "Category" << endl;
    cout << "1. Animals" << endl
         << "2. Teams" << endl
         << "3. Districts" << endl
         << "4. Films" << endl
         << "5. Books" << endl;
    cat:
        cout << "Please select a category: ";
        cin >> category;
        if (category == 1)
        {
            file.open("category/animals.txt", ios::in);
        }
        else if (category == 2)
        {
            file.open("category/teams.txt", ios::in);
        }
        else if (category == 3)
        {
            file.open("category/districts.txt", ios::in);
        }
        else if (category == 4)
        {
            file.open("./category/films.txt", ios::in);
        }
        else if (category == 5)
        {
            file.open("./category/books.txt", ios::in);
        }
        else
        {
            cout << "Please select a valid number" << endl;
            goto cat;
        }
        srand(time(0));
        random_number = (rand())
        cout
                        << "Please enter a word to play(0 for random): ";
        int choice;
        bool valid = false;

        while (!valid)
        {
            cin >> choice;
            if (choice >= 0 && choice <= 20)
            {
                valid = true;
            }
            else
            {
                cout << "Error. Please enter a number between 0  and 20: ";
            }
        }
        if (choice == 0)
        {
            choice = rand() % 20 + 1;
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
        int guesses = 3;
        bool gameOver = false;
        while (!gameOver)
        {
            cout << "The word is " << blanks << endl;
            if (guesses == 1)
            {
                cout << "You have " << guesses << " guess left." << endl;
            }
            else
            {
                cout << "You have " << guesses << " guesses left." << endl;
            }
            cout << "Please enter a letter to guess: ";
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
                cout << "Sorry, the word does not contain the letter '" << letter << "'" << endl;
                guesses--;
            }
            if (blanks == word)
            {
                gameOver = true;
                cout << "Congratulations! You are such a great game player" << endl;
                cout << "The word is " << word << endl;
            }
            if (guesses == 0)
            {
                gameOver = true;
                cout << "You are out of guesses. I am sure you will win next time" << endl;
                cout << "The word is " << word << endl;
            }
        }
        cout << "Would you like to continue playing? (y/n): ";
        cin >> play;
        if (play == 'y')
        {
            goto start;
        }
        else
        {
            cout << endl
                 << "Thanks for playing!" << endl;
        }
}