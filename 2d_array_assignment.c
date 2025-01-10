#include <stdio.h>
#define MAXIMUM_ROWS 10
#define MAXIMUM_COLUMNS 101
#define MAXIMUM_STRING_LENGTH 50

int starts_with_vowel(char name[]) {
     char first_character = name[0];
    return (first_character == 'a' || first_character == 'e' || first_character == 'i' || first_character == 'o' || first_character == 'u' || first_character == 'A' || first_character == 'E' || first_character == 'I' || first_character == 'O' || first_character == 'U');
}

int string_length(char string[]) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

void string_copy(char destination[], char source[]) {
    int index = 0;
    while (source[index] != '\0') {
        destination[index] = source[index];
        index++;
    }
    destination[index] = '\0';
}

void find_longest_name(char names[MAXIMUM_ROWS][MAXIMUM_COLUMNS][MAXIMUM_STRING_LENGTH + 1], int rows, int columns, char longest_name[]) {
    int maximum_length = 0, row_index, column_index, length;
    for (row_index = 0; row_index < rows; row_index++) {
        for (column_index = 0; column_index < columns; column_index++) {
            length = string_length(names[row_index][column_index]);
            if (length > maximum_length) {
                maximum_length = length;
                string_copy(longest_name, names[row_index][column_index]);
            }
        }
    }
}

int validate_integer(const char *prompt, int minimum_value, int maximum_value) {
    int value, valid;
    do {
        printf("%s", prompt);
        valid = scanf("%d", &value);
        while (getchar() != '\n');
        if (!valid || value < minimum_value || value > maximum_value) {
            printf("Invalid input. Please enter an integer between %d and %d.\n", minimum_value, maximum_value);
        }
    } while (!valid || value < minimum_value || value > maximum_value);
    return value;
}

int main() {
    int rows, columns, row_index, column_index;
	rows = validate_integer("Enter number of rows: ", 1, 10);
    columns = validate_integer("Enter number of columns: ", 1, 101);

    char names[MAXIMUM_ROWS][MAXIMUM_COLUMNS][MAXIMUM_STRING_LENGTH + 1];

    printf("Enter the names:\n");
    for (row_index = 0; row_index < rows; row_index++) {
        for (column_index = 0; column_index < columns; column_index++) {
            while(1){
                printf("Name at (%d,%d): ", row_index, column_index);
                scanf("%s", names[row_index][column_index]);
                if(string_length (names[row_index][column_index]) < MAXIMUM_STRING_LENGTH){
                    break;
                } else{
                    printf("Name is too long. Please enter a name with 50 characters.\n");
                }
            }
        }
    }

    printf("\nThe 2D array of names is:\n");
    for (row_index = 0; row_index < rows; row_index++) {
        for (column_index = 0; column_index < columns; column_index++) {
            printf("%s ", names[row_index][column_index]);
        }
        printf("\n");
    }

    int count_vowels = 0;
    for (row_index = 0; row_index < rows; row_index++) {
        for (column_index = 0; column_index < columns; column_index++) {
            if (starts_with_vowel(names[row_index][column_index])) {
                count_vowels++;
            }
        }
    }
    printf("\nNumber of names starting with a vowel: %d\n", count_vowels);

    char longest_name[MAXIMUM_STRING_LENGTH + 1];
    find_longest_name(names, rows, columns, longest_name);
    printf("The longest name: %s\n", longest_name);

    return 0;
}
