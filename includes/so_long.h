/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:04 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/16 12:35:03 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "../library/libft/libft.h"
# include "../library/ft_printf_fd/ft_printf.h"
# include <fcntl.h>
# include <errno.h>
//# include "MLX42.h"

//Resolution 4k
# define PIXEL 64

//windowlength 3840/64
# define WINDOW_LENGTH 60

//windowwidth 2160/64
# define WINDOW_WIDTH 34

# define BUFFER_SIZE 2041

# define ENT_IMG 14

//Wall and Ground
// # define WALL1 "game_assets/wall/w1.png"
// # define WALL2 "game_assets/wall/w2.png"
// # define WALL3 "game_assets/wall/w3.png"
// # define WALL4 "game_assets/wall/w4.png"
// # define WALLL "game_assets/wall/left.png"
// # define WALLR "game_assets/wall/right.png"
// # define WALLT "game_assets/wall/top.png"
// # define WALLB "game_assets/wall/bottom.png"
// # define GROUND "game_assets/wall/ground.png"

//Character
// # define CHARACTER "game_assets/character/character.png"

//Objects
// # define OPENED_GATE "game_assets/objects/gate/open.png"
// # define CLOSED_GATE "game_assets/objects/gate/close.png"
// # define COLLECTIBLES "game_assets/objects/Collectibles/soul.png"
// # define OBSTACLES	"game_assets/wall/obstacles.png"

/*	t_point
*	Net point (row, col), as a index used for map->grid
*/
typedef struct s_point
{
	int32_t	row;
	int32_t	col;
}	t_point;

/*	t_dpoint
*	Real point (maps coordinates in double type)
*/
typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_dpoint;

/*	t_color
*	RGBA color is packed into uint32_t
*/
typedef struct s_color
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;
}	t_color;

/*
*char   *no;   	        -> file path for the North wall texture
*char   *so;   	        -> file path for the South wall texture
*char   *we;   	        -> file path for the West wall texture
*char   *ea;   	        -> file path for the East wall texture
*char   **grid;     	-> 2D map array containing characters: '0', '1', 'N', 'S', 'E', 'W'
*t_color  floor;    	-> floor color
*t_color  ceiling;  	-> ceiling color
*int      width;    	-> number of columns in the map
*int      height;   	-> number of rows in the map
*-> All info of map + textures + color
*/
typedef struct s_map
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		**grid;
	t_color		f;
	t_color		c;
	int			width;
	int			height;
}	t_map;
/*
    t_dpoint    pos;    // current position
    t_dpoint    prev;   // position before moving
    double      angle;  // viewing angle (in radians)
    double      speed;  // movement speed
	-> All info of a player/camera
*/
typedef struct s_player
{
	t_dpoint	pos;
	t_dpoint	prev;
	double		angle;
	double		speed;
}	t_player;

/*
*	HORIZONTAL,
*	VERTICAL
* -> Result of 1 ray in ray-casting
*/
typedef enum s_hit_dir
{
	HOR,
	VER,
}	t_hit_dir;

/*
 t_dpoint    start;      // starting position (player.pos)
    t_dpoint    hit_pos;    // actual collision point
    t_point     hit_cell;   // grid cell where the collision occurred
    double      distance;   // distance (fish-eye correction applied)
    t_hit_dir   hit_dir;    // direction of collision (horizontal or vertical)
    int         tex_id;     // texture ID (0–3 corresponding to NO, SO, WE, EA)
    int         tex_x;      // pixel offset within the texture
*/
typedef struct s_ray
{
	t_dpoint	start;
	t_dpoint	hit_pos;
	t_point		hit_cell;
	double		dis;
	t_hit_dir	hit_dir;
	int			tex_id;
	int			tex_x;
}	t_ray;

/* Complete application context
 void        *mlx;       // MLX42 context
    void        *win;       // MLX window
    t_map        map;       // map data: textures and colors
    t_player     player;    // camera/player
    int          screen_w;  // window width
    int          screen_h;  // window height
    t_ray      **rays;      // array of ray pointers, length = screen_w
    // … you will add asset manager, sprites, image buffer, etc. here
*/
typedef struct s_cub
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	pler;
	int			screen_w;
	int			screen_h;
	t_ray		**rays;
}	t_cub;

//Utilities
int32_t	execution(char **av);

//PARSING
//read_map
void	read_map(char *map_file, t_map *map);

//map_validation
void	map_validation(t_map *map);

void	assets_validation(void);
//utils
void	character_count(t_map *map, int32_t row);
void	file_validation(char *map_file, int32_t *fd);

//bfs
void	enqueue(t_queue *q, t_point point);
t_point	dequeue(t_queue *q);
int32_t	is_empty(t_queue *q);
void	assign_dimension(t_dimension *d);
int32_t	bfs(t_map *map, int32_t width, int32_t length);
t_queue	*create_queue(int32_t size);
void	ft_free_queue(t_queue *q, t_map *map);

//ERROR_HANDLING
void	game_map_error(int32_t status, char *msg, t_map *map);
void	map_file_error(int32_t status, char *msg, int32_t fd);
void	path_error(int32_t status, char *msg, t_map *map);
void	memory_error(t_queue *q, int32_t status, char *msg, t_map *map);

//EXECUTION
int		game_start(t_solong *game);
void	graphic(t_solong *game);
void	display_img_to_windows(t_solong *game);
void	game_control(mlx_key_data_t keypress, void *param);
void	game_end(t_solong *game, int exit_status);
void	game_error(const char *msg, t_solong *game);

#endif
