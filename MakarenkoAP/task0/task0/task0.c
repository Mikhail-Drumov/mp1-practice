#include <stdio.h>
#include <math.h>

int main()
{
	double x1, y1, r1, x2, y2, r2;
	printf("First circle:\n");
	scanf_s("%lf%lf%lf", &x1, &y1, &r1);
	printf("Second circle:\n");
	scanf_s("%lf%lf%lf", &x2, &y2, &r2);
	if (r1 < 0 || r2 < 0)
	{
		printf("\nRadius can't be negative!");
		return 0;
	}
	double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (dist == 0 && r1 == r2)
	{
		printf("\nThe circles are the same");
		return 0;
	}
	if (dist < abs(r1 - r2) || dist > r1 + r2)
		printf("\nThe circles don't intersect");
	else if (dist == abs(r1 - r2) || dist == r1 + r2)
		printf("\nThe circles are tangent");
	else
		printf("\nThe circles intersect at two points");
	if (dist >= r1 + r2)
		printf(", \nare located outside of each other");
	else if (dist <= r1 - r2)
		printf(", \nthe 2nd is fully inside the 1st");
	else if (dist <= r2 - r1)
		printf(", \nthe 1st is fully inside the 2nd");
	printf(", \ncenter of the 1st is located %s the 2nd", dist < r2 ? "inside of" : dist == r2 ? "on" : "outside of");
	printf(", \ncenter of the 2nd is located %s the 1st", dist < r1 ? "inside of" : dist == r1 ? "on" : "outside of");
	return 0;
}