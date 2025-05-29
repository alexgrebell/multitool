#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
int _kbhit(void) {
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
}
int _getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
void Sleep(int milliseconds) {
    usleep(milliseconds * 1000);
}
#endif

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForEnter() {
    printf("\nPress Enter to continue...\n");
    getchar();
}

void timer() {
    int sec = 0, min = 0, hours = 0;
    printf("How many seconds? ");
    scanf("%d", &sec);
    printf("How many minutes? ");
    scanf("%d", &min);
    printf("How many hours? ");
    scanf("%d", &hours);
    getchar(); // flush newline

    int total_time = hours * 3600 + min * 60 + sec;
    int paused = 0;

    for (int i = total_time; i >= 0; i--) {
        if (_kbhit()) {
            char key = _getch();
            if (key == ' ') {
                paused = !paused;
            } else if (key == 'q') {
                printf("\nTimer stopped!\n");
                return;
            }
        }
        if (paused) {
            printf("Paused. Press SPACE to resume or Q to quit.\n");
            while (paused) {
                if (_kbhit()) {
                    char key = _getch();
                    if (key == ' ') paused = 0;
                    else if (key == 'q') {
                        printf("\nTimer stopped!\n");
                        return;
                    }
                }
                Sleep(200);
            }
        }
        clearScreen();
        printf("Time left: %02d:%02d:%02d\n", i / 3600, (i / 60) % 60, i % 60);
        Sleep(1000);
    }
    printf("Time's up!\n");
    waitForEnter();
}

void calculator() {
    char input[100];
    while (1) {
        float num1, num2;
        char op;

        printf("First number (or 'q' to quit): ");
        if (!fgets(input, sizeof(input), stdin)) break;
        if (input[0] == 'q') break;
        num1 = atof(input);

        printf("Operator (+ - * /): ");
        if (!fgets(input, sizeof(input), stdin)) break;
        if (input[0] == 'q') break;
        op = input[0];

        printf("Second number: ");
        if (!fgets(input, sizeof(input), stdin)) break;
        if (input[0] == 'q') break;
        num2 = atof(input);

        double result;
        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 == 0) {
                    printf("Division by zero error.\n");
                    continue;
                }
                result = num1 / num2; break;
            default:
                printf("Invalid operator.\n");
                continue;
        }
        printf("Result: %.2f\n", result);
    }
}

int timeToSeconds(const char *time) {
    int h, m, s;
    sscanf(time, "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

void secondsToTime(int sec, char *out) {
    if (sec < 0) sec = 0;
    sprintf(out, "%02d:%02d:%02d", sec / 3600, (sec / 60) % 60, sec % 60);
}
void time_calculator() {
    while (1) {
        char t1[9], t2[9], out[9], op;
        printf("Enter time 1 (hh:mm:ss or q): ");
        scanf("%8s", t1);
        if (t1[0] == 'q') break;

        printf("Enter time 2 (hh:mm:ss): ");
        scanf("%8s", t2);

        printf("Operation (+ - * /): ");
        scanf(" %c", &op);
        getchar();

        int s1 = timeToSeconds(t1);
        int s2 = timeToSeconds(t2);
        int res;

        switch (op) {
            case '+':
                res = s1 + s2;
                secondsToTime(res, out);
                printf("Result: %s\n", out);
                break;
            case '-':
                res = s1 - s2;
                secondsToTime(res, out);
                printf("Result: %s\n", out);
                break;
            case '*':
                res = s1 * s2;
                secondsToTime(res, out);
                printf("Result: %s\n", out);
                break;
            case '/':
                if (s2 == 0) {
                    printf("Cannot divide by zero.\n");
                } else {
                    res = s1 / s2;
                    secondsToTime(res, out);
                    printf("Quotient time: %s\n", out);
                }
                break;
            default:
                printf("Invalid operator.\n");
        }

        waitForEnter();
    }
}

void percentage_calculator() {
    double base, percent;
    printf("Enter number: ");
    scanf("%lf", &base);
    printf("Enter percent: ");
    scanf("%lf", &percent);
    getchar();
    printf("%.2lf%% of %.2lf is %.2lf\n", percent, base, (base * percent / 100.0));
    waitForEnter();
}

void randomizer() {
    int min, max;
    printf("Enter minimum number: ");
    scanf("%d", &min);
    printf("Enter maximum number: ");
    scanf("%d", &max);
    getchar();
    if (min > max) {
        int temp = min; min = max; max = temp;
    }
    srand(time(NULL));
    int result = rand() % (max - min + 1) + min;
    printf("Random number: %d\n", result);
    waitForEnter();
}
char int_menu() {
    char input[10];
    printf ("##########################################\n");
    printf ("##########################################\n");
    printf ("##########  There is multitool  ##########\n");
    printf ("##########   program for your   ##########\n");
    printf ("########## poor and slim system ##########\n");
    printf ("##########################################\n");
    printf ("##########################################\n");
    printf("\nSelect a function:\n");
    printf("1. Timer\n");
    printf("2. Calculator                                   You can finish\n");
    printf("3. Time calculation                             or return this\n");
    printf("4. Percentage calculator                         program even\n");
    printf("5. Randomizer                                  during execution\n\n");
    fgets(input, sizeof(input), stdin);
    clearScreen();
    return input[0];
}

int main() {
    while (1) {
        char choice = int_menu();
        switch (choice) {
            case '1': timer(); break;
            case '2': calculator(); break;
            case '3': time_calculator(); break;
            case '4': percentage_calculator(); break;
            case '5': randomizer(); break;
            case 'q': printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
}