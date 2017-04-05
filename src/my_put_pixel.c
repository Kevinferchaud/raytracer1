/*
** my_put_pixel.c for emacs in /home/kevin.ferchaud/wireframe/src
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Dec 10 17:05:29 2016 ferchaud kevin
** Last update Sun Jan 15 13:29:45 2017 ferchaud kevin
*/

#include "my.h"

void    my_put_pixel(t_my_framebuffer *buffer, int x, int y, sfColor color)
{
  if (x >= 0 && x <= buffer->width &&
      y >= 0 && y <= buffer->height)
    {
      buffer->pixels[(buffer->width * y + x) * 4] = color.r;
      buffer->pixels[(buffer->width * y + x) * 4 + 1] = color.g;
      buffer->pixels[(buffer->width * y + x) * 4 + 2] = color.b;
      buffer->pixels[(buffer->width * y + x) * 4 + 3] = color.a;
    }
}
