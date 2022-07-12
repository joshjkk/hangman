#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include "words.h"

std::string get_random_word()
{
    int rand_i = rand() % all_words.size();
    return all_words[rand_i];
}

class Word 
{
    private:
        std::string _hidden_word;

    public:
        std::string word = get_random_word();
        int guesses_left = 5;

        Word()
        {
            for (char c : word)
                _hidden_word.append("_");
            
            print_hidden_word();
            std::cout << "Guess a letter to start!" << std::endl;
        }

        void print_hidden_word()
        {
            std::cout << "\n" << _hidden_word << std::endl;
        }

        void guess(char guess_c)
        {
            int correct_guess = 0;

            for (size_t i = 0; i < word.length(); i++)
            {
                if (word[i] == guess_c && _hidden_word[i] != guess_c)
                {
                    _hidden_word[i] = guess_c;
                    correct_guess++;
                }
            }

            if (correct_guess == 0)
                guesses_left--;

            hanged_man(guesses_left);
            print_hidden_word();
            check_win();
        }

        void check_win()
        {
            for (size_t i = 0; i < _hidden_word.length(); i++)
            {
                if (_hidden_word[i] == '_')
                    return;
            }

            std::cout << "Well done!\nYou won with " << guesses_left + 1 << " guesses left!" << std::endl;
            exit(0);
        }

        void lose()
        {
            std::cout << "You lose!\nThe word was " << word << "!" << std::endl;
            exit(0);
        }

        void hanged_man(int guesses_remaining)
        {
            std::cout << "\n";

            if (guesses_remaining == 5)
            {
                std::cout << "----\n" <<
                              "|   |\n" <<
                              "|\n" <<    
                              "|\n" <<
                              "|\n" <<
                              "--------" << std::endl;
            }
            
            else if (guesses_remaining == 4)
            {
                std::cout << "----\n" <<
                              "|   |\n" <<
                              "|   O\n" <<    
                              "|\n" <<
                              "|\n" <<
                              "--------" << std::endl;
            }

            else if (guesses_remaining == 3)
            {
                std::cout << "----\n" <<
                              "|   |\n" <<
                              "|   O\n" <<    
                              "|   |\n" <<
                              "|\n" <<
                              "--------" << std::endl;
            }

            else if (guesses_remaining == 2)
            {
                std::cout << "----\n" <<
                              "|   |\n" <<
                              "|   O\n" <<    
                              "|   |\\ \n" <<
                              "|\n" <<
                              "--------" << std::endl;
            }

            else if (guesses_remaining == 1)
            {
                std::cout << "----\n" <<
                              "|   |\n" <<
                              "|   O\n" <<    
                              "|  /|\\ \n" <<
                              "|\n" <<
                              "--------" << std::endl;
            }

            else if (guesses_remaining == 0)
            {
                std::cout << "----\n" <<
                              "|   |\n" <<
                              "|   O\n" <<    
                              "|  /|\\ \n" <<
                              "|  /\n" <<
                              "--------" << std::endl;
            }

            else
            {
                std::cout << "----\n" <<
                              "|   |\n" <<
                              "|   O\n" <<    
                              "|  /|\\ \n" <<
                              "|  / \\ \n" <<
                              "--------" << std::endl;

                lose();
            }
        }
};

int main()
{
    srand(time(0));

    Word word;

    while (true)
    {
        char guess;
        std::cin >> guess;
        word.guess(toupper(guess));
    }

    return 0;
}
