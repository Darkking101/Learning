#include<stdio.h>
#include<string.h>

int to_number (int len, char num[]) {

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

int is_binary (int len, char num[]) {

	for (int i = 0; i < len; i++) {
		if (num[i] != '1' && num[i] != '0') {
			return 1;
		}
	}
	return 0;
}

//int is_digit(char num[]) {
//	
//	for(int i=0; i < strlen(num))
//}

int main() {
	int length = 0;
	printf("Enter any Number in any format :  ");
	char input_number[1024] = {};

	fgets(
		input_number, 
		sizeof(input_number),
		stdin
	);

	for (int i = 0; i < 1024; i++) {
		if (input_number[i] == '\n') {
			input_number[i] = '\0';
			length = i-1;
			break;
		}
	}

	int check_digit = is_binary(
		length,
		input_number
	); 
	
	if (check_digit) {
		printf("The given number is not binary\n");
		return 0;
	}

	int val = to_number(
		length,
		input_number
	);

	printf("The value of the Bianry form is : %d\n", val);
	return 0;

}
