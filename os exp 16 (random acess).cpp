#include <stdio.h>
#include <stdlib.h>
struct Employee {
    int empId;
    char name[50];
    float salary;
};
void addEmployee(FILE *file) {
    struct Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d", &emp.empId);
    printf("Enter Name: ");
    scanf("%s", emp.name);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    fseek(file, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);
    printf("Employee added successfully.\n");
}
void displayAllEmployees(FILE *file) {
    struct Employee emp;
    fseek(file, 0, SEEK_SET);
    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        printf("Employee ID: %d\n", emp.empId);
        printf("Name: %s\n", emp.name);
        printf("Salary: %.2f\n", emp.salary);
        printf("--------------------------\n");
    }
}
void searchEmployee(FILE *file) {
    int targetId;
    struct Employee emp;
    printf("Enter Employee ID to search: ");
    scanf("%d", &targetId);
    fseek(file, (targetId - 1) * sizeof(struct Employee), SEEK_SET);
    if (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        printf("Employee found:\n");
        printf("Employee ID: %d\n", emp.empId);
        printf("Name: %s\n", emp.name);
        printf("Salary: %.2f\n", emp.salary);
    } else {
        printf("Employee not found with ID: %d\n", targetId);
    }
}
void updateEmployee(FILE*file) {
    int targetId;
    struct Employee emp;
    printf("Enter Employee ID to update: ");
    scanf("%d", &targetId);
    fseek(file, (targetId - 1) * sizeof(struct Employee), SEEK_SET);
    if (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        printf("Enter New Name: ");
        scanf("%s", emp.name);
        printf("Enter New Salary: ");
        scanf("%f", &emp.salary);
        fseek(file, -sizeof(struct Employee), SEEK_CUR);
        fwrite(&emp, sizeof(struct Employee), 1, file);
        printf("Employee updated successfully.\n");
    } else {
        printf("Employee not found with ID: %d\n", targetId);
    }
}
int main() {
    FILE *employeeFile;
    int choice;
    employeeFile = fopen("employee.dat", "rb+");
    if (employeeFile == NULL) {
        employeeFile = fopen("employee.dat", "wb+");
        if (employeeFile == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
    }
    while (1) {
        printf("\nEmployee Database Menu:\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee(employeeFile);
                break;
            case 2:
                displayAllEmployees(employeeFile);
                break;
            case 3:
                searchEmployee(employeeFile);
                break;
            case 4:
                updateEmployee(employeeFile);
                break;
            case 5:
                fclose(employeeFile);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


