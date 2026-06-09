#include<stdio.h>
#include<string.h>

int to_number (int len, char* num) {

	int value = 0;
	int j = 0;
	for (int i = len; i >= 0; i--) {
		if (num[i] == '1') {
			value += (1 << j);
		}
		j++;
	
	}
	return value;
}

int is_binary (int len, char* num) {

	for (int i = 0; i < len; i++) {
		if (num[i] != '1' && num[i] != '0') {
			printf ("Given input is not binary.\n");
			return 1;
		}
	}
	return 0;
}

int char_to_int (int len, char *num) {
	int value = 0;
	for (int i = 0; i <= len; i++) {
		value = (value * 10) + (num[i] - '0');
	}
	return value;
}

char* to_binary (int value) {
	char a_binary[1024] = {};
	int count = 0;

	for (int i = 0; value !=0; i++) {
		if (value % 2 == 0) {
			a_binary[i] = '0';
		}
		else {
			a_binary[i] = '1';
		}
		value /= 2;
		count ++;
	}
	static char binary[1024] = {};
	for (int i = 0; i <= count; i++) {
		binary[i] = a_binary[count - i];
		printf("%c",binary[i]);
	}
	printf("\n");
	return binary;
}

/*char* to_binary (int value) {
	
	static char binary[1024] = {};
	int j = 0;
	for (int i = 0; i <= value; i++) {
		j = 1 << i;
		if (j > value) {
			j = j / 2;
			break;
		}
	}
	for (int k = 0; value != 0; k++) {
		if (value == 0) {
			break;
		}
		if (value > j) {
			binary[k] = '1';
			value = value - j;
		}
		else {
			binary[k] = '0';
		}
		j = j / 2;
	}
	return binary;
}
*/

void input (char* input_number, int* length) {

	printf ("Enter Values : ");
	char c;
	while ( (c = getchar()) != '\n' && c != EOF);

	fgets (
		input_number, 
		*length,
		stdin
	);

	for (int i = 0; i < 1024; i++) {
		if (input_number[i] == '\n') {
			input_number[i] = '\0';
			*length = (i - 1);
			break;
		}
	}
}

int main () {

	int length = 1024;
	char input_number[1024] = {};

	printf ("Choose number conversion \n"
		"1.Numbers to Binary\n"
		"2.Binary to Decimals: "
	);

	int choice = 0;
	scanf ("%d", &choice);

	switch (choice) {
		case 1:
			input (input_number, &length);
			int val = char_to_int (length, input_number);
			to_binary (val);
			break;
		case 2:
			input (input_number, &length);
			if (!is_binary (length, input_number) ) {
				printf("%d\n", to_number (length, input_number) );
			}
			break;
	}
	
	return 0;
}
