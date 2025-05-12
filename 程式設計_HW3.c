#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define ROWS 9
#define COLS 9
#define MAX_ATTEMPTS 3

typedef struct {
    char seats[ROWS][COLS];
    char password[5];
    int attempts;
} BookingSystem;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void initializeSeats(BookingSystem *sys) {
    memset(sys->seats, '-', sizeof(sys->seats));
    srand(time(0));
    int count = 0;
    while (count < 10) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (sys->seats[row][col] == '-') {
            sys->seats[row][col] = '*';
            count++;
        }
    }
}

void displayWelcome() {
    clearScreen();
    printf("\n\n");
    printf("      ******************************\n");
    printf("      *                            *\n");
    printf("      *       �w��Ө�             *\n");
    printf("      *     �q�v�|�q��t��         *\n");
    printf("      *         2025               *\n");
    printf("      *                            *\n");
    printf("      ******************************\n");
    printf("\n\n");
    printf("      ���t�δ��ѥH�U�\��G\n");
    printf("      - �d�ݥi�ήy��\n");
    printf("      - �۰ʦw�Ʈy��\n");
    printf("      - ��ʿ�ܮy��\n");
    printf("\n\n");
    printf("      �п�J4��ƱK�X (�w�]��2025)\n");
    printf("\n\n");
}

int passwordCheck(BookingSystem *sys) {
    while (sys->attempts < MAX_ATTEMPTS) {
        char input[5];
        printf("�п�J�K�X: ");
        scanf("%4s", input);
        
        if (strcmp(input, sys->password) == 0) {
            printf("\n�K�X���T�I�w��ϥέq��t�ΡC\n");
            return 1;
        } else {
            sys->attempts++;
            int remaining = MAX_ATTEMPTS - sys->attempts;
            printf("�K�X���~�I�Ѿl���զ���: %d\n", remaining);
        }
    }
    printf("\n���~���զ��ƹL�h�I�t����w�C\n");
    return 0;
}

void displayMenu() {
    clearScreen();
    printf("\n          -------------------------\n");
    printf("          ---[ �q��t�ΥD��� ]---\n");
    printf("          a. �d�ݥi�ήy��\n");
    printf("          b. �۰ʦw�Ʈy��\n");
    printf("          c. ��ʿ�ܮy��\n");
    printf("          d. ���}�t��\n");
    printf("          -------------------------\n\n");
}

void displaySeats(BookingSystem *sys) {
    clearScreen();
    printf("\n  123456789\n");
    int i;
    for (i = 0; i < ROWS; ++i) {
        printf("%d ", 9 - i);
        int j;
        for (j = 0; j < COLS; ++j) {
            printf("%c", sys->seats[i][j]);
        }
        printf("\n");
    }
    printf("Press any key to continue...");
    _getch();
}

void arrangeSeats(BookingSystem *sys, int numSeats) {
    clearScreen();
    int found = 0;
    int i;
    for (i = 0; i < ROWS && !found; ++i) {
    	int j;
        for (j = 0; j <= COLS - numSeats; ++j) {
            int available = 1;
            int k;
            for (k = 0; k < numSeats; ++k) {
                if (sys->seats[i][j+k] != '-') {
                    available = 0;
                    break;
                }
            }
            if (available) {
            	int k;
                for (k = 0; k < numSeats; ++k) {
                    sys->seats[i][j+k] = '@';
                }
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("�䤣��i�ήy��C\n");
    } else {
        printf("�y��w�Ʀ��\�C\n");
    }
    displaySeats(sys);
}

void chooseSeats(BookingSystem *sys) {
    clearScreen();
    int row, col;
    char dash;
    printf("��J�y���m (�榡: ��-�C�A�Ҧp:1-2): ");
    if (scanf("%d-%d", &row, &col) != 2) {
        while(getchar() != '\n'); // �M����J�w�İ�
        printf("�榡���~�I�Шϥ� ��-�C �榡�C\n");
        return;
    }
    
    if (row < 1 || row > 9 || col < 1 || col > 9) {
        printf("�L�Ī��y��C\n");
    } else if (sys->seats[9 - row][col - 1] != '-') {
        printf("�y��w�Q�w�q�C\n");
    } else {
        sys->seats[9 - row][col - 1] = '@';
        printf("�w�q���\�C\n");
        displaySeats(sys);
    }
}

int exitSystem() {
    clearScreen();
    printf("�~��ϥΡH(y/n): ");
    char choice = getchar();
    while(getchar() != '\n'); // �M����J�w�İ�
    return (choice == 'y' || choice == 'Y');
}

int main() {
    BookingSystem sys;
    strcpy(sys.password, "2025");
    sys.attempts = 0;
    initializeSeats(&sys);

    displayWelcome();
    if (!passwordCheck(&sys)) {
        return 0;
    }

    while(1) {
        displayMenu();
        printf("��J��� (a-d): ");
        char choice = getchar();
        while(getchar() != '\n'); // �M����J�w�İ�

        switch(choice) {
            case 'a':
                displaySeats(&sys);
                break;
            case 'b': {
                int numSeats;
                printf("�ݭn�X�Ӯy�� (1-4)? ");
                if (scanf("%d", &numSeats) == 1 && numSeats >=1 && numSeats <=4) {
                    while(getchar() != '\n'); // �M����J�w�İ�
                    arrangeSeats(&sys, numSeats);
                } else {
                    while(getchar() != '\n');
                    printf("�L�Ŀ�J�C\n");
                }
                break;
            }
            case 'c':
                chooseSeats(&sys);
                break;
            case 'd':
                if (!exitSystem()) return 0;
                break;
            default:
                printf("�L�Ŀﶵ�C\n");
        }
    }
    return 0;
}
