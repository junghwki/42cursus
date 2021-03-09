static int	cmp_sprites( const void* a, const void* b )
{
	if (((const sprite_t*)a)->dist > ((const sprite_t*)b)->dist)))
		return(-1);
	else
		return(1);
}

static sprite_t* get_visible_sprites( player_t* pp, int** vis, int* pcnt )
{
    int n = 0;
    sprite_t* sp = NULL; /* dynamic array */

    /* build list of visible sprites */
    for( int x=0; x<map_xmax(); x++ ) {
        for( int y=0; y<map_ymax(); y++ ) {
            if( vis[x][y] == 0 || map_get_cell(x,y) <= CELL_WALL )
                continue;

            if( n == 0 ) sp = (sprite_t*) malloc(sizeof(sprite_t));
            else sp = (sprite_t*) realloc(sp, sizeof(sprite_t)*(n+1));

            sp[n].tex = (map_get_cell(x,y) - CELL_WALL) + 5;
            sp[n].x = x;
            sp[n].y = y;
            sp[n].th = atan2((y+0.5)-(pp->y), (x+0.5)-(pp->x));
            if( sp[n].th < 0 ) sp[n].th += _2PI;
            sp[n].dist = l2dist(pp->x, pp->y, x+0.5, y+0.5) * cos(pp->th - sp[n].th);
            n++;
        }
    }
    *pcnt = n;
    return sp;
}