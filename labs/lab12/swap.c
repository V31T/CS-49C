int printf(const char * restrict format, ... );

#define SWAP(a,b) { int tmp=a; a=b; b=tmp; }

int main(int argc, const char* argv[]) {
  int x = 4, y = 5;
  printf("x=%d, y=%d\n", x, y);
  SWAP(x,y);
  printf("x=%d, y=%d\n", x, y);
}


