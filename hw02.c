#include <stdio.h>
#include <stdlib.h>

/*
Prints the sizes and possible ranges of four integer data types. 
*/
void print_int_ranges() {
  // These are made up numbers that will not be correct on most systems!
  // TODO correctly compute these values! 
  int short_bytes = sizeof(short), int_bytes = sizeof(int), uint_bytes = sizeof(uint), long_bytes = sizeof(long);

 // long  short_min = -32768,       short_max = 32767;
 // long  int_min   = -2147483648L, int_max   = 2147483647L;
 // long  uint_min  = 0,            uint_max  = 1 << (int_bytes * 8 - 1);
 // long  long_min  = -2147483648L, long_max  = 2147483647L;
    short short_min= 1;
    short short_max;
    int int_min = 1;
    int int_max;
    unsigned int uint_min = 1;
    unsigned uint_max;
    long long_min = 1;
    long long_max;

    short_min = short_min << (short_bytes * 8 - 1);
    short_max = ~short_min;
    int_min = int_min << (int_bytes * 8 - 1);
    int_max = ~int_min;
    uint_min = uint_min << (uint_bytes * 8 - 1);
    uint_max = ~uint_min;
    long_min = long_min << (long_bytes *8 - 1);
    long_max = ~long_min;
  // Keep these exact printf commands :)   
  printf("short is %d bytes or %d bits and ranges from %ld to %ld\n",
         short_bytes, short_bytes * 8, short_min, short_max);
  printf("int is %d bytes or %d bits and ranges from %ld to %ld\n",
         int_bytes, int_bytes * 8, int_min, int_max);
  printf("long is %d bytes or %d bits and ranges from %ld to %ld\n",
         long_bytes, long_bytes * 8, long_min, long_max);
  printf("unsigned int is %d bytes or %d bits and ranges from %ld to %ld\n",
         uint_bytes, uint_bytes * 8, uint_min, uint_max);
}

/*
Takes in an integer value v and a integer bit index i
Returns 1 if bit i in value v equals 1
Returns 0 if bit i in value v equals 0
*/
int is_bit_set(unsigned char v, unsigned char i) {
  int mask = 1 << i;
  if (i >= sizeof(unsigned char) * 8) {
    fprintf(stderr, "Index out of range!\n");
    return 0;
  }
  else if((v & mask) == 0){
    return 0;
  }
    else{
    return 1;
  }
  /*
  TODO your implementation goes here!
  */

}

/*
Don't touch anything in main!
*/
int main(int argc, char* argv[])
{
  if (argc < 3) {
    fprintf(stderr, "Not enough arguments!\n");
    return -1;  
  }

  print_int_ranges();
  
  unsigned char value = atoi(argv[1]);
  unsigned char bit = atoi(argv[2]);
  int is_set = is_bit_set(value, bit);
  switch(is_set) {
    case 1:
      printf("Bit %u in value %u is set\n", bit, value);
      break;
    case 0:
      printf("Bit %u in value %u is not set\n", bit, value);
      break;
    default:
      fprintf(stderr, "is_bit_set returned an invalid value!\n");
  } 
  
  return 0;
}
