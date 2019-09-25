#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#include <cstring>
using namespace std;

int answer(vector<int> vect, vector<int> vect1)
{
vector <int> ans;
set_intersection(vect.begin(), vect.end(), vect1.begin(), vect1.end(), back_inserter(ans));
return ans.size();
}

void kattis()
{
  int N, M;
  while (cin >> N >> M && N!=0 && M!=0)
  {
    vector<int> vect, vect1, ans;
    int temp;
  for (int i = 0; i <N; i++)
  {
  cin >> temp;
  vect.push_back(temp);
  }

  for (int i = 0; i < M; i++)
    {
      cin >> temp;
      vect1.push_back(temp);
    }
    cout << answer(vect,vect1) << endl;
  }
}

void test()
{

  vector<int>Jill = {3, 5, 1};
  vector<int>Jack = {4, 5, 2};
  assert(answer(Jill, Jack) == 1);

  vector<int>Jill2 = {4, 9, 3, 1};
  vector<int>Jack2 = {4, 9, 3, 1};
  assert(answer(Jill2, Jack2) == 4);

  vector<int>Jill3 = {2, 3, 5};
  vector<int>Jack3 = {1, 2, 3};
  assert(answer(Jill3, Jack3) == 2);

  cout << "All test cases passed...";
}

  int main(int argc, char* argv[])
  {
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
        test();
    else
        kattis();
    return 0;
  }



/*int main()
{
  int N, M;

  while (cin >> N >> M && N!=0 && M!=0)
  {
    vector<int> vect, vect1, ans;

    int temp;
    for (int i = 0; i <N; i++)
    {
    cin >> temp;
    vect.push_back(temp);
    }

    for (int i = 0; i < M; i++)
      {
        cin >> temp;
        vect1.push_back(temp);
      }
      set_intersection(vect.begin(), vect.end(), vect1.begin(), vect1.end(), back_inserter(ans));
      cout << ans.size() << endl;
    }
}*/
