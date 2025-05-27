#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h> // �Ω� getch() ���
#include <windows.h> // �Ω�M���ù�

#define MAX_STUDENTS 10
#define PASSWORD "2025"
#define MAX_ATTEMPTS 3

// �ǥ͵��c�w�q
typedef struct {
char name[50];
int id;
int math;
int physics;
int english;
float average;
} Student;

// �禡�ŧi
void displayWelcomeScreen();
int verifyPassword();
void clearScreen();
void displayMainMenu();
void enterGrades(Student students[], int *n);
void displayAllGrades(Student students[], int n);
void searchStudent(Student students[], int n);
void displayRanking(Student students[], int n);
void exitSystem();

// �D�禡
int main() {
Student students[MAX_STUDENTS];
int studentCount = 0;
char choice;

// ����w��e�������ұK�X
if (!verifyPassword()) {
return 0; // �K�X���~�A�����{��
}

// �D���`��
while (1) {
displayMainMenu();
printf("�п�J�z�����: ");
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
printf("�L�Ī��ﶵ�A�Э��s��J�C\n");
Sleep(1000); // �Ȱ�1��
break;
}
}

return 0;
}

// ����w��e��
void displayWelcomeScreen() {
printf("\n\n");
printf("****************************************************\n");
printf("* *\n");
printf("* �w��ϥΦ��Z�޲z�t�� *\n");
printf("* *\n");
printf("* �}�o��: [�z���W�r] *\n");
printf("* �Ǹ�: [�z���Ǹ�] *\n");
printf("* ���: 2024�~5�� *\n");
printf("* *\n");
printf("* ���t�δ��ѥH�U�\��: *\n");
printf("* 1. ��J�ǥͦ��Z *\n");
printf("* 2. ��ܩҦ��ǥͦ��Z *\n");
printf("* 3. �j�M�S�w�ǥͦ��Z *\n");
printf("* 4. ���Z�ƦW *\n");
printf("* *\n");
printf("****************************************************\n");
printf("\n\n");
}

// ���ұK�X
int verifyPassword() {
char input[5];
int attempts = 0;

displayWelcomeScreen();

while (attempts < MAX_ATTEMPTS) {
printf("�п�J4��ƱK�X (���� %d/%d): ", attempts + 1, MAX_ATTEMPTS);
scanf("%4s", input);

if (strcmp(input, PASSWORD) == 0) {
printf("\n�K�X���T�A�w��ϥΥ��t�ΡI\n");
Sleep(1000); // �Ȱ�1��
clearScreen();
return 1;
} else {
attempts++;
if (attempts < MAX_ATTEMPTS) {
printf("�K�X���~�A�ЦA�դ@���C\n");
}
}
}

printf("\nĵ�i�I�z�w�s���J���~�K�X%d���A�t�αN�����C\n", MAX_ATTEMPTS);
Sleep(2000); // �Ȱ�2��
return 0;
}

// �M���ù�
void clearScreen() {
system("cls"); // Windows�t��
// system("clear"); // Unix/Linux�t��
}

// ��ܥD���
void displayMainMenu() {
printf("\n");
printf("---[Grade System]---\n");
printf("a. ��J�ǥͦ��Z\n");
printf("b. ��ܾǥͦ��Z\n");
printf("c. �j�M�ǥͦ��Z\n");
printf("d. ���Z�ƦW\n");
printf("e. ���}�t��\n");
printf("\n");
}

// ��J�ǥͦ��Z
void enterGrades(Student students[], int *n) {
clearScreen();
printf("--- ��J�ǥͦ��Z ---\n");

// ��J�ǥͤH��
while (1) {
printf("�п�J�ǥͤH�� (5~10): ");
scanf("%d", n);

if (*n >= 5 && *n <= 10) {
break;
} else {
printf("���~�I�H�ƥ����b5��10�����C\n");
}
}

// ��J�C��ǥͪ����
int i;
for (i = 0; i < *n; i++) 
{
printf("\n�ǥ� #%d:\n", i + 1);

// ��J�m�W
printf("�m�W: ");
scanf("%s", students[i].name);

// ��J�Ǹ�
while (1) {
printf("�Ǹ� (6��Ʀr): ");
scanf("%d", &students[i].id);

if (students[i].id >= 100000 && students[i].id <= 999999) {
break;
} else {
printf("���~�I�Ǹ������O6��Ʀr�C\n");
}
}

// ��J�ƾǦ��Z
while (1) {
printf("�ƾǦ��Z (0~100): ");
scanf("%d", &students[i].math);

if (students[i].math >= 0 && students[i].math <= 100) {
break;
} else {
printf("���~�I���Z�����b0��100�����C\n");
}
}

// ��J���z���Z
while (1) {
printf("���z���Z (0~100): ");
scanf("%d", &students[i].physics);

if (students[i].physics >= 0 && students[i].physics <= 100) {
break;
} else {
printf("���~�I���Z�����b0��100�����C\n");
}
}

// ��J�^�妨�Z
while (1) {
printf("�^�妨�Z (0~100): ");
scanf("%d", &students[i].english);

if (students[i].english >= 0 && students[i].english <= 100) {
break;
} else {
printf("���~�I���Z�����b0��100�����C\n");
}
}

// �p�⥭�����Z
students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
}

printf("\n�Ҧ��ǥͦ��Z�w��J�����I\n");
printf("�����N���^�D���...");
getch();
clearScreen();
}

// ��ܩҦ��ǥͦ��Z
void displayAllGrades(Student students[], int n) {
clearScreen();

if (n == 0) {
printf("�ثe�S���ǥ͸�ơC\n");
} else {
printf("--- �Ҧ��ǥͦ��Z ---\n");
printf("%-20s %-10s %-8s %-8s %-8s %-8s\n",
"�m�W", "�Ǹ�", "�ƾ�", "���z", "�^��", "����");
printf("------------------------------------------------------------\n");
int i;
for (i = 0; i < n; i++) {
printf("%-20s %-10d %-8d %-8d %-8d %-8.1f\n",
students[i].name, students[i].id,
students[i].math, students[i].physics,
students[i].english, students[i].average);
}
}

printf("\n�����N���^�D���...");
getch();
clearScreen();
}

// �j�M�ǥ�
void searchStudent(Student students[], int n) {
clearScreen();
char name[50];
int found = 0;

printf("--- �j�M�ǥͦ��Z ---\n");

if (n == 0) {
printf("�ثe�S���ǥ͸�ơC\n");
} else {
printf("�п�J�n�j�M���ǥͩm�W: ");
scanf("%s", name);
int i;
for (i = 0; i < n; i++) {
if (strcmp(students[i].name, name) == 0) {
printf("\n���ǥ͸��:\n");
printf("%-20s %-10s %-8s %-8s %-8s %-8s\n",
"�m�W", "�Ǹ�", "�ƾ�", "���z", "�^��", "����");
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
printf("\n�䤣��m�W�� %s ���ǥ͡C\n", name);
}
}

printf("\n�����N���^�D���...");
getch();
clearScreen();
}

// ��ܦ��Z�ƦW
void displayRanking(Student students[], int n) {
clearScreen();

if (n == 0) {
printf("�ثe�S���ǥ͸�ơC\n");
} else {
// �إ߰ƥ��i��Ƨ�
Student sortedStudents[MAX_STUDENTS];
int i;
for (i = 0; i < n; i++) {
sortedStudents[i] = students[i];
}

// �ϥΪw�j�ƧǪk���������Z�Ƨ�

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

printf("--- ���Z�ƦW ---\n");
printf("%-5s %-20s %-10s %-8s\n", "�ƦW", "�m�W", "�Ǹ�", "�������Z");
printf("----------------------------------------\n");

for (i = 0; i < n; i++) {
printf("%-5d %-20s %-10d %-8.1f\n",
i + 1, sortedStudents[i].name,
sortedStudents[i].id, sortedStudents[i].average);
}
}

printf("\n�����N���^�D���...");
getch();
clearScreen();
}

// ���}�t��
void exitSystem() {
char confirm;

while (1) {
clearScreen();
printf("�T�w���}�H (y/n): ");
confirm = getch();
printf("%c\n", confirm);

if (tolower(confirm) == 'y') {
printf("\n�P�¨ϥΥ��t�ΡA�A���I\n");
Sleep(1000);
exit(0);
} else if (tolower(confirm) == 'n') {
clearScreen();
return;
} else {
printf("�L�Ī���J�A�п�J 'y' �� 'n'�C\n");
Sleep(1000);
}
}
}
