#include <stdint.h>
#include "data.h"
#include "memory.h"

#include "platform.h" // FOR DEBUGGING


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  uint8_t count = 0; // track number of digits in data
  int8_t negative = 1; // -1 if data is negative

  /* Handle 0 explicitly, otherwise empty string is printed for 0 */
  if (data == 0)
  {
    *ptr = '0';
    count++;
    *(ptr + count) = '\0';
    return 1;
  }

  if (data < 0)
  {
    negative = -1;
    data = -data;
  }

  *ptr = '\0';
  count++;

  while (data != 0)
  {
    int32_t rem = data % base;

    if (rem > 9)
    {
      *(ptr + count) = rem - 10 + 'a';
    } else {
      *(ptr + count) = rem + '0';
    }

    data = data/base; 
    count++;
  } 

  // If number is negative, append '-' 
  if (negative == -1)
      *(ptr + count) = '-';

  my_reverse(ptr, count);
  //i++;

  // Return reversed string

  // FOR DEBUGGING
  for (int j = 0; j < count; j++) {
    PRINTF("  char: %c\n", *(ptr + j));
  }
  PRINTF("%d\n", 'a');
  // END DEBUGGIGN

  return count;
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
