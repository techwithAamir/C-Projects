#include <stdio.h>

int main() {
    char name[50];
    char roll_number[20];
    int english, maths, hindi, physics, chemistry,Total;
    int num_fail =0;
    float percentage;

    printf("Enter student's name: ");
    scanf("%s", name); //input  students's name

    printf("Enter student's roll number: "); // input student's rollno.
    scanf("%s", roll_number);

    printf("Enter marks for English: ");
    scanf("%d", &english); // english's marks is being stored at english var.

    printf("Enter marks for Mathematics: ");
    scanf("%d", &maths);

    printf("Enter marks for Hindi: ");
    scanf("%d", &hindi);

    printf("Enter marks for Physics: ");
    scanf("%d", &physics);
    printf("Enter marks for Chemistry: ");
    scanf("%d", &chemistry);

    // Check and display remarks for each subject
    printf("Student Name: %s\n", name);
    printf("Roll Number: %s\n", roll_number);

    printf("Remarks:\n"); // remarks declaration and comparing of the marks 
    if (english >= 40)
     {
        printf("English:Pass\n");
    } 
    else {
        printf("English:Fail\n");
    }
    if (maths >= 40) {
        printf("Maths:Pass\n");
    }
     else {
        printf("Maths:Fail\n");
    }
    if (hindi >= 40) {
        printf("Hindi: Pass\n");
    } 
    else {
        printf("Hindi: Fail\n");
    }
    if (physics >= 40) {
        printf("Physics:Pass\n");
    } 
    else {
        printf("Physics:Fail\n");
    }
    if (chemistry >= 40) {
        printf("Chemistry:Pass\n");
    } 
    else {
        printf("Chemistry:Fail\n");
    }
    // check the subjects student failed or pass, making of the final result 
     if (english < 40) {
        num_fail++;
    }
     if (maths < 40) {
        num_fail++;
    }
     if (hindi < 40) {
        num_fail++;
    }
     if (physics < 40) {
        num_fail++;
    }
     if (chemistry < 40) {
        num_fail++;
    }
    Total = english+maths+hindi+physics+chemistry;
      percentage = Total / 500.0 * 100.0;

    printf("Total Marks obtainbed : %d\n", Total);
     printf("Percentage: %f\n", percentage);
     if (num_fail > 2) {
        printf("Result: Not Promoted to next class\n");
    } else {
        printf("Result: Promoted to next class\n");
    }
    
    return 0;
}

