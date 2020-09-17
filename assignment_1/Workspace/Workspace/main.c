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


void mario(void) {
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


void cash(void) {
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
    while (x % 10 > 0) {
        digit_sum += x % 10;
        x = x/10;
    }
    return digit_sum;
}

string credit(void){
    printf("\n--- 'Credit' Assignment ---\nPrints whether the CC number entered is valid and what type of CC it is.\nOnly accepts MIT specs for CC numbers:\nVISA: 13 or 16 digits, begins with 4\nMASTERCARD: 16 digits, begins with 5 \n       *** MC DOES NOT CURRENTLY WORK\nAMEX: 15 digits, begins with 3\n\n");
    
    // Get CC number
    long cc_number;
    cc_number = get_long("Number: ");
    
    bool multiply = false;
    int numbertotal = 0;
    long newccnumber = cc_number;
    
    // Iterate through CC number digits, add and multiply as per algorithm
    while (newccnumber / 10 > 0 || newccnumber % 10 > 0.9)
    {
        if (multiply) {
            numbertotal += sum_product_digits((newccnumber % 10) * 2);
            
        } else {
            numbertotal += newccnumber % 10;
            }
        newccnumber = floor(newccnumber/10);
        
        //Flip multiply value
        multiply = !multiply;
    }
    
    // Check Luhn's Algorithm
    if (numbertotal % 10 != 0) {
        return "INVALID\n";
    }
    
    // Check if 13 digit Visa
    if (cc_number / 10000000000000.0 < 1 && cc_number / 1000000000000 == 4) {
        return "VISA\n";
        }
    
    // Check if Amex
    if (cc_number / 1000000000000000.0 < 1 && cc_number / 100000000000000 == 3) {
        return "AMEX\n";
        }
    
    // Check if MasterCard or 16 digit Visa or none
    if (cc_number / 10000000000000000.0 < 1 && cc_number / 1000000000000000 == 5) {
        return "MASTERCARD\n";
    }
    if (cc_number / 10000000000000000.0 < 1 && cc_number / 1000000000000000 == 4) {
        return "VISA\n";
    } else {
        return "INVALID\n";
    }
}


int main(void) {
    hello();
    mario();
    cash();
    printf("%s", credit());
    return 0;
}
