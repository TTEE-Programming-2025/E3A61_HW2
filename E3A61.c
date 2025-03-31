#include <stdio.h> 
#include <stdlib.h>


// 清除螢幕

void clearScreen() {

    system("CLS");

}

// 顯示歡迎畫面

void showWelcomeScreen() {

    printf("**************************************\n");
    printf("*                  *                 *\n");
    printf("*  .           +   *         +       *\n");
    printf("*       +         ***   .        .   *\n");
    printf("*    .            ***                *\n");
    printf("*          .      ***                *\n");
    printf("*             +  *****      +        *\n");
    printf("*       .        *****               *\n");
    printf("*               *******              *\n");
    printf("*    +          *******         +    *\n");
    printf("*           .   *******     +        *\n");
    printf("*         +     *******          +   *\n");
    printf("*    .          *******      .       *\n");
    printf("*               *******              *\n");
    printf("*               *******              *\n");
    printf("*           *   *******   *    +     *\n");
    printf("*  .       ***  *******  ***      .  *\n");
    printf("*         ***** ******* *****        *\n");
    printf("*         ***** ******* *****    +   *\n");
    printf("*      .  ***** ******* *****        *\n");
    printf("*         ***** ******* *****        *\n");
    printf("*         ***** ******* *****   .    *\n");
    printf("*   +     ***** ******* *****        *\n");
    printf("*       * ***** ******* ***** *      *\n");
    printf("*      ** ***** ******* ***** **     *\n");
    printf("*     *** ***** ******* ***** ***    *\n");
    printf("*               * * * *              *\n");
    printf("*               * * * *              *\n");
    printf("*          Designed by 丁維棕        *\n");

    printf("**************************************\n");
    printf("請按ENTER鍵進入下一步\n");
 
    getchar();
    
    clearScreen();  // 清除螢幕

}

// 輸入密碼

int checkPassword() 
{ 

    int password;

    int correctPassword = 8780;

    printf("請輸入4位數密碼: ");
	 
    scanf("%d", &password);
    
    while (getchar() != '\n');



    if (password == correctPassword) 
	{

        printf("密碼正確，恭喜進入系統。\n");

        return 1;

    } 
	else 
	{ 

        printf("\a密碼錯誤，麻煩重新輸入。\n");

        return 0;

    }

}
int main() {


     
    showWelcomeScreen();
    
     // 讓使用者輸入密碼，直到正確為止

    while (!checkPassword());



    system("PAUSE");  // 暫停螢幕

    return 0;

}



