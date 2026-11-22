#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enum for business departments (5 departments listed in prompt)
typedef enum department {
    HR,
    SALES,
    RESEARCH,
    SOFTWARE,
    EXECUTIVE
} department;

// Struct to store employee details
typedef struct employee {
    department dept;
    int salary;
    unsigned int ssn;
} employee;

// Helper function to get string representation of department enum
const char* get_dept_name(department d) {
    switch(d) {
        case HR:        return "HR";
        case SALES:     return "Sales";
        case RESEARCH:  return "Research";
        case SOFTWARE:  return "Software";
        case EXECUTIVE: return "Executive";
        default:        return "Unknown";
    }
}

// Function to generate salary based on department base salary + random offset
int generate_salary(department dept) {
    int base_salary = 0;
    
    switch(dept) {
        case HR:        base_salary = 50000; break;
        case SALES:     base_salary = 60000; break;
        case RESEARCH:  base_salary = 75000; break;
        case SOFTWARE:  base_salary = 85000; break;
        case EXECUTIVE: base_salary = 120000; break;
    }
    
    // Add a random offset between 0 and 15,000
    int offset = rand() % 15001; 
    return base_salary + offset;
}

int main(void) {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    employee staff[10];

    // Generate 10 employees with different SSNs and random salaries
    for (int i = 0; i < 10; i++) {
        // Assign departments in a round-robin cycle
        staff[i].dept = (department)(i % 5);
        
        // Generate salary using base department salary + random offset
        staff[i].salary = generate_salary(staff[i].dept);
        
        // Assign distinct Social Security Numbers
        staff[i].ssn = 100000000 + (i + 1) * 1234567; 
    }

    // Print all 10 employees, one line at a time
    printf("Employee List:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("Employee %2d: Dept: %-10s | SSN: %u | Salary: $%d\n", 
               i + 1, 
               get_dept_name(staff[i].dept), 
               staff[i].ssn, 
               staff[i].salary);
    }

    return 0;
}