#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_SUPPORTED_CURRENCIES 2

// each currency is a struct
struct Currency
{
    char abbreviation[3];
};

// check if the user tries to convert a supported currency
struct Currency supported_currencies[NUMBER_OF_SUPPORTED_CURRENCIES] = {{"GBP"}, {"USD"}};

// variables for conversion
struct Currency from;
struct Currency to;
double money = 0;
double converted_money = 0;

// main functions

void main_menu();
void currency_menu();
void get_values();
double convert_currencies();

// convert functions

void gbp_to_usd(double money);
void usd_to_gbp(double money);

int main()
{
    main_menu();
    return 0;
}

// hub of the converter
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

    switch (choice)
    {
        case 1:
            get_values();
            currency_menu();
            break;

        case 2:
            exit(0);
    }
}

// get the currency from and to convert to, as well as the amount to convert
void get_values()
{
    printf("Currency to convert from [USD, GBP etc]: ");
    scanf("%99s", &from.abbreviation);

    printf("Currency to convert to [USD, GBP etc]: ");
    scanf("%99s", &to.abbreviation);

    printf("Amount to convert: ");
    scanf("%lf", &money);
}

double convert_currencies()
{
    // not implemented
}   

void currency_menu()
{   
    convert_currencies();
 
    printf("\nCurrency Menu\n");
    printf("----------------------------\n");
    printf("Money: %g\n", money);
    printf("From: %s\n", from.abbreviation);
    printf("To: %s\n", to.abbreviation);
    printf("----------------------------\n");
    printf("Converted Money: %g\n", converted_money);
}