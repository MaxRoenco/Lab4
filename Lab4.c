#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define BUFFER_SIZE 100
#define CONST_SIZE 100
#define clean() while(getchar() != '\n')

void make_upper(){
char string[BUFFER_SIZE];
printf("Input word: ");
fgets(string, BUFFER_SIZE, stdin);
    for(int i = 0; string[i] != '\n'; i++){
        if(string[i] >= 97 && string[i] <= 122 ){
            string[i] -= 32;
        }
    }
printf("String upper: %s\n", string);
}

void count_vowels(){
char string[BUFFER_SIZE];
printf("Input string: ");
fgets(string, BUFFER_SIZE, stdin);
int length = strlen(string);
int count = 0;
for(int i = 0; string[i] != '\n'; i++){
        if(string[i] >= 97 && string[i] <= 122 ){
            string[i] -= 32;
        }
    }
    for(int i =0; i < length; i++){
        switch(string[i]){
            case 'A':
            case 'E':
            case 'U':
            case 'I':
            case 'O':
            case 'Q':
            case 'Y':
                count++;
        }
    }
printf("Number of vowels in string: %d\n", count);
}

void palindrom(){
char string[BUFFER_SIZE];
printf("Input word: ");
fgets(string, BUFFER_SIZE, stdin);
int length = strlen(string);
int is_palindrom = 1;
    for(int i = 0, j = length - 2; i < j; i++, j--){
            if(string[i] != string[j]){
                is_palindrom = 0;
                break;
            }
    }
    if(is_palindrom){
        printf("It's palindrom\n");
    }else{
        printf("It's not palindrom\n");
    }
}

int is_letter(char c){
return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c <= '9' && c >= '0'));
}

int is_alphabet(char c){
return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

void word_count(){
char string[BUFFER_SIZE];
printf("Input string: ");
fgets(string, BUFFER_SIZE, stdin);
int len = strlen(string);
string[len - 1] = '\0';
int index = 0;
int words = 0;
    while(index < len - 1){
        if(is_letter(string[index])){
            words++;
            index++;
        while(is_letter(string[index]) && index < len){
            index++;
                }
        }else{
            index++;
        }
    }
printf("Number of words: %d\n", words);
}

void swap(char* a, char* b){
    char temp = *a;
         *a = *b;
         *b = temp;
}

void rotate(char* word_2){
    int len = strlen(word_2);
        for(int j = 0 ; j < len - 1; j++){
            swap(&word_2[j], &word_2[j + 1]);
        }
}

int rotation(char* word_1, char* word_2){
    int result = 0;
    int len = strlen(word_1);
    for(int i = 0; i < len; i++){
        rotate(word_2);
        if(strcmp(word_1, word_2) == 0){
            result = 1;
            break;
        }
    }
    return result;
}


int rotation_main(){
char word_1[BUFFER_SIZE];
char word_2[BUFFER_SIZE];
printf("Input word 1: ");
scanf("%s", &word_1);
printf("Input word 2: ");
scanf("%s", &word_2);
    if(rotation(word_1, word_2)) {
        printf("Is rotation\n");
    } else {
        printf("Not rotation\n");
    }
}

void mark_punctuation(){
char string[BUFFER_SIZE];
printf("Input string: ");
fgets(string, CONST_SIZE, stdin);
int len = strlen(string);
string[len - 1] = '\0';
int marks = 0;
    for(int i = 0; i < len; i++){
        if((string[i] > ' ' && string[i] < '0')  || (string[i] > '9' && string[i] < 'A')  || (string[i] > 'Z' && string[i] < 'a')  || (string[i] > 'z' && string[i] < 127)){
            marks++;
        }
    }
printf("\nMarks: %d\n", marks);
}

int value_of(char c) {
    char chars[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    int len = 52;
    for(int i = 0; i < len; i++) {
        if(c == chars[i]) {
            return i+1;
        }
    }
    return 0;
}

void sort(){
char string[BUFFER_SIZE];
printf("Input string: ");
fgets(string, CONST_SIZE, stdin);
int len = 0;
len = strlen(string);
string[len - 1] = '\0';
    for(int i = len; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(!value_of(string[j]) || !value_of(string[j+1])){
                continue;
            }
            if(value_of(string[j]) > value_of(string[j+1])) {
                swap(&string[j], &string[j + 1]);
            }

        }
    }
printf("String sorted: %s\n", string);
}
/*
void swap_str(char* arr1, char* arr2){
    int step = 0;
    char arr_temp[BUFFER_SIZE];
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    if(len1 >= len2){
         step = len1;
    } else{
         step = len2;
    }
    for(int i = 0; i < step; i++){
        arr_temp[i] = *arr1[i];
        *arr1[i] = *arr2[i];
        *arr2[i] = arr_temp[i];
    }
}
*/
void Kulev_task() {
    char string[BUFFER_SIZE];
    printf("Input string: ");
    fgets(string, BUFFER_SIZE, stdin);
    int len = strlen(string);
    string[len - 1] = '\0';

    int index = 0;
    int words = 0;

    while (index < len) {
        if (is_letter(string[index])) {
            words++;
            while (is_letter(string[index]) && index < len) {
                index++;
            }
        } else {
            index++;
        }
    }

    index = 0;
    int i = 0;
    char* array[words];

    while (index < len) {
        if (is_letter(string[index])) {
            int index_array = 0;
            array[i] = (char*)malloc(BUFFER_SIZE);
            while (is_letter(string[index]) && index < len) {
                array[i][index_array] = string[index];
                index++;
                index_array++;
            }
            array[i][index_array] = '\0';
            i++;
        } else {
            index++;
        }
    }

    char arr_temp[BUFFER_SIZE];

    for (int j = words - 1; j > 0; j--) {
        i = 0;
        for (int m = 0; m < j; m++) {
            for (int k = 0; k < strlen(array[m]) || k < strlen(array[m + 1]); k++) {
                while(!is_alphabet(array[m][k])){
                    k++;
                }
                while(!is_alphabet(array[m+1][i])){
                    i++;
                }
                if (value_of(array[m][k]) > value_of(array[m + 1][i])) {
                    strcpy(arr_temp, array[m]);
                    strcpy(array[m], array[m + 1]);
                    strcpy(array[m + 1], arr_temp);
                    break;
                }else if(value_of(array[m][k]) < value_of(array[m + 1][i])){
                    break;
                } else if (value_of(array[m][k]) == value_of(array[m + 1][i])){
                    continue;
                }
            }
        }
    }

    printf("Sorted strings:\n");
    for (int g = 0; g < words; g++) {
        printf("%s ", array[g]);
    }
    printf("\n");
    printf("The smallest string: %s\n", array[0]);

    for (int g = 0; g < words; g++) {
        free(array[g]);
    }
}

int main(){
int i;
char word_1[CONST_SIZE];
char word_2[CONST_SIZE];
start:
printf("\t1 - Easy 1 : Palindrom word or not\n");
printf("\t2 - Easy 2 : Make uppercase\n");
printf("\t3 - Easy 3 : Count vowels in string\n");
printf("\t4 - Easy 4 : Count words in the string\n");
printf("\t5 - Medium 1 : Rotation\n");
printf("\t6 - Medium 2 : Count punctuations\n");
printf("\t7 - Medium 5 : String  sorted alphabetically\n");
printf("\t8 - Kulev task Variant 4: Determine the 'smallest' word in the meaning lexicographic.\n");
printf("\t9 - Exit\n");
scanf("%d", &i);
clean();
    if(i == 1){
    palindrom();
    } else if(i == 2){
    make_upper();
    } else if(i == 3){
    count_vowels();
    } else if(i == 4){
    word_count();
    } else if(i == 5){
    rotation_main();
    } else if(i == 6){
    mark_punctuation();
    } else if(i == 7){
    sort();
    } else if(i == 8){
    Kulev_task();
    } else if(i == 9){
        return 0;
    }
goto start;
}
