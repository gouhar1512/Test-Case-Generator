#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class TestCaseGenerator;
class RandomNumber;

typedef TestCaseGenerator TCGen;
typedef RandomNumber RN;

class TestCaseGenerator {
  public:
    int numberOfTestCases;

  TestCaseGenerator() {
    numberOfTestCases = 0;
  }
  TestCaseGenerator(int t) {
    numberOfTestCases = t;
  }~TestCaseGenerator() {}
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

  int get() {
    return value;
  }

  void set(int x) {
    value = x;
  }

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

  char get() {
    return value;
  }
  friend ostream & operator << (ostream & out,
    const RandomChar & obj);
};

class RandomFloat: public RandomValue {
  private: float value;
  public: RandomFloat() {
    value = 0.0;
  }
  RandomFloat(float maxm): RandomValue(maxm) {
    float f = (float)(rand() % 10) / (float)(100);
    value = (float)(RandomValue::value);
    value = value - value * f;

  }
  RandomFloat(float minm, float maxm): RandomValue(minm, maxm) {
    float f = (float)(rand() % 10) / (float)(100);
    value = (float)(RandomValue::value);
    value = value - value * f;
  }~RandomFloat() {}

  float get() {
    return value;
  }
  friend ostream & operator << (ostream & out,
    const RandomFloat & obj);
};

class RandomIntArray {
  private:
    int * arr;
  int size;

  public:
    RandomIntArray() {
      arr = NULL;
      size = 0;
    }
  RandomIntArray(int n, int maxm) {
    size = n;
    arr = (int * ) malloc(n * sizeof(int));
    for (int i = 0; i < size; i++) {
      arr[i] = RandomInt(maxm).get();
    }
  }
  RandomIntArray(int n, int minm, int maxm) {
    size = n;
    arr = (int * ) malloc(n * sizeof(int));
    for (int i = 0; i < size; i++) {
      arr[i] = RandomInt(minm, maxm).get();
    }
  }~RandomIntArray() {}

  friend ostream & operator << (ostream & out,
    const RandomIntArray & obj);
};

class RandomCharArray {
  private:
    char * arr;
  int size;

  public:
    RandomCharArray() {
      arr = NULL;
      size = 0;
    }
  RandomCharArray(int n, char maxm) {
    size = n;
    arr = (char * ) malloc(n * sizeof(char));
    for (int i = 0; i < size; i++) {
      arr[i] = RandomChar(maxm).get();
    }
  }
  RandomCharArray(int n, char minm, char maxm) {
    size = n;
    arr = (char * ) malloc(n * sizeof(char));
    for (int i = 0; i < size; i++) {
      arr[i] = RandomChar(minm, maxm).get();
    }
  }~RandomCharArray() {}

  friend ostream & operator << (ostream & out,
    const RandomCharArray & obj);
};

class RandomFloatArray {
  private:
    float * arr;
  int size;

  public:
    RandomFloatArray() {
      arr = NULL;
      size = 0;
    }
  RandomFloatArray(int n, float maxm) {
    size = n;
    arr = (float * ) malloc(n * sizeof(float));
    for (int i = 0; i < size; i++) {
      arr[i] = RandomFloat(maxm).get();
    }
  }
  RandomFloatArray(int n, float minm, float maxm) {
    size = n;
    arr = (float * ) malloc(n * sizeof(float));
    for (int i = 0; i < size; i++) {
      arr[i] = RandomFloat(minm, maxm).get();
    }
  }~RandomFloatArray() {}

  friend ostream & operator << (ostream & out,
    const RandomFloatArray & obj);
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
  const RandomIntArray & obj) {
  for (int i = 0; i < obj.size; i++) {
    out << obj.arr[i] << ' ';
  }
  return out;
}

ostream & operator << (ostream & out,
  const RandomCharArray & obj) {
  for (int i = 0; i < obj.size; i++) {
    out << obj.arr[i] << ' ';
  }
  return out;
}

ostream & operator << (ostream & out,
  const RandomFloatArray & obj) {
  for (int i = 0; i < obj.size; i++) {
    out << obj.arr[i] << ' ';
  }
  return out;
}

void solve() {
  RandomFloatArray b(10, 6, 10);
  cout << b << endl;
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