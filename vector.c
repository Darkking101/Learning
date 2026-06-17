#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {

	int *data;
	int length;
	int size;
} vectar;

vectar create_vectar();
vectar create_verctar_with_size(int size);
void clear(vectar *vec);
void pop(vectar *vec);
void push(vectar *vec, int data);
int compare(vectar *vec_a, vectar *vec_b);
vectar reverse(vectar *vec);
vectar clone(vectar *vec);
void insert_at(vectar *vec, int index, int data);
void remove_at(vectar *vec, int index);
void test();

vectar create_vectar() {
	
	vectar new_vectar;
	new_vectar.data = NULL;
	new_vectar.length = 0;
	new_vectar.size = 0;
	return new_vectar;
}

vectar create_vectar_with_size(int size) {

	vectar new_vectar;
	new_vectar.data = malloc(size * sizeof(int));
	new_vectar.length = 0;
	new_vectar.size = size;
	return new_vectar;
}

void clear(vectar *vec) {
	
	if(vec -> length == 0) {
		return;
	}
	int i = 0;
	while(i <= (vec -> length)) {
		vec -> data[i] = 0;
		i++;
	}
	vec -> length = 0;
	return;
}

void pop(vectar *vec) {

	if(vec -> size == 0) {
		return;
	}
	vec -> data[vec -> length - 1] = 0;
	vec -> length--;
	return;
}

void push(vectar *vec, int data) {

	if(vec -> size == 0) {
		vec -> data = malloc(sizeof(int));
		vec -> size = 1;
	}
	if(vec -> length == vec -> size) {
		int *temp = malloc((vec -> size * 2) * sizeof(int));
		memcpy(temp, vec -> data, (vec -> size * sizeof(int)));
		free(vec -> data);
		vec -> data = temp;
		vec -> size *= 2;
	}
	vec -> data[vec -> length] = data;
	vec -> length++;
	return;
}

int compare(vectar *vec_a, vectar *vec_b) {

	if((vec_a -> length) != (vec_b -> length)) {
		return 0;
	}
	int i = 0;
	while(i < (vec_a -> size)) {
		if((vec_a -> data[i]) != (vec_b -> data[i]))
			return 0;
		i++;
	}
	return 1;
}

vectar reverse(vectar *vec) {

	if((vec -> length) == 0) {
		return create_vectar();
	}
	vectar reversed_vec = create_vectar_with_size(vec -> size);
	reversed_vec.size   = vec -> size;
	reversed_vec.length = vec -> length;
	int vec_length      = vec -> length - 1;
	int i = vec_length;
	while(i >= 0) {
		reversed_vec.data[vec_length - i] = vec -> data[i];
		i--;
	}
	return reversed_vec;
}

void self_reverse(vectar *vec) {

	int i = 0;
	int length = (vec -> length) - 1;
	while(i < length) {
		int temp = vec -> data[i];
		vec -> data[i] = vec -> data[length];
		vec -> data[length] = temp;
		i++;
		length--;
	}
	return;
}

vectar clone(vectar *vec) {

	if((vec -> length) == 0) {
		return create_vectar_with_size(vec -> size);
	}
	vectar cloned_vec = create_vectar_with_size(vec -> size);
	cloned_vec.length = vec -> length;
	cloned_vec.size   = vec -> size;
	int i             = vec -> length - 1;
	while(i >= 0) {
		cloned_vec.data[i] = vec -> data[i];
		i--;
	}
	return cloned_vec;
}

void insert_at(vectar *vec, int index, int data) {
	
	if(index > (vec -> length)) {
		return;
	}
	if(index == (vec -> length)) {
		vec -> data[index] = data;
		return;
	}
	int i = index;
	int temp = (vec -> data[i]);
	while(i < (vec -> length - 1)) {
		vec -> data[i] = data; 
		data           = temp;
		temp           = vec -> data[i+1];
		i++;
	}
	return;
	
}

void remove_at(vectar *vec, int index) {

	if(index > (vec -> length - 1)) {
		return;
	}
	int i = index;
	while(i < (vec -> length - 1)) {
		vec -> data[i] = vec -> data[i + 1];
		i++;
	}
	vec -> data[i] = 0;
	return;
}

void display(vectar *vec) {

	int i = 0;
	while (i < (vec -> length - 1)) {
		printf("%d, ", vec -> data[i]);
		i++;
	}
	printf("%d\n", vec -> data[i]);
	return;
}

int main() {

	test();
	return 0;
}

void test() {

	vectar vec  = create_vectar();
	vectar vec2 = create_vectar();

	push(&vec, 0);
	if(vec.data[0] != 0) {
		printf("push test 1 failed\n");
		exit(1);
	}	else {
		printf("push test 1 passed\n");
	}
	push(&vec, 1);
	if(vec.data[1] != 1) {
		printf("push test 2 failed\n");
		exit(1);
	}	else {
		printf("push test 2 passed\n");
	}
	push(&vec, -1);
	if(vec.data[2] != -1) {
		printf("push test 3 failed\n");
		exit(1);
	}	else {
		printf("push test 3 passed\n");
	}
	push(&vec, -100);
	if(vec.data[3] != -100) {
		printf("push test 4 failed\n");
		exit(1);
	}	else {
		printf("push test 4 passed\n");
	}
	push(&vec, 1000);
	if(vec.data[4] != 1000) {
		printf("push test 5 failed\n");
		exit(1);
	}	else {
		printf("push test 5 passed\n");
	}
	
	pop(&vec);
	if(vec.length != 4) {
		printf("pop test 1 failed\n");
		exit(1);
	}	else {
		printf("pop test 1 passed\n");
	}
	pop(&vec);
	if(vec.length != 3) {
		printf("pop test 2 failed\n");
		exit(1);
	}	else {
		printf("pop test 2 passed\n");
	}
	pop(&vec);
	if(vec.length != 2) {
		printf("pop test 3 failed\n");
		exit(1);
	}	else {
		printf("pop test 3 passed\n");
	}

	push(&vec, 1000);
	if(vec.data[2] != 1000) {
		printf("push test 6 failed\n");
		exit(2);
	}	else {
		printf("push test 6 passed\n");
	}
	push(&vec, 2000);
	if(vec.data[3] != 2000) {
		printf("push test 7 failed\n");
		exit(1);
	}	else {
		printf("push test 7 passed\n");
	}
	
	clear(&vec);
	if(vec.length != 0) {
		printf("clear test failes\n");
		exit(1);
	}	else {
		printf("clear test passed\n");
	}
	for(int i = 0; i < 60; i += 10) {
		push(&vec, i);
		push(&vec2, i);
	}

	if(compare(&vec, &vec2) != 1) {
		printf("compare test 1 failed\n");
		exit(1);
	}	else {
		printf("compare test 1 passed\n");
	}
	push(&vec, 7770);
	if(compare(&vec, &vec2) != 0) {
		printf("compare test 2 failed\n");
		exit(1);
	}	else {
		printf("compare test 2 passed\n");
	}

	vectar cloned_vec = clone(&vec);
	if(compare(&vec, &cloned_vec) != 1) {
		printf("clone test 1 failed\n");
		exit(1);
	}	else {
		printf("clone test 1 passed\n");
	}

	clear(&vec2);
	cloned_vec = clone(&vec2);
	if(compare(&vec, &cloned_vec) != 0) {
		printf("clone test 2 failed\n");
		exit(1);
	}	else {
		printf("clone test 2 passed\n");
	}

	cloned_vec = reverse(&cloned_vec);
	self_reverse(&cloned_vec);
	if(compare(&vec, &cloned_vec) != 0) {
		printf("reverse & self reverse test 1 failed\n");
		exit(1);
	}	else {
		printf("reverse & self reverse test 1 passed\n");
	}

	insert_at(&vec, 0, 0);
	if(vec.data[0] != 0) {
		printf("insert test 1 failed\n");
		exit(1);
	}	else {
		printf("insert test 1 passed\n");
	}
	insert_at(&vec, 2, 2);
	if(vec.data[2] != 2) {
		printf("insert test 2 failed\n");
		exit(1);
	}	else {
		printf("insert test 2 passed\n");
	}
	insert_at(&vec, 1, 1);
	if(vec.data[1] != 1) {
		printf("insert test 3 failed\n");
		exit(1);
	}	else {
		printf("insert test 3 passed\n");
	}
	insert_at(&vec, 0, 110);
	if(vec.data[0] != 110) {
		printf("insert test 4 failed\n");
		exit(1);
	}	else {
		printf("insert test 4 passed\n");
	}

	remove_at(&vec, 0);
	if(vec.data[0] == 110) {
		printf("remove test 1 failed\n");
		exit(1);
	}	else {
		printf("remove test 1 passed\n");
	}
	remove_at(&vec, 0);
	if(vec.data[0] == 0) {
		printf("remove test 2 failed\n");
		exit(1);
	}	else {
		printf("remove test 2 passed\n");
	}
	remove_at(&vec, 0);
	if(vec.data[0] == 1) {
		printf("remove test 3 failed\n");
		exit(1);
	}	else {
		printf("remove test 3 passed\n");
	}
	remove_at(&vec, 0);
	if(vec.data[0] == 0) {
		printf("remove test 4 failed\n");
		exit(1);
	}	else {
		printf("remove test 4 passed\n");
	}

	return;
}
