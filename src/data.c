#include <stdint.h>
#include "data.h"
#include "memory.h"


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  uint8_t i = 0;
  int8_t negative = 1; // -1 if data is negative

  /* Handle 0 explicitely, otherwise empty string is printed for 0 */
  if (data == 0)
  {
    *(ptr + i++) = '0';
    *(ptr + i) = '\0';
    return *ptr;
  }

  if (data < 0)
  {
    negative = -1;
    data = -data;
  }

  *(ptr + i++) = '\0';

  while (data != 0)
  {
    int rem = data % base;

    if (rem > 9)
    {
      *(ptr + i) = rem - 10 + 'a';
    } else {
      *(ptr + i) = rem + '0';
    }

    data = data/base; 
    i++;
  } 

  // If number is negative, append '-' 
  if (negative == -1)
      *(ptr + i) = '-';

  my_reverse(ptr, i);
  i++;

  // Return reversed string
  return i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  uint8_t i = 0;
  int8_t negative = 1; // -1 if data is negative
  int32_t data = 0;

  if (*ptr == '-')
  {
    negative = -1;
    i++;
    digits--;
  }

  for ( ; i < digits; i++)
  {
    data = data * base + *(ptr + i) - '0';
  }

  return negative*data;
}
