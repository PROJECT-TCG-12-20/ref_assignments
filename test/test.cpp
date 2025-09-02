#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Level
{
private:
    // int length; For Now it is bydefault 5;
    char matrixChart[5][5];
    static int queensCount;

public:
    Level()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                matrixChart[i][j] = ' ';
            }
        }
    }
    void view()
    {
        cout << endl;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << "[" << matrixChart[i][j] << "]" << " ";
            }
            cout << endl;
        }
    }
    void markCross(int i, int j)
    {
        matrixChart[i - 1][j - 1] = 'x';
        this->view();
    }
    void markQueen(int i, int j)
    {
        if (queensCount >= 5)
        {
            cout << "Game Over Exit Now!!!" << endl;
            return;
        }
        --i;
        --j;
        // check if correct
        static unordered_map<int, int> iBlackList;
        static unordered_map<int, int> jBlackList;

        if (iBlackList.find(i) != iBlackList.end() || jBlackList.find(j) != jBlackList.end())
        {
            cout << "Bad Location" << endl;
            this->view();
            return;
        }
        else
        {
            iBlackList[i]++;
            jBlackList[j]++;

            // for (auto it : iBlackList)
            //     cout << "iBlackList: " << it.first << endl;
            // for (auto it : jBlackList)
            //     cout << "jBlackList: " << it.first << endl;
            matrixChart[i][j] = 'Q';
            queensCount++;
            this->view();
        }
    }
};
int Level::queensCount = 0;

int main()
{
    Level l5;
    int i, j;
    int choice;
    l5.view();
    while (choice)
    {
        cout << "0. Exit" << endl
             << "1. markCross" << endl
             << "2. markQueen" << endl
             << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Location {i,j} :";
            cin >> i >> j;
            l5.markCross(i, j);
            break;
        case 2:
            cout << "Enter Location {i,j} :";
            cin >> i >> j;
            l5.markQueen(i, j);
            break;

        default:
            break;
        }
    }

    // cout<<"Enter your choice location"
    return 0;
}   