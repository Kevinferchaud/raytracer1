/*
** raytracer11.c for emacs in /home/kevin.ferchaud/raytracer1
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Mar 19 20:29:53 2017 ferchaud kevin
** Last update Sun Mar 19 20:32:44 2017 ferchaud kevin
*/

#include "my.h"

sfRenderWindow          *create_window(char *name)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  mode.width = 1280;
  mode.height = 720;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

sfColor         set_color(int r, int g, int b, int a)
{
  sfColor       color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}

t_my_framebuffer         *my_framebuffer_create(int awidth, int aheight)
{
  int                    i;
  sfUint8                *apixels;
  t_my_framebuffer       *res;

  res = malloc(sizeof(*res));
  apixels = malloc(awidth * aheight * 4 * sizeof(*apixels));
  if (apixels == NULL)
    return (NULL);
  i = -1;
  while (++i < awidth * aheight * 4)
    apixels[i] = 0;
  res->pixels = apixels;
  res->width = awidth;
  res->height = aheight;
  return (res);
}

int                     return_val(float *form)
{
  int                   cpt;
  float                 tot;
  int                   res;

  cpt = -1;
  tot = 9999999;
  while (++cpt < 5)
    if (form[cpt] != -1 && form[cpt] < tot)
      {
	tot = form[cpt];
	res = cpt;
      }
  if (tot == 9999999)
    return (0);
  else
    return (res);
}
