#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include "words.h"

#define WORDS_FILE "words.txt"

std::string get_random_word()
{
    int rand_i = rand() % all_words.size();
    return all_words[rand_i];
}

class Word 
{
    private:
        std::string hidden_word;

    public:
        std::string word = get_random_word();

        Word()
        {
            for (char c : word)
                hidden_word.append("_");
            
            print_hidden_word();
            std::cout << "Guess a letter to start!" << std::endl;
        }

        void print_hidden_word()
        {
            std::cout << hidden_word << std::endl;
        }

        void guess(char guess_c)
        {
            for (size_t i = 0; i < word.length(); i++)
            {
                if (word[i] == guess_c && hidden_word[i] != guess_c)
                    hidden_word[i] = guess_c;
            }

            print_hidden_word();
            check_win();
        }

        void check_win()
        {
            for (size_t i = 0; i < hidden_word.length(); i++)
            {
                if (hidden_word[i] == '_')
                    return;
            }

            std::cout << "Well done, you won!" << std::endl;
            exit(0);
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
