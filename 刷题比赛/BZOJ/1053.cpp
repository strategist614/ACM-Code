#include<bits/stdc++.h>
using namespace std;
const int N = 2e9;
const int prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int main ()
{
  int maxn = 0;
  for (int i = 2; i <= N; i++)
  {
    int tmp = 1;
    int _ = i;
    for (int j = 1; j <= 10; j++)
    {
      int cnt = 0;
      while (_ % prime[j] == 0)
      {
        _ /= prime[j];
        cnt++;
      }
      tmp *= (cnt + 1);
      if (_ == 1) break;
    }
    if (tmp > maxn)
    {
      cout << i << endl;
      maxn = tmp;
    }
  }
  return 0 ;
}
#include<bits/stdc++.h>
using namespace std;
int a[] = {1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200,
           332640, 498960, 554400, 665280, 720720, 1081080, 1441440, 2162160, 2882880, 3603600,
           4324320, 6486480, 7207200, 8648640, 10810800, 14414400, 17297280, 21621600, 32432400,
           36756720, 43243200, 61261200, 73513440, 110270160, 122522400, 147026880, 183783600, 245044800, 294053760, 367567200, 551350800, 735134400, 1102701600
           , 1396755360
          };
int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= 67; i++)
  {
    if (n < a[i])
    {
      cout << a[i - 1] << endl;
      //cout<<1;
      return 0;
    }
  }
  cout << a[66] << endl;
  return 0 ;
}