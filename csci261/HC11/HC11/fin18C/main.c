short int foo(short int, short int);
void increment(unsigned char*);

volatile unsigned char c;

unsigned char main() {
  short int c;
  c=foo(4,5);
  c = 23;
  increment(&c);
  return (0);
}

short int foo(short int i, short int j) {
   return (i+j+3);  
}

void increment(unsigned char* a) {
   *a = *a + 1;
}
