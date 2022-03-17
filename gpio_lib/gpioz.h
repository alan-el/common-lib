#ifndef _GPIO_Z_H_
#define _GPIO_Z_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifdef __cplusplus
extern "C"{
#endif


typedef enum gpio_mode
{
    GPIO_MODE_IN,    /* IN MODE */
    GPIO_MODE_OUT    /* OUT MODE */
}gpio_mode_t;

typedef enum gpio_level
{
    GPIO_LEVEL_LOW = 0,
    GPIO_LEVEL_HIGH = 1
}gpio_level_t;

int gpio_export(char *gpio_num);
int gpio_unexport(char *gpio_num);
int gpio_set_direction(char *gpio_num, char *dir);
int gpio_set_value(char *gpio_num, char *val);
int gpio_get_value(char *gpio_num, char *val);

#ifdef __cplusplus
}
#endif

#endif  /* _GPIO_Z_H_ */

