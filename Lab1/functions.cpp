#include "functions.h"

using namespace std;


void LessLen(vector<string> words, int length, int len)
{
  int spaces = (abs)(length - len) / 2;
  for (int j = 0; j < spaces; j++)
    cout << " ";
  for (auto i : words)
    cout << i << " ";
  for (int j = 0; j < spaces - 1; j++)
    cout << " ";
  cout << "\n";
}

void Equal(vector<string> words)
{
  for (auto i : words)
    cout << i << " ";
  cout << "\n";
}

void TextToCenter(string str, int length)
{
  int sum = 0;
  int len = str.length();
  istringstream iss(str);
  vector<string> words;
  copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string>>(words));
  if (len == length)
  {
    Equal(words);
  }
  else if (len < length)
  {
    LessLen(words, length, len);
  }
  else if (len > length)
  {
    for (auto i : words)
    {
      vector<string> tmp;
      if (sum + i.length() <= (unsigned int)length)
      {
        sum += i.length();
        tmp.push_back(i);
      }
      else
      {
        const char* let = i.c_str();
        int k = 0;
        while ((int)strlen(let) - k >= length)
        {
          for (int j = 0; j < length; j++)
          {
            cout << let[k];
            k++;
          }
          cout << "\n";
        }
        if (strlen(let) - k < (unsigned int)length)
        {
          const int relen = strlen(let) - k;
          int spaces = (length - relen) / 2;
          for (int j = 0; j < spaces; j++)
            cout << " ";
          for (int j = k; j < (int)strlen(let); j++)
          {
            cout << let[j];
          }
          for (int j = 0; j < spaces - 1; j++)
            cout << " ";
          cout << "\n";
          break;
        }
      }
      if (sum == length)
      {
        Equal(tmp);
        sum = 0;
      }
      else if (sum < length)
      {
        LessLen(tmp, length, sum);
        sum = 0;
      }
    }
  }
}
