#include <iostream>
#include <cstring>

using namespace std;


#define M 1046527


char table[M][16];


unsigned int h1(unsigned int key)
{
    return key % M;
}


unsigned int h2(unsigned int key)
{
    return 1 + (key % (M - 1));
}


unsigned int h(unsigned int key, unsigned int i)
{
    return (h1(key) + i * h2(key)) % M;
}


int str_to_int(char str[])
{
    char *p = str;
    int ret = 0;
    while (*p) {
        ret += (int)(*p++ - 'A');
        ret *= 26;
    }
    return ret;
}


void insert(char str[])
{
    int v = str_to_int(str);
    unsigned int hash;
    int i = 0;
    do {
        hash = h(v, i++);
    } while(strlen(table[hash]) != 0);

    strcpy(table[hash], str);
}


bool search(char str[])
{
    int v = str_to_int(str);
    unsigned int hash;
    int i = 0;
    do {
        hash = h(v, i++);
        if (strcmp(table[hash], str) == 0)
            return true;
    } while(strlen(table[hash]) != 0);
    return false;
}


int main()
{
    memset(table, 0, M * 16);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        char str[16];
        cin >> str;

        if (cmd[0] == 'i')
            insert(str);
        else if (cmd[0] == 'f') {
            if (search(str))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
}
