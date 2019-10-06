#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

int answer(int maro[],int &NoF, int &MaxF)
{
  int best = 0;
  for (int i = 0; i < NoF; i++)
  {
    int stomach = 0, count = 0;
    for (int j = i; j < NoF; j++)
    {
        if (maro[j] <= MaxF - stomach)
        {
            count++;
            stomach += maro[j];
        }

        if (stomach == MaxF)
        {
            break;
        }
    }
    if (count > best)
    {
        best = count;
    }
  }
  return best;
}

void test()
{
  int x = 5, y = 10;
  int test[] = {4, 5, 2, 1, 3};
  assert(answer(test, x, y) == 3);

  int a = 5, b = 1;
  int test2[] = {5, 3, 4, 6, 1};
  assert(answer(test2, a, b) == 1);

  int c = 10, d = 0;
  int test3[] = {4, 3, 1, 2, 5, 3, 8, 9, 10};
  assert(answer(test3, c, d) == 0);

  cout << "All test cases passed..." << endl;
}

void kattis()
{
  int NoF, MaxF, best, stomach, count, fruit;
  cin >> NoF >> MaxF;
  int maro[NoF];
  for (int i = 0; i < NoF; i++)
  {
    cin >> maro[i];
  }

  cout << answer(maro, NoF, MaxF);
}


int main(int argc, char* argv[])
{
  if (argc > 1 && strncmp(argv[1], "test", 4) == 0) //argument to be used for testing
      test();
  else
      kattis();
  return 0;
}




























/*int main()
{
  int NoF, MaxF, best, stomach, count, fruit;
  cin >> NoF >> MaxF;
  int arr[NoF];
  for (int i = 0; i < NoF; i++)
  {
    cin >> arr[i];
  }
  best = 0;
  for (int i = 0; i < NoF; i++)
  {
    stomach = 0;
    count = 0;
    for (int j = i; j < NoF; j++)
    {
        if (arr[j] <= MaxF - stomach)
        {
            count++;
            stomach += arr[j];
        }

        if (stomach == MaxF)
        {
            break;
        }
    }
    if (count > best)
    {
        best = count;
      }
}
cout << best << endl;
return 0;
}
*/
