#include<stdio.h>
#include<string.h>

typedef struct {
    char productName[20];
    int productPrice;
    int productNumber;
} Product;
// 商品初始化为A，B，C，D，E
Product A = {"Juice", 10, 5};
Product B = {"Cola", 6, 1};
Product C = {"Tea", 5, 2};
Product D = {"Water", 8, 1};
Product E = {"Coffee", 7, 9};

typedef struct {
    int coinValueOne;
    int coinValueTwo;
    int coinValueFive;
    int coinValueTen;
    int coinProfit;
    int conDeposit;
} Coin;

Coin coin = {1, 2, 5, 10, 0, 0};

char productStatus(Product product) {
    char status;

    if (product.productNumber == 0) {
        return status = 'X';
    }

    if (product.productPrice == coin.conDeposit) {
        return  status = 'O';
    }

    if (product.productNumber > 0) {
        return status = ' ';
    }
}

void customerPage();
void choicePage();

void choiceResultPage(int insertChoice);
/*
商品信息展示，包括商品名称和商品价格
*/
void Readproductinformation() {
    printf("A. %s ($ %d)", A.productName, A.productPrice);
    printf("B. %s ($ %d)", B.productName, B.productPrice);
    printf("C. %s ($ %d)", C.productName, C.productPrice);
    printf("D. %s ($ %d)", D.productName, D.productPrice);
    printf("E. %s ($ %d)", E.productName, E.productPrice);
}
/*
用户只能投入给定面值的硬币，贩卖机的商品状态，投币口金额会发生变化
*/
void InsertCoin() {
    while (1) {
        int InsertCoin;

        puts("(2) Which coin would you like to insert?");
        puts("1. $1");
        puts("2. $2");
        puts("3. $5");
        puts("4. $10");
        puts("0. Go back\n");
        printf("Your choice:");
        scanf("%d", &InsertCoin);

        switch (InsertCoin) {
        case 1:
            coin.conDeposit += coin.coinValueOne;
            break;

        case 2:
            coin.conDeposit += coin.coinValueTwo;
            break;

        case 3:
            coin.conDeposit += coin.coinValueFive;
            break;

        case 4:
            coin.conDeposit += coin.coinValueTen;
            break;

        case 0:
            break;

        default:
            puts("insert wrong coin");
            break;
        }
    }
}
/*
商品代码,A,B,C,D,E
*/
char producCode;
/*
购买商品的业务逻辑
*/
void outProduct(Product product, char code, char *producCode) {
    product.productNumber -= 1;
    *producCode = code;
    coin.coinProfit += product.productPrice;
}
/*
用户输入商品代号，购买商品
*/
void PressProductButton() {
    int productButton;
    puts("(3) Which product button would you like to press?");
    puts("1. A");
    puts("2. B");
    puts("3. C");
    puts("4. D");
    puts("5. E");
    puts("0. Go back\n");
    printf("Your choice:"); scanf("%d", &productButton);

    switch (productButton) {
    case 1:
        puts("You have pressed button A.");
        outProduct(A, 'A', &producCode);
        break;

    case 2:
        puts("You have pressed button B.");
        outProduct(B, 'B', &producCode);
        break;

    case 3:
        puts("You have pressed button C.");
        outProduct(C, 'C', &producCode);
        break;

    case 4:
        puts("You have pressed button D.");
        outProduct(D, 'D', &producCode);
        break;

    case 5:
        puts("You have pressed button E.");
        outProduct(E, 'E', &producCode);
        break;

    case 0:
        puts("Going back!");
        break;

    default:
        puts("wrong choice!");
        break;
    }

}
/*
用户退币
*/
void PressReturnButton() {
    coin.conDeposit = 0;
}
/*
用户退出系统
*/
void Quit() {
    exit(0);
}
int main(int argc, char const *argv[]) {


    customerPage();
    int insertChoice = -1;

    while (insertChoice != 1 || insertChoice != 2 || insertChoice != 3 || insertChoice != 4 || insertChoice != 9 || insertChoice != 0) {
        choicePage();
        printf("Your choice:");  sacnf("%d", &insertChoice);

        if (insertChoice != 1 || insertChoice != 2 || insertChoice != 3 || insertChoice != 4 || insertChoice != 9 || insertChoice != 0) {
            puts("Invalid choice!");
        } else {
            choiceResultPage(insertChoice);
        }
    }



    printf("[%c]", productStatus(A));
    return 0;
}