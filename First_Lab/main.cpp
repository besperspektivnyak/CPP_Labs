#include "functions.h"


int main(void)
{
  int length;
  string name, str;
  cin >> name;
  cin >> length;
  ifstream file(name);
  while (getline(file, str))
  {
    TextToCenter(str, length);
  }
  system("pause");
  return 0;
}