#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

void test();
char* decimal_to_hex (char *input_value); 

int get_result (int val) {

	int result = 0;
	while (val > 0) {
		val /= 10;
		result++;
	}
	return result;
}

int get_length (char *str) {
	int i = 0;
	if (str == NULL) 
		return i;
	while (str[i] != '\0') {
		i++;
	}
	return i;
} 

int is_same (char* actual_value, char* expect_value) {
	
	int i = 0;
	int length_av = get_length (actual_value);
	int length_ev = get_length (expect_value);
	if (length_av != length_ev) 
		return FALSE;

	if (actual_value == NULL || expect_value == NULL) {
		return FALSE;
	}
	while (expect_value[i] != '\0') {
		if (actual_value[i] != expect_value[i]) {
			return FALSE;
		}
		i++;
	}
	return TRUE;
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
	for (int i = 0; i < len; i++) {
		if (num[i] == '\0') {
			break;
		}
		if (num[i] == '-') {
			continue;
		}
		value = (value * 10) + (num[i] - '0');
	}
	return value;
}

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
			*length = i;
			break;
		}
	}
	printf ("Entered Number: %s\n", input_number);
	printf ("length: %d\n", *length);
}

char* binary_to_decimal (int len, char* num) {

	int value = 0;
	int j = 0;
	for (int i = len-1; i >= 0; i--) {
		if (num[i] == '1') {
			value += (1 << j);
		}
		j++;
	
	}
	char *result = malloc (1024);
	j = get_result (value);
	int temp = j;
	j--;
	if (value == 0) {
		result[0] = '0';
		return result;
	}
	while (value > 0) {
		result[j] = (value % 10) + '0';
		value /= 10;
		j--;
	}
	result[temp] = '\0';
	return result;

}

char* decimal_to_binary (int value) {

	printf ("Input : %d\n", value);
	char a_binary[1024] = {};
	int count = 0;
	if (value == 0) {
		a_binary[0] = '0';
		count++;
	}
	for (int i = 0; value > 0; i++) {
		if (value % 2 == 0) {
			a_binary[i] = '0';
		}
		else {
			a_binary[i] = '1';
		}
		value /= 2;
		count++;
	}
	count--;
	char *result = malloc (1024);
	for (int i = 0; i <= count; i++) {
		result[i] = a_binary[count - i];
	}
	return result;
}

char* decimal_to_octal (char *input_value) {
	
	int len = strlen (input_value);
	int value = char_to_int (len, input_value);
	char *result = malloc (1024);
	int i = 0;
	while (value > 8) {
		result[i] = (value % 8) + '0';
		value /= 8;
		i++;
	}
	result[i] = value + '0';
	result[i+1] = '\0';
	len = strlen (result);
	for (int j = 0; j < i; j++) {
		char temp = result[j];
		result[j] = result[i];
		result[i] = temp;
		i--;
	}
	return result;
}



char* octal_to_binary (char *input_value) {
	
	int len = get_length (input_value);
	char *result = malloc ((len * 3) + 1);
	int k = 2;
	int x = 0;
	for (int i = 0; i < len; i++) {
		int value = input_value[i] - '0';
		if (value == 0) {
			result[i] = '0';
			continue;
		}
		
		x = k;
		for (int j = 0; j < 3; j++) {
			if (value > 0 && (value % 2 == 1)) {
				result[k] = '1';
			}
			else {
				result[k] = '0';
			}
			value /= 2;
			k--;
		}
		k = x + 3;
	}
	return result;

}

char* octal_to_decimal (char *input_value) {

	int value = 0;
	int temp_var = 0;
	int len = get_length (input_value) -1;
	int j = 0;
	for (int i = len; i >= 0 ; i--) {
		temp_var = input_value[i] - '0';
		int power = (int) pow(8, j);
		value += power * temp_var;
		j++;
	}
	char *result = malloc (1024);

	if (input_value[0] == '0' && len < 1)
		result[0] = '0';
	
	len = get_result (value);
	for (int i = len-1; value > 0 ; i--) {
		result[i] = (value % 10) + '0';
		value = value / 10;
	}
	return result;
}



char* octal_to_hex (char *input_value) {
	
	int value = 0;
	input_value = octal_to_decimal (input_value);

	int len = get_length (input_value);

	for (int i = 0; i < len; i++) {
		value = (value * 10) + (input_value[i] - '0') ;
	}
	int i = 0;
	char *result = malloc (len);
	if (value == 0) {
		result [0] = '0';
		return result;
	}
	while (value > 0) {
		
		int temp = (value % 16);
		if (temp <= 9 && temp >= 0) {
			result[i] = temp + '0';
		}
		else if (temp >= 10 && temp <= 15) {
			result[i] = temp + 'A' - 10;
		}
		value /= 16;
		i++;
	}
	len = get_length (result) - 1;
	for (i = 0; i < len; i++) {
		char t         = result[i];
		result [i]     = result [len];
		result [len] = t;
		len --;
	}
	return result;

}

char* hex_to_decimal (char *input_value) {

	int value = 0;
	int temp_var = 0;
	int len = get_length(input_value) - 1;
	int j = 0;
	for (int i = len; i >= 0 ; i--) {
		if ( (input_value[i] >= 'a') && (input_value[i] <= 'f')) {
			temp_var = input_value[i] - 'a' + 10;
		}
		else if ( (input_value[i] >= 'A') && (input_value[i] <= 'F')) {
			temp_var = input_value[i] - 'A' + 10;

		}
		else {
			temp_var = input_value[i] - '0';
		}
		int power = (int) pow(16, j);
		value    += power * temp_var;
		j++;
	}
	char *result = malloc (1024);
	len = get_result (value);
	if (value == 0 && len < 1) {
		result[0] = '0';
		return result;
	}
	for (int i = len-1; value > 0 ; i--) {
		result[i] = (value % 10) + '0';
		value     = value / 10;
	}
	result[len] = '\0';
	return result;
}

char* hex_to_octal (char *input_value) {
	
	input_value = hex_to_decimal (input_value);
	int len = get_length (input_value) - 1;
	int value   = 0;
	char *result = malloc (50);

	for (int i = 0; i <= len; i++) {
		value = (value * 10) + (input_value[i] - '0'); 
	}

	int i = 0;
	int temp = 0;
	if (value == 0) {
		result[i] = '0';
	}
	while (value > 0) {
		int power = (int) pow (10, i);
		temp += ((value % 8) * power);
		value /= 8;
		i++;
	}
	
	value = temp;
	len = get_result (value);
	for (int i = len - 1; i >= 0; i--) {
		result[i] = (value % 10) + '0'; 
		value /= 10;
	}
	return result;

}
char* single_hex_to_binary (char input);
char* multi_hex_to_binary (char *input_value);

int main () {

	int length = 1024;
	char input_number[1024] = {};
	test();
	return 0;
	printf ("Choose number conversion \n"
		"1.Decimal to Binary\n"
		"2.Binary to Decimals\n"
		"3.Hex to Decimal\n"
		"4.Octal to Decimal\n"
		"5.Decimal to Octal\n"
		"6.Decimal to Hex\n"
		"7.Hex to Binary\n"
		"8.Octal to Binary: "
	);

	int choice = 0;
	scanf ("%d", &choice);
	char *arr = NULL;

	switch (choice) {
		case 1:
			input (input_number, &length);
			int val = char_to_int (length, input_number);
			arr = decimal_to_binary (val);
			printf("result: %s\n", arr);
			break;
		case 2:
			input (input_number, &length);
			if (!is_binary (length, input_number)) {
				printf("result: %s\n", binary_to_decimal (length, input_number));
			}
			break;
		case 3:
			input (input_number, &length);
			arr = hex_to_decimal(input_number);
			printf("result: %s\n", arr);
			break;
		case 4:
			input (input_number, &length);
			arr = octal_to_decimal(input_number);
			printf("result: %s\n", arr);
			break;
		case 5:
			input (input_number, &length);
			arr = decimal_to_octal(input_number);
			printf("result: %s\n", arr);
			break;
		case 6:
			input (input_number, &length);
			arr = decimal_to_hex(input_number);
			printf("result: %s\n", arr);
			break;
		case 7:
			input (input_number, &length);
			arr = multi_hex_to_binary (input_number);
			printf("result: %s\n", arr);
			break;
		case 8:
			input (input_number, &length);
			arr = octal_to_binary (input_number);
			printf("result: %s\n", arr);
			break;
		case 9:
			input (input_number, &length);
			arr = hex_to_octal (input_number);
			printf("result: %s\n", arr);
			break;
		case 10:
			input (input_number, &length);
			arr = octal_to_hex (input_number);
			printf("result: %s\n", arr);
			break;
	
	}
	return 0;
}

char* decimal_to_hex (char *input_value) {

	int len = strlen (input_value);
	int value = char_to_int (len, input_value);
	char *result = malloc (1024);
	int i = 0;
	int temp = 0;
	while (value > 16) {
		temp = (value % 16);
		if ( (temp >= 10) && (temp <= 15)) {
			result[i] = 'A' + (temp - 10);
		}
		else if (temp <= 9) {
			result[i] = '0' + temp;
		}
		value /= 16;
		i++;
	}
	if ( (value >= 10) && (value <= 15)) {
		result[i] = 'A' + (value - 10);
	}
	else {
		result[i] = '0' + value;
	}
	result[i+1] = '\0';

	for (int j = 0; j < i; j++) {
		char temp_char = result[j];
		result[j]      = result[i];
		result[i]      = temp_char;
		i--;
	}

	return result;
}


void test () {
	if (!is_same (binary_to_decimal(8,"10000000"), "128")) {
		printf ("1st test failed\n");
		exit (1);
	}
	if (!is_same (binary_to_decimal(15,"100000000000000"), "16384")) {
		printf ("2st test failed\n");
		exit (1);
	}
	
	if (!is_same (binary_to_decimal(4,"1100"), "12")) {
		printf ("1st test failed\n");
		exit (1);
	}
	else {
		printf ("Test 1 Passed\n");
	}
	if (!is_same (binary_to_decimal(4,"0110"), "6")) {
		printf ("2st test failed\n");
		exit (1);
	}
	else {
		printf ("Test 2 Passed\n");
	}

	if (!is_same (binary_to_decimal(1,"0"), "0")) {
		printf ("3st test failed\n");
		exit (1);
	}
	else {
		printf ("Test 3 Passed\n");
	}

			
	if (!is_same (binary_to_decimal(7,"1111011"), "123")) {
		printf ("4st test failed\n");
		exit (1);
	}
	else {
		printf ("Test 4 Passed\n");
	}

	if (!is_same (binary_to_decimal(8,"11111111"), "255")) {
		printf ("5st test failed\n");
		exit (1);
	}
	else {
		printf ("Test 5 Passed\n");
	}
	if (!is_same (hex_to_decimal("1"), "1")) {
		printf ("6th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 6 Passed\n");
	}


	if (!is_same (hex_to_decimal("0"), "0")) {
		printf ("6th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 6 Passed\n");
	}

	if (!is_same (hex_to_decimal("1330"), "4912")) {
		printf ("7th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 7 Passed\n");
	}

	if (!is_same (hex_to_decimal("32748"), "206664")) {
		printf ("8th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 8 Passed\n");
	}

	if (!is_same (hex_to_decimal("77"), "119")) {
		printf ("9th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 9 Passed\n");
	}

	if (!is_same (octal_to_decimal("30"), "24")) {
		printf ("10th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 10 Passed\n");
	}
	if (!is_same (octal_to_decimal("0"), "0")) {
		printf ("11th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 11 Passed\n");
	}
	if (!is_same (octal_to_decimal("1"), "1")) {
		printf ("12th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 12 Passed\n");
	}
	if (!is_same (octal_to_decimal("100"), "64")) {
		printf ("13th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 13 Passed\n");
	}
	if (!is_same (octal_to_decimal("30041"), "12321")) {
		printf ("14th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 14 Passed\n");
	}
	if (!is_same (octal_to_decimal("277"), "191")) {
		printf ("14th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 14 Passed\n");
	}
	if (!is_same (decimal_to_octal("0"), "0")) {
		printf ("15th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 15 Passed\n");
	}
	if (!is_same (decimal_to_octal("10"), "12")) {
		printf ("16th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 16 Passed\n");
	}
	if (!is_same (decimal_to_octal("1"), "1")) {
		printf ("17th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 17 Passed\n");
	}
	if (!is_same (decimal_to_octal("277"), "425")) {
		printf ("18th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 18 Passed\n");
	}
	if (!is_same (decimal_to_hex("277"), "115")) {
		printf ("19th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 19 Passed\n");
	}
	if (!is_same (decimal_to_hex("1"), "1")) {
		printf ("19th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 19 Passed\n");
	}


	if (!is_same (decimal_to_hex("0"), "0")) {
		printf ("20th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 20 Passed\n");
	}
	if (!is_same (decimal_to_hex("3"), "3")) {
		printf ("21th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 21 Passed\n");
	}
	if (!is_same (decimal_to_hex("399"), "18F")) {
		printf ("22th test failed\n");
		exit (1);
	}
	else {
		printf ("Test 22 Passed\n");
	}
	if (!is_same (hex_to_octal("1"), "1")) {
		printf ("Hex - > octal test 1 failed\n");
		exit (1);
	}
	else {
		printf ("Hex -> octal test 1 passed\n");
	}
	if (!is_same (hex_to_octal("0"), "0")) {
		printf ("Hex - > octal test 2 failed\n");
		exit (1);
	}
	else {
		printf ("Hex -> octal test 2 passed\n");
	}
	if (!is_same (hex_to_octal("7"), "7")) {
		printf ("Hex - > octal test 3 failed\n");
		exit (1);
	}
	else {
		printf ("Hex -> octal test 3 passed\n");
	}
	if (!is_same (hex_to_octal("1F"), "37")) {
		printf ("Hex -> octal test 4 failed\n");
		exit (1);
	}
	else {
		printf ("Hex -> octal test 4 passed\n");
	}
	if (!is_same (hex_to_octal("24232"), "441062")) {
		printf ("Hex -> octal test 4 failed\n");
		exit (1);
	}
	else {
		printf ("Hex -> octal test 4 passed\n");
	}



	if (!is_same (hex_to_octal("D"), "15")) {
		printf ("Hex -> octal test 5 failed\n");
		exit (1);
	}
	else {
		printf ("Hex -> octall test 5 passed\n");
	}

	if (!is_same (octal_to_hex("0"), "0")) {
		printf ("oct -> hex test 1 failed\n");
		exit (1);
	}
	else {
		printf ("oct -> hex test 1 passed\n");
	}
	if (!is_same (octal_to_hex("1"), "1")) {
		printf ("oct -> hex test 2 failed\n");
		exit (1);
	}
	else {
		printf ("oct -> hex test 2 passed\n");
	}
	if (!is_same (octal_to_hex("3"), "3")) {
		printf ("oct -> hex test 3 failed\n");
		exit (1);
	}
	else {
		printf ("oct -> hex test 3 passed\n");
	}

	if (!is_same (octal_to_hex("7"), "7")) {
		printf ("oct -> hex test 4 failed\n");
		exit (1);
	}
	else {
		printf ("oct -> hex test 4 passed\n");
	}

	if (!is_same (octal_to_hex("12"), "A")) {
		printf ("oct -> hex test 5 failed\n");
		exit (1);
	}
	else {
		printf ("oct -> hex test 5 passed\n");
	}

	if (!is_same (octal_to_hex("25"), "15")) {
		printf ("oct -> hex test 6 failed\n");
		exit (1);
	}
	else {
		printf ("oct -> hex test 6 passed\n");
	}
	if (!is_same (octal_to_hex("12412"), "150A")) {
		printf ("oct -> hex test 6 failed\n");
		exit (1);
	}
	else {
		printf ("oct -> hex test 6 passed\n");
	}




	printf ("All tests are passed\n");
}


char* multi_hex_to_binary (char *input_value) {
	
	int len = get_length (input_value);
	int size = len * 4;
	char *result = malloc (200);
	int j = 0;
	int notthan0 = 0;
	for (int i = 0; i < len; i++) {
		int k = 0;
		if (input_value[i] != '0') {
			notthan0 = 1;
		}
		if (input_value[i] == '0' && i == 0) {
			result[i] = '0';
		}
		if (notthan0 == 0 && input_value[i] == '0') {
			continue;
		}
		char *arr = single_hex_to_binary (input_value[i]);
		while (k < 4) {
			result[j] = arr[k];
			j++;
			k++;
		}

	}
	return result;
}

char* single_hex_to_binary (char input) {
	
	int temp = 0;
	char *dummy = (char*) malloc (5);
	if (input >= 'A' && input <= 'F') {
		temp = input - 'A' + 10;
	}
	else if (input >= 'a' && input <= 'f') {
		temp = input - 'a' + 10;
	}
	else if (input >= '0' && input <= '9'){
		temp = input - '0';
	}
	else {
		printf ("Enter valid number format\n");
		exit(1);
	}
	int i = 3;
	while (i >= 0) {
		
		if (temp % 2 == 1) {
			dummy[i] = '1';
		}
		else {
			dummy[i] = '0';
		}
		temp /= 2;
		i--;
	}
	return dummy;
}
