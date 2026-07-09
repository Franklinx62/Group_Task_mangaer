#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {

    char *Name;

    int age;


}Person;


typedef struct {

    Person **c;

    int count;
}group;

Person* create_thing(char *name , int age ) {

    int length = strlen(name);

    // كدا عايزين ننشئ مساحة الشخص

    Person *person  = (Person *) malloc(sizeof(Person));

    if (!person) {

        printf("faild save in memory \n");

        return NULL;
    }


    person->age = age;

    person->Name = (char *) malloc((length + 1) * sizeof(char));
    if (!person->Name) {

        printf("Faild save in memory \n");

        return NULL;
    }

    strcpy(person->Name  , name );


    return person;
}

void Menu(int n) {

    for (int i = 0 ; i < n ; i++ ) {

        printf("%d-Person\n",i+1);
    }

}
int main() { 

    int count_people = 0;

    printf("enter the number Persons:");

    scanf("%d" , &count_people);

    getchar();

    group my_group;

    my_group.count = count_people;

    my_group.c = (Person **) malloc(count_people * sizeof(Person *));


    for (int i = 0 ; i < count_people ; i ++ ) {

        char Name[40];

        int age = 0;

        printf("enter the Name:");

        fgets(Name , sizeof(Name) , stdin);

        Name[strcspn(Name , "\n" ) ] = '\0';

        printf("enter the age:");

        scanf("%d" , &age);

        while((getchar()) !='\n');

        my_group.c[i] = create_thing(Name , age);



    } 

    do {
        int choose = 0;
        Menu(count_people);

        printf("%d-Exit \n",count_people + 1);

        printf("enter your choice:");

        scanf("%d" , &choose);

        if (choose > count_people + 1) {

            printf("wrong choice \n");

            continue;
        }

        else if (choose == count_people + 1) {

            break;
        }

        else {

            int index = choose - 1;

            printf("============== User_ %d ==================\n", choose);

            printf("the user_Name = %s \n" , my_group.c[index]->Name);

            printf("the Age = %d \n" ,my_group.c[index]->age);
            
            printf("==========================================\n");

        }

    }while(1);

    for (int i = 0; i < count_people; i++) {

        free(my_group.c[i]->Name);

        free(my_group.c[i]);

    }
    
    
    free(my_group.c);

    return 0;
}

