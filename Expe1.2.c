 #include <stdio.h>
 #include<stdlib.h>
 struct node
 {
    int info;
     struct node *link };
     struct node *start ;
 void main()
 {
     int c;    
     int b;
         printf("Enter 1 for insertion\n");
         printf("Enter 2 for traverse\n");
         printf("Enter 3 for delete\n");
         printf("Enter 4 for exit\n");
    while(b != 0){
        void clearScreen();
       

     printf("Input your choice: ");
    scanf("%d", &c);

     switch(c)
     {
         case 1:
             insert();
             break;
         case 2:
             traverse();
             break;

         case 3:
             delete1();
             break;

         case 4:
              exit(0);

         default:
             printf("Wrong Choice\n");
     }
     b--;
   }
 }

 
 void insert()
 {
     struct node *new, *ptr;
     int data;

     new = (struct node *)malloc(sizeof(struct node));

     
     printf("Enter the data: ");
     scanf("%d", &data);

     new->info = data;
     new->link = NULL;

     if(start == NULL)
     {
         start = new;
     }
     else
     {
         ptr = start;

         while(ptr->link != NULL)
         {
             ptr = ptr->link;
         }
         ptr->link = new;
   }
 }

 void traverse()
 {
     struct node *ptr;
     ptr = start;

     while(ptr != NULL)
     {
        printf("%d\n", ptr->info);
         ptr = ptr->link;
     }
 }

void delete1(){
    struct node *ptr;

    if(start == NULL){
        printf("Linkedlist is empty\n");
    }

    else{
        ptr = start;
        start = start-> link;
        printf("%d, is deleted\n", ptr->info);
    }
}


