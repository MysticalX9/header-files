#include <math.h>

// count total bits
template<class T>
T countbits(T value) {
  return log2(value)+1;
}

// count set or unset bits
template<class T>
T countbitstates(T value, T state) {
  T t = 0;
  while(value) {
    if((value&1) ^ !state) t++;
    value >>= 1;
  }
  return t;
}

// count set bits
template<class T>
T countsetbits(T value) {
  return countbitstates(value, 1);
}

// count unset bits
template<class T>
T countunsetbits(T value) {
  return countbitstates(value, 0);
}

// get bit by index
template<class T>
T getbit(T value, T index) {
  return (value >> (countbits(value)-index-1)) & 1;
}

// set or unset bit by index
template<class T>
T setbit(T value, T index, T state) {
  T pivot = countbits(value)-index;
  T l = value >> pivot << pivot;
  T r = 0;

  for(T i = 0; i < pivot-1; i++) {
    r += (value&1) << i;
    value >>= 1;
  }
  r += state << (pivot-1);
  
  return l + r;
}

int main() {
  std::cout << std::bitset<8>(setbit(0b10001010, 2, 1)) << std::endl;

  // Program output:
  // 10101010

  return 0;
}
