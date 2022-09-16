#include <stdio.h>
#include <stdlib.h>

/* === Creating the data structure === */

typedef struct // I've used typedef to make my code more readable and easier to debug
{

    char *Fname; // array of chars to hold the first name 
    char *Lname; // array of chars to hold the last name
    int day; // int var to hold day of birth
    int month; // int var to hold month of birth
    int year; // int var to hold year of birth
    int age; // int var to hold age

}Student;

/* === end === */

/* === Bubble sort === */

int bubbleSort(int arr[])
{

    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 5 ; j++){

            if(arr[j] < arr[j+1]){

                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }

        }

    }

    for(int k = 0; k < 5; k++){

        printf("%d\n", arr[k]);

    };

};

/* === a function to calculate the exact age === */

void exactAge(int present_day, int birthDay, int present_month, int birthMonth, int birthYear, int present_Year)
{

    int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if(birthDay > present_day)
    {

        present_day = present_day + month[birthMonth - 1];
        present_month = present_month - 1;

    }


    int final_date = present_day - birthDay;
    int final_month = present_month - birthMonth;
    int final_year = present_Year - birthYear;

    printf("Your present age : %d years old %d months and %d days :",final_year,final_month, final_date);

};

/* === a function to create student accounts and show them if thr user wants to === */


void CreatingAndShowingStudents()
{


    // Asking the user about how many account he wants to create 

    int num,c;

    printf("How many students accounts wants you create ? :");
    scanf("%d" , &num);

    // Creating accounts using struct

    Student *students = calloc(num , sizeof(Student));

    for(int i = 0; i < num; i++){

        printf("Enter the informations of student N%d\n",i+1 );
        printf("First name : ");
        scanf("%s", &students[i].Fname);
        printf("Last name : ");
        scanf("%s", &students[i].Lname);
        printf("Day of birth : ");
        scanf("%d", &students[i].day);
        printf("Month of birth");
        scanf("%d", &students[i].month);
        printf("Year of birth : ");
        scanf("%d", &students[i].year);
        printf("How old are you ? :");
        scanf("%d", &students[i].age);

    }
    

    printf("--Type 1 if you want to show the list of names :\n--Type 2 if you want to show the list of ages :\n--Type 3 if you want to know your exact age :\n--Type 4 if you want to know the average age :\n--type 5 if you want to know the older age :\n--Type 6 if you want to know the youngest age :");
    scanf("%d", &c);

    if(c == 1){

        for(int i = 0; i < num; i++){

            printf("%s %s\n", &students[i].Fname , &students[i].Lname);

        }

    }else if(c == 2){

        for(int i = 0; i < num; i++){

           printf("%d", students[i].age);

        }

    }else if(c == 3){

        for(int b = 0; b < num; b++){

            exactAge(16,students[b].day, 9, students[b].month,students[b].year,2022);

        }
    }else if(c == 4){
        float sum;

        for(int i = 0; i < num; i++){

            sum+=students[i].age;
            
            
        } 
        
        float avg = sum/2;
        
        printf("The average age is : %f", avg);

    }else if(c == 5){
        int arr[] = {4,6,78,0};
        bubbleSort(arr);

    };

    

};

/* === end === */



int main() 
{

    CreatingAndShowingStudents();
    

}