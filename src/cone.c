/*
** cone.c for emacs in /home/kevin.ferchaud/bsraytracer1/src
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Mar 19 14:31:28 2017 ferchaud kevin
** Last update Sun Mar 19 18:06:54 2017 ferchaud kevin
*/

#include "my.h"

float   return_intercone(float a, float b, float discr)
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

float   intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
		       float semiangle)
{
  float a;
  float b;
  float c;
  float discr;
  float res;

  if (semiangle == 90)
    return (-1);
  semiangle *= (2 * M_PI) / 360;
  a = powf(dir_vector.x, 2) + powf(dir_vector.y, 2) - powf(dir_vector.z, 2)
    * powf(tanf(semiangle), 2);
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y -
	   eye_pos.z * dir_vector.z * powf(tanf(semiangle), 2));
  c = (powf(eye_pos.x, 2) + powf(eye_pos.y, 2) - powf(eye_pos.z, 2) *
       powf(tanf(semiangle), 2));
  discr = powf(b, 2) - (4 * a * c);
  res = return_inters(a, b, discr);
  return (res);
}

sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  semiangle *= (2 * M_PI) / 360;
  intersection_point.z *= -tanf(semiangle);
  return (intersection_point);
}
