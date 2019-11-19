void inplace_swap(int *x, int *y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

int main() {
  int x = 4;  // 0100
  int y = 10; // 1010

  inplace_swap(&x, &y);
  return 0;
}
