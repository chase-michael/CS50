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
    
    // Get input and convert to int representing just the coin change
    float dollar_input;
    int coin_only;
    do
    {
        dollar_input = get_float("Change owed: ");
    } while (dollar_input<0);
    coin_only = round((dollar_input - floor(dollar_input/1)) * 100);
    
    int num_coins = 0;
    // Quarters
    while (coin_only - 25 >= 0)
    {
        coin_only -= 25;
        num_coins++;
    }
    // Dimes
    while (coin_only - 10 >= 0)
    {
        coin_only -= 10;
        num_coins++;
    }
    // Nickels
    while (coin_only - 5 >= 0)
    {
        coin_only -= 25;
        num_coins++;
    }
    // Pennies
    while (coin_only - 1 >= 0)
    {
        coin_only -= 1;
        num_coins++;
    }
    printf("%i\n", num_coins);

}

string credit(void){
    printf("\n--- 'Credit' Assignment ---\nPrints whether the CC number entered is valid and what type of CC it is.\nOnly accepts MIT specs for CC numbers:\nVISA: 13 or 16 digits, begins with 4\nMASTERCARD: 16 digits, begins with 5 \n       *** MC DOES NOT CURRENTLY WORK\nAMEX: 15 digits, begins with 3\n\n");
    
    // Get CC number
    long cc_number;
    cc_number = get_long("Number: ");
    
    int multbool = 0;
    int multnumber = 0;
    int numbertotal = 0;
    long newccnumber = cc_number;
    
    // Iterate through CC number digits, add and multiply as per algorithm
    while (newccnumber / 10 > 0 || newccnumber % 10 > 0.9)
    {
        if (multbool == 0)
        {
            numbertotal += newccnumber % 10;
        } else
        {
            multnumber += (newccnumber % 10) * 2;
            while (multnumber % 10 > 0) {
                numbertotal += multnumber % 10;
                multnumber = floor(multnumber/10);
            }
        }
        newccnumber = floor(newccnumber/10);
        
        //Flip multbool value
        if (multbool == 0)
        {
            multbool = 1;
        } else
        {
            multbool = 0;
        }
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
    //hello();
   // mario();
   // cash();
    string cc_type = credit();
    printf("%s", cc_type);
    return 0;
}
