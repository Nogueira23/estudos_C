#include <stdio.h>
#include <cs50.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);


int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    int coins = 0;

    while (cents != 0)
    {
        // Calculate the number of pennies to give the customer
        int quarters = 0;
        int dimes = 0;
        int nickels = 0;
        int pennies = 0;

        if (cents >= 25)
        {
            quarters = calculate_quarters(cents);
            cents = cents - quarters * 25;
            coins += quarters;
        }
        else if (cents >= 10)
        {
            dimes = calculate_dimes(cents);
            cents = cents - dimes * 10;
            coins += dimes;
        }
        else if (cents >= 5)
        {
            nickels = calculate_nickels(cents);
            cents = cents - nickels * 5;
            coins += nickels;
        }
        else if (cents >= 1)
        {
            pennies = calculate_pennies(cents);
            cents = cents - pennies * 1;
            coins += pennies;

        }
        // Sum coins
        //int coins = quarters + dimes + nickels + pennies;
    }
    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents()
{
    int cents = get_int("cents: ");
    while (cents < 0)
    {
        cents = get_int("cents: ");
    }
    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 25;
    int number = 0;
    while (true)
    {
        number += cents / quarters;
        return number;
    }
}

int calculate_dimes(int cents)
{
    int dimes = 10;
    int number = 0;
    while (true)
    {
        number += cents / dimes;
        return number;
    }
}

int calculate_nickels(int cents)
{
    int nickels = 5;
    int number = 0;
    while (true)
    {
        number += cents / nickels;
        return number;
    }
}

int calculate_pennies(int cents)
{
    int pennies = 1;
    int number = 0;
    while (true)
    {
        number += cents / pennies;
        return number;
    }
}

