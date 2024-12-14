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
            case 1:	add_user();
               		break;
            case 2: display_users();
                    break;
            case 3: update_user();
    				break;
            case 4: delete_user();
					break;
            case 5: exit(0);
            default:
                printf("Enter valid choice.\n");
        }
    }
    return 0;
}

void create_file() 
{
    FILE *file = fopen(file_name,"a");
    if( file == NULL){
        perror("file not created");
        exit(1);
    }
    fclose(file);
}

void add_user() 
{
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
    printf("Enter User ID: ");
    scanf("%d", &user.id);
    getchar();
    printf("Enter User Name: ");
    char c;
    while (scanf("%c", &c) == 1 && c != '\n') 
	{
        if (length + 1 >= capacity) 
        {
            capacity *= 2;
            char *new_name = (char *)realloc(user.name, capacity * sizeof(char));
            if (new_name == NULL) {
                printf("No Memory Allocated.\n");
                fclose(file);
                free(user.name);
                return;
            }
            user.name = new_name;
        }
        user.name[length++] = c;
    }
    user.name[length] = '\0';
    printf("Enter User Age: ");
    scanf("%d", &user.age);

    fprintf(file,"%-5d %-20s %-3d\n", user.id, user.name, user.age);
    free(user.name);
    fclose(file);
    printf("User added in file.\n");
}

void display_users() 
{
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
    while(fscanf(file, "%d %49s %d\n", &user.id, user.name, &user.age)==3) 
	{
        printf("%-5d %-20s %-3d\n", user.id, user.name, user.age);
    }
    free(user.name);
    fclose(file);
}

void update_user() 
{
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

    printf("Enter User ID to update: ");
    scanf("%d", &id);
    getchar();

    while(fscanf(file,"%d %49s %d\n", &user.id, user.name, &user.age)==3)  
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
            char c;
            while (scanf("%c", &c) == 1 && c != '\n') 
			{
                if (length + 1 >= capacity) 
				{
                    capacity *= 2;
                    char *new_name = (char *)realloc(user.name, capacity * sizeof(char));
                    if (new_name == NULL) {
                        printf("No Memory Allocated.\n");
                        free(user.name);
                        fclose(file);
                        fclose(tempFile);
                        return;
                    }
                    user.name = new_name;
                }
                user.name[length++] = c;
            }
            user.name[length] = '\0';
            printf("Enter new User Age: ");
            scanf("%d", &user.age);
            getchar();
        }
        fprintf(tempFile,"%-5d %-20s %-3d\n", user.id, user.name, user.age);
    }
    fclose(file);
    fclose(tempFile);

    if(found) {
        remove(file_name);
        rename("temp.txt", file_name);
        printf("User updated.\n");
    } else {
        remove("temp.txt");
        printf("User not found.\n");
    }
    if (user.name) {
        free(user.name);
    }
}

void delete_user() 
{
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

    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    while(fscanf(file,"%d %49s %d\n", &user.id, user.name, &user.age)==3) 
	{
        if(user.id!=id) {
            fprintf(tempFile,"%-5d %-20s %-3d\n", user.id, user.name, user.age);
        } else {
            found=1;
        }
    }

    fclose(file);
    fclose(tempFile);
    if(found) {
        remove(file_name);
        rename("temp.txt",file_name);
        printf("User deleted.\n");
    } else {
        remove("temp.txt");
        printf("User not found.\n");
    }
    free(user.name);
}
