#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define file_name "users.txt"

typedef struct {
    int id;
    char *name;
    int age;
} User;

void create_file();
void add_user();
void display_users();
void update_user();
void delete_user();
void overwrite_file(const char *temp_file_name, const char *original_file_name);
int check_duplicate_id(int id);
void delete_temp_file(const char *filename);
void input_user_name(User *user);
void handle_file_operation(FILE *file, FILE *tempFile, const char *temp_file_name, int found, User *user);
int get_valid_int_input(const char *prompt);

int main() 
{
    int choice;
    create_file();
    while(1) {
        printf("\nUser CRUD Operations\n");
        printf("1.CREATE (Add a new user to the file).\n");
        printf("2.READ (Display all users stored in the file).\n");
        printf("3.UPDATE (Modify the details of a user based on ID).\n");
        printf("4.DELETE (Remove a user by their ID).\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_user(); break;
            case 2: display_users(); break;
            case 3: update_user(); break;
            case 4: delete_user(); break;
            case 5: exit(0);
            default: printf("Enter valid choice.\n");
        }
    }
    return 0;
}

void create_file() {
    FILE *file = fopen(file_name,"a");
    if( file == NULL){
        perror("file not created");
        exit(1);
    }
    fclose(file);
}

void add_user() {
    FILE *file = fopen(file_name, "a");
    if(file == NULL) {
        perror("file not opening");
        return;
    }
    User user;
    user.name = NULL;
    int capacity = 10, length = 0;
    user.name = (char *)malloc(capacity * sizeof(char));
    if (user.name == NULL){
        printf("No Memory Allocated.\n");
        fclose(file);
        return;
    }
    user.id = get_valid_int_input("Enter User ID: ");
    if (check_duplicate_id(user.id)) {
        printf("User with ID %d already exists.\n", user.id);
        free(user.name);
        fclose(file);
        return;
    }
    getchar();
    printf("Enter User Name: ");
    input_user_name(&user);
    user.age = get_valid_int_input("Enter User Age: ");

    fprintf(file,"%-5d %-20s %-3d\n", user.id, user.name, user.age);
    free(user.name);
    fclose(file);
    printf("User added in file.\n");
}

void display_users() {
    FILE *file = fopen(file_name, "r");
    if(file == NULL) {
        perror("file not opening");
        return;
    }
    User user;
    user.name = (char *)malloc(50 * sizeof(char));
    if (user.name == NULL) {
        printf("No Memory Allocated.\n");
        fclose(file);
        return;
    }
    printf("\nList of Users:\n");
    printf("\n%-5s %-20s %-3s\n", "ID", "Name", "Age");
    printf("--------------------------------\n");
    while(fscanf(file, "%d %49[^0-9] %d\n", &user.id, user.name, &user.age)==3) 
	{
        printf("%-5d %-20s %-3d\n", user.id, user.name, user.age);
    }
    free(user.name);
    fclose(file);
}

void update_user() {
    FILE *file = fopen(file_name,"r");
    if(file == NULL) {
        perror("file not opening");
        return;
    }
    int id,found=0;
    User user;
    user.name = (char *)malloc(50 * sizeof(char));
    FILE *tempFile = fopen("temp.txt","w");
    if(tempFile == NULL) {
        perror("Error in creating temporary file");
        fclose(file);
        return;
    }

    id = get_valid_int_input("Enter User ID to update: ");
    getchar();

    while(fscanf(file,"%d %49[^0-9] %d\n", &user.id, user.name, &user.age)==3)  
	{
        if(user.id==id) {
            found=1;
            printf("Enter new User Name: ");
            int capacity = 10, length = 0;
            user.name = (char *)malloc(capacity * sizeof(char));
            if (user.name == NULL) {
                printf("No Memory Allocated.\n");
                fclose(file);
                fclose(tempFile);
                return;
            }
            input_user_name(&user);
            user.age = get_valid_int_input("Enter new User Age: ");
            getchar();
        }
        fprintf(tempFile,"%-5d %-20s %-3d\n", user.id, user.name, user.age);
    }
    fclose(file);
    fclose(tempFile);
    handle_file_operation(file, tempFile, "temp.txt", found, &user);
}

void delete_user() {
    FILE *file = fopen(file_name, "r");
    if(file == NULL) {
        perror("file not opening");
        return;
    }
    int id,found=0;
    User user;
    user.name = (char *)malloc(50 * sizeof(char));
    if (user.name == NULL) {
        printf("No Memory Allocated.\n");
        fclose(file);
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if(tempFile == NULL) {
        perror("Error in creating temporary file");
        fclose(file);
        return;
    }
    id = get_valid_int_input("Enter User ID to delete: ");
    while(fscanf(file,"%d %49[^0-9] %d\n", &user.id, user.name, &user.age)==3) 
	{
        if(user.id!=id) {
            fprintf(tempFile,"%-5d %-20s %-3d\n", user.id, user.name, user.age);
        } else {
            found=1;
        }
    }
    fclose(file);
    fclose(tempFile);
    handle_file_operation(file, tempFile, "temp.txt", found, &user);
}

void overwrite_file(const char *temp_file_name, const char *original_file_name) {
    FILE *temp = fopen(temp_file_name, "r");
    FILE *original = fopen(original_file_name, "w");
    if (temp == NULL || original == NULL) {
        perror("Error in overwriting file");
        if (temp) fclose(temp);
        if (original) fclose(original);
        return;
    }
    char ch;
    while ((ch = fgetc(temp)) != EOF) {
        fputc(ch, original);
    }
    fclose(temp);
    fclose(original);
    delete_temp_file(temp_file_name);
}

int check_duplicate_id(int id) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("File not opening");
        return 0;
    }
    User user;
    user.name = (char *)malloc(50 * sizeof(char));
    if (user.name == NULL) {
        printf("No memory allocated.\n");
        fclose(file);
        return 0;
    }
    while (fscanf(file, "%d %49[^0-9] %d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == id) {
            free(user.name);
            fclose(file);
            return 1;
        }
    }
    free(user.name);
    fclose(file);
    return 0;
}

void delete_temp_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fclose(file);
        if (unlink(filename) != 0) {
            perror("Error deleting temporary file");
        }
    }
}

void input_user_name(User *user) {
    int capacity = 10, length = 0;
    char c;
    while (1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        if (length + 1 >= capacity) {
            capacity *= 2;
            char *new_name = (char *)realloc(user->name, capacity * sizeof(char));
            if (new_name == NULL) {
                printf("No Memory Allocated.\n");
                free(user->name);
                return;
            }
            user->name = new_name;
        }
        user->name[length++] = c;
    }
    user->name[length] = '\0';
}

void handle_file_operation(FILE *file, FILE *tempFile, const char *temp_file_name, int found, User *user) {
    if(found) {
        overwrite_file(temp_file_name, file_name);
        printf("Operation completed successfully.\n");
    } else {
        delete_temp_file(temp_file_name);
        printf("User not found.\n");
    }
    free(user->name);
}

int get_valid_int_input(const char *prompt) {
    int num;
    int valid_input = 0;
    while (!valid_input) {
        printf("%s", prompt);
        if (scanf("%d", &num) == 1) {
            valid_input = 1;
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n');
        }
    }
    return num;
}