#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n;
     cout << "Enter Size of Matrix: ";
     cin >> n;

     cout << "Entering Non Zero elements of Symmetrix Matrix: ";

     int arr[n * (n + 1) / 2];

     for (int i = 0; i < n * (n + 1) / 2; i++)
     {
          cin >> arr[i];
     }

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               if (i == j)
               {
                    cout << arr[((i * (i + 1)) / 2) + i] << " ";
               }
               else if (i > j)
               {
                    cout << arr[((i * (i + 1)) / 2) + j] << " ";
               }
               else
               {
                    cout << arr[((j * (j + 1)) / 2) + i] << " ";
               }
          }
     }
}
