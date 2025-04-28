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
     // 主選單迴圈
    while (run) {
        showMenu();
        printf("請輸入代號：");
        scanf(" %c", &choice); // 前面空格為了吃掉前一個enter

        switch (choice) {
            case 'a':
            case 'A':
                system("cls"); // 清除螢幕 (Windows)
                drawTriangle();
                system("pause"); // 程式暫停，等待按鍵
                break;
            case 'b':
            case 'B':
                system("cls");
                multiplicationTable();
                system("pause");
                break;
            case 'c':
            case 'C':
                system("cls");
                int result = askContinue();
                if (result == 1) {
                    continue;   // 選擇繼續
                } else if (result == 0) {
                    run = 0;    // 結束主迴圈
                }
                break;
            default:
                printf("無效選項，請重新選擇。\n");
        }
    }

    printf("感謝使用，再見！\n");
    return 0;
}

// 顯示主選單
void showMenu() {
    system("cls"); // 清除螢幕
    printf("=============================\n");
    printf("a. 畫出直角三角形\n");
    printf("b. 顯示乘法表\n");
    printf("c. 結束系統\n");
    printf("=============================\n");
}

// 畫出直角三角形
void drawTriangle() {
    char ch;
    do
	{
    printf("請輸入一個字元 (a~n)：");
    scanf(" %c", &ch);
    if (ch < 'a' || ch > 'n') 
	{
		 printf("輸入錯誤！請重新輸入有效字元。\n");
    }
    }
    while (ch < 'a' || ch > 'n');
	
        printf("\n直角三角形： \n");
        char i;
       
        for (i = ch; i >= 'a'; i--) 
		{
			int space;
			for (space = 0; space < (i - 'a'); space++)
			{
				printf("  ");
			}
			char j;
            for (j = i; j <= ch; j++) 
			{
                printf("%c ", j);
            }
            printf("\n");
        }
     
}

// 顯示乘法表
void multiplicationTable() {
    int n;
    do 
	{
    printf("請輸入一個數字 (1~9)：");
    scanf("%d", &n);
    if (n < 1 || n > 9) 
	    {
            printf("輸入錯誤！請重新輸入有效的數字（1~9）。\n");

        }
        
    }
	while (n < 1 || n > 9); // 只要錯誤就重複輸入
        printf("\n乘法表：\n");
        int i;
        for (i = 1; i <= n; i++) 
		{
            printf("%d x %d = %d\n", i, i, i * i);
        }
}

// 詢問是否繼續
int askContinue() {
    char choice;
    printf("Continue? (y/n)：");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        return 1; // 繼續
    } else if (choice == 'n' || choice == 'N') {
        printf("結束程式！\n");
        return 0; // 結束
    } else {
        printf("輸入錯誤，請重新輸入。\n");
        return -1; // 錯誤，回到上層
    }
} 
