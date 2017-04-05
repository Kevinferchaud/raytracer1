/*
** cylinder.c for emacs in /home/kevin.ferchaud/bsraytracer1/src
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Mar 19 14:25:37 2017 ferchaud kevin
** Last update Sun Mar 19 18:05:46 2017 ferchaud kevin
*/

#include "my.h"

float   return_intercyl(float a, float b, float discr)
{
  float dist;
  float dist2;

  if (discr < 0)
    return (-1.0);
  if (discr == 0)
    dist = (-b) / (2 * a);
  if (discr > 0)
    {
      dist = (-b + sqrt(discr)) / (2 * a);
      dist2 = (-b - sqrt(discr)) / (2 * a);
      if (dist < 0 && dist2 < 0)
	return (-1.0);
      if (dist < 0 && dist2 > 0)
	return (dist2);
      if (dist > 0 && dist2 < 0)
	return (dist);
      if (dist > dist2)
	return (dist2);
      else
	return (dist);
    }
  return (dist);
}

float		intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
				   float radius)
{
  float a;
  float b;
  float c;
  float discr;
  float res;

  a = powf(dir_vector.x, 2) + powf(dir_vector.y, 2);
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y);
  c = (powf(eye_pos.x, 2) + pow(eye_pos.y, 2) - powf(radius, 2));
  discr = pow(b, 2) - (4 * a * c);
  res = return_intercyl(a, b, discr);
  return (res);
}

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  intersection_point.z = 0;
  return (intersection_point);
}
