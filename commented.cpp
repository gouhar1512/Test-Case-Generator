
// class RandomArray {
//   private:
//   int randomize(int maxm) {
//     // [0 to maxm]
//     return (rand() % (maxm + 1));
//   }
//   public:
//     int size;
//     friend ostream & operator << (ostream & out,
//       const RandomArray & c);

//   RandomArray() {
//     size = 0;
//   }
  // RandomArray(int n, int maxm) {
  //   size = n;
  //   arr = (int * ) malloc(n * sizeof(int));
  //   for (int i = 0; i < n; i++) {
  //     arr[i] = randomize(abs(maxm));
  //     if (maxm < 0) arr[i] *= -1;
  //   }
  // }

  // RandomArray(int n, int minm, int maxm) {
  //   size = n;
  //   arr = (int * ) malloc(n * sizeof(int));
  //   for (int i = 0; i < n; i++) {
  //     arr[i] = minm + (rand() % (maxm - minm + 1));
  //     if (maxm < 0) arr[i] *= -1;
  //   }
  // }
//   ~RandomArray() {}
// };