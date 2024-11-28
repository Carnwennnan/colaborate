#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#define KEY_LEFT  (256 + 75)
#define KEY_RIGHT (256 + 77)
#define KEY_UP    (256 + 72)
#define KEY_DOWN  (256 + 80)

int GetKey(void);
double GetElapsedTime(clock_t initial_clock, clock_t current_clock);
void GotoXY(int x, int y);
void Erase(int x, int y);    // (x, y)로 이동하여 공백 문자 출력
void Draw(int x, int y);     // (x, y)로 이동하여 ‘*’ 문자 출력
void draw_border(int width, int height);


int direction = 3;
int dir_diff;
int x_diff = -1;
int y_diff = 0;
int left = 0;
int right = 79;
int top = 0;
int bottom = 24;

#define MAX_SIZE 30
int x_list[MAX_SIZE] = { 15,16,17,18,19 };
int y_list[MAX_SIZE] = { 10,10,10,10,10 };
int cur_size = 5;
int head = 0;

void quit_game(const char* message);
int check_border(int left, int right, int top, int bottom);
void set_xy_diff(int direction, int* x_diff, int* y_diff);

int main(void)
{
    srand((unsigned int)time(NULL));

    CONSOLE_CURSOR_INFO ci = { 100, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
    draw_border(80, 25);
    int x = 70;
    int y = 11;
    Draw(x, y);

    clock_t initial_clock = clock();

    while (1)
    {
        Sleep(1);
        clock_t current_clock = clock();

        if (GetElapsedTime(initial_clock, current_clock) > 0.5)
        {   // 0.5초 경과
            Erase(x, y);

            int new_head = (head - 1 + MAX_SIZE) % MAX_SIZE;
            x_list[new_head] = x_list[head] + x_diff;
            y_list[new_head] = y_list[head] + y_diff;
            head = new_head;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#define KEY_LEFT  (256 + 75)
#define KEY_RIGHT (256 + 77)
#define KEY_UP    (256 + 72)
#define KEY_DOWN  (256 + 80)

int GetKey(void);
double GetElapsedTime(clock_t initial_clock, clock_t current_clock);
void GotoXY(int x, int y);
void Erase(int x, int y);    // (x, y)로 이동하여 공백 문자 출력
void Draw(int x, int y);     // (x, y)로 이동하여 ‘*’ 문자 출력
void draw_border(int width, int height);


int direction = 3;
int dir_diff;
int x_diff = -1;
int y_diff = 0;
int left = 0;
int right = 79;
int top = 0;
int bottom = 24;

#define MAX_SIZE 30
int x_list[MAX_SIZE] = { 15,16,17,18,19 };
int y_list[MAX_SIZE] = { 10,10,10,10,10 };
int cur_size = 5;
int head = 0;

void quit_game(const char* message);
int check_border(int left, int right, int top, int bottom);
void set_xy_diff(int direction, int* x_diff, int* y_diff);

int main(void)
{
    srand((unsigned int)time(NULL));

    CONSOLE_CURSOR_INFO ci = { 100, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
    draw_border(80, 25);
    int x = 70;
    int y = 11;
    Draw(x, y);

    clock_t initial_clock = clock();

    while (1)
    {
        Sleep(1);
        clock_t current_clock = clock();

        if (GetElapsedTime(initial_clock, current_clock) > 0.5)
        {   // 0.5초 경과
            Erase(x, y);
