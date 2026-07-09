#include <stdio.h>

#include <string.h>

#include <stdlib.h>


typedef struct {

    char *Item_name;

    int count;

    int price;
}Details;
typedef struct {

    char Name[40];

    int *orders;

    int number_orders;

    int total;

    Details *Myorders;

    

}Customer;


Customer* create_customer(char *name) {
    // حجزنا مساحة للزبون جوة الدالة بالـ malloc
    Customer *new_guest = (Customer *) malloc(sizeof(Customer));
    
    if (new_guest == NULL) {

        printf("faild save in memory \n");

        return NULL;
    }
    strncpy(new_guest->Name ,name ,sizeof(new_guest->Name) - 1);

    new_guest->Name[strcspn(new_guest->Name , "\n")] = '\0';

    new_guest->number_orders = 0;

    

    new_guest->orders =NULL;

    new_guest->Myorders = NULL;

    new_guest->total = 0;



    
    
    return new_guest; // رجعنا عنوان الزبون للـ main!
}



void Menu(Customer *guest) {

    int count_orders = 0;
    
    printf("The user _%s \n",guest->Name);
    

    printf("enter number_orders:");

    scanf("%d" , &count_orders);

    while((getchar()) != '\n');

    

    Customer **orders = (Customer **) malloc(count_orders * sizeof(Customer *);
    
    printf("1-Tea = 10 \n");

    printf("2-Milk Tea = 20 \n");

    printf("3-coffe = 30 \n");

    printf("4-Mango joice = 40 \n");

    printf("5-Water = 5 \n");

    


int main() {
    long long  number_customers;
    printf("enter numbers_customers:");

    scanf("%lld" , &number_customers);

    Customer **all_customers =(Customer **) malloc(number_customers * sizeof(Customer *));

    if (all_customers == NULL) {

        printf("faild to save in memory \n");

        return 1;
    }


    getchar();


    for (int i = 0 ; i < number_customers ; i++ ) {
        char NAME[40];

        printf("enter your name_customer:");

        fgets(NAME , sizeof(NAME) , stdin);

        all_customers[i] = create_customer(NAME);

    }


    




    return 0;
}