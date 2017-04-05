/*
** raytracer1.c for emacs in /home/kevin.ferchaud/raytracer1
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Mar 19 13:50:25 2017 ferchaud kevin
** Last update Sun Mar 19 20:59:00 2017 ferchaud kevin
*/

#include "my.h"

t_list		*stockmyform(t_list *forms, sfVector3f pix,
			     sfVector2i screen_pos, sfVector2i screen_size)
{
  forms->fsphere = intersect_sphere(translate(pix, forms->sphere),
				    calc_dir_vector(500, screen_size,
						    screen_pos), 50);
  forms->fplan = intersect_plane(translate(pix, forms->plan),
				 calc_dir_vector(500, screen_size,
						 screen_pos));
  forms->fcone = intersect_cone(translate(pix, forms->cone),
				calc_dir_vector(500, screen_size,
						screen_pos), 30);
  forms->fcyl = intersect_cylinder(translate(pix, forms->cyl),
				   calc_dir_vector(500, screen_size,
						   screen_pos), 20);
  forms->form[0] = -1;
  forms->form[1] = forms->fsphere;
  forms->form[2] = forms->fplan;
  forms->form[3] = forms->fcone;
  forms->form[4] = forms->fcyl;
  return (forms);
}

t_list		*myform()
{
  t_list	*form;

  if ((form = malloc(sizeof(t_list))) == NULL)
    exit(84);
  form->cone.x = 0;
  form->cone.y = 30;
  form->cone.z = 0;
  form->sphere.x = 0;
  form->sphere.y = 0;
  form->sphere.z = 0;
  form->cyl.x = 0;
  form->cyl.y = -100;
  form->cyl.z = 0;
  form->plan.x = 0;
  form->plan.y = 0;
  form->plan.z = 30;
  form->pix.x = -200;
  form->pix.y = 0;
  form->pix.z = 0;
  if ((form->form = malloc(sizeof(float) * 5)) == NULL)
    exit(84);
  return (form);
}

void			print_forms(t_list *form, sfVector2i screen_size,
				    t_my_framebuffer *b, sfVector3f pix)
{
  sfVector2i		screen_pos;

  screen_pos.y = 0;
  while (screen_pos.y != screen_size.y)
    {
      screen_pos.x = 0;
      while (screen_pos.x != screen_size.x)
	{
	  form = stockmyform(form, pix, screen_pos, screen_size);
	  if (return_val(form->form) == 0)
	    my_put_pixel(b, screen_pos.x, screen_pos.y, sfBlack);
	  if (return_val(form->form) == 1)
	    my_put_pixel(b, screen_pos.x, screen_pos.y, sfRed);
	  if (return_val(form->form) == 2)
	    my_put_pixel(b, screen_pos.x, screen_pos.y, sfGreen);
	  if (return_val(form->form) == 3)
	    my_put_pixel(b, screen_pos.x, screen_pos.y, sfBlue);
	  if (return_val(form->form) == 4)
	    my_put_pixel(b, screen_pos.x, screen_pos.y, sfWhite);
	  screen_pos.x++;
	}
      screen_pos.y++;
    }
}

void			main2(sfRenderWindow *window, sfTexture *t,
			      sfSprite *sprite, t_my_framebuffer *b)
{
  t_list		*form;
  sfEvent		key;
  sfVector2i		screen_size;
  sfColor		color;

  form = myform();
  screen_size.y = b->height;
  screen_size.x = b->width;
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      form = move_forms(form, key);
      print_forms(form, screen_size, b, form->pix);
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(window);
      sfTexture_updateFromPixels(t, b->pixels, b->width, b->height, 0, 0);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
}

int			main(int ac, char **av)
{
  sfRenderWindow        *window;
  sfTexture             *t;
  sfSprite              *sprite;
  t_my_framebuffer      *b;

  window = create_window("Window");
  sprite = sfSprite_create();
  t = sfTexture_create(1280, 720);
  sfSprite_setTexture(sprite, t, sfTrue);
  b = my_framebuffer_create(1280, 720);
  main2(window, t, sprite, b);
  return (0);
}
