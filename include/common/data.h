#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Converts data from standard integer to ASCII string
 *
 * @param data			number to be converted to ASCII string
 * @param ptr			maximum value in the dataset
 * @param base			mean value of the dataset
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts data from ASCII string to standard integer
 *
 * @param data			minimum value in the dataset
 * @param ptr			maximum value in the dataset
 * @param base			mean value of the dataset
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
