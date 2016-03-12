/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void quick_sort(struct student *stu, int low, int high)
{
	int pivot, j, i;
	struct student temp;
	if (low<high)
	{
		pivot = low;
		i = low;
		j = high;

		while (i<j)
		{
			while ((stu[i].score >= stu[pivot].score) && (i<high))
			{
				i++;
			}

			while (stu[j].score < stu[pivot].score)
			{
				j--;
			}

			if (i<j)
			{
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}

		temp = stu[pivot];
		stu[pivot] = stu[j];
		stu[j] = temp;
		quick_sort(stu, low, j - 1);
		quick_sort(stu, j + 1, high);
	}
}
void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len < 0)
		return NULL;
	quick_sort(students, 0, len - 1);
}