#include "unity.h"
#include <function.h> /* Name of the header file of your project */

/* These two lines are need to be set according to project name */
#include <function.h>
#define PROJECT_NAME    "Billing"

/* Prototype / Function Declaration */
// Write all the function defined in the program.

void test_input(void);
void test_writefile(void);
void test_search(void);
void test_output(void);

/* Required by the unity test framework */

void setUp(){}

/* Required by the unity test framework */

void tearDown(){}

/* Start of the application test */

// Write the code for testing.

int main()
{
    /* Initiate the Unity Test Framework (Initiation) */

    UNITY_BEGIN();

    /*Now Run the Test function*/
    /* Means write the fucntion name for testing */

  RUN_TEST(input);
  RUN_TEST(writefile);
  RUN_TEST(search);
  RUN_TEST(output);

   /* Close the Unity Test Framework */
  return UNITY_END();

}

/* Write all the test functions. */
/* Here we have to write all the test cases means values for the program input that program is taking proper input and giving the desired result or not! */

void input(void) {
    TEST_ASSERT_EQUAL();
}

void writefile(void) {
    TEST_ASSERT_EQUAL();
}

void search(void) {
    
}

void output(void) {
    TEST_ASSERT_EQUAL();
}