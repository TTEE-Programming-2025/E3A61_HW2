#include <stdio.h>
#include <stdlib.h> // system() 用來清除螢幕及暫停

// 函式宣告
void showMenu();              // 顯示選單
void drawTriangle();          // 畫出直角三角形
void multiplicationTable();   // 顯示乘法表
int askContinue();            // 詢問是否繼續

int main() 
{
    int run = 1;               // 控制主迴圈
    int password;              // 密碼變數
    int attempts = 0;          // 密碼輸入次數
    char choice;               // 選單選項

    // 顯示個人風格畫面 (至少20行)
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
    
    // 密碼檢查，最多輸入3次
    while (attempts < 3) 
	{
        printf("請輸入4位數密碼：");
        scanf("%d", &password);
        
        if (password == 2025) {
            printf("密碼正確！進入系統...\n");
            break;
        } else {
            printf("密碼錯誤，請重新輸入。\n");
            attempts++;
        }
    }

    // 若錯誤3次，結束程式
    if (attempts == 3) 
	{
        printf("錯誤次數過多，請檢查密碼設定。\n");
     
        return 0;
    }
    } 
