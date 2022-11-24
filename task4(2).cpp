#include <iostream>
#include <string>

using namespace std;

struct Memory
{
    unsigned month : 4;
    unsigned hour : 5;
    unsigned day : 5;
    unsigned minute : 6;
    unsigned year : 12;
};

int main()
{
    int size;
    int* data = new int[5];

    string s, num = "";
    cout << "Input time and date: " << "\n";
    getline(cin, s);
    int i = 0;
    for (char& chr : s)
    {
        if (isspace(chr))
            data[i] = stoi(num), num = "", i++;
        else
            num += chr;
    }

    Memory Mem;
    Mem.hour = data[0];
    Mem.minute = data[1];
    Mem.day = data[2];
    Mem.month = data[3];
    Mem.year = data[4];

    cout << "Date: " << "\n";
    cout << "" << Mem.hour << ":" << Mem.minute << " " << Mem.day << "." << Mem.month << "." << Mem.year;
    cout << "\n";
}
