/*
** intersect_sphere.c for emacs in /home/kevin.ferchaud/bsraytracer1
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Wed Feb  8 15:09:14 2017 ferchaud kevin
** Last update Sun Mar 19 18:06:25 2017 ferchaud kevin
*/

#include "my.h"

float	return_inters(float a, float b, float discr)
{
  float	dist;
  float	dist2;

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

float	intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
			 float radius)
{
  float	a;
  float	b;
  float	c;
  float	discr;
  float	res;

  a = powf(dir_vector.x, 2) + powf(dir_vector.y, 2) + powf(dir_vector.z, 2);
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y +
	   eye_pos.z * dir_vector.z);
  c = (powf(eye_pos.x, 2) + powf(eye_pos.y, 2) + powf(eye_pos.z, 2) -
       powf(radius, 2));
  discr = powf(b, 2) - (4 * a * c);
  res = return_inters(a, b, discr);
  return (res);
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}
