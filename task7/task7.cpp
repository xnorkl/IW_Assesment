#include <iostream>
using namespace std;
int main() {
  int Result=0;
  for (int index=0; index < 100; index++) {
    cout << "index: " << index << endl;
    if (index % 2 == 0) {
      Result+=index;
    }
    cout << "result: " << Result << endl;
  }
  return 0;
}
