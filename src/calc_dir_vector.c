/*
** calc_dir_vector.c for emacs in /home/kevin.ferchaud/wolf3d
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Wed Feb  8 14:50:21 2017 ferchaud kevin
** Last update Sun Mar 19 18:05:15 2017 ferchaud kevin
*/

#include "my.h"

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
				sfVector2i screen_pos)
{
  sfVector3f	val;

  val.x = dist_to_plane;
  val.y = ((screen_size.x) / 2) - screen_pos.x;
  val.z = ((screen_size.y) / 2) - screen_pos.y;
  return (val);
}
