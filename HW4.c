#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h> // 用於 getch() 函數
#include <windows.h> // 用於清除螢幕

#define MAX_STUDENTS 10
#define PASSWORD "2025"
#define MAX_ATTEMPTS 3

// 學生結構定義
typedef struct {
char name[50];
int id;
int math;
int physics;
int english;
float average;
} Student;

// 函式宣告
void displayWelcomeScreen();
int verifyPassword();
void clearScreen();
void displayMainMenu();
void enterGrades(Student students[], int *n);
void displayAllGrades(Student students[], int n);
void searchStudent(Student students[], int n);
void displayRanking(Student students[], int n);
void exitSystem();

// 主函式
int main() {
Student students[MAX_STUDENTS];
int studentCount = 0;
char choice;

// 顯示歡迎畫面並驗證密碼
if (!verifyPassword()) {
return 0; // 密碼錯誤，結束程式
}

// 主選單循環
while (1) {
displayMainMenu();
printf("請輸入您的選擇: ");
choice = getch();
printf("%c\n", choice);

switch (tolower(choice)) {
case 'a':
enterGrades(students, &studentCount);
break;
case 'b':
displayAllGrades(students, studentCount);
break;
case 'c':
searchStudent(students, studentCount);
break;
case 'd':
displayRanking(students, studentCount);
break;
case 'e':
exitSystem();
break;
default:
printf("無效的選項，請重新輸入。\n");
Sleep(1000); // 暫停1秒
break;
}
}

return 0;
}

// 顯示歡迎畫面
void displayWelcomeScreen() {
printf("\n\n");
printf("****************************************************\n");
printf("* *\n");
printf("* 歡迎使用成績管理系統 *\n");
printf("* *\n");
printf("* 開發者: [您的名字] *\n");
printf("* 學號: [您的學號] *\n");
printf("* 日期: 2024年5月 *\n");
printf("* *\n");
printf("* 本系統提供以下功能: *\n");
printf("* 1. 輸入學生成績 *\n");
printf("* 2. 顯示所有學生成績 *\n");
printf("* 3. 搜尋特定學生成績 *\n");
printf("* 4. 成績排名 *\n");
printf("* *\n");
printf("****************************************************\n");
printf("\n\n");
}

// 驗證密碼
int verifyPassword() {
char input[5];
int attempts = 0;

displayWelcomeScreen();

while (attempts < MAX_ATTEMPTS) {
printf("請輸入4位數密碼 (嘗試 %d/%d): ", attempts + 1, MAX_ATTEMPTS);
scanf("%4s", input);

if (strcmp(input, PASSWORD) == 0) {
printf("\n密碼正確，歡迎使用本系統！\n");
Sleep(1000); // 暫停1秒
clearScreen();
return 1;
} else {
attempts++;
if (attempts < MAX_ATTEMPTS) {
printf("密碼錯誤，請再試一次。\n");
}
}
}

printf("\n警告！您已連續輸入錯誤密碼%d次，系統將關閉。\n", MAX_ATTEMPTS);
Sleep(2000); // 暫停2秒
return 0;
}

// 清除螢幕
void clearScreen() {
system("cls"); // Windows系統
// system("clear"); // Unix/Linux系統
}

// 顯示主選單
void displayMainMenu() {
printf("\n");
printf("---[Grade System]---\n");
printf("a. 輸入學生成績\n");
printf("b. 顯示學生成績\n");
printf("c. 搜尋學生成績\n");
printf("d. 成績排名\n");
printf("e. 離開系統\n");
printf("\n");
}

// 輸入學生成績
void enterGrades(Student students[], int *n) {
clearScreen();
printf("--- 輸入學生成績 ---\n");

// 輸入學生人數
while (1) {
printf("請輸入學生人數 (5~10): ");
scanf("%d", n);

if (*n >= 5 && *n <= 10) {
break;
} else {
printf("錯誤！人數必須在5到10之間。\n");
}
}

// 輸入每位學生的資料
int i;
for (i = 0; i < *n; i++) 
{
printf("\n學生 #%d:\n", i + 1);

// 輸入姓名
printf("姓名: ");
scanf("%s", students[i].name);

// 輸入學號
while (1) {
printf("學號 (6位數字): ");
scanf("%d", &students[i].id);

if (students[i].id >= 100000 && students[i].id <= 999999) {
break;
} else {
printf("錯誤！學號必須是6位數字。\n");
}
}

// 輸入數學成績
while (1) {
printf("數學成績 (0~100): ");
scanf("%d", &students[i].math);

if (students[i].math >= 0 && students[i].math <= 100) {
break;
} else {
printf("錯誤！成績必須在0到100之間。\n");
}
}

// 輸入物理成績
while (1) {
printf("物理成績 (0~100): ");
scanf("%d", &students[i].physics);

if (students[i].physics >= 0 && students[i].physics <= 100) {
break;
} else {
printf("錯誤！成績必須在0到100之間。\n");
}
}

// 輸入英文成績
while (1) {
printf("英文成績 (0~100): ");
scanf("%d", &students[i].english);

if (students[i].english >= 0 && students[i].english <= 100) {
break;
} else {
printf("錯誤！成績必須在0到100之間。\n");
}
}

// 計算平均成績
students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
}

printf("\n所有學生成績已輸入完成！\n");
printf("按任意鍵返回主選單...");
getch();
clearScreen();
}

// 顯示所有學生成績
void displayAllGrades(Student students[], int n) {
clearScreen();

if (n == 0) {
printf("目前沒有學生資料。\n");
} else {
printf("--- 所有學生成績 ---\n");
printf("%-20s %-10s %-8s %-8s %-8s %-8s\n",
"姓名", "學號", "數學", "物理", "英文", "平均");
printf("------------------------------------------------------------\n");
int i;
for (i = 0; i < n; i++) {
printf("%-20s %-10d %-8d %-8d %-8d %-8.1f\n",
students[i].name, students[i].id,
students[i].math, students[i].physics,
students[i].english, students[i].average);
}
}

printf("\n按任意鍵返回主選單...");
getch();
clearScreen();
}

// 搜尋學生
void searchStudent(Student students[], int n) {
clearScreen();
char name[50];
int found = 0;

printf("--- 搜尋學生成績 ---\n");

if (n == 0) {
printf("目前沒有學生資料。\n");
} else {
printf("請輸入要搜尋的學生姓名: ");
scanf("%s", name);
int i;
for (i = 0; i < n; i++) {
if (strcmp(students[i].name, name) == 0) {
printf("\n找到學生資料:\n");
printf("%-20s %-10s %-8s %-8s %-8s %-8s\n",
"姓名", "學號", "數學", "物理", "英文", "平均");
printf("------------------------------------------------------------\n");
printf("%-20s %-10d %-8d %-8d %-8d %-8.1f\n",
students[i].name, students[i].id,
students[i].math, students[i].physics,
students[i].english, students[i].average);
found = 1;
break;
}
}

if (!found) {
printf("\n找不到姓名為 %s 的學生。\n", name);
}
}

printf("\n按任意鍵返回主選單...");
getch();
clearScreen();
}

// 顯示成績排名
void displayRanking(Student students[], int n) {
clearScreen();

if (n == 0) {
printf("目前沒有學生資料。\n");
} else {
// 建立副本進行排序
Student sortedStudents[MAX_STUDENTS];
int i;
for (i = 0; i < n; i++) {
sortedStudents[i] = students[i];
}

// 使用泡沫排序法按平均成績排序

for (i = 0; i < n - 1; i++) {
	int j;
for (j = 0; j < n - i - 1; j++) {
if (sortedStudents[j].average < sortedStudents[j + 1].average) {
Student temp = sortedStudents[j];
sortedStudents[j] = sortedStudents[j + 1];
sortedStudents[j + 1] = temp;
}
}
}

printf("--- 成績排名 ---\n");
printf("%-5s %-20s %-10s %-8s\n", "排名", "姓名", "學號", "平均成績");
printf("----------------------------------------\n");

for (i = 0; i < n; i++) {
printf("%-5d %-20s %-10d %-8.1f\n",
i + 1, sortedStudents[i].name,
sortedStudents[i].id, sortedStudents[i].average);
}
}

printf("\n按任意鍵返回主選單...");
getch();
clearScreen();
}

// 離開系統
void exitSystem() {
char confirm;

while (1) {
clearScreen();
printf("確定離開？ (y/n): ");
confirm = getch();
printf("%c\n", confirm);

if (tolower(confirm) == 'y') {
printf("\n感謝使用本系統，再見！\n");
Sleep(1000);
exit(0);
} else if (tolower(confirm) == 'n') {
clearScreen();
return;
} else {
printf("無效的輸入，請輸入 'y' 或 'n'。\n");
Sleep(1000);
}
}
}
