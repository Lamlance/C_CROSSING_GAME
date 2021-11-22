#include "GUI.h"
void gameIntro() {
    HANDLE handle;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 11);
    carrunning car;
    carrunning car1;
    carrunning car2;
    carrunning car3;
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
        std::cout << "\n\n                                                   Loanding " << k << "%\n";
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
        car.x += 4;
        car1.x += 4;
        car2.x += 4;
        car3.x += 4;
        k += 4;
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