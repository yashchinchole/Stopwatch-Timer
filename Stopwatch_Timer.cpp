// AUTHOR NAME - YASH CHINCHOLE

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <MMsystem.h>

#define t1 "\t"
#define t2 "\t\t"
#define t3 "\t\t\t"
#define t4 "\t\t\t\t"
#define t5 "\t\t\t\t\t"
#define l1 "\n"
#define l2 "\n\n"
#define l3 "\n\n\n"
#define l4 "\n\n\n\n"

using namespace std;

int main()
{
    int second = 0, minute = 0, hour = 0;
    int delay = 1000;

    system("cls");

    cout << t5 << "| ======================================================= |" << endl;
    cout << t5 << t1 << "---- S T O P W A T C H   &   T I M E R ----" << endl;
    cout << t5 << "| ======================================================= |" << endl;

    cout << l3 << t1 << "ENTER :" << l2;
    cout << t2 << "'S' for STOPWATCH" << l2;
    cout << t2 << "'T' for TIMER" << l2;

    char key;
    cout << t1;
    cin >> key;

    if (key == 'S' || key == 's')
    {
        while (1)
        {
            second++;

            if (second > 59)
            {
                minute++;
                second = 0;
            }

            if (minute > 59)
            {
                hour++;
                minute = 0;
            }

            if (hour > 23)
            {
                hour = 0;
            }

            system("cls");

            cout << l1 << t5 << "|----------------------------------------|";
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5 << "|           S T O P W A T C H            |";
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5 << "|----------------------------------------|";
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5;
            printf("|              %.2d : %.2d : %.2d              |", hour, minute, second);
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5 << "|----------------------------------------|";

            cout << l4 << t1 << "ENTER :" << l2;
            cout << t2 << "'P' for PAUSE" << l2;
            cout << t2 << "'E' for EXIT (twice)" << l2;
            cout << t1;

            Sleep(delay);

            if (kbhit())
            {
                if ('P' == getch() || 'p' == getch())
                {
                    cout << l2 << t1 << "TIME - PAUSE" << l2;

                    cout << t1;
                    system("pause");
                    cout << l1 << t1;
                }

                if ('E' == getch() || 'e' == getch())
                {
                    system("cls");
                    exit(0);
                }
            }
        }
    }

    if (key == 'T' || key == 't')
    {
        system("cls");

        cout << l1 << t1 << "SET TIMER :";
        cout << l2 << t2 << "HOURS : ";
        cin >> hour;
        cout << l1 << t2 << "MINUTES : ";
        cin >> minute;
        cout << l1 << t2 << "SECONDS : ";
        cin >> second;

        if (hour > 23 || minute > 60 || second > 60 || (second == 0 && minute == 0 && hour == 0))
        {
            cout << l2 << t2 << "ERROR ! YOU ENTER WRONG TIME" << l3;
            exit(0);
        }

        while (1)
        {
            second--;

            if (second < 0)
            {
                second = 59;
                minute--;
            }

            if (minute < 0)
            {
                hour--;
                minute = 59;
            }

            if (hour < 0)
            {
                hour = 0;
                minute = 0;
                second = 0;
            }

            system("cls");

            cout << l1 << t5 << "|----------------------------------------|";
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5 << "|                T I M E R               |";
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5 << "|----------------------------------------|";
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5;
            printf("|              %.2d : %.2d : %.2d              |", hour, minute, second);
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5 << "|                                        |";
            cout << l1 << t5 << "|----------------------------------------|";

            if (hour == 0 && minute == 0 && second == 0)
            {
                system("cls");

                cout << t5 << "TIME ENDS" << l3;
                for (int i = 0; i < 10; i++)
                    Beep(555, 555);

                exit(0);
            }

            Sleep(delay);
        }
    }
    return 0;
}