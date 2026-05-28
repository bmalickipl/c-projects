#include "primlib.h"
#include <stdlib.h>
#include <math.h>

struct target {
	int x;
	int y;
	int side;
	int speed;
	int color;
	int is_exploding;
	int explosion_radius;																									
	int start_x;																													
	int start_y;
	int size;
	int size_rect;																															
};

void draw_target(struct target *t){
	gfx_filledCircle(t->x - t->size, t->y, t->size,  t->color);
	gfx_filledCircle(t->x + t->size, t->y, t->size,  t->color);
	gfx_filledRect(t->x - t->size_rect, t->y - t->size_rect + 5, t->x + t->size_rect, t->y + t->size_rect + 5, t->color);
	gfx_filledRect(t->x - t->size_rect, t->y - t->size_rect - 15, t->x + t->size_rect, t->y + t->size_rect - 15, t->color);
}

void move_target(struct target *t){
	if(t->side == 0)
	{
		t->x += t->speed;
		if(t->x > gfx_screenWidth() - 15)
			t->side = 1;
	}
	
	else if(t->side == 1)
	{
		t->y += t->speed;
		if(t->y > gfx_screenHeight() - 200)
			t->side = 2;
	}
	else if(t->side == 2)
	{
		t->x -= t->speed;
		if(t->x < 10)
			t->side = 3;
	}
	else if(t->side == 3)
	{
		t->y -= t->speed;
		if(t->y <= 40)
			t->side = 0;
	}
}

void draw_bullet(int x1, int y1, int x2, int y2, int width, double taper, int color) {		

  int dx = x2 - x1;
  int dy = y2 - y1;

  int dx_p = dy;
  int dy_p = -dx;
  double len = hypot(dx_p, dy_p);

  int dx_p_s = width / (2.0 * len) * dx_p;
  int dy_p_s = width / (2.0 * len) * dy_p;

  int dx_p_s_t = dx_p_s * taper;
  int dy_p_s_t = dy_p_s * taper;

  int x1c = x2 - dx_p_s_t;
  int y1c = y2 - dy_p_s_t;

  int x2c = x2 + dx_p_s_t;
  int y2c = y2 + dy_p_s_t;

  int x3c = x1 - dx_p_s;
  int y3c = y1 - dy_p_s;

  int x4c = x1 + dx_p_s;
  int y4c = y1 + dy_p_s;

  gfx_filledTriangle(x1c, y1c, x2c, y2c, x3c, y3c, color);
  gfx_filledTriangle(x4c, y4c, x2c, y2c, x3c, y3c, color);
}

int main()
{
	if(gfx_init())
		exit(3);
		
	int fire_x = gfx_screenWidth() / 2; 																	
	double bullet_distance = 0.0;
	int is_shooting = 0;
	int space_was_pressed = 0;																						
	const int barrel_length = 150;																				
	int cannon_x = gfx_screenWidth() / 2;																							
																																				
	struct target t[4];
	t[0].start_x = 0;																											
	t[0].start_y = 40;																										 
	t[0].size = 15;				
	t[0].size_rect = 10;																								 
	t[0].x = t[0].start_x;																								 
	t[0].y = t[0].start_y;																								
	t[0].explosion_radius = 0;																						
	t[0].speed = 3;
	t[0].side = 0;
	t[0].color = BLUE;
	t[0].is_exploding = 0;
	
	t[1].start_x = gfx_screenWidth() / 2;
	t[1].start_y = 80;
	t[1].size = 15;
	t[1].size_rect = 10;
	t[1].x = t[1].start_x;
	t[1].y = t[1].start_y;
	t[1].explosion_radius = 0;
	t[1].speed = 3;
	t[1].side = 2;
	t[1].color = MAGENTA;
	t[1].is_exploding = 0;
	
	t[2].start_x = gfx_screenWidth() - 150;
	t[2].start_y = gfx_screenHeight() / 4;
	t[2].size = 15;
	t[2].size_rect = 10;
	t[2].x = t[2].start_x;
	t[2].y = t[2].start_y;
	t[2].explosion_radius = 0;
	t[2].speed = 3;
	t[2].side = 1;
	t[2].color = GREEN;
	t[2].is_exploding = 0;
	
	t[3].start_x = gfx_screenWidth() - 15;
	t[3].start_y = gfx_screenHeight() - 300;
	t[3].size = 15;
	t[3].size_rect = 10;
	t[3].x = t[3].start_x;
	t[3].y = t[3].start_y;
	t[3].explosion_radius = 0;
	t[3].speed = 3;
	t[3].side = 0;
	t[3].color = CYAN;
	t[3].is_exploding = 0;	
	
	while(1)
	{																																										
		gfx_filledRect(0, 0, gfx_screenWidth() - 1, gfx_screenHeight() - 1, BLACK);	
																																											
		gfx_filledRect(cannon_x - 40, gfx_screenHeight() - 15, cannon_x + 40, gfx_screenHeight(), BLUE);
		gfx_filledRect(cannon_x - 15, gfx_screenHeight() - 35, cannon_x + 15, gfx_screenHeight() - 15, YELLOW	);
		gfx_filledTriangle(cannon_x - 15, gfx_screenHeight() - 35, cannon_x + 15, gfx_screenHeight() - 35,cannon_x, gfx_screenHeight() - barrel_length,RED);
    
    int x_bullet_begin_tlc = fire_x;																	
    int y_bullet_begin_tlc = gfx_screenHeight() - bullet_distance;

    int x_bullet_end_tlc = fire_x;
    int y_bullet_end_tlc = gfx_screenHeight() - (bullet_distance + 30);                       
		for(int i = 0; i < 4; i++)																					
		{
			if(t[i].is_exploding)
			{
				gfx_filledCircle(t[i].x, t[i].y, t[i].explosion_radius,WHITE);
			}
			else
			{
				draw_target(&t[i]);
			}
		}																																		
		if(is_shooting)
		{
			draw_bullet(x_bullet_begin_tlc, y_bullet_begin_tlc, x_bullet_end_tlc,y_bullet_end_tlc, 10, 0.5, RED); 
		}
		gfx_updateScreen();
		if(is_shooting)
		{
			bullet_distance += 5.0;																						
			int x_bullet = fire_x;
			int y_bullet = gfx_screenHeight() - bullet_distance;
			if(x_bullet < 0 || x_bullet >= gfx_screenWidth() || y_bullet < 0)
			{
				is_shooting = 0;
			}
			for(int i = 0; i < 4; i++)																													
			{
				if(hypot(x_bullet - t[i].x, y_bullet - t[i].y) < 25 && !t[i].is_exploding)
				{
					is_shooting = 0;
					t[i].is_exploding = 1;
					t[i].explosion_radius = 1;
					break;
				}
			}
		}
		for(int i = 0; i < 4; i++)																					
		{
			if(t[i].is_exploding)
			{
				t[i].explosion_radius += 2;
				if(t[i].explosion_radius > 50)																	
				{
					t[i].is_exploding = 0;																				
					t[i].explosion_radius = 0;																		
					t[i].x = t[i].start_x;																				
					t[i].y = t[i].start_y;																				
				}	
			}
		}
		for(int i = 0; i < 4; i++)																					
		{
			if(!t[i].is_exploding)
				move_target(&t[i]);
		}
		
		if(gfx_isKeyDown(SDLK_RIGHT) && cannon_x < gfx_screenWidth())				
			cannon_x += 5;																										
		if(gfx_isKeyDown(SDLK_LEFT) && cannon_x > 0)												
			cannon_x -= 5;
		if(gfx_isKeyDown(SDLK_SPACE))
		{
			if(!space_was_pressed && is_shooting == 0)
			{
				is_shooting = 1;
				bullet_distance = 159.0;
				fire_x = cannon_x;
			}
			space_was_pressed = 1;
		}
		else
			space_was_pressed = 0;
			
		if(gfx_isKeyDown(SDLK_ESCAPE))
			break;
		SDL_Delay(10);
	}
	return 0;
}
