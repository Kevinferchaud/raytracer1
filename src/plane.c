/*
** intersect_plane.c for emacs in /home/kevin.ferchaud/bsraytracer1/src
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Wed Feb  8 15:46:02 2017 ferchaud kevin
** Last update Sun Mar 19 18:06:11 2017 ferchaud kevin
*/

#include "my.h"

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	dist;

  if (dir_vector.z == 0)
    return (-1.0);
  else
    dist = -eye_pos.z / dir_vector.z;
  if (dist < 0)
    return (-1.0);
  else
    return (dist);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	res;

  res.y = 0;
  res.x = 0;
  if (upward != 0)
    res.z = 100;
  else
    res.z = -100;
  return (res);
}
