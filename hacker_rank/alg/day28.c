#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NAME_MAX
# define NAME_MAX 256
#endif

#define N 256

struct Info {
	char name[NAME_MAX], email[NAME_MAX];
} people[N];
int people_num = 0;

char chosen_name[N][NAME_MAX];
int chosen_num = 0;

int cmp(const void *a, const void *b) {
	const char *namea = (const char *)a;
	const char *nameb = (const char *)b;
	return strcmp(namea, nameb);
}

int main(int argc, char *argv[])
{
	int i;
	while (scanf("%d", &people_num) != EOF && people_num > 0) {
		chosen_num = 0;
		for (i = 0; i < people_num; ++i) {
			scanf("%s%s", people[i].name, people[i].email);
			if (strstr(people[i].email, "@gmail.com")) {
				strncpy(chosen_name[chosen_num++], people[i].name, NAME_MAX-1);
			}
		}

		qsort(chosen_name, chosen_num, sizeof(chosen_name[0]), cmp);
		for (i = 0; i < chosen_num; ++i) {
			puts(chosen_name[i]);
		}
	}
	return 0;
}
