#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
int Count(char* s)  //!!!!!!!!!!!!!!!1.3 завдання
{
    bool isI = false, pos = 0;
    char* t;
    while (t = strchr(s + pos, 'n'))
    {
        pos = t - s + 1;
        if (s[pos + 1] == 'o')
            isI = true;
    }
    return isI;
}
char* Change(char* s)
{
    char* t = new char[strlen(s)];
    char* p;
    int pos1 = 0,
        pos2 = 0;
    *t = 0;
    while (p = strchr(s + pos1, 'n'))
    {
        if (s[p - s + 2] == 'o')
        {
            pos2 = p - s + 3;
            strncat(t, s + pos1, pos2 - pos1 - 1);
            strcat(t, "**");
            pos1 = pos2;
        }
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl; //enter divide into parts as example
    cin.getline(str, 100);
    Count(str) ? cout << "Such i exists" : cout << "Such i doesn't exist";
    char* dest = new char[151];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}