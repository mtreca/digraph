#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

typedef struct digraph {
	wint_t x;
	wint_t y;
	wint_t d;
} digr_T;

static digr_T digraphtable[] = {
	{'N',  'U',  0x0a},
	{'S',  'H',  0x01},
	{'S',  'X',  0x02},
	{'E',  'X',  0x03},
	{'E',  'T',  0x04},
	{'E',  'Q',  0x05},
	{'A',  'K',  0x06},
	{'B',  'L',  0x07},
	{'B',  'S',  0x08},
	{'H',  'T',  0x09},
	{'L',  'F',  0x0a},
	{'V',  'T',  0x0b},
	{'F',  'F',  0x0c},
	{'C',  'R',  0x0d},
	{'S',  'O',  0x0e},
	{'S',  'I',  0x0f},
	{'D',  'L',  0x10},
	{'D',  '1',  0x11},
	{'D',  '2',  0x12},
	{'D',  '3',  0x13},
	{'D',  '4',  0x14},
	{'N',  'K',  0x15},
	{'S',  'Y',  0x16},
	{'E',  'B',  0x17},
	{'C',  'N',  0x18},
	{'E',  'M',  0x19},
	{'S',  'B',  0x1a},
	{'E',  'C',  0x1b},
	{'F',  'S',  0x1c},
	{'G',  'S',  0x1d},
	{'R',  'S',  0x1e},
	{'U',  'S',  0x1f},
	{'S',  'P',  0x20},
	{'N',  'b',  0x23},
	{'D',  'O',  0x24},
	{'A',  't',  0x40},
	{'<',  '(',  0x5b},
	{'/',  '/',  0x5c},
	{')',  '>',  0x5d},
	{'\'', '>',  0x5e},
	{'\'', '!',  0x60},
	{'(',  '!',  0x7b},
	{'!',  '!',  0x7c},
	{'!',  ')',  0x7d},
	{'\'', '?',  0x7e},
	{'D',  'T',  0x7f},
	{'P',  'A',  0x80},
	{'H',  'O',  0x81},
	{'B',  'H',  0x82},
	{'N',  'H',  0x83},
	{'I',  'N',  0x84},
	{'N',  'L',  0x85},
	{'S',  'A',  0x86},
	{'E',  'S',  0x87},
	{'H',  'S',  0x88},
	{'H',  'J',  0x89},
	{'V',  'S',  0x8a},
	{'P',  'D',  0x8b},
	{'P',  'U',  0x8c},
	{'R',  'I',  0x8d},
	{'S',  '2',  0x8e},
	{'S',  '3',  0x8f},
	{'D',  'C',  0x90},
	{'P',  '1',  0x91},
	{'P',  '2',  0x92},
	{'T',  'S',  0x93},
	{'C',  'C',  0x94},
	{'M',  'W',  0x95},
	{'S',  'G',  0x96},
	{'E',  'G',  0x97},
	{'S',  'S',  0x98},
	{'G',  'C',  0x99},
	{'S',  'C',  0x9a},
	{'C',  'I',  0x9b},
	{'S',  'T',  0x9c},
	{'O',  'C',  0x9d},
	{'P',  'M',  0x9e},
	{'A',  'C',  0x9f},
	{'N',  'S',  0xa0},
	{'!',  'I',  0xa1},
	{'~',  '!',  0xa1},
	{'C',  't',  0xa2},
	{'c',  '|',  0xa2},
	{'P',  'd',  0xa3},
	{'$',  '$',  0xa3},
	{'C',  'u',  0xa4},
	{'o',  'x',  0xa4},
	{'Y',  'e',  0xa5},
	{'Y',  '-',  0xa5},
	{'B',  'B',  0xa6},
	{'|',  '|',  0xa6},
	{'S',  'E',  0xa7},
	{'\'', ':',  0xa8},
	{'C',  'o',  0xa9},
	{'c',  'O',  0xa9},
	{'-',  'a',  0xaa},
	{'<',  '<',  0xab},
	{'N',  'O',  0xac},
	{'-',  ',',  0xac},
	{'-',  '-',  0xad},
	{'R',  'g',  0xae},
	{'\'', 'm',  0xaf},
	{'-',  '=',  0xaf},
	{'D',  'G',  0xb0},
	{'~',  'o',  0xb0},
	{'+',  '-',  0xb1},
	{'2',  'S',  0xb2},
	{'2',  '2',  0xb2},
	{'3',  'S',  0xb3},
	{'3',  '3',  0xb3},
	{'\'', '\'', 0xb4},
	{'M',  'y',  0xb5},
	{'P',  'I',  0xb6},
	{'p',  'p',  0xb6},
	{'.',  'M',  0xb7},
	{'~',  '.',  0xb7},
	{'\'', ',',  0xb8},
	{'1',  'S',  0xb9},
	{'1',  '1',  0xb9},
	{'-',  'o',  0xba},
	{'>',  '>',  0xbb},
	{'1',  '4',  0xbc},
	{'1',  '2',  0xbd},
	{'3',  '4',  0xbe},
	{'?',  'I',  0xbf},
	{'~',  '?',  0xbf},
	{'A',  '!',  0xc0},
	{'A',  '`',  0xc0},
	{'A',  '\'', 0xc1},
	{'A',  '>',  0xc2},
	{'A',  '^',  0xc2},
	{'A',  '?',  0xc3},
	{'A',  '~',  0xc3},
	{'A',  ':',  0xc4},
	{'A',  '"',  0xc4},
	{'A',  'A',  0xc5},
	{'A',  '@',  0xc5},
	{'A',  'E',  0xc6},
	{'C',  ',',  0xc7},
	{'E',  '!',  0xc8},
	{'E',  '`',  0xc8},
	{'E',  '\'', 0xc9},
	{'E',  '>',  0xca},
	{'E',  '^',  0xca},
	{'E',  ':',  0xcb},
	{'E',  '"',  0xcb},
	{'I',  '!',  0xcc},
	{'I',  '`',  0xcc},
	{'I',  '\'', 0xcd},
	{'I',  '>',  0xce},
	{'I',  '^',  0xce},
	{'I',  ':',  0xcf},
	{'I',  '"',  0xcf},
	{'D',  '-',  0xd0},
	{'N',  '?',  0xd1},
	{'N',  '~',  0xd1},
	{'O',  '!',  0xd2},
	{'O',  '`',  0xd2},
	{'O',  '\'', 0xd3},
	{'O',  '>',  0xd4},
	{'O',  '^',  0xd4},
	{'O',  '?',  0xd5},
	{'O',  '~',  0xd5},
	{'O',  ':',  0xd6},
	{'*',  'X',  0xd7},
	{'/',  '\\', 0xd7},
	{'O',  '/',  0xd8},
	{'U',  '!',  0xd9},
	{'U',  '`',  0xd9},
	{'U',  '\'', 0xda},
	{'U',  '>',  0xdb},
	{'U',  '^',  0xdb},
	{'U',  ':',  0xdc},
	{'Y',  '\'', 0xdd},
	{'T',  'H',  0xde},
	{'I',  'p',  0xde},
	{'s',  's',  0xdf},
	{'a',  '!',  0xe0},
	{'a',  '`',  0xe0},
	{'a',  '\'', 0xe1},
	{'a',  '>',  0xe2},
	{'a',  '^',  0xe2},
	{'a',  '?',  0xe3},
	{'a',  '~',  0xe3},
	{'a',  ':',  0xe4},
	{'a',  '"',  0xe4},
	{'a',  'a',  0xe5},
	{'a',  '@',  0xe5},
	{'a',  'e',  0xe6},
	{'c',  ',',  0xe7},
	{'e',  '!',  0xe8},
	{'e',  '`',  0xe8},
	{'e',  '\'', 0xe9},
	{'e',  '>',  0xea},
	{'e',  '^',  0xea},
	{'e',  ':',  0xeb},
	{'e',  '"',  0xeb},
	{'i',  '!',  0xec},
	{'i',  '`',  0xec},
	{'i',  '\'', 0xed},
	{'i',  '>',  0xee},
	{'i',  '^',  0xee},
	{'i',  ':',  0xef},
	{'d',  '-',  0xf0},
	{'n',  '?',  0xf1},
	{'n',  '~',  0xf1},
	{'o',  '!',  0xf2},
	{'o',  '`',  0xf2},
	{'o',  '\'', 0xf3},
	{'o',  '>',  0xf4},
	{'o',  '^',  0xf4},
	{'o',  '?',  0xf5},
	{'o',  '~',  0xf5},
	{'o',  ':',  0xf6},
	{'-',  ':',  0xf7},
	{'o',  '/',  0xf8},
	{'u',  '!',  0xf9},
	{'u',  '`',  0xf9},
	{'u',  '\'', 0xfa},
	{'u',  '>',  0xfb},
	{'u',  '^',  0xfb},
	{'u',  ':',  0xfc},
	{'y',  '\'', 0xfd},
	{'t',  'h',  0xfe},
	{'y',  ':',  0xff},
	{'y',  '"',  0xff},
};

wint_t
getdigraph(wint_t x, wint_t y)
{

	digr_T *dp;
	dp = digraphtable;

	for (int i = 0; dp->x != 0; ++i) {
		if (dp->x == x && dp->y == y) {
			return dp->d;
		}
		++dp;
	}

	return y;

}

wint_t
digraph(wint_t x, wint_t y)
{

	wint_t d;

	if (((d = getdigraph(x, y)) == y) && ((d = getdigraph(y, x)) == x)) {
		return x;
	} else {
		return d;
	}

}

void
read_stdin(wint_t s)
{

	wint_t c, x, y;

	while ((c = getwc(stdin)) != WEOF) {
		if (c == s) {
			if (((x = getwc(stdin)) > 31) && ((y = getwc(stdin)) > 31)) {
				putwchar(digraph(x, y));
			}
		} else {
			putwchar(c);
		}
	}

}

void
usage()
{
	fprintf(stderr, "usage: digraph [-sh]\n");
	exit(1);
}

int
main(int argc, char *argv[])
{

	setlocale(LC_CTYPE, "");

	int opt;
	char *c;
	wint_t s = '#';

	while((opt = getopt(argc, argv, "s:h")) != -1) {
		switch(opt) {
			case 's':
				c = optarg;
				if (strlen(c) != 1) {
					fprintf(stderr, "invalid separator: %s\n", c);
					exit(1);
				}
				s = c[0];
				break;
			case 'h':
			default:
				usage();
				break;
		}
	}

	read_stdin(s);
	return 0;

}
