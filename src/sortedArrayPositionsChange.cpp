/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
/*l=low
  m=mid
  h=high*/
void merge(int a[], int l, int m, int h)
{
	int b[1000];
	int i = l, j = m + 1, k = 0;

	while (i <= m && j <= h) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= m)
		b[k++] = a[i++];

	while (j <= h)
		b[k++] = a[j++];

	k--;
	while (k >= 0) {
		a[l + k] = b[k];
		k--;
	}
}
void sort(int a[], int l, int h)
{
	if (l < h) {
		int m = (h + l) / 2;
		sort(a, l, m);
		sort(a, m + 1, h);
		merge(a, l, m, h);
	}
}
void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (len < 1 || len == 1 || Arr == NULL)
		return NULL;
	else
	{
		sort(Arr, 0, len - 1);
	}
}