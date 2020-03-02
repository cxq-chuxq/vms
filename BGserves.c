#include "BGserves.h"
int password = 1234;
void Service(){
    int a,lock=1;
    puts("(9) Opening service menu. Access code is required.");
    printf("Enter access code: ");
    scanf("%d",&a);
    if(a!=password){
        puts("Incorrect code!\n");
    }else{
        puts("Correct code!\n");
        a = Nextmenu();
        while(lock){
            switch(a){
                case 1:
                    Machine();
                    break;
                case 2:
                    Withdrawn();
                    break;
                case 3:
                    Refill();
                    break;
                case 4:
                    Change();
                    break;
                case 0:
                    lock = 0;
                    break;
                default:
                    puts("Invalid choice!");
                    break;
            }
            if(a!=0){
                a = Nextmenu();
            }
        }
    } 
}
