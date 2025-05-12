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
    printf("      *       歡迎來到             *\n");
    printf("      *     電影院訂位系統         *\n");
    printf("      *         2025               *\n");
    printf("      *                            *\n");
    printf("      ******************************\n");
    printf("\n\n");
    printf("      本系統提供以下功能：\n");
    printf("      - 查看可用座位\n");
    printf("      - 自動安排座位\n");
    printf("      - 手動選擇座位\n");
    printf("\n\n");
    printf("      請輸入4位數密碼 (預設為2025)\n");
    printf("\n\n");
}

int passwordCheck(BookingSystem *sys) {
    while (sys->attempts < MAX_ATTEMPTS) {
        char input[5];
        printf("請輸入密碼: ");
        scanf("%4s", input);
        
        if (strcmp(input, sys->password) == 0) {
            printf("\n密碼正確！歡迎使用訂位系統。\n");
            return 1;
        } else {
            sys->attempts++;
            int remaining = MAX_ATTEMPTS - sys->attempts;
            printf("密碼錯誤！剩餘嘗試次數: %d\n", remaining);
        }
    }
    printf("\n錯誤嘗試次數過多！系統鎖定。\n");
    return 0;
}

void displayMenu() {
    clearScreen();
    printf("\n          -------------------------\n");
    printf("          ---[ 訂位系統主選單 ]---\n");
    printf("          a. 查看可用座位\n");
    printf("          b. 自動安排座位\n");
    printf("          c. 手動選擇座位\n");
    printf("          d. 離開系統\n");
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
        printf("找不到可用座位。\n");
    } else {
        printf("座位安排成功。\n");
    }
    displaySeats(sys);
}

void chooseSeats(BookingSystem *sys) {
    clearScreen();
    int row, col;
    char dash;
    printf("輸入座位位置 (格式: 行-列，例如:1-2): ");
    if (scanf("%d-%d", &row, &col) != 2) {
        while(getchar() != '\n'); // 清除輸入緩衝區
        printf("格式錯誤！請使用 行-列 格式。\n");
        return;
    }
    
    if (row < 1 || row > 9 || col < 1 || col > 9) {
        printf("無效的座位。\n");
    } else if (sys->seats[9 - row][col - 1] != '-') {
        printf("座位已被預訂。\n");
    } else {
        sys->seats[9 - row][col - 1] = '@';
        printf("預訂成功。\n");
        displaySeats(sys);
    }
}

int exitSystem() {
    clearScreen();
    printf("繼續使用？(y/n): ");
    char choice = getchar();
    while(getchar() != '\n'); // 清除輸入緩衝區
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
        printf("輸入選擇 (a-d): ");
        char choice = getchar();
        while(getchar() != '\n'); // 清除輸入緩衝區

        switch(choice) {
            case 'a':
                displaySeats(&sys);
                break;
            case 'b': {
                int numSeats;
                printf("需要幾個座位 (1-4)? ");
                if (scanf("%d", &numSeats) == 1 && numSeats >=1 && numSeats <=4) {
                    while(getchar() != '\n'); // 清除輸入緩衝區
                    arrangeSeats(&sys, numSeats);
                } else {
                    while(getchar() != '\n');
                    printf("無效輸入。\n");
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
                printf("無效選項。\n");
        }
    }
    return 0;
}
