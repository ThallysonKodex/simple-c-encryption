#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt_message(char [1000]);
void decrypt_message(char [1000]);
int set_passkey(const char [10]);
int has_zeros(const char [10]);
int calculate_add_up(const char [10]);

char passkey[10];


int main(){

	char to_set[10];

	for(int i = 0; i < 10; i++){
		to_set[i] = 1;
	}

	printf("Choose a passkey (no zeros, 10 characters): ");
	scanf("%s", to_set);
	int passkey_set = set_passkey(to_set);
	
	if(passkey_set == 1){
		exit(0);
	}
	

	printf("%s\n", passkey);


	char message[2000] = "Hello, World!";
	encrypt_message(message);

	printf("Modified Message: %s\n", message);

	return 0;

}

void encrypt_message(char strr[]) {
	int add_up = calculate_add_up(passkey);

	for (int i = 0; i < strlen(strr); i++) {
		if (isalpha(strr[i])) {
			if (isupper(strr[i])) {
				strr[i] = (strr[i] - 'A' + add_up) % 26 + 'A';
			} else {
				strr[i] = (strr[i] - 'a' + add_up) % 26 + 'a';
			}
		}
	}
}

void decrypt_message(char strr[]) {
	int add_up = calculate_add_up(passkey);

	for (int i = 0; i < strlen(strr); i++) {
		if (isalpha(strr[i])) {
			if (isupper(strr[i])) {
				strr[i] = (strr[i] - 'A' - add_up + 26) % 26 + 'A';
			} else {
				strr[i] = (strr[i] - 'a' - add_up + 26) % 26 + 'a';
			}
		}
	}
}

int calculate_add_up(const char p_passkey[10]) {
	int add_up = 0;
	for (int i = 0; i < 10; i++) {
		add_up += p_passkey[i] - '0';
	}
	return add_up;
}

int set_passkey(const char p_passkey[10]){
	if(strlen(p_passkey) > 10){
		printf("Passkey is more than 10 characters.\n");
		return 1;
	}
		
	if(has_zeros(p_passkey) == 1){
		printf("Passkey cannot contain zeros\n");
		return 1;
	} else {

		for(int i = 0; i < 10; i++){
			passkey[i] = p_passkey[i];
		}
	}

		

	return 0;
}

int has_zeros(const char p_passkey[10]){
	

	for(int i = 0; i < 10; i++){
		if(p_passkey[i] == 0){
			return 1;
		}
	}

	return 0;
}
