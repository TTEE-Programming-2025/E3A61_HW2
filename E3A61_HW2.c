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
    } 
