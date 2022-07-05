#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_SUPPORTED_CURRENCIES 2

// a structure that contains an abbreviation 
struct Currency
{
    char abbreviation[3];
};

// array of supported currencies    
const struct Currency supported_currencies[NUMBER_OF_SUPPORTED_CURRENCIES] = { {"GBP"}, {"USD"} };

void main_menu();
double get_amount();
struct Currency *get_currencies();
void currency_menu(const struct Currency from, const struct Currency to, const double money);

int main()
{
    main_menu();
    return 0;
}

// prompts options for the user to select
void main_menu()
{
    int choice;

    printf("\nWelcome to the Currency Converter\n");
    printf("----------------------------\n");
    printf("1) Convert Currency\n");
    printf("2) Quit\n");
    printf("----------------------------\n");
    printf("Please select an option from above\n");

    scanf("%d", &choice);

    struct Currency *currencies = get_currencies();
    struct Currency from = currencies[0];
    struct Currency to = currencies[1];
    double amount = get_amount();

    if (choice == 1)
        currency_menu(from, to, amount);

    free(currencies);
}

// gets the amount of money to convert
double get_amount()
{
    double amount;
    
    printf("Amount of money to convert [3.10, 5 etc]: ");
    scanf("%lf", &amount);

    return amount;
}

// gets the abbreviations of the currencies wanted to convert from and to
struct Currency *get_currencies()
{
    struct Currency *currencies = (struct Currency*)calloc(2, sizeof(struct Currency));

    printf("Currency to convert from [USD, GBP etc]: ");
    scanf("%99s", currencies[0].abbreviation);

    printf("Currency to convert to [USD, GBP etc]: ");
    scanf("%99s", currencies[1].abbreviation);

    return currencies;
}

// shows the converted amount of money in the currency wanted to convert to
void currency_menu(struct Currency from, struct Currency to, double amount)
{   
    printf("\nCurrency Menu\n");
    printf("----------------------------\n");
    printf("Money: %g\n", amount);
    printf("From: %s\n", from.abbreviation);
    printf("To: %s\n", to.abbreviation);
    printf("----------------------------\n");
}