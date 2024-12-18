#include <stdio.h>
#include "area_calculation.h"

int main() {
    
    float base,height,radius;
	printf("enter the base value:");
	scanf("%d",&base);
	printf("\nenter the height value");
	scanf("%d",&height);
	printf("\nenter the radius");
	scanf("%d",&radius);

	float traiangle_area = AREA_OF_TRIANGLE(base,height);

	float circle_area=AREA_OF_CIRCLE(radius);


    printf("Area of the triangle (base=%f, height=%f): %f\n", base, height, triangle_area);
    printf("Area of the circle (radius=%f): %f\n", radius, circle_area);

    return 0;
}

