#include <stdio.h> 
#include <stdlib.h>


// 清除螢幕

void clearScreen() {

    system("CLS");

}

// 顯示歡迎畫面

void showWelcomeScreen() 
{

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

    int correctPassword = 2024;

    printf("請輸入4位數密碼: ");
	 
    scanf("%d", &password);
    
    while (getchar() != '\n');



    if (password == correctPassword) 
	{

        printf("密碼正確，恭喜進入系統。\n");
        printf("請按ENTER鍵進入下一步\n");
        getchar();
        
        clearScreen();  // 清除螢幕

        return 1;

    } 
	else 
	{ 

        printf("\a密碼錯誤，麻煩重新輸入。\n");

        return 0;
   
    }

}
// 判斷字元類型
void checkCharacterType() 
{
      char inputChar;
      printf("\n========== 主選單 ==========\n");
      printf("1. 'A'....'Z':Uppercase\n");
      printf("2. 'a'....'z':Lowercase\n");
      printf("3. '0'....'9':Digit\n");
      printf("4. Otherwise:丁維棕\n");
      printf("請輸入一個字元: ");
      fflush(stdin); // 清除輸入緩衝
      scanf(" %c", &inputChar);

     if (inputChar >= 'A' && inputChar <= 'Z') 
	 {
      printf("Uppercase\n");
     } 
      else if (inputChar >= 'a' && inputChar <= 'z') 
	     {
           printf("Lowercase\n");
         } 
		 else if (inputChar >= '0' && inputChar <= '9') 
		 {
           printf("Digit\n");
         } 
		 else 
		 {
           printf("E3A61 丁維棕\n"); 
         }
}
int main() {


     
    showWelcomeScreen();
    
     // 讓使用者輸入密碼，直到正確為止

    while (!checkPassword());

     // 判斷字元類型
    checkCharacterType();

    system("PAUSE");  // 暫停螢幕

    return 0;

}



