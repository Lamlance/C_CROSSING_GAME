#include "GUI.h"
#include <vector>
#include <conio.h>
void gameIntro(HANDLE handle) {
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    object car;
    object car1;
    object car2;
    object car3;
    strcpy_s(car.t, "  ______");
    strcpy_s(car1.t, " /|_||_\\`.");
    strcpy_s(car2.t, "(   _    _ _\\");
    strcpy_s(car3.t, "=`-(_)--(_)-'");
    car.x = 0;
    car.y = 20;
    car1.x = 0;
    car1.y = 21;
    car2.x = 0;
    car2.y = 22;
    car3.x = 0;
    car3.y = 23;
    int k = 0;
    while (1) {
        SetConsoleTextAttribute(handle, 12);
        std::cout << "\n\n\n";
        std::cout << "                        ___       ___      ___       ___      ___       ___      _  _      ___                  \n";
        std::cout << "               o O O   / __|     | _ \\    / _ \\     / __|    / __|     |_ _|    | \\| |    / __|      o O O      \n";
        std::cout << "              o       | (__      |   /   | (_) |    \\__ \\    \\__ \\      | |     | .` |   | (_ |     o        \n";
        std::cout << "             GR__[4]   \\___|     |_|_\\    \\___/     |___/    |___/     |___|    |_|\\_|    \\___|    GR__[4]      \n";
        std::cout << "            {======| _|'''''| _ |'''''| _|'''''| _ |'''''| _|'''''| _ |'''''| _|'''''| _ |'''''|  {======|      \n";
        std::cout << "           ./o--000' '`-0-0-   '`-0-0-' '`-0-0-'  '`-0-0- ''`-0-0-'  '`-0-0-' '`-0-0-'  '`-0-0-' ./o--000'      \n";
        std::cout << "                                            ___      ___     __  __     ___                                  \n";
        std::cout << "               o O O     o O O     o O O   / __|    /   \\   |  \\/  |   | __|      o O O     o O O     o O O  \n";
        std::cout << "              o         o         o       | (_ |    | - |   | |\\/| |   | _|      o         o         o       \n";
        std::cout << "             GR__[4]   GR__[4]   GR__[4]   \\___|    |_|_|   |_|__|_|   |___|    GR__[4]   GR__[4]   GR__[4]  \n";
        std::cout << "            {======|  {======|  {======| _|'''''| _|'''''| _|'''''| _ |'''''|  {======|  {======|  {======|  \n";
        std::cout << "           ./o--000' ./o--000' ./o--000' '`-0-0-' '`-0-0-'  `-0-0-'  '`-0-0-' ./o--000' . / o--000' ./o--000'  \n";
        if ((car.x + 4 >= consoleWidth)) k = 100;
        std::cout << "\n\n                                                   Loanding ";
        SetConsoleTextAttribute(handle, 11);
        std::cout << k;
        SetConsoleTextAttribute(handle, 12);
        std::cout << " %\n";
        SetConsoleTextAttribute(handle, 11);
        gotoxy(car.x, car.y);
        printf("%s", car.t);
        std::cout << "\n";
        gotoxy(car1.x, car1.y);
        printf("%s", car1.t);
        std::cout << "\n";
        gotoxy(car2.x, car2.y);
        printf("%s", car2.t);
        std::cout << "\n";
        gotoxy(car3.x, car3.y);
        printf("%s", car3.t);
        car.x += 7;
        car1.x += 7;
        car2.x += 7;
        car3.x += 7;
        k += 7;
        Sleep(300);
        cls(handle);
        if (car.x >= consoleWidth) break;
    }


}
void cls(HANDLE hConsole)
{
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.
    if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
        (TCHAR)' ',      // Character to write to the buffer
        dwConSize,       // Number of cells to write
        coordScreen,     // Coordinates of first cell
        &cCharsWritten)) // Receive number of characters written
    {
        return;
    }

    // Get the current text attribute.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    // Set the buffer's attributes accordingly.
    if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
        csbi.wAttributes, // Character attributes to use
        dwConSize,        // Number of cells to set attribute
        coordScreen,      // Coordinates of first cell
        &cCharsWritten))  // Receive number of characters written
    {
        return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hConsole, coordScreen);
}

void gotoxy(short x, short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x, y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}



void box(int x, int y, HANDLE handle, int& select) {
    std::vector <chartext> menu_items;
    chartext c, c1, c2, c3, c4;
    strcpy_s(c.t, "          +-+ +-+ +-+ +-+ +-+");
    strcpy_s(c.t2, "          |s| |t| |a| |r| |t|");
    strcpy_s(c.t3, "          +-+ +-+ +-+ +-+ +-+");
    menu_items.push_back(c);
    strcpy_s(c1.t, "    +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+");
    strcpy_s(c1.t2, "    |l| |o| |a| |d| |g| |a| |m| |e|");
    strcpy_s(c1.t3, "    +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+");
    menu_items.push_back(c1);
    strcpy_s(c2.t, "            +-+ +-+ +-+ +-+");
    strcpy_s(c2.t2, "            |r| |u| |l| |e|");
    strcpy_s(c2.t3, "            +-+ +-+ +-+ +-+");
    menu_items.push_back(c2);
    strcpy_s(c3.t, "          +-+ +-+ +-+ +-+ +-+");
    strcpy_s(c3.t2, "          |a| |b| |o| |u| |t|");
    strcpy_s(c3.t3, "          +-+ +-+ +-+ +-+ +-+");
    menu_items.push_back(c3);
    int h = menu_items.size() * 4;
    int w = 50;
    select = 0;
    int y0 = y;
    while (true) {
        cls(handle);
        SetConsoleTextAttribute(handle, 12);
        std::cout << "\n    _________________ _______ _____________________________   ___________       ________________ ______  _____________\n";
        std::cout << "    __  ____/___  __ \\__  __ \\__  ___/__  ___/____  _/___  | / /__  ____/       __  ____/___    |___   |/  /___  ____/\n";
        std::cout << "    _  /     __  /_/ /_  / / /_____ \\ _____ \\  __  /  __   |/ / _  / __         _  / __  __  /| |__  /|_/ / __  __/   \n";
        std::cout << "    / /___   _  _, _/ / /_/ / ____/ / ____/ / __/ /   _  /|  /  / /_/ /         / /_/ /  _  ___ |_  /  / /  _  /___ \n";
        std::cout << "    \\____/   /_/ |_|  \\____/  /____/  /____/  /___/   /_/ |_/   \\____/          \\____/   /_/  |_|/_/  /_/   /_____/   \n";
        SetConsoleTextAttribute(handle, 14);
        gotoxy(x, y);
        std::cout << char(218);
        gotoxy(x + w, y);
        std::cout << char(191);

        for (int i = 0; i < menu_items.size(); i++) {

            if (i == 0) {
                gotoxy(x + 1, y);
                for (int j = x; j <= x + w - 2; j++) {
                    std::cout << char(196);
                }
            }
            if (i == select) {
                SetConsoleTextAttribute(handle, 11);
            }

            gotoxy(x + 5, y + i + 1);
            printf("%s", menu_items[i].t);

            gotoxy(x + 5, y + i + 2);
            printf("%s", menu_items[i].t2);

            gotoxy(x + 5, y + i + 3);
            printf("%s", menu_items[i].t3);
            SetConsoleTextAttribute(handle, 14);
            gotoxy(x, y + i + 1);
            std::cout << char(179);
            gotoxy(x + w, y + i + 1);
            std::cout << char(179);

            gotoxy(x, y + i + 2);
            std::cout << char(179);
            gotoxy(x + w, y + i + 2);
            std::cout << char(179);

            gotoxy(x, y + i + 3);
            std::cout << char(179);
            gotoxy(x + w, y + i + 3);
            std::cout << char(179);
            if (i == menu_items.size() - 1) {
                gotoxy(x, y + 7);
                for (int j = x; j <= x + w - 1; j++) {
                    std::cout << char(196);
                }
                gotoxy(x, y + 7);
                std::cout << char(192);
                gotoxy(x + w, y + 7);
                std::cout << char(217);
                y = y0;
            }
            else y += 2;
        }
        SetConsoleTextAttribute(handle, 11);
        std::cout << "\n\n                                                   _/\\______\\\\__\n";
        std::cout << "                                                  / ,-. -|-  ,-.`-.\n";
        std::cout << "                                                `( o )----( o )-'\n";
        std::cout << "                                                  `-'      `-'\n";
        int key = _getch();
        if ((int)key == 80 || key == 's' || key == 'S') {
            select++;
            if (select > menu_items.size() - 1) select = 0;
        }
        if (key == 72 || key == 'W' || key == 'w') {
            select--;
            if (select < 0) select = menu_items.size() - 1;
        }
        if (key == 13) {
            break;
        }
        cls(handle);
    }
}


void rule(HANDLE handle, int& option) {

    while (true) {
        cls(handle);
        SetConsoleTextAttribute(handle, 14);
        std::cout << "\n\n";
        std::cout << "                                     ______     __  __     __         ______    \n";
        std::cout << "                                    /\\  == \\   /\\ \\/\\ \\   /\\ \\       /\\  ___\\   \n";
        std::cout << "                                    \\ \\  __<   \\ \\ \\_\\ \\  \\ \\ \\____  \\ \\  __\\  \n";
        std::cout << "                                     \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\ \n";
        std::cout << "                                      \\/_/ /_/   \\/_____/   \\/_____/   \\/_____/ \n";
        SetConsoleTextAttribute(handle, 12);
        std::cout << "\n                                                      CONTROL \n";
        SetConsoleTextAttribute(handle, 11);
        std::cout << "                                              ____                   ____ \n";
        std::cout << "                                    UP:      ||W ||        DOWN:    ||S ||\n";
        std::cout << "                                             ||__||                 ||__||\n";
        std::cout << "                                             |/__\\|                 |/__\\|\n";
        std::cout << "                                              ____                   ____ \n";
        std::cout << "                                    LEFT:    ||A ||        RIGHT:   ||D ||\n";
        std::cout << "                                             ||__||                 ||__||\n";
        std::cout << "                                             |/__\\|                 |/__\\|\n";
        std::cout << "\n                                    MOVE UP, DOWN, LEFT, RIGHT TO CROSS THE ROAD\n";
        std::cout << "           WHEN THE RED TRAFFIC LIGHT IS ON, VEHICLES WILL STOP. IF HIT ANIMAL OR VEHICLE, THE GAME IS ENDED\n";
        std::cout << "\n";

        gotoxy(55, 21);
        if (option == 5) {
            SetConsoleTextAttribute(handle, 12);
        }
        std::cout << "EXIT";
        int key = _getch();
        if ((int)key == 80 || key == 's' || key == 'S') {

            option = 5;
        }

        if (key == 13 && option == 5) {

            break;
        }
        SetConsoleTextAttribute(handle, 11);
    }
    cls(handle);
}

void about(HANDLE handle, int& option) {

    while (true) {
        cls(handle);
        SetConsoleTextAttribute(handle, 14);
        std::cout << "\n\n";
        std::cout << "                                      _____ __________ ________   ____ ______________  ____ ___  _________    \n";
        std::cout << "                                    /  _  \\______   \\_____  \ |    |   \__    ___/  |    |   \/   _____/   \n";
        std::cout << "                                   /  /_\  \|    |  _/ /   |   \|    |   / |    |     |    |   /\_____  \  \n";
        std::cout << "                                  /    |    \    |   \/    |    \    |  /  |    |     |    |  / /        \ \n";
        std::cout << "                                  \____|__  /______  /\_______  /______/   |____|     |______/ /_______  / \n";
        std::cout << "                                          \/       \/         \/                                       \/  \n";
        SetConsoleTextAttribute(handle, 11);
        std::cout << "                                                             NGUYEN XUAN HOANG LAM                     \n";
        std::cout << "                                                             TRAN NGUYEN LAN TRINH                     \n";
        std::cout << "                                                               HAN THO NHAT PHU                        \n";
        std::cout << "                                                               TRUONG GIA THINH                        \n";
        std::cout << "\n";
        /*gotoxy(55, 21);
        if (option == 5) {
            SetConsoleTextAttribute(handle, 12);
        }
        std::cout << "EXIT";
        int key = _getch();
        if ((int)key == 80 || key == 's' || key == 'S') {

            option = 5;
        }

        if (key == 13 && option == 5) {

            break;
        }
        SetConsoleTextAttribute(handle, 11);*/
    }
    cls(handle);
}