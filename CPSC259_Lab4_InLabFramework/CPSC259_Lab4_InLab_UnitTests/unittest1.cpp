#include <sstream>
#include <iostream>
#include <climits>
#include "CppUnitTest.h"


#include <string.h>
#define BUFFERLENGTH 1024

extern "C" {
	#include "recursion.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTests
{		
	TEST_CLASS(To_Do_2_calculate_power_function)
	{
	public:
		
		TEST_METHOD(positive_base_positive_exponent)
		{
			Assert::AreEqual( calculate_power(5, 3), 125);
		}

		TEST_METHOD(positive_base_zero_exponent)
		{
			Assert::AreEqual( calculate_power(5, 0), 1);
		}

		TEST_METHOD(negative_base_positive_odd_exponent)
		{
			Assert::AreEqual( calculate_power(-5, 3), -125);
		}

		TEST_METHOD(negative_base_positive_even_exponent)
		{
			Assert::AreEqual( calculate_power(-5, 4), 625);
		}

		TEST_METHOD(negative_base_zero_exponent)
		{
			Assert::AreEqual( calculate_power(-5, 0), 1);
		}

	};

	TEST_CLASS(To_Do_3_count_digits_function)
	{
	public:
		
		TEST_METHOD(positive_1_digit_small)
		{
			Assert::AreEqual( count_digits(1), 1);
		}

		TEST_METHOD(positive_1_digit_large)
		{
			Assert::AreEqual( count_digits(9), 1);
		}

		TEST_METHOD(positive_2_digits_small)
		{
			Assert::AreEqual( count_digits(10), 2);
		}

		TEST_METHOD(positive_2_digits_large)
		{
			Assert::AreEqual( count_digits(99), 2);
		}

		TEST_METHOD(positive_many_digits_div_10)
		{
			Assert::AreEqual( count_digits(123450), 6);
		}

		TEST_METHOD(positive_many_digits_not_div_10)
		{
			Assert::AreEqual( count_digits(123456), 6);
		}

		TEST_METHOD(positive_max_digits)
		{
			Assert::AreEqual( count_digits(INT_MAX), 10);
		}

	};

	TEST_CLASS(To_Do_4_string_length_function)
	{
	public:
		
		TEST_METHOD(zero_length)
		{
			Assert::AreEqual( string_length(""), 0 );
		}

		TEST_METHOD(zero_length_alternate_representation)
		{
			char string[] = { '\0' };
			Assert::AreEqual( string_length(string), 0 );
		}

		TEST_METHOD(zero_length_alternate_representation_2)
		{
			char * string = "";
			Assert::AreEqual( string_length(string), 0 );
		}

		TEST_METHOD(zero_length_alternate_representation_3)
		{
			char string[1];
			string[0] = '\0';
			Assert::AreEqual( string_length(string), 0 );
		}

		TEST_METHOD(one_word)
		{
			Assert::AreEqual( string_length("polymorphism"), (int) strlen("polymorphism") );
		}

		TEST_METHOD(two_words)
		{
			Assert::AreEqual( string_length("polymorphism and abstraction"), (int) strlen("polymorphism and abstraction") );
		}

		TEST_METHOD(array_of_nulls)
		{
			char string[] = { '\0', '\0', '\0' };
			Assert::AreEqual( string_length(string), 0 );
		}

		TEST_METHOD(array_of_terminating_nulls)
		{
			char string[] = { 'a', '\0', '\0', '\0' };
			Assert::AreEqual( string_length(string), 1 );
		}

		TEST_METHOD(array_of_terminating_nulls_2)
		{
			char string[] = { 'a', 'b', '\0', '\0' };
			Assert::AreEqual( string_length(string), 2 );
		}

	};

	TEST_CLASS(To_Do_5_is_palindrome_function)
	{
	public:
		
		TEST_METHOD(zero_length)
		{
			Assert::AreEqual( is_palindrome("", 0), 1);
		}

		TEST_METHOD(length_one)
		{
			Assert::AreEqual( is_palindrome("A", 1), 1);
		}

		TEST_METHOD(length_two_positive)
		{
			Assert::AreEqual( is_palindrome("AA", 2), 1);
		}

		TEST_METHOD(length_two_negative)
		{
			Assert::AreEqual( is_palindrome("Aa", 2), 0);
		}

		TEST_METHOD(long_positive)
		{
			Assert::AreEqual( is_palindrome("able was i ere i saw elba", strlen("able was i ere i saw elba")), 1);
		}

		TEST_METHOD(long_negative)
		{
			Assert::AreEqual( is_palindrome("definitely not a palindrome", strlen("definitely not a palindrome")), 0);
		}

	};

	TEST_CLASS(To_Do_6_draw_ramp_function)
	{
	public:

		TEST_METHOD(ramp_1)
		{
			char result_string[BUFFERLENGTH];
			int index;
			// initialize result_string
			for (index = 0; index < BUFFERLENGTH; index++)
				result_string[index] = '\0';
			char solution_string[] = "*";

			draw_ramp(1, result_string);

			Assert::AreEqual(strcmp(result_string, solution_string), 0);
		}

		TEST_METHOD(ramp_2)
		{
			char result_string[BUFFERLENGTH];
			int index;
			// initialize result_string
			for (index = 0; index < BUFFERLENGTH; index++)
				result_string[index] = '\0';
			char solution_string[] = "**\n*\n**";

			draw_ramp(2, result_string);

			Assert::AreEqual(strcmp(result_string, solution_string), 0);
		}

		TEST_METHOD(ramp_3)
		{
			char result_string[BUFFERLENGTH];
			int index;
			// initialize result_string
			for (index = 0; index < BUFFERLENGTH; index++)
				result_string[index] = '\0';
			char solution_string[] = "***\n**\n*\n**\n***";

			draw_ramp(3, result_string);

			Assert::AreEqual(strcmp(result_string, solution_string), 0);
		}

		TEST_METHOD(ramp_4)
		{
			char result_string[BUFFERLENGTH];
			int index;
			// initialize result_string
			for (index = 0; index < BUFFERLENGTH; index++)
				result_string[index] = '\0';
			char solution_string[] = "****\n***\n**\n*\n**\n***\n****";

			draw_ramp(4, result_string);

			Assert::AreEqual(strcmp(result_string, solution_string), 0);
		}

		TEST_METHOD(ramp_5)
		{
			char result_string[BUFFERLENGTH];
			int index;
			// initialize result_string
			for (index = 0; index < BUFFERLENGTH; index++)
				result_string[index] = '\0';
			char solution_string[] = "*****\n****\n***\n**\n*\n**\n***\n****\n*****";

			draw_ramp(5, result_string);

			Assert::AreEqual(strcmp(result_string, solution_string), 0);
		}
	};
}