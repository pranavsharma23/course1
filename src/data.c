#include "data.h"
#include "memory.h"


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  int i = 0;
  bool isNegative = false;

  /* Handle 0 explicitely, otherwise empty string is printed for 0 */
  if (data == 0)
  {
      *(ptr + i++) = '0';
      *(ptr + i) = '\0';
      return ptr;
  }

  if (data < 0)
  {
      isNegative = true;
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
  if (isNegative)
      *(ptr + i) = '-';

  *ptr = my_reverse(ptr, i);
  i++;

  // Return reversed string
  return ptr;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  int i = 0;
  bool isNegative = false;
  int32_t data = 0;

  if (*ptr == '-')
  {
    isNegative = true;
    i++;
  }

  for (int i = 0; i < digits; i++)
  {
    data = data * base + *(ptr + i) - '0';
  }

  if (isNegative)
    data = -1 * data;

  return data;
}
