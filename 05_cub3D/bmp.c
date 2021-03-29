#include "../includes/cub3d.h"
void	bitmap_file_header(t_data *d, t_bitmapfileheader *bfh)
{
	bfh->bf_type = 'B';
	bfh->bf_type <<= 8;
	bfh->bf_type += 'M';
	bfh->bf_size = 54 + 4 * d->cub.width * d->cub.height;
	bfh->bf_reserved1 = 0;
	bfh->bf_reserved2 = 0;
	bfh->bf_off_bits = 54;
	write(d->bmp.fd, "B", 1);
	write(d->bmp.fd, "M", 1);
	write(d->bmp.fd, &bfh->bf_size, 4);
	write(d->bmp.fd, &bfh->bf_reserved1, 2);
	write(d->bmp.fd, &bfh->bf_reserved2, 2);
	write(d->bmp.fd, &bfh->bf_off_bits, 4);
}
void	bitmap_info_header(t_data *d, t_bitmapinfoheader *bih)
{
	bih->bi_size = 40;
	bih->bi_width = d->cub.width;
	bih->bi_height = -d->cub.height;
	bih->bi_planes = 1;
	bih->bi_bit_count = 32;
	bih->bi_compression = 0;
	bih->bi_size_image = 4 * d->cub.width * d->cub.height;
	bih->bi_x_pels_per_meter = 0;
	bih->bi_y_pels_per_meter = 0;
	bih->bi_clr_used = 0;
	bih->bi_clr_important = 0;
	write(d->bmp.fd, &bih->bi_size, 4);
	write(d->bmp.fd, &bih->bi_width, 4);
	write(d->bmp.fd, &bih->bi_height, 4);
	write(d->bmp.fd, &bih->bi_planes, 2);
	write(d->bmp.fd, &bih->bi_bit_count, 2);
	write(d->bmp.fd, &bih->bi_compression, 4);
	write(d->bmp.fd, &bih->bi_size_image, 4);
	write(d->bmp.fd, &bih->bi_x_pels_per_meter, 4);
	write(d->bmp.fd, &bih->bi_y_pels_per_meter, 4);
	write(d->bmp.fd, &bih->bi_clr_used, 4);
	write(d->bmp.fd, &bih->bi_clr_important, 4);
}
/*
** O_WRONLY
** O_TRUNC
** O_APPEND
** O_CREAT
** O_EXCL
** S_IRWXU
** S_IRWXG
** S_IRWXO
*/
void	bmp(t_data *d, int *img_data, t_bmp *b)
{
	b->fd = open("save.bmp", O_RDWR | O_TRUNC | O_APPEND | O_CREAT
	, S_IRWXU | S_IRWXG | S_IRWXO);
	bitmap_file_header(d, &b->bfh);
	bitmap_info_header(d, &b->bih);
	write(b->fd, img_data, b->bih.bi_size_image);
	close(b->fd);
}