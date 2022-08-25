/*
To celebrate your birthday you have prepared a festive table! Now you want to seat as 
many guests as possible.

The table can be represented as a rectangle with height h and width w, divided into 
h×w cells. Let (i,j) denote the cell in the i-th row and the j-th column of the 
rectangle (1≤i≤h; 1≤j≤w).

Into each cell of the table you can either put a plate or keep it empty.

As each guest has to be seated next to their plate, you can only put plates on the
 edge of the table — into the first or the last row of the rectangle, or into the 
 first or the last column. Formally, for each cell (i,j) you put a plate into, at 
 least one of the following conditions must be satisfied: i=1, i=h, j=1, j=w.

To make the guests comfortable, no two plates must be put into cells that have a 
common side or corner. In other words, if cell (i,j) contains a plate, you can't 
put plates into cells (i−1,j), (i,j−1), (i+1,j), (i,j+1), (i−1,j−1), (i−1,j+1), (i+1,j−1), (i+1,j+1).

Put as many plates on the table as possible without violating the rules above.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int h, w;
        cin >> w >> h;
        vector<int> v[w];
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                if (j % 2 == 0 && (i == 0 || i == w - 1))
                {
                    v[i].push_back(1);
                }
                else
                {
                    v[i].push_back(0);
                }
            }
        }
        for (int i = 1; i < w - 1; i++)
        {
            for (int j = 0; j < h; j++)
            {
                if (j == h - 1 &&
                    v[i - 1][j] != 1 && v[i + 1][j] != 1 &&
                    v[i - 1][j - 1] != 1 && v[i + 1][j - 1] != 1)
                {
                    v[i].at(j) = 1;
                }
                else if (j == 0 &&
                         v[i - 1][j] != 1 && v[i + 1][j] != 1 &&
                         v[i - 1][j + 1] != 1 && v[i + 1][j + 1] != 1)
                {
                    v[i].at(j) = 1;
                }
                else
                {
                    v[i].at(j) = 0;
                }
            }
        }
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; ++j)
            {
                cout << v[i].at(j);
            }
            cout << "\n";
        }
    }
}