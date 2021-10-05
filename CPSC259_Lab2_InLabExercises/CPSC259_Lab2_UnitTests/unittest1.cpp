#include "CppUnitTest.h"

extern "C" {
#include "lab2_in-lab_exercises.h"
#include <string.h>
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CPSC259_2017W1_Lab2_UnitTests
{
  TEST_CLASS(UnitTest1)
  {
  public:

    TEST_METHOD(Test01_swap_ints_01)
    {
      // Let's test two positive ints
      int first = 1;
      int second = 2;
      swap_ints(&first, &second);
      Assert::AreEqual(2, first);
      Assert::AreEqual(1, second);
    }

    TEST_METHOD(Test02_swap_ints_02)
    {
      // Let's test a negative int and zero
      int first = 0;
      int second = -1;
      swap_ints(&first, &second);
      Assert::AreEqual(-1, first);
      Assert::AreEqual(0, second);
    }

    TEST_METHOD(Test03_swap_ints_03)
    {
      // Let's test some bigger numbers
      int first = INT_MAX;
      int second = INT_MIN;
      swap_ints(&first, &second);
      Assert::AreEqual(INT_MIN, first);
      Assert::AreEqual(INT_MAX, second);
    }

    TEST_METHOD(Test04_reverse_string_01)
    {
      // Let's test a small string with an even number of char
      char original[] = "Canada";
      char reversed[] = "adanaC";
      reverse_string(original);
      Assert::AreEqual(0, strcmp(original, reversed));
    }

    TEST_METHOD(Test05_reverse_string_02)
    {
      // Let's test a small string with an odd number of char
      char original[] = "Vancouver";
      char reversed[] = "revuocnaV";
      reverse_string(original);
      Assert::AreEqual(0, strncmp(original, reversed, strlen(original)));
    }

    TEST_METHOD(Test06_reverse_string_03)
    {
      // Let's test an empty string
      char original[] = "";
      char reversed[] = "";
      reverse_string(original);
      Assert::AreEqual(0, strncmp(original, reversed, strlen(original)));
    }

    TEST_METHOD(Test07_reverse_string_04)
    {
      // Let's test a string of the same characters
      char original[] = "AAAAA";
      char reversed[] = "AAAAA";
      reverse_string(original);
      Assert::AreEqual(0, strncmp(original, reversed, strlen(original)));
    }

    TEST_METHOD(Test08_reverse_string_05)
    {
      // Let's test a string with some internal spaces
      char original[] = "A man a plan a canal Panama";
      char reversed[] = "amanaP lanac a nalp a nam A";
      reverse_string(original);
      Assert::AreEqual(0, strncmp(original, reversed, strlen(original)));
    }

    TEST_METHOD(Test09_reverse_string_06)
    {
      // Let's test a string with one character
      char original[] = "A";
      char reversed[] = "A";
      reverse_string(original);
      Assert::AreEqual(0, strncmp(original, reversed, strlen(original)));
    }

    TEST_METHOD(Test10_reverse_string_07)
    {
      // Let's test a string of odd size with an escaped character (not in the middle)
      char original[] = "This \t is a tab";
      char reversed[] = "bat a si \t sihT";
      reverse_string(original);
      Assert::AreEqual(0, strncmp(original, reversed, strlen(original)));
    }

    TEST_METHOD(Test11_reverse_string_08)
    {
      // Let's test a string with some special unicode characters in it
      // If you are using your home computer, this may not work if you are
      // using a non-English language pack.
      char original[] = "\u2500\u2501\n";
      char reversed[] = "\n\u2501\u2500";
      reverse_string(original);
      Assert::AreEqual(0, strncmp(original, reversed, strlen(original)));
    }

    TEST_METHOD(Test12_contains_sample_01)
    {
      // Let's conduct a positive test for a short candidate and sample
      // where the sample is at the beginning of the candidate
      char candidate[] = "soupspoon";
      char sample[] = "soup";
      Assert::AreEqual(1, contains_sample(candidate, sample));
    }

    TEST_METHOD(Test13_contains_sample_02)
    {
      // Let's conduct a positive test for a short candidate and sample
      // where the sample is at the end of the candidate
      char candidate[] = "soupspoon";
      char sample[] = "spoon";
      Assert::AreEqual(1, contains_sample(candidate, sample));
    }

    TEST_METHOD(Test14_contains_sample_03)
    {
      // Let's conduct a negative test for a short candidate and sample
      // where something similar to the sample is at the beginning of the candidate
      char candidate[] = "Soupspoon";
      char sample[] = "soup";
      Assert::AreEqual(0, contains_sample(candidate, sample));
    }

    TEST_METHOD(Test15_contains_sample_04)
    {
      // Let's conduct a negative test for a short candidate and sample
      // where something similar to the sample is at the end of the candidate
      char candidate[] = "soupspoon";
      char sample[] = "Spoon";
      Assert::AreEqual(0, contains_sample(candidate, sample));
    }

    TEST_METHOD(Test16_contains_sample_05)
    {
      // Let's conduct a positive test for a candidate and sample
      // of identical size
      char candidate[] = "soupspoon";
      char sample[] = "soupspoon";
      Assert::AreEqual(1, contains_sample(candidate, sample));
    }

    TEST_METHOD(Test17_contains_sample_06)
    {
      // Let's test an empty sample
      char candidate[] = "soupspoon";
      char sample[] = "";
      Assert::AreEqual(1, contains_sample(candidate, sample));
    }

    TEST_METHOD(Test18_contains_sample_07)
    {
      // Let's conduct a negative test using an empty candidate
      char candidate[] = "";
      char sample[] = "soupspoon";
      Assert::AreEqual(0, contains_sample(candidate, sample));
    }

    TEST_METHOD(Test19_contains_sample_08)
    {
      // Let's conduct a positive test using an empty candidate
      // and empty sample
      char candidate[] = "";
      char sample[] = "";
      Assert::AreEqual(1, contains_sample(candidate, sample));
    }

    TEST_METHOD(Test20_find_index_01)
    {
      // Let's conduct a positive test for a short candidate and sample
      // where the sample is at the beginning of the candidate
      char candidate[] = "soupspoon";
      char sample[] = "soup";
      Assert::AreEqual(0, find_index(candidate, sample));
    }

    TEST_METHOD(Test21_find_index_02)
    {
      // Let's conduct a positive test for a short candidate and sample
      // where the sample is at the end of the candidate
      char candidate[] = "soupspoon";
      char sample[] = "spoon";
      Assert::AreEqual(4, find_index(candidate, sample));
    }

    TEST_METHOD(Test22_find_index_03)
    {
      // Let's test identical strings
      char candidate[] = "soupspoon";
      char sample[] = "soupspoon";
      Assert::AreEqual(0, find_index(candidate, sample));
    }

    TEST_METHOD(Test23_find_index_04)
    {
      // Let's test empty strings
      char candidate[] = "";
      char sample[] = "";
      Assert::AreEqual(0, find_index(candidate, sample));
    }

    TEST_METHOD(Test24_find_index_05)
    {
      // Let's conduct a negative test
      char candidate[] = "soupspoon";
      char sample[] = "teaspoon";
      Assert::AreEqual(-1, find_index(candidate, sample));
    }

    TEST_METHOD(Test25_find_index_06)
    {
      // Let's conduct another negative test with a sample
      // that is bigger than the candidate
      char candidate[] = "soupspoon";
      char sample[] = "soupspoons";
      Assert::AreEqual(-1, find_index(candidate, sample));
    }

    TEST_METHOD(Test26_find_index_07)
    {
      // Let's conduct a positive test.  All strings
      // contain the empty string, with index 0
      char candidate[] = "soupspoon";
      char sample[] = "";
      Assert::AreEqual(0, find_index(candidate, sample));
    }
  };
}