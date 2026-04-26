#include <iostream>
#include <string>
using namespace std;

unsigned int curHour = 0;
unsigned int curMinute = 0;
unsigned int curSecond = 0;


// --------------------
// Getters and Setters
// --------------------
unsigned int getHour() { return curHour; }
unsigned int getMinute() { return curMinute; }
unsigned int getSecond() { return curSecond; }

void setHour(unsigned int h) { curHour = h; }
void setMinute(unsigned int m) { curMinute = m; }
void setSecond(unsigned int s) { curSecond = s; }

// --------------------
// Utility Functions
// --------------------
string twoDigit(unsigned int n) {
    return (n < 10) ? ("0" + to_string(n)) : to_string(n);
}

string repeatChar(size_t n, char c) {
    return string(n, c);
}

// --------------------
// Time formatting
// --------------------
string to24Hour(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigit(h) + ":" + twoDigit(m) + ":" + twoDigit(s);
}

string to12Hour(unsigned int h, unsigned int m, unsigned int s) {
    string meridian = (h < 12) ? "A M" : "P M";
    unsigned int hour12 = h % 12;
    if (hour12 == 0) hour12 = 12;
    return twoDigit(hour12) + ":" + twoDigit(m) + ":" + twoDigit(s) + " " + meridian;
}

// --------------------
// Time increment functions
// --------------------
void addHour() {
    if (curHour < 23) curHour++;
    else curHour = 0;
}

void addMinute() {
    if (curMinute < 59) curMinute++;
    else {
        curMinute = 0;
        addHour();
    }
}

void addSecond() {
    if (curSecond < 59) curSecond++;
    else {
        curSecond = 0;
        addMinute();
    }
}

// --------------------
// Display clocks
// --------------------
void showClocks() {
    // Top border
    cout << repeatChar(27, '*') << "   " << repeatChar(27, '*') << endl;

    // Titles
    cout << "*" << repeatChar(6, ' ') << "12-HOUR CLOCK" << repeatChar(6, ' ') << "*   ";
    cout << "*" << repeatChar(6, ' ') << "24-HOUR CLOCK" << repeatChar(6, ' ') << "*" << endl;

    cout << endl;

    // Times
    cout << "*" << repeatChar(6, ' ') << to12Hour(curHour, curMinute, curSecond) << repeatChar(7, ' ') << "*   ";
    cout << "*" << repeatChar(8, ' ') << to24Hour(curHour, curMinute, curSecond) << repeatChar(9, ' ') << "*" << endl;

    // Bottom border
    cout << repeatChar(27, '*') << "   " << repeatChar(27, '*') << endl;
}

// --------------------
// Menu display
// --------------------
void displayMenu(char* options[], unsigned int count, unsigned int lineWidth) {
    cout << repeatChar(lineWidth, '*') << endl;

    for (unsigned int i = 0; i < count; i++) {
        string entry = to_string(i + 1) + " - " + options[i];
        unsigned int spaces = lineWidth - 3 - entry.length(); // 3 = "* " + "*"
        cout << "* " << entry << repeatChar(spaces, ' ') << "*" << endl;
        if (i != count - 1) cout << endl;
    }

    cout << repeatChar(lineWidth, '*') << endl;
}

// --------------------
// Get user choice
// --------------------
unsigned int getChoice(unsigned int maxOption) {
    unsigned int choice;
    while (true) {
        cin >> choice;
        if (choice >= 1 && choice <= maxOption) return choice;
    }
}

// --------------------
// Main menu logic
// --------------------
void mainMenu() {
    char* menuItems[] = {
        (char*)"Add One Hour",
        (char*)"Add One Minute",
        (char*)"Add One Second",
        (char*)"Exit Program"
    };

    unsigned int userChoice = 0;

    while (userChoice != 4) {
        showClocks();
        displayMenu(menuItems, 4, 26);
        userChoice = getChoice(4);

        if (userChoice == 1) addHour();
        else if (userChoice == 2) addMinute();
        else if (userChoice == 3) addSecond();
    }
}

// --------------------
// main()
// --------------------
int main() {
    mainMenu();
    return 0;
}