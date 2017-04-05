/*
** move.c for emacs in /home/kevin.ferchaud/raytracer1
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Mar 19 20:57:24 2017 ferchaud kevin
** Last update Sun Mar 19 20:59:09 2017 ferchaud kevin
*/

#include "my.h"

t_list                  *do_plan(t_list *form, sfEvent key)
{
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    form->plan.z -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    form->plan.z += 2;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    form->plan.y -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    form->plan.y += 2;
  if (sfKeyboard_isKeyPressed(sfKeyO) == sfTrue)
    form->plan.x -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
    form->plan.x += 2;
  return (form);
}

t_list                  *do_sphere(t_list *form, sfEvent key)
{
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    form->sphere.z -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    form->sphere.z += 2;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    form->sphere.y -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    form->sphere.y += 2;
  if (sfKeyboard_isKeyPressed(sfKeyO) == sfTrue)
    form->sphere.x -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
    form->sphere.x += 2;
  return (form);
}

t_list                  *do_cone(t_list *form, sfEvent key)
{
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    form->cone.z -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    form->cone.z += 2;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    form->cone.y -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    form->cone.y += 2;
  if (sfKeyboard_isKeyPressed(sfKeyO) == sfTrue)
    form->cone.x -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
    form->cone.x += 2;
  return (form);
}

t_list                  *do_cyl(t_list *form, sfEvent key)
{
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    form->cyl.z -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    form->cyl.z += 2;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    form->cyl.y -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    form->cyl.y += 2;
  if (sfKeyboard_isKeyPressed(sfKeyO) == sfTrue)
    form->cyl.x -= 2;
  if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
    form->cyl.x += 2;
  return (form);
}

t_list                  *move_forms(t_list *form, sfEvent key)
{
  if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue)
    do_plan(form, key);
  if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
    do_sphere(form, key);
  if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
    do_cone(form, key);
  if (sfKeyboard_isKeyPressed(sfKeyR) == sfTrue)
    do_cyl(form, key);
  return (form);
}
