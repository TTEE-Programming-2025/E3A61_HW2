#include <stdio.h>
#include <stdlib.h> // system() �ΨӲM���ù��μȰ�

// �禡�ŧi
void showMenu();              // ��ܿ��
void drawTriangle();          // �e�X�����T����
void multiplicationTable();   // ��ܭ��k��
int askContinue();            // �߰ݬO�_�~��

int main() 
{
    int run = 1;               // ����D�j��
    int password;              // �K�X�ܼ�
    int attempts = 0;          // �K�X��J����
    char choice;               // ���ﶵ

    // ��ܭӤH����e�� (�ܤ�20��)
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
    printf("*          Designed by �B����        *\n");

    printf("**************************************\n");
    
    // �K�X�ˬd�A�̦h��J3��
    while (attempts < 3) 
	{
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &password);
        
        if (password == 2025) {
            printf("�K�X���T�I�i�J�t��...\n");
            break;
        } else {
            printf("�K�X���~�A�Э��s��J�C\n");
            attempts++;
        }
    }

    // �Y���~3���A�����{��
    if (attempts == 3) 
	{
        printf("���~���ƹL�h�A���ˬd�K�X�]�w�C\n");
     
        return 0;
    }
     // �D���j��
    while (run) {
        showMenu();
        printf("�п�J�N���G");
        scanf(" %c", &choice); // �e���Ů欰�F�Y���e�@��enter

        switch (choice) {
            case 'a':
            case 'A':
                system("cls"); // �M���ù� (Windows)
                drawTriangle();
                system("pause"); // �{���Ȱ��A���ݫ���
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
                    continue;   // ����~��
                } else if (result == 0) {
                    run = 0;    // �����D�j��
                }
                break;
            default:
                printf("�L�Ŀﶵ�A�Э��s��ܡC\n");
        }
    }

    printf("�P�¨ϥΡA�A���I\n");
    return 0;
}

// ��ܥD���
void showMenu() {
    system("cls"); // �M���ù�
    printf("=============================\n");
    printf("a. �e�X�����T����\n");
    printf("b. ��ܭ��k��\n");
    printf("c. �����t��\n");
    printf("=============================\n");
}

// �e�X�����T����
void drawTriangle() {
    char ch;
    do
	{
    printf("�п�J�@�Ӧr�� (a~n)�G");
    scanf(" %c", &ch);
    if (ch < 'a' || ch > 'n') 
	{
		 printf("��J���~�I�Э��s��J���Ħr���C\n");
    }
    }
    while (ch < 'a' || ch > 'n');
	
        printf("\n�����T���ΡG \n");
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

// ��ܭ��k��
void multiplicationTable() {
    int n;
    do 
	{
    printf("�п�J�@�ӼƦr (1~9)�G");
    scanf("%d", &n);
    if (n < 1 || n > 9) 
	    {
            printf("��J���~�I�Э��s��J���Ī��Ʀr�]1~9�^�C\n");

        }
        
    }
	while (n < 1 || n > 9); // �u�n���~�N���ƿ�J
        printf("\n���k��G\n");
        int i;
        for (i = 1; i <= n; i++) 
		{
            printf("%d x %d = %d\n", i, i, i * i);
        }
}

// �߰ݬO�_�~��
int askContinue() {
    char choice;
    printf("Continue? (y/n)�G");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        return 1; // �~��
    } else if (choice == 'n' || choice == 'N') {
        printf("�����{���I\n");
        return 0; // ����
    } else {
        printf("��J���~�A�Э��s��J�C\n");
        return -1; // ���~�A�^��W�h
    }
} 
