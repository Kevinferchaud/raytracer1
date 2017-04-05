/*
** translate.c for emacs in /home/kevin.ferchaud/raytracer1/src
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Mar 19 17:56:14 2017 ferchaud kevin
** Last update Sun Mar 19 18:07:09 2017 ferchaud kevin
*/

#include "my.h"

sfVector3f		translate(sfVector3f to_translate,
				  sfVector3f translations)
{
  sfVector3f		tot;

  tot.x = to_translate.x + translations.x;
  tot.y = to_translate.y + translations.y;
  tot.z = to_translate.z + translations.z;
  return (tot);
}
