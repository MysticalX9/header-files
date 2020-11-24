#include <bitset>

// count total bits
int countbits(int value) {
  return log2(value)+1;
}

// count set or unset bits
int countbitstates(int value, int state) {
  int t = 0;
  while(value) {
    if((value&1) ^ !state) t++;
    value >>= 1;
  }
  return t;
}

// count set bits
int countsetbits(int value) {
  return countbitstates(value, 1);
}

// count unset bits
int countunsetbits(int value) {
  return countbitstates(value, 0);
}

// get bit by index
int getbit(int value, int index) {
  return (value >> (countbits(value)-index-1)) & 1;
}

// set or unset bit by index
int setbit(int value, int index, int state) {
  int pivot = countbits(value)-index;
  int l = value >> pivot << pivot;
  int r = 0;

  for(int i = 0; i < pivot-1; i++) {
    r += (value&1) << i;
    value >>= 1;
  }
  r += state << (pivot-1);
  
  return l + r;
}
