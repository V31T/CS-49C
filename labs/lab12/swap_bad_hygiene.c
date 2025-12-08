int printf(const char * restrict format, ... );

#define SWAP(a,b) { int tmp=a; a=b; b=tmp; }

int main(int argc, const char* argv[]) {
  int x = 4, tmp = 5;
  printf("x=%d, tmp=%d\n", x, tmp);
  SWAP(x,tmp);
  printf("x=%d, tmp=%d\n", x, tmp);
}


