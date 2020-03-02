#include "BGselection.h"
int Nextmenu(){
    int a;
    putchar('\n');
    puts("(9) What would you like to do?");
    puts("1. Inspect machine status");
    puts("2. Withdraw all money");
    puts("3. Refill product");
    puts("4. Change product");
    puts("0. Go back");
    a = scanIn();
    return a;
}
