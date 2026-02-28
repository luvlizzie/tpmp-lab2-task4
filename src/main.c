/*
 * Author: Kudinova Elizaveta, group 12
 * Description: Main program for Student data management
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/student.h"

#define DATA_FILE "data/students.txt"
#define OUTPUT_FILE "data/low_performers.txt"

/*
 * Function: print_menu
 * Displays the program menu
 */
void print_menu(void) {
    printf("   STUDENT DATABASE MANAGEMENT\n");
    printf("1. Create initial file with sample data\n");
    printf("2. Load students from file\n");
    printf("3. Add new student (interactive)\n");
    printf("4. Show all students\n");
    printf("5. Find students with average grade < 7.0\n");
    printf("6. Save low performers to file\n");
    printf("7. Save all students to file\n");
    printf("0. Exit\n");
    printf("-------------------------------------\n");
    printf("Your choice: ");
}

/*
 * Main function
 */
int main(void) {
    Student students[100];  // Maximum 100 students
    int count = 0;          // Current number of students
    int choice;
    int loaded = 0;
    
    printf("\nWelcome to Student Database Management System\n");
    
    do {
        print_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Create initial file with sample data
                create_initial_file(DATA_FILE);
                break;
                
            case 2:
                // Load students from file
                if (load_from_file(students, &count, DATA_FILE)) {
                    loaded = 1;
                    printf("Successfully loaded %d students.\n", count);
                }
                break;
                
            case 3:
                // Add new student interactively
                add_student(students, &count);
                break;
                
            case 4:
                // Show all students
                if (count == 0) {
                    printf("No students loaded. Please load from file or add new students.\n");
                } else {
                    print_all_students(students, count);
                }
                break;
                
            case 5:
                // Find low performers (average grade < 7.0)
                if (count == 0) {
                    printf("No students loaded. Please load from file first.\n");
                } else {
                    find_low_performers(students, count);
                }
                break;
                
            case 6:
                // Save low performers to file
                if (count == 0) {
                    printf("No students loaded. Please load from file first.\n");
                } else {
                    print_low_performers_to_file(students, count, OUTPUT_FILE);
                }
                break;
                
            case 7:
                // Save all students to file
                if (count == 0) {
                    printf("No students to save.\n");
                } else {
                    save_to_file(students, count, DATA_FILE);
                }
                break;
                
            case 0:
                printf("Exiting program. Goodbye!\n");
                // Auto-save before exit if there are changes
                if (count > 0) {
                    printf("Auto-saving data...\n");
                    save_to_file(students, count, DATA_FILE);
                }
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}
