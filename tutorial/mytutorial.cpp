#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;


string answer(int m, int n, int t)
{
  int factorial = 1;
  int product = n;
  switch (t)
  {
    case 1:
    for(int i = n; i > 0; --i)
      {
        if(factorial > m)
        {
          return "TLE";
        }
        factorial *=i;
      }
    break;

    case 2:
    if (exp2(n) > m)
    {
      return "TLE";
    }

    break;

    case 3:
    for(int i = 1; i < 4; ++i)
    {
      product*=n;
      if(product > m)
      {
        return "TLE";
      }
    }
    break;

    case 4:
    for(int i = 1; i < 3; ++i)
    {
      product*=n;
      if(product > m)
      {
      return "TLE";
      }
    }

    break;

    case 5:
    for(int i = 1; i < 2; ++i)
    {
      product*=n;
      if(product > m)
      {
        return "TLE";
      }
    }

    break;

    case 6:
    if((n*log2(n))>m)
    {
    return "TLE";
    }

    break;

    case 7:
    if(n > m)
    {
      return "TLE";
    }

    break;

  }
  return "AC";
}

void test()
{
  int m = 100000000, n = 500, t = 2;
  int a = 100000000, b = 1000, c = 3;
  int d = 180000000, e = 5, f = 2;

  assert(answer(a,b,c) == "TLE");
  assert(answer(m,n,t) == "TLE");
  assert(answer(d,e,f) == "AC");

  cout << "All test cases passed... " << endl;
}

void kattis()
{
  int m, n, t;
  cin >> m >> n >> t;
  cout << answer(m,n,t);
}

int main(int argc, char* argv[])
{
  if (argc > 1 && strncmp(argv[1], "test", 4) == 0) //argument to be used for testing
      test();
  else
      kattis();
  return 0;
}


/*
int main()
{
  int m, n, t;
  cin >> m >> n >> t;
  int factorial = 1;
  int product = n;
  switch (t)
  {
    case 1:
    for(int i = n; i > 0; --i)
  		{
  			if(factorial > m)
        {
  				cout << "TLE" << endl;
  				return 0;
  			}
  			factorial *=i;
  		}
    break;

    case 2:
    if (exp2(n) > m)
    {
      cout << "TLE" << endl;
      return 0;
    }

    break;

    case 3:
    for(int i = 1; i < 4; ++i)
    {
      product*=n;
      if(product > m)
      {
        cout << "TLE" << endl;
        return 0;
      }
    }
    break;

    case 4:
    for(int i = 1; i < 3; ++i)
    {
      product*=n;
      if(product > m)
      {
        cout << "TLE" << endl;
        return 0;
      }
    }

    break;

    case 5:
    for(int i = 1; i < 2; ++i)
    {
      product*=n;
      if(product > m)
      {
        cout << "TLE" << endl;
        return 0;
      }
    }

    break;

    case 6:
    if((n*log2(n))>m)
    {
      cout << "TLE" << endl;
      return 0;
    }

    break;

    case 7:
    if(n > m)
    {
      cout << "TLE" << endl;
      return 0;
    }

    break;

  }
  cout << "AC" << endl;
  return 0;
}
*/
