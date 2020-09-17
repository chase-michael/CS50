//
//  main.c
//  Workspace
//
//  Created by Chase Michael on 9/15/20.
//  Copyright © 2020 Chase Michael. All rights reserved.
//

#include "cs50.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void hello(void) {
    printf("--- 'Hello' Assignment ---\nAsks user for name, prints 'hello, *name*'.\n");
    
    string name = get_string("Name? ");
    printf("hello, %s\n", name);
}


void mario() {
    printf("\n--- 'Mario' (difficult version) Assignment ---\nAsks for number of rows, prints special hash pyramid.\n");
    
    int height = get_int("Height: ");
    
    for (int i = 0; i < height; i++) {
        
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf("\n");
    }
}


void cash() {
    printf("\n--- 'Cash' Assignment ---\nTells user what is the least number of coins required to return proper change.\n");
    
    float dollar_input;
    int coin_only;
    do
    {
        dollar_input = get_float("Change owed: ");
    } while (dollar_input<0);                                       // Input must be greater than 0
    coin_only = round((dollar_input - floor(dollar_input)) * 100);  // Strip whole dollarts
    
    // Find coins
    int num_coins = 0;
    int denominations[] = {25, 10, 5};
    
    for (int i = 0; i < 3; i++) {
        
        num_coins += coin_only/denominations[i];
        coin_only = coin_only%denominations[i];
    }
    num_coins += coin_only;
    
    printf("%i\n", num_coins);
}


int sum_product_digits(int x) {
    int digit_sum = 0;
    while (x > 0) {
        digit_sum += x % 10;
        x = x/10;
    }
    return digit_sum;
}


bool validate_luhns(long card_number) {
    bool multiply = false;
    int numbertotal = 0;
    
    while (card_number > 0) {
        if (multiply)
            numbertotal += sum_product_digits((card_number % 10) * 2);
        else
            numbertotal += card_number % 10;
        card_number = card_number/10;
        
        multiply = !multiply;
    }
    
    return (numbertotal % 10 == 0);
}
    
    
string get_cc_type(long card_number) {
    // Check if 13 digit Visa
    int first_digit = (card_number / pow(10, 12));
    if (first_digit == 4) return "VISA\n";
    
    // Check if Amex
    first_digit = (card_number / pow(10, 14));
    if (first_digit == 3) return "AMEX\n";
    
    // Check if MasterCard or 16 digit Visa or none
    first_digit = (card_number / pow(10, 15));
    if (first_digit == 5) return "MASTERCARD\n";
    if (first_digit == 4) return "VISA\n";
    
    // Does not fall under any above criteria
    return "INVALID\n";
}


string credit() {
    printf("\n--- 'Credit' Assignment ---\nPrints whether the CC number entered is valid and what type of CC it is.\nOnly accepts CS50 specs for CC numbers:\nVISA: 13 or 16 digits, begins with 4\nMASTERCARD: 16 digits, begins with 5 \nAMEX: 15 digits, begins with 3\n\n");
    
    long cc_number;
    cc_number = get_long("Number: ");
    
    if (validate_luhns(cc_number)) return get_cc_type(cc_number);
    else return "INVALID\n";
}


int main() {
    hello();
    mario();
    cash();
    printf("%s", credit());
    return 0;
}
