#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

using namespace std;

class TestCaseGenerator;
class RandomNumber;
class RandomArray;

typedef TestCaseGenerator TCGen;
typedef RandomNumber RN;
typedef RandomArray RA;

class TestCaseGenerator {
  public:
    int numberOfTestCases;

  TestCaseGenerator() {
    numberOfTestCases = 0;
  }
  TestCaseGenerator(int t) {
    numberOfTestCases = t;
  }~TestCaseGenerator() {

  }
};

class RandomValue {
  private:
    int randomize(int maxm) {
      return (rand() % (maxm + 1));
    }
  public:
    int value;
  RandomValue() {
    value = 0;
  }

  RandomValue(int maxm) {
    value = randomize(abs(maxm));
    if (maxm < 0) value *= -1;
  }

  RandomValue(int minm, int maxm) {
    value = minm + (rand() % (maxm - minm + 1));
  }~RandomValue() {}
};

class RandomInt: public RandomValue {
  private: int value;
  public: RandomInt() {
    value = 0;
  }
  RandomInt(int maxm): RandomValue(maxm) {
    value = (int)(RandomValue::value);
  }
  RandomInt(int minm, int maxm): RandomValue(minm, maxm) {
    value = (int)(RandomValue::value);
  }~RandomInt() {}

  friend ostream & operator << (ostream & out,
    const RandomInt & obj);
};

class RandomChar: public RandomValue {
  private: char value;
  public: RandomChar() {
    value = ' ';
  }
  RandomChar(char maxm): RandomValue(maxm - 'a') {
    value = (char)('a' + RandomValue::value);
  }
  RandomChar(char minm, char maxm): RandomValue(minm - 'a', maxm - 'a') {
    value = (char)('a' + RandomValue::value);
  }~RandomChar() {}
  friend ostream & operator << (ostream & out,
    const RandomChar & obj);
};

class RandomFloat: public RandomValue {
  private: float value;
  public: RandomFloat() {
    value = 0.0;
  }
  RandomFloat(float maxm): RandomValue(maxm) {
    float f = (float)(rand()%10)/(float)(100);
    value = (float)(RandomValue::value);
    value = value - value*f;

  }
  RandomFloat(float minm, float maxm): RandomValue(minm, maxm) {
    float f = (float)(rand()%10)/(float)(100);
    value = (float)(RandomValue::value);
    value = value - value*f;
  }
  ~RandomFloat() {}

  friend ostream & operator << (ostream & out,
    const RandomFloat & obj);
};

class RandomArray {
  private:
    int * arr;
  int size;
  int randomize(int maxm) {
    // [0 to maxm]
    return (rand() % (maxm + 1));
  }
  public:

    friend ostream & operator << (ostream & out,
      const RandomArray & c);

  RandomArray() {
    size = 0;
    arr = NULL;
  }
  RandomArray(int n, int maxm) {
    size = n;
    arr = (int * ) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
      arr[i] = randomize(abs(maxm));
      if (maxm < 0) arr[i] *= -1;
    }
  }

  RandomArray(int n, int minm, int maxm) {
    size = n;
    arr = (int * ) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
      arr[i] = minm + (rand() % (maxm - minm + 1));
      if (maxm < 0) arr[i] *= -1;
    }
  }~RandomArray() {}
};

ostream & operator << (ostream & out,
  const RandomInt & obj) {
  out << obj.value;
}
ostream & operator << (ostream & out,
  const RandomChar & obj) {
  out << obj.value;
}
ostream & operator << (ostream & out,
  const RandomFloat & obj) {
  out << obj.value;
}

ostream & operator << (ostream & out,
  const RandomArray & obj) {
  for (int i = 0; i < obj.size; i++) {
    out << obj.arr[i] << ' ';
  }
  return out;
}

void solve() {
  RandomFloat a(7.0, 8.0);
  cout << a << endl;

}

int main() {

  //for random value every time
  srand(time(NULL));

  for (int t = 0; t < 10; t++)
    solve();

  return 0;
}

/*
	How to write class prototype for derived class?
	How to use cerr
  To make RandomFloat better for ranges
*/