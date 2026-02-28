/*
 * Author: Kudinova Elizaveta, group 12
 * Description: Header file for Student structure and functions
 */

#ifndef STUDENT_H
#define STUDENT_H

/*
 * Structure for date of birth
 */
typedef struct {
    int year;
    int month;
    int day;
} BirthDate;

/*
 * Structure for address
 */
typedef struct {
    char postal_index[10];
    char country[50];
    char region[50];
    char district[50];
    char city[50];
    char street[50];
    char house[10];
    char apartment[10];
} Address;

/*
 * Main Student structure
 */
typedef struct {
    char surname[50];
    char name[50];
    char patronymic[50];
    char sex;                    // 'M' or 'F'
    char nationality[30];
    float height;                 // in cm
    float weight;                 // in kg
    BirthDate birth_date;
    char phone[15];
    Address address;
    char university[100];
    int course;
    char group[10];
    float average_grade;
    char speciality[100];
} Student;

/*
 * Function prototypes
 * All functions receive data through parameters (no global variables)
 */

// File operations
void create_initial_file(const char *filename);
int load_from_file(Student *students, int *count, const char *filename);
void save_to_file(const Student *students, int count, const char *filename);
void save_low_performers(const Student *students, int count, const char *filename);

// Student operations
void add_student(Student *students, int *count);
void print_all_students(const Student *students, int count);
void print_student(const Student *student);
void find_low_performers(const Student *students, int count);
void print_low_performers_to_file(const Student *students, int count, const char *filename);

// Helper functions
void print_address(const Address *addr);
void print_birth_date(const BirthDate *date);

#endif
