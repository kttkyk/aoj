#include <iostream>

using namespace std;


struct node {
    int p, l, r;
};


node nodes[40];
int pre[40];
int ino[40];


void recon(int r)
{

}


int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ino[i];
    }
}
