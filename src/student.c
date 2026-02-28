/*
 * Author: Kudinova Elizaveta, group 12
 * Description: Implementation of Student structure functions
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/student.h"

/*
 * Function: print_address
 * Prints address structure in readable format
 */
void print_address(const Address *addr) {
    printf("  Address: %s %s, %s, %s, %s, st. %s, %s, apt. %s\n",
           addr->postal_index, addr->country, addr->region, addr->district,
           addr->city, addr->street, addr->house, addr->apartment);
}

/*
 * Function: print_birth_date
 * Prints birth date in readable format
 */
void print_birth_date(const BirthDate *date) {
    printf("  Birth date: %d-%02d-%02d\n", date->year, date->month, date->day);
}

/*
 * Function: print_student
 * Prints all information about a single student
 */
void print_student(const Student *student) {
    printf("\n--- Student: %s %s %s ---\n", 
           student->surname, student->name, student->patronymic);
    printf("  Sex: %c\n", student->sex);
    printf("  Nationality: %s\n", student->nationality);
    printf("  Height: %.1f cm, Weight: %.1f kg\n", student->height, student->weight);
    print_birth_date(&student->birth_date);
    printf("  Phone: %s\n", student->phone);
    print_address(&student->address);
    printf("  University: %s\n", student->university);
    printf("  Course: %d, Group: %s\n", student->course, student->group);
    printf("  Average grade: %.2f\n", student->average_grade);
    printf("  Speciality: %s\n", student->speciality);
}

/*
 * Function: add_student
 * Adds a new student to the array (interactive input)
 */
void add_student(Student *students, int *count) {
    if (*count >= 100) {
        printf("Error: maximum number of students reached (100)\n");
        return;
    }
    
    printf("\n--- Adding new student ---\n");
    
    printf("Surname: ");
    scanf("%s", students[*count].surname);
    
    printf("Name: ");
    scanf("%s", students[*count].name);
    
    printf("Patronymic: ");
    scanf("%s", students[*count].patronymic);
    
    printf("Sex (M/F): ");
    scanf(" %c", &students[*count].sex);
    
    printf("Nationality: ");
    scanf("%s", students[*count].nationality);
    
    printf("Height (cm): ");
    scanf("%f", &students[*count].height);
    
    printf("Weight (kg): ");
    scanf("%f", &students[*count].weight);
    
    printf("Birth date (year month day): ");
    scanf("%d %d %d", 
          &students[*count].birth_date.year,
          &students[*count].birth_date.month,
          &students[*count].birth_date.day);
    
    printf("Phone: ");
    scanf("%s", students[*count].phone);
    
    printf("Postal index: ");
    scanf("%s", students[*count].address.postal_index);
    
    printf("Country: ");
    scanf("%s", students[*count].address.country);
    
    printf("Region: ");
    scanf("%s", students[*count].address.region);
    
    printf("District: ");
    scanf("%s", students[*count].address.district);
    
    printf("City: ");
    scanf("%s", students[*count].address.city);
    
    printf("Street: ");
    scanf("%s", students[*count].address.street);
    
    printf("House: ");
    scanf("%s", students[*count].address.house);
    
    printf("Apartment: ");
    scanf("%s", students[*count].address.apartment);
    
    printf("University: ");
    scanf("%s", students[*count].university);
    
    printf("Course: ");
    scanf("%d", &students[*count].course);
    
    printf("Group: ");
    scanf("%s", students[*count].group);
    
    printf("Average grade: ");
    scanf("%f", &students[*count].average_grade);
    
    printf("Speciality: ");
    scanf("%s", students[*count].speciality);
    
    (*count)++;
    printf("Student added successfully. Total: %d\n", *count);
}

/*
 * Function: print_all_students
 * Prints all students in the array
 */
void print_all_students(const Student *students, int count) {
    if (count == 0) {
        printf("No students in the list.\n");
        return;
    }
    
    printf("\n=== All students (%d) ===\n", count);
    for (int i = 0; i < count; i++) {
        print_student(&students[i]);
    }
}

/*
 * Function: create_initial_file
 * Creates a file with sample student data
 */
void create_initial_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file %s\n", filename);
        return;
    }
    
    fprintf(file, "5\n");  // Number of students
    
    // Student 1 - low performer
    fprintf(file, "Ivanov\nIvan\nIvanovich\nM\nRussian\n180.5\n75.2\n2000 5 15\n+375291234567\n220001 Belarus Minsk Minsk Minsk Lenina 10 5\nBSU\n3\n11\n6.2\nComputer Science\n");
    
    // Student 2 - good student
    fprintf(file, "Petrov\nPetr\nPetrovich\nM\nBelarusian\n175.0\n70.0\n2001 3 20\n+375292345678\n220002 Belarus Minsk Minsk Minsk Pushkina 15 7\nBSU\n2\n12\n8.5\nMathematics\n");
    
    // Student 3 - low performer
    fprintf(file, "Sidorova\nAnna\nSergeevna\nF\nRussian\n165.3\n55.0\n2000 11 3\n+375293456789\n220003 Belarus Minsk Minsk Minsk Gagarina 20 3\nBSU\n3\n11\n6.8\nComputer Science\n");
    
    // Student 4 - good student
    fprintf(file, "Kozlova\nElena\nDmitrievna\nF\nBelarusian\n170.2\n60.0\n2002 7 8\n+375294567890\n220004 Belarus Minsk Minsk Minsk Kolas 25 9\nBSU\n1\n13\n9.2\nPhysics\n");
    
    // Student 5 - low performer
    fprintf(file, "Novikov\nAlexey\nSergeevich\nM\nRussian\n182.0\n80.0\n2001 12 1\n+375295678901\n220005 Belarus Minsk Minsk Minsk Kupaly 30 2\nBSU\n2\n12\n5.9\nMathematics\n");
    
    fclose(file);
    printf("Initial file %s created successfully.\n", filename);
}

/*
 * Function: load_from_file
 * Loads student data from text file
 */
int load_from_file(Student *students, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s for reading\n", filename);
        return 0;
    }
    
    fscanf(file, "%d\n", count);
    
    for (int i = 0; i < *count; i++) {
        fscanf(file, "%[^\n]\n", students[i].surname);
        fscanf(file, "%[^\n]\n", students[i].name);
        fscanf(file, "%[^\n]\n", students[i].patronymic);
        fscanf(file, "%c\n", &students[i].sex);
        fscanf(file, "%[^\n]\n", students[i].nationality);
        fscanf(file, "%f\n", &students[i].height);
        fscanf(file, "%f\n", &students[i].weight);
        fscanf(file, "%d %d %d\n", 
               &students[i].birth_date.year,
               &students[i].birth_date.month,
               &students[i].birth_date.day);
        fscanf(file, "%[^\n]\n", students[i].phone);
        
        // Read address fields
        fscanf(file, "%[^\n]\n", students[i].address.postal_index);
        fscanf(file, "%[^\n]\n", students[i].address.country);
        fscanf(file, "%[^\n]\n", students[i].address.region);
        fscanf(file, "%[^\n]\n", students[i].address.district);
        fscanf(file, "%[^\n]\n", students[i].address.city);
        fscanf(file, "%[^\n]\n", students[i].address.street);
        fscanf(file, "%[^\n]\n", students[i].address.house);
        fscanf(file, "%[^\n]\n", students[i].address.apartment);
        
        fscanf(file, "%[^\n]\n", students[i].university);
        fscanf(file, "%d\n", &students[i].course);
        fscanf(file, "%[^\n]\n", students[i].group);
        fscanf(file, "%f\n", &students[i].average_grade);
        fscanf(file, "%[^\n]\n", students[i].speciality);
    }
    
    fclose(file);
    printf("Loaded %d students from %s\n", *count, filename);
    return 1;
}

/*
 * Function: save_to_file
 * Saves all students to a text file
 */
void save_to_file(const Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s for writing\n", filename);
        return;
    }
    
    fprintf(file, "%d\n", count);
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", students[i].surname);
        fprintf(file, "%s\n", students[i].name);
        fprintf(file, "%s\n", students[i].patronymic);
        fprintf(file, "%c\n", students[i].sex);
        fprintf(file, "%s\n", students[i].nationality);
        fprintf(file, "%.1f\n", students[i].height);
        fprintf(file, "%.1f\n", students[i].weight);
        fprintf(file, "%d %d %d\n", 
                students[i].birth_date.year,
                students[i].birth_date.month,
                students[i].birth_date.day);
        fprintf(file, "%s\n", students[i].phone);
        
        // Save address fields
        fprintf(file, "%s\n", students[i].address.postal_index);
        fprintf(file, "%s\n", students[i].address.country);
        fprintf(file, "%s\n", students[i].address.region);
        fprintf(file, "%s\n", students[i].address.district);
        fprintf(file, "%s\n", students[i].address.city);
        fprintf(file, "%s\n", students[i].address.street);
        fprintf(file, "%s\n", students[i].address.house);
        fprintf(file, "%s\n", students[i].address.apartment);
        
        fprintf(file, "%s\n", students[i].university);
        fprintf(file, "%d\n", students[i].course);
        fprintf(file, "%s\n", students[i].group);
        fprintf(file, "%.2f\n", students[i].average_grade);
        fprintf(file, "%s\n", students[i].speciality);
    }
    
    fclose(file);
    printf("Saved %d students to %s\n", count, filename);
}

/*
 * Function: find_low_performers
 * Finds and prints students with average grade < 7.0
 */
void find_low_performers(const Student *students, int count) {
    int found = 0;
    
    printf("\n=== Students with average grade below 7.0 ===\n");
    
    for (int i = 0; i < count; i++) {
        if (students[i].average_grade < 7.0) {
            printf("%d. %s %s %s (grade: %.2f)\n", 
                   ++found,
                   students[i].surname,
                   students[i].name,
                   students[i].patronymic,
                   students[i].average_grade);
        }
    }
    
    if (found == 0) {
        printf("No students with average grade below 7.0 found.\n");
    } else {
        printf("Total: %d students\n", found);
    }
}

/*
 * Function: print_low_performers_to_file
 * Saves low performers to a separate file
 */
void print_low_performers_to_file(const Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s for writing\n", filename);
        return;
    }
    
    int found = 0;
    fprintf(file, "Students with average grade below 7.0:\n");
    fprintf(file, "======================================\n\n");
    
    for (int i = 0; i < count; i++) {
        if (students[i].average_grade < 7.0) {
            found++;
            fprintf(file, "%d. %s %s %s\n", found, students[i].surname, students[i].name, students[i].patronymic);
            fprintf(file, "   Sex: %c\n", students[i].sex);
            fprintf(file, "   Nationality: %s\n", students[i].nationality);
            fprintf(file, "   Birth date: %d-%02d-%02d\n", 
                    students[i].birth_date.year,
                    students[i].birth_date.month,
                    students[i].birth_date.day);
            fprintf(file, "   University: %s, Course: %d, Group: %s\n", 
                    students[i].university, students[i].course, students[i].group);
            fprintf(file, "   Average grade: %.2f\n", students[i].average_grade);
            fprintf(file, "   Speciality: %s\n", students[i].speciality);
            fprintf(file, "\n");
        }
    }
    
    if (found == 0) {
        fprintf(file, "No students with average grade below 7.0 found.\n");
    } else {
        fprintf(file, "Total: %d students\n", found);
    }
    
    fclose(file);
    printf("Low performers saved to %s\n", filename);
}
