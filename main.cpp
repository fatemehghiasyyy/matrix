#include <iostream>

using namespace std;

int   fibonachi(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonachi(n - 1) + fibonachi(n - 2);
  }
}

int main() {
  int n;
  cout << "Enter the number : ";
  cin >> n;

  if (n <= 0) {
    cout << "Please enter a positive integer." << endl;
  } else {
    for (int i = 0; i < n; ++i) {
      cout << fibonachi(i) << " ";
    }
    cout << endl;
  }
  return 0;
}
