#include <stdio.h>
#include <string.h>

static char *map1[] = {
".-",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--..",
"..--",
"---.",
".-.-",
"----",
};

static int map2[] = {
2,
4,
4,
3,
1,
4,
3,
4,
2,
4,
3,
4,
2,
2,
3,
4,
4,
3,
3,
1,
3,
4,
3,
4,
4,
4,
4,
4,
4,
4,
};

static char char_map1[] = {
'E',
'T',
};

static char char_map2[] = {
'I',
'A',
'N',
'M',
};

static char char_map3[] = {
'S',
'U',
'R',
'W',
'D',
'K',
'G',
'O',
};

static char char_map4[] = {
'H',
'V',
'F',
'_',

'L',
',',
'P',
'J',

'B',
'X',
'C',
'Y',

'Z',
'Q',
'.',
'?',
};

static char *map_c(char c, int *len)
{
	int i;
	switch(c) {
	case '_':
		i = 26;
		break;
	case '.':
		i = 27;
		break;
	case ',':
		i = 28;
		break;
	case '?':
		i = 29;
		break;
	default:
		i = c - 'A';
		break;
	}

	if(len) *len = map2[i];

	return map1[i];
}

int main() {
	int n_case, i, j, a, b, len, ts, ci;
	char buf[101], t[8];

	scanf("%d\n", &n_case);
	for(i=0; i<n_case; ++i) {
		scanf("%s\n", buf);

		printf("%d: ", i+1);

		a = 0;
		ts = 0;
		b = strlen(buf)-1;

		while(b >= 0) {
			map_c(buf[b--], &len);			
			while(len > ts) {
				char *code;
				int code_len;
				code = map_c(buf[a++], &code_len);
				for(j=0; j<code_len; j++)
					t[ts++] = code[j];
			}
			for(ci=0, j=0; j<len; ++j) {
				ci <<= 1;
				if(t[j] == '-') {
					ci |= 1;
				}
			}

			switch(len) {
			case 1:
				printf("%c", char_map1[ci]); break;
			case 2:
				printf("%c", char_map2[ci]); break;
			case 3:
				printf("%c", char_map3[ci]); break;
			case 4:
				printf("%c", char_map4[ci]); break;
			}

			memmove(t, t+len, ts-len);
			ts -= len;
		}
		printf("\n");
	}
	return 0;
}