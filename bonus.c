void count(int i)
{
	while (i < 10000000)
		i++;
}

void move1(t_ptr *ptr, int i, char *path)
{
	count(i);
	ptr->path=path;
	next_frame(ptr);
}

void move2(t_ptr *ptr, int i, char *path)
{
	count(i);
	ptr->path=path;
	next_frame(ptr);
}

void move3(t_ptr *ptr, int i, char *path)
{
	count(i);
	ptr->path=path;
	next_frame(ptr);
}

void player_d(t_ptr *ptr)
{
	int i;

	i = 0;
	ptr->x+=5;
	move1(ptr, i, "./character/char_right1.xpm");
	ptr->x+=5;
	move2(ptr, i, "./character/char_right2.xpm");
	ptr->x+=5;
	move3(ptr, i, "./character/char_right.xpm");
}

void player_s(t_ptr *ptr)
{
	int i;

	i = 0;
	ptr->y+=5;
	move1(ptr, i, "./character/char_down1.xpm");
	ptr->y+=5;
	move2(ptr, i, "./character/char_down2.xpm");
	ptr->y+=5;
	move3(ptr, i, "./character/char_down5.xpm");
}

void player_w(t_ptr *ptr)
{
	int i;

	i = 0;
	ptr->y-=5;
	move1(ptr, i, "./character/char_up1.xpm");
	ptr->y-=5;
	move2(ptr, i, "./character/char_up2.xpm");
	ptr->y-=5;
	move3(ptr, i, "./character/char_up.xpm");
}

void player_a(t_ptr *ptr)
{
	int i;

	i = 0;
	ptr->x-=5;
	move1(ptr, i, "./character/char_left1.xpm");
	ptr->x-=5;
	move2(ptr, i, "./character/char_left2.xpm");
	ptr->x-=5;
	move3(ptr, i, "./character/char_left.xpm");
}
