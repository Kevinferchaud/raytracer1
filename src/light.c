/*
** light.c for emacs in /home/kevin.ferchaud/bsraytracer1/src
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Mar 19 14:37:48 2017 ferchaud kevin
** Last update Sun Mar 19 18:05:54 2017 ferchaud kevin
*/

#include "my.h"

float		get_light_coef(sfVector3f light_vector,
			       sfVector3f normal_vector)
{
  float		res;
  float		tot;

  res = sqrtf(powf(normal_vector.x, 2) + powf(normal_vector.y, 2) +
	      powf(normal_vector.z, 2)) * sqrtf(powf(light_vector.x, 2) +
						powf(light_vector.y, 2) +
						powf(light_vector.z, 2));
  tot = normal_vector.x * light_vector.x + normal_vector.y *
    light_vector.y + normal_vector.z * light_vector.z;
  if (res == 0)
    return (0);
  if (tot / res < 0)
    return (0);
  return (tot / res);
}
