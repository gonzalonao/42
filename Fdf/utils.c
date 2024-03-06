#include "Fdf.h"

uint32_t ft_generate_color2(int z, int min_z, int max_z, uint32_t min_color, uint32_t max_color)
{
    double percentage;
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    percentage = (double)(z - min_z) / (max_z - min_z);
    //printf("percentage: %f\n", percentage);

    uint8_t min_red = (min_color >> 16) & 0xFF;
    uint8_t max_red = (max_color >> 16) & 0xFF;
    red = min_red + (uint8_t)(percentage * (max_red - min_red));
    // printf("red: %u\n", red);
     printf("max_red: %u\n", max_red);
     printf("min_red: %u\n", min_red);

    uint8_t min_green = (min_color >> 8) & 0xFF;
    uint8_t max_green = (max_color >> 8) & 0xFF;
    green = min_green + (uint8_t)(percentage * (max_green - min_green));
    printf("max_green2: %u\n", max_green);
    printf("min_green2: %u\n", min_green);
    //printf("green2: %u\n", green);

    uint8_t min_blue = min_color & 0xFF;
    uint8_t max_blue = max_color & 0xFF;
    blue = min_blue + (uint8_t)(percentage * (max_blue - min_blue));
    // printf("blue: %u\n", blue);
     printf("max_blue: %u\n", max_blue);
     printf("min_blue: %u\n", min_blue);

    return ((red << 16) | (green << 8) | blue);
}

uint32_t ft_generate_color(int z, int min_z, int max_z, uint32_t min_color, uint32_t max_color)
{
	double percentage;
	uint8_t red;
	uint8_t green;
	uint8_t blue;

	percentage = (double)(z - min_z) / (max_z - min_z);
    printf("percentage: %f\n", percentage);
    printf("max_green1: %u\n", (max_color >> 8) & 0xFF);
    printf("min_green1: %u\n", (min_color >> 8) & 0xFF);
	red = ((min_color >> 16) & 0xFF) + (uint8_t)(percentage * (((max_color >> 16) & 0xFF) - ((min_color >> 16) & 0xFF)));
	//printf("red: %u\n", red);
    green = ((min_color >> 8) & 0xFF) + (uint8_t)(percentage * (((max_color >> 8) & 0xFF) - ((min_color >> 8) & 0xFF)));
	printf("green1: %u\n", green);
    blue = (min_color & 0xFF) + (uint8_t)(percentage * ((max_color & 0xFF) - (min_color & 0xFF)));
    //printf("blue: %u\n", blue);

	return ((red << 16) | (green << 8) | blue);
}

int main()
{
    uint32_t max_color;
    uint32_t min_color;
    int z;
    int min_z;
    int max_z;

    max_color = 0xFF;
    min_color = 0xFF00;
    z = 23;
    min_z = 23;
    max_z = 200;
  //  printf("color: %x\n", ft_generate_color(z, min_z, max_z, min_color, max_color));
    printf("color: %x\n", ft_generate_color2(z, min_z, max_z, min_color, max_color));
   // z = 67;
    //printf("color: %x\n", ft_generate_color(z, min_z, max_z, min_color, max_color));
    return 0;
}