/*
** my.h for emacs in /home/kevin.ferchaud/raytracer1/include
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Mar 19 13:51:42 2017 ferchaud kevin
** Last update Sun Mar 19 20:59:53 2017 ferchaud kevin
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <SFML/System/Export.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct          s_my_framebuffer
{
  sfUint8               *pixels;
  int                   width;
  int                   height;
}                       t_my_framebuffer;

typedef struct		s_list
{
  sfVector3f		cone;
  sfVector3f		sphere;
  sfVector3f		cyl;
  sfVector3f		plan;
  float			fsphere;
  float			fplan;
  float			fcone;
  float			fcyl;
  float			*form;
  sfVector3f            pix;
}			t_list;

void			my_put_pixel(t_my_framebuffer *a, int b, int c, sfColor d);
void			my_draw_line(t_my_framebuffer *a, sfVector2i b, \
			     sfVector2i c, sfColor color);
float			return_inters(float, float, float);
float			intersect_sphere(sfVector3f, sfVector3f, float);
sfVector3f		calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
				sfVector2i screen_pos);
float			intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
float			intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
			       float semiangle);
float			intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
				   float radius);
sfVector3f		translate(sfVector3f to_translate,
			  sfVector3f translations);
sfRenderWindow		*create_window(char *name);
sfColor			set_color(int r, int g, int b, int a);
t_my_framebuffer         *my_framebuffer_create(int awidth, int aheight);
int			return_val(float *form);
t_list                  *do_plan(t_list *form, sfEvent key);
t_list                  *do_sphere(t_list *form, sfEvent key);
t_list                  *do_cone(t_list *form, sfEvent key);
t_list                  *do_cyl(t_list *form, sfEvent key);
t_list                  *move_forms(t_list *form, sfEvent key);
