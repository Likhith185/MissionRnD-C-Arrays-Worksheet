/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void quick_sort1(struct student *stu, int low, int high)
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
		quick_sort1(stu, low, j - 1);
		quick_sort1(stu, j + 1, high);
	}
}
struct student ** topKStudents(struct student *students, int len, int K) {
	int i = 0, high = 0, a, j;
	if (students == NULL || len == 0 || K <= 0)
		return NULL;
	if (K == 1)
	{
		for (i = 0; i < len; i++)
		{
			if (students[i].score>high)
			{
				high = students[i].score;
				a = i;
			}
		}
		struct student **topKstud = (struct student **)calloc(K, sizeof(struct student));
		topKstud[0] = &students[a];
		return topKstud;
	}
	else
	{
		struct student **topKstud = (struct student **)calloc(K, sizeof(struct student));
		quick_sort1(students, 0, len - 1);
		for (j = 0; j < K; j++)
			topKstud[j] = &students[j];
		return topKstud;
	}
}