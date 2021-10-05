#include <sstream>
#include <iostream>
#include "CppUnitTest.h"


extern "C" {
#include "linkedlist.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Microsoft.VisualStudio.TestTools.UnitTesting::StringAssert
#define CORRECT_STRUCT_AIRPLANE_SIZE 28
#define CORRECT_STRUCT_NODE_SIZE     32
#define CORRECT_STRUCT_ELEMENT_SIZE  4

namespace UnitTests
{
	TEST_CLASS(ToDo_01_struct_airplane)
	{
	public:

		struct airplane test_struct;

		TEST_METHOD(Test_1_struct_airplant_size)
		{
			Assert::AreEqual(((int)sizeof(struct airplane)), CORRECT_STRUCT_AIRPLANE_SIZE);
		}

		TEST_METHOD(Test_2_flight_number_type_size)
		{
			Assert::AreEqual(((int)sizeof(test_struct.flight_number)), CORRECT_STRUCT_ELEMENT_SIZE);
		}

		TEST_METHOD(Test_3_city_origin_type_size)
		{
			Assert::AreEqual(((int)sizeof(test_struct.city_origin)), CORRECT_STRUCT_ELEMENT_SIZE);
		}

		TEST_METHOD(Test_4_city_destination_type_size)
		{
			Assert::AreEqual(((int)sizeof(test_struct.city_destination)), CORRECT_STRUCT_ELEMENT_SIZE);
		}

		TEST_METHOD(Test_5_priority_type_size)
		{
			Assert::AreEqual(((int)sizeof(test_struct.priority)), CORRECT_STRUCT_ELEMENT_SIZE);
		}

		TEST_METHOD(Test_6_maximum_speed_kph_type_size)
		{
			Assert::AreEqual(((int)sizeof(test_struct.maximum_speed_kph)), CORRECT_STRUCT_ELEMENT_SIZE);
		}

		TEST_METHOD(Test_7_cruising_altitude_type_size)
		{
			Assert::AreEqual(((int)sizeof(test_struct.cruising_altitude)), CORRECT_STRUCT_ELEMENT_SIZE);
		}

		TEST_METHOD(Test_8_capacity_type_size)
		{
			Assert::AreEqual(((int)sizeof(test_struct.capacity)), CORRECT_STRUCT_ELEMENT_SIZE);
		}
	};

	TEST_CLASS(ToDo_02_struct_node)
	{
	public:

		struct node test_struct;

		TEST_METHOD(Test_1_struct_node_size)
		{
			Assert::AreEqual(((int)sizeof(struct node)), CORRECT_STRUCT_NODE_SIZE);
		}

		TEST_METHOD(Test_2_struct_node_data_size)
		{

			Assert::AreEqual(((int)sizeof(test_struct.plane)), CORRECT_STRUCT_AIRPLANE_SIZE);
		}

		TEST_METHOD(Test_3_struct_node_pointer_size)
		{
			Assert::AreEqual(((int)sizeof(test_struct.next)), CORRECT_STRUCT_ELEMENT_SIZE);
		}
	};

	TEST_CLASS(ToDo_03_create_linked_list)
	{
	public:

		TEST_METHOD(Test_1_new_list_should_be_empty)
		{
			struct node* new_empty_list = create_linked_list();
			Assert::IsNull(new_empty_list);
		}
	};

	TEST_CLASS(ToDo_04_create_node)
	{
	public:

		TEST_METHOD(Test_1_new_node_must_exist)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane_one);

			Assert::IsNotNull(test_node);
		}

		TEST_METHOD(Test_2_new_node_pointer_must_point_to_nothing)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane_one);

			Assert::IsNull(test_node->next);
		}

		TEST_METHOD(Test_3_new_node_plane_flight_number)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane_one);

			Assert::AreEqual(test_node->plane.flight_number, 100);
		}

		TEST_METHOD(Test_4_new_node_plane_city_origin)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane_one);

			Assert::AreEqual(test_node->plane.city_origin, "Vancouver");
		}

		TEST_METHOD(Test_5_new_node_plane_city_destination)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane_one);

			Assert::AreEqual(test_node->plane.city_destination, "Toronto");
		}

		TEST_METHOD(Test_6_new_node_plane_priority)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane_one);

			Assert::AreEqual(test_node->plane.priority, 1);
		}

		TEST_METHOD(Test_7_new_node_plane_maximum_speed_kph)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane_one);

			Assert::AreEqual(test_node->plane.maximum_speed_kph, 900);
		}

		TEST_METHOD(Test_8_new_node_plane_cruising_altitude)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane_one);

			Assert::AreEqual(test_node->plane.cruising_altitude, 36000);
		}

		TEST_METHOD(Test_9_new_node_plane_capacity)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane_one);

			Assert::AreEqual(test_node->plane.capacity, 350);
		}
	};

	TEST_CLASS(ToDo_05_prepend_node)
	{
	public:

		TEST_METHOD(Test_1_prepend_node_to_empty_list)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_list = create_linked_list();
			struct node* new_node_one = create_node(test_airplane_one);
			test_list = prepend_node(test_list, new_node_one);
			Assert::AreEqual(test_list->plane.city_origin, "Vancouver");
			Assert::IsNull(test_list->next);
		}

		TEST_METHOD(Test_2_prepend_node_to_nonempty_list)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct node* test_list = create_linked_list();
			struct node* new_node_one = create_node(test_airplane_one);
			struct node* new_node_two = create_node(test_airplane_two);

			test_list = prepend_node(test_list, new_node_one);
			test_list = prepend_node(test_list, new_node_two);
			Assert::AreEqual(test_list->plane.city_origin, "Toronto");
			Assert::AreEqual(test_list->next->plane.city_origin, "Vancouver");
			Assert::IsNull(test_list->next->next);
		}
	};

	TEST_CLASS(ToDo_06_delete_node)
	{
	public:

		TEST_METHOD(Test_1_delete_node_from_empty_list)
		{
			struct node* test_list = create_linked_list();
			test_list = delete_node(test_list);
			Assert::IsNull(test_list);
		}

		TEST_METHOD(Test_2_delete_node_from_list_size_1)
		{
			struct airplane test_airplane = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane));
			Assert::AreEqual(test_list->plane.city_origin, "Vancouver");
			test_list = delete_node(test_list);
			Assert::IsNull(test_list);
		}

		TEST_METHOD(Test_3_delete_node_from_nonempty_list)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane_one));
			test_list = prepend_node(test_list, create_node(test_airplane_two));
			test_list = delete_node(test_list);
			Assert::AreEqual(test_list->plane.city_origin, "Vancouver");
			Assert::IsNull(test_list->next);
		}
	};

	TEST_CLASS(ToDo_07_get_length)
	{
	public:

		TEST_METHOD(Test_1_empty_list)
		{
			struct node* test_list = create_linked_list();
			int length = get_length(test_list);
			Assert::AreEqual(length, 0);
		}

		TEST_METHOD(Test_2_list_length_one)
		{
			struct airplane test_airplane = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane));
			int length = get_length(test_list);
			Assert::AreEqual(length, 1);
		}

		TEST_METHOD(Test_3_nonempty_list)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane_one));
			test_list = prepend_node(test_list, create_node(test_airplane_two));
			int length = get_length(test_list);
			Assert::AreEqual(length, 2);
		}
	};

	TEST_CLASS(ToDo_08_delete_list)
	{
	public:

		TEST_METHOD(Test_1_empty_list)
		{
			struct node* test_list = create_linked_list();
			test_list = delete_list(test_list);
			int length = get_length(test_list);
			Assert::AreEqual(length, 0);
			Assert::IsNull(test_list);
		}

		TEST_METHOD(Test_2_list_length_one)
		{
			struct airplane test_airplane = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane));
			int length = get_length(test_list);
			Assert::AreEqual(length, 1);
			test_list = delete_list(test_list);
			length = get_length(test_list);
			Assert::AreEqual(length, 0);
			Assert::IsNull(test_list);
		}

		TEST_METHOD(Test_3_nonempty_list)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane_one));
			test_list = prepend_node(test_list, create_node(test_airplane_two));
			int length = get_length(test_list);
			Assert::AreEqual(length, 2);
			test_list = delete_list(test_list);
			length = get_length(test_list);
			Assert::AreEqual(length, 0);
			Assert::IsNull(test_list);
		}
	};

	TEST_CLASS(ToDo_11_reverse_list)
	{
	public:

		TEST_METHOD(Test_1_empty_list)
		{
			struct node* test_list = create_linked_list();
			test_list = reverse(test_list);
			int length = get_length(test_list);
			Assert::AreEqual(length, 0);
			Assert::IsNull(test_list);
		}

		TEST_METHOD(Test_2_list_length_one)
		{
			struct airplane test_airplane = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane));
			int length = get_length(test_list);
			Assert::AreEqual(length, 1);
			test_list = reverse(test_list);
			length = get_length(test_list);
			Assert::AreEqual(length, 1);
			Assert::IsNotNull(test_list);
		}

		TEST_METHOD(Test_3_nonempty_list_1)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Halifax", 2, 800, 26000, 280 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			test_list = reverse(test_list);
			int length = get_length(test_list);
			Assert::AreEqual(length, 3);
		}

		TEST_METHOD(Test_4_nonempty_list_2)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Halifax", 3, 700, 30000, 200 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			test_list = reverse(test_list);
			Assert::AreEqual(100, test_list->plane.flight_number);
			Assert::AreEqual("Vancouver", test_list->plane.city_origin);
			Assert::AreEqual("Toronto", test_list->plane.city_destination);
			Assert::AreEqual(1, test_list->plane.priority);
			Assert::AreEqual(900, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(36000, test_list->plane.cruising_altitude);
			Assert::AreEqual(350, test_list->plane.capacity);
			Assert::AreEqual((int)test_node_two, (int)test_list->next);
		}

		TEST_METHOD(Test_5_nonempty_list_3)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Halifax", 3, 700, 30000, 200 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			test_list = reverse(test_list);
			test_list = test_list->next;
			Assert::AreEqual(200, test_list->plane.flight_number);
			Assert::AreEqual("Toronto", test_list->plane.city_origin);
			Assert::AreEqual("Halifax", test_list->plane.city_destination);
			Assert::AreEqual(2, test_list->plane.priority);
			Assert::AreEqual(800, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(26000, test_list->plane.cruising_altitude);
			Assert::AreEqual(280, test_list->plane.capacity);
			Assert::AreEqual((int)test_node_three, (int)test_list->next);
		}

		TEST_METHOD(Test_6_nonempty_list_4)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			test_list = reverse(test_list);
			test_list = test_list->next->next;
			Assert::AreEqual(300, test_list->plane.flight_number);
			Assert::AreEqual("Calgary", test_list->plane.city_origin);
			Assert::AreEqual("Edmonton", test_list->plane.city_destination);
			Assert::AreEqual(3, test_list->plane.priority);
			Assert::AreEqual(700, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(30000, test_list->plane.cruising_altitude);
			Assert::AreEqual(200, test_list->plane.capacity);
			Assert::IsNull(test_list->next);
		}
	};

	TEST_CLASS(ToDo_12_remove_from_list)
	{
	public:

		TEST_METHOD(Test_1_empty_list)
		{
			struct node* test_list = create_linked_list();
			test_list = remove_from_list(test_list, "Vancouver");
			Assert::IsNull(test_list);
		}

		TEST_METHOD(Test_2_list_length_one_positive_test)
		{
			struct airplane test_airplane = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane));
			test_list = remove_from_list(test_list, "Toronto");
			Assert::IsNull(test_list);
		}

		TEST_METHOD(Test_3_list_length_one_negative_test)
		{
			struct airplane test_airplane = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane));
			test_list = remove_from_list(test_list, "Vancouver");
			Assert::IsNotNull(test_list);
			int length = get_length(test_list);
			Assert::AreEqual(length, 1);
		}

		TEST_METHOD(Test_4_list_length_two_header_positive_test)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane_one));
			test_list = prepend_node(test_list, create_node(test_airplane_two));
			test_list = remove_from_list(test_list, "Halifax");
			Assert::IsNotNull(test_list);
			int length = get_length(test_list);
			Assert::AreEqual(length, 1);
			Assert::AreEqual(100, test_list->plane.flight_number);
			Assert::AreEqual("Vancouver", test_list->plane.city_origin);
			Assert::AreEqual("Toronto", test_list->plane.city_destination);
			Assert::AreEqual(1, test_list->plane.priority);
			Assert::AreEqual(900, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(36000, test_list->plane.cruising_altitude);
			Assert::AreEqual(350, test_list->plane.capacity);
			Assert::IsNull(test_list->next);
		}

		TEST_METHOD(Test_5_list_length_two_tail_positive_test)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane_one));
			test_list = prepend_node(test_list, create_node(test_airplane_two));
			test_list = remove_from_list(test_list, "Toronto");
			Assert::IsNotNull(test_list);
			int length = get_length(test_list);
			Assert::AreEqual(length, 1);
			Assert::AreEqual(200, test_list->plane.flight_number);
			Assert::AreEqual("Toronto", test_list->plane.city_origin);
			Assert::AreEqual("Halifax", test_list->plane.city_destination);
			Assert::AreEqual(2, test_list->plane.priority);
			Assert::AreEqual(800, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(26000, test_list->plane.cruising_altitude);
			Assert::AreEqual(280, test_list->plane.capacity);
			Assert::IsNull(test_list->next);
		}

		TEST_METHOD(Test_6_list_long_middle_positive_test)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			test_list = remove_from_list(test_list, "Halifax");
			Assert::IsNotNull(test_list);
			int length = get_length(test_list);
			Assert::AreEqual(length, 2);
			Assert::AreEqual(300, test_list->plane.flight_number);
			Assert::AreEqual("Calgary", test_list->plane.city_origin);
			Assert::AreEqual("Edmonton", test_list->plane.city_destination);
			Assert::AreEqual(3, test_list->plane.priority);
			Assert::AreEqual(700, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(30000, test_list->plane.cruising_altitude);
			Assert::AreEqual(200, test_list->plane.capacity);
			Assert::AreEqual((int)test_list->next, (int)test_node_one);
			Assert::AreEqual(100, test_list->next->plane.flight_number);
			Assert::AreEqual("Vancouver", test_list->next->plane.city_origin);
			Assert::AreEqual("Toronto", test_list->next->plane.city_destination);
			Assert::AreEqual(1, test_list->next->plane.priority);
			Assert::AreEqual(900, test_list->next->plane.maximum_speed_kph);
			Assert::AreEqual(36000, test_list->next->plane.cruising_altitude);
			Assert::AreEqual(350, test_list->next->plane.capacity);
			Assert::IsNull(test_list->next->next);
		}

		TEST_METHOD(Test_7_list_long_tail_positive_test)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			test_list = remove_from_list(test_list, "Toronto");
			Assert::IsNotNull(test_list);
			int length = get_length(test_list);
			Assert::AreEqual(length, 2);
			Assert::AreEqual(300, test_list->plane.flight_number);
			Assert::AreEqual("Calgary", test_list->plane.city_origin);
			Assert::AreEqual("Edmonton", test_list->plane.city_destination);
			Assert::AreEqual(3, test_list->plane.priority);
			Assert::AreEqual(700, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(30000, test_list->plane.cruising_altitude);
			Assert::AreEqual(200, test_list->plane.capacity);
			Assert::AreEqual((int)test_list->next, (int)test_node_two);
			Assert::AreEqual(200, test_list->next->plane.flight_number);
			Assert::AreEqual("Toronto", test_list->next->plane.city_origin);
			Assert::AreEqual("Halifax", test_list->next->plane.city_destination);
			Assert::AreEqual(2, test_list->next->plane.priority);
			Assert::AreEqual(800, test_list->next->plane.maximum_speed_kph);
			Assert::AreEqual(26000, test_list->next->plane.cruising_altitude);
			Assert::AreEqual(280, test_list->next->plane.capacity);
			Assert::IsNull(test_list->next->next);
		}
	};
	TEST_CLASS(ToDo_13_retrieve_nth)
	{
	public:

		TEST_METHOD(Test_1_empty_list)
		{
			struct node* test_list = create_linked_list();
			int length = get_length(test_list);
			Assert::AreEqual(length, 0);
			struct node* result = retrieve_nth(test_list, 1);
			Assert::IsNull(result);
		}

		TEST_METHOD(Test_2_list_length_one_correct_ordinality)
		{
			struct airplane test_airplane = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane));
			int length = get_length(test_list);
			Assert::AreEqual(length, 1);
			struct node* result = retrieve_nth(test_list, 1);
			Assert::IsNotNull(result);
			length = get_length(result);
			Assert::AreEqual(length, 1);
			Assert::AreEqual(100, result->plane.flight_number);
			Assert::AreEqual("Vancouver", result->plane.city_origin);
			Assert::AreEqual("Toronto", result->plane.city_destination);
			Assert::AreEqual(1, result->plane.priority);
			Assert::AreEqual(900, result->plane.maximum_speed_kph);
			Assert::AreEqual(36000, result->plane.cruising_altitude);
			Assert::AreEqual(350, result->plane.capacity);
			Assert::IsNull(result->next);
			length = get_length(test_list);
			Assert::AreEqual(length, 1);
			Assert::AreEqual(100, test_list->plane.flight_number);
			Assert::AreEqual("Vancouver", test_list->plane.city_origin);
			Assert::AreEqual("Toronto", test_list->plane.city_destination);
			Assert::AreEqual(1, test_list->plane.priority);
			Assert::AreEqual(900, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(36000, test_list->plane.cruising_altitude);
			Assert::AreEqual(350, result->plane.capacity);
			Assert::IsNull(result->next);
		}

		TEST_METHOD(Test_3_list_length_one_incorrect_ordinality)
		{
			struct airplane test_airplane = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, create_node(test_airplane));
			int length = get_length(test_list);
			Assert::AreEqual(length, 1);
			struct node* result = retrieve_nth(test_list, 2);
			Assert::IsNull(result);
			length = get_length(test_list);
			Assert::AreEqual(length, 1);
			Assert::AreEqual(100, test_list->plane.flight_number);
			Assert::AreEqual("Vancouver", test_list->plane.city_origin);
			Assert::AreEqual("Toronto", test_list->plane.city_destination);
			Assert::AreEqual(1, test_list->plane.priority);
			Assert::AreEqual(900, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(36000, test_list->plane.cruising_altitude);
			Assert::AreEqual(350, test_list->plane.capacity);
			Assert::IsNull(test_list->next);
		}

		TEST_METHOD(Test_4_list_incorrect_ordinality)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			int length = get_length(test_list);
			Assert::AreEqual(length, 3);
			struct node* result = retrieve_nth(test_list, 4);
			Assert::IsNull(result);
			length = get_length(test_list);
			Assert::AreEqual(length, 3);
			Assert::AreEqual(300, test_list->plane.flight_number);
			Assert::AreEqual("Calgary", test_list->plane.city_origin);
			Assert::AreEqual("Edmonton", test_list->plane.city_destination);
			Assert::AreEqual(3, test_list->plane.priority);
			Assert::AreEqual(700, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(30000, test_list->plane.cruising_altitude);
			Assert::AreEqual(200, test_list->plane.capacity);
			Assert::AreEqual((int)test_list->next, (int)test_node_two);
			Assert::AreEqual((int)test_list->next->next, (int)test_node_one);
		}

		TEST_METHOD(Test_5_list_correct_ordinality_header)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			int length = get_length(test_list);
			Assert::AreEqual(length, 3);
			struct node* result = retrieve_nth(test_list, 1);
			Assert::IsNotNull(result);
			length = get_length(result);
			Assert::AreEqual(length, 3);
			Assert::AreEqual(300, result->plane.flight_number);
			Assert::AreEqual("Calgary", result->plane.city_origin);
			Assert::AreEqual("Edmonton", result->plane.city_destination);
			Assert::AreEqual(3, result->plane.priority);
			Assert::AreEqual(700, result->plane.maximum_speed_kph);
			Assert::AreEqual(30000, result->plane.cruising_altitude);
			Assert::AreEqual(200, result->plane.capacity);
			Assert::AreEqual((int)result->next, (int)test_node_two);
			length = get_length(test_list);
			Assert::AreEqual(length, 3);
			Assert::AreEqual(300, test_list->plane.flight_number);
			Assert::AreEqual("Calgary", test_list->plane.city_origin);
			Assert::AreEqual("Edmonton", test_list->plane.city_destination);
			Assert::AreEqual(3, test_list->plane.priority);
			Assert::AreEqual(700, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(30000, test_list->plane.cruising_altitude);
			Assert::AreEqual(200, test_list->plane.capacity);
			Assert::AreEqual((int)test_list->next, (int)test_node_two);
		}

		TEST_METHOD(Test_6_list_correct_ordinality_middle)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			int length = get_length(test_list);
			Assert::AreEqual(length, 3);
			struct node* result = retrieve_nth(test_list, 2);
			Assert::IsNotNull(result);
			length = get_length(result);
			Assert::AreEqual(length, 2);
			Assert::AreEqual(200, result->plane.flight_number);
			Assert::AreEqual("Toronto", result->plane.city_origin);
			Assert::AreEqual("Halifax", result->plane.city_destination);
			Assert::AreEqual(2, result->plane.priority);
			Assert::AreEqual(800, result->plane.maximum_speed_kph);
			Assert::AreEqual(26000, result->plane.cruising_altitude);
			Assert::AreEqual(280, result->plane.capacity);
			Assert::AreEqual((int)result->next, (int)test_node_one);
			Assert::IsNull(result->next->next);
			length = get_length(test_list);
			Assert::AreEqual(length, 3);
			Assert::AreEqual(300, test_list->plane.flight_number);
			Assert::AreEqual("Calgary", test_list->plane.city_origin);
			Assert::AreEqual("Edmonton", test_list->plane.city_destination);
			Assert::AreEqual(3, test_list->plane.priority);
			Assert::AreEqual(700, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(30000, test_list->plane.cruising_altitude);
			Assert::AreEqual(200, test_list->plane.capacity);
			Assert::AreEqual((int)test_list->next, (int)test_node_two);
			Assert::AreEqual((int)test_list->next->next, (int)test_node_one);
		}

		TEST_METHOD(Test_7_list_correct_ordinality_tail)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			int length = get_length(test_list);
			Assert::AreEqual(length, 3);
			struct node* result = retrieve_nth(test_list, 3);
			Assert::IsNotNull(result);
			length = get_length(result);
			Assert::AreEqual(length, 1);
			Assert::AreEqual(100, result->plane.flight_number);
			Assert::AreEqual("Vancouver", result->plane.city_origin);
			Assert::AreEqual("Toronto", result->plane.city_destination);
			Assert::AreEqual(1, result->plane.priority);
			Assert::AreEqual(900, result->plane.maximum_speed_kph);
			Assert::AreEqual(36000, result->plane.cruising_altitude);
			Assert::AreEqual(350, result->plane.capacity);
			Assert::IsNull(result->next);
			length = get_length(test_list);
			Assert::AreEqual(length, 3);
			Assert::AreEqual(300, test_list->plane.flight_number);
			Assert::AreEqual("Calgary", test_list->plane.city_origin);
			Assert::AreEqual("Edmonton", test_list->plane.city_destination);
			Assert::AreEqual(3, test_list->plane.priority);
			Assert::AreEqual(700, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(30000, test_list->plane.cruising_altitude);
			Assert::AreEqual(200, test_list->plane.capacity);
			Assert::AreEqual((int)test_list->next, (int)test_node_two);
			Assert::AreEqual((int)test_list->next->next, (int)test_node_one);
		}
	};

	TEST_CLASS(ToDo_14_insert_nth)
	{
	public:

		TEST_METHOD(Test_1_empty_list_positive_test)
		{
			struct airplane test_airplane = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane);
			struct node* test_list = create_linked_list();
			test_list = insert_nth(test_list, test_node, 1);
			int length = get_length(test_list);
			Assert::AreEqual(length, 1);
			Assert::AreEqual(length, 1);
			Assert::AreEqual(100, test_list->plane.flight_number);
			Assert::AreEqual("Vancouver", test_list->plane.city_origin);
			Assert::AreEqual("Toronto", test_list->plane.city_destination);
			Assert::AreEqual(1, test_list->plane.priority);
			Assert::AreEqual(900, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(36000, test_list->plane.cruising_altitude);
			Assert::AreEqual(350, test_list->plane.capacity);
			Assert::IsNull(test_list->next);
		}

		TEST_METHOD(Test_2_empty_list_negative_test)
		{
			struct airplane test_airplane = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct node* test_node = create_node(test_airplane);
			struct node* test_list = create_linked_list();
			test_list = insert_nth(test_list, test_node, 2);
			Assert::IsNull(test_list);
		}

		TEST_METHOD(Test_3_list_size_one_insert_header)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = insert_nth(test_list, test_node_two, 1);
			int length = get_length(test_list);
			Assert::AreEqual(length, 2);
			Assert::AreEqual(200, test_list->plane.flight_number);
			Assert::AreEqual("Toronto", test_list->plane.city_origin);
			Assert::AreEqual("Halifax", test_list->plane.city_destination);
			Assert::AreEqual(2, test_list->plane.priority);
			Assert::AreEqual(800, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(26000, test_list->plane.cruising_altitude);
			Assert::AreEqual(280, test_list->plane.capacity);
			Assert::AreEqual((int)test_list->next, (int)test_node_one);
			test_list = test_list->next;
			Assert::AreEqual(100, test_list->plane.flight_number);
			Assert::AreEqual("Vancouver", test_list->plane.city_origin);
			Assert::AreEqual("Toronto", test_list->plane.city_destination);
			Assert::AreEqual(1, test_list->plane.priority);
			Assert::AreEqual(900, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(36000, test_list->plane.cruising_altitude);
			Assert::AreEqual(350, test_list->plane.capacity);
			Assert::IsNull(test_list->next);
		}

		TEST_METHOD(Test_4_list_size_one_insert_footer)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = insert_nth(test_list, test_node_two, 2);
			int length = get_length(test_list);
			Assert::AreEqual(length, 2);
			Assert::AreEqual(100, test_list->plane.flight_number);
			Assert::AreEqual("Vancouver", test_list->plane.city_origin);
			Assert::AreEqual("Toronto", test_list->plane.city_destination);
			Assert::AreEqual(1, test_list->plane.priority);
			Assert::AreEqual(900, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(36000, test_list->plane.cruising_altitude);
			Assert::AreEqual(350, test_list->plane.capacity);
			Assert::AreEqual((int)test_list->next, (int)test_node_two);
			test_list = test_list->next;
			Assert::AreEqual(200, test_list->plane.flight_number);
			Assert::AreEqual("Toronto", test_list->plane.city_origin);
			Assert::AreEqual("Halifax", test_list->plane.city_destination);
			Assert::AreEqual(2, test_list->plane.priority);
			Assert::AreEqual(800, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(26000, test_list->plane.cruising_altitude);
			Assert::AreEqual(280, test_list->plane.capacity);
			Assert::IsNull(test_list->next);
		}

		TEST_METHOD(Test_5_list_negative_test)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct airplane test_airplane_four = { 400, "Kelowna", "Prince George", 4, 600, 20000, 100 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_node_four = create_node(test_airplane_four);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			int length = get_length(test_list);
			Assert::AreEqual(length, 3);
			test_list = insert_nth(test_list, test_node_four, 5);
			length = get_length(test_list);
			Assert::AreEqual(length, 3);
		}

		TEST_METHOD(Test_6_list_insert_header)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct airplane test_airplane_four = { 400, "Kelowna", "Prince George", 4, 600, 20000, 100 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_node_four = create_node(test_airplane_four);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			int length = get_length(test_list);
			Assert::AreEqual(length, 3);
			test_list = insert_nth(test_list, test_node_four, 1);
			length = get_length(test_list);
			Assert::AreEqual(length, 4);
			Assert::AreEqual(400, test_list->plane.flight_number);
			Assert::AreEqual("Kelowna", test_list->plane.city_origin);
			Assert::AreEqual("Prince George", test_list->plane.city_destination);
			Assert::AreEqual(4, test_list->plane.priority);
			Assert::AreEqual(600, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(20000, test_list->plane.cruising_altitude);
			Assert::AreEqual(100, test_list->plane.capacity);
			Assert::IsNotNull(test_list->next);
			Assert::AreEqual((int)test_list->next, (int)test_node_three);
			test_list = test_list->next;
			Assert::AreEqual(300, test_list->plane.flight_number);
			Assert::AreEqual("Calgary", test_list->plane.city_origin);
			Assert::AreEqual("Edmonton", test_list->plane.city_destination);
			Assert::AreEqual(3, test_list->plane.priority);
			Assert::AreEqual(700, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(30000, test_list->plane.cruising_altitude);
			Assert::AreEqual(200, test_list->plane.capacity);
			length = get_length(test_list);
			Assert::AreEqual(length, 3);
		}

		TEST_METHOD(Test_7_list_insert_footer)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct airplane test_airplane_four = { 400, "Kelowna", "Prince George", 4, 600, 20000, 100 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_node_four = create_node(test_airplane_four);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			int length = get_length(test_list);
			Assert::AreEqual(length, 3);
			test_list = insert_nth(test_list, test_node_four, 4);
			length = get_length(test_list);
			Assert::AreEqual(length, 4);
			Assert::AreEqual(300, test_list->plane.flight_number);
			Assert::AreEqual("Calgary", test_list->plane.city_origin);
			Assert::AreEqual("Edmonton", test_list->plane.city_destination);
			Assert::AreEqual(3, test_list->plane.priority);
			Assert::AreEqual(700, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(30000, test_list->plane.cruising_altitude);
			Assert::AreEqual(200, test_list->plane.capacity);
			Assert::IsNotNull(test_list->next);
			test_list = test_list->next;
			Assert::IsNotNull(test_list->next);
			test_list = test_list->next;
			Assert::IsNotNull(test_list->next);
			test_list = test_list->next;
			Assert::AreEqual(400, test_list->plane.flight_number);
			Assert::AreEqual("Kelowna", test_list->plane.city_origin);
			Assert::AreEqual("Prince George", test_list->plane.city_destination);
			Assert::AreEqual(4, test_list->plane.priority);
			Assert::AreEqual(600, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(20000, test_list->plane.cruising_altitude);
			Assert::AreEqual(100, test_list->plane.capacity);
			Assert::IsNull(test_list->next);
		}

		TEST_METHOD(Test_8_list_insert_middle)
		{
			struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
			struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
			struct airplane test_airplane_three = { 300, "Calgary", "Edmonton", 3, 700, 30000, 200 };
			struct airplane test_airplane_four = { 400, "Kelowna", "Prince George", 4, 600, 20000, 100 };
			struct node* test_node_one = create_node(test_airplane_one);
			struct node* test_node_two = create_node(test_airplane_two);
			struct node* test_node_three = create_node(test_airplane_three);
			struct node* test_node_four = create_node(test_airplane_four);
			struct node* test_list = create_linked_list();
			test_list = prepend_node(test_list, test_node_one);
			test_list = prepend_node(test_list, test_node_two);
			test_list = prepend_node(test_list, test_node_three);
			int length = get_length(test_list);
			Assert::AreEqual(length, 3);
			test_list = insert_nth(test_list, test_node_four, 3);
			length = get_length(test_list);
			Assert::AreEqual(length, 4);
			Assert::AreEqual(300, test_list->plane.flight_number);
			Assert::AreEqual("Calgary", test_list->plane.city_origin);
			Assert::AreEqual("Edmonton", test_list->plane.city_destination);
			Assert::AreEqual(3, test_list->plane.priority);
			Assert::AreEqual(700, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(30000, test_list->plane.cruising_altitude);
			Assert::AreEqual(200, test_list->plane.capacity);
			Assert::IsNotNull(test_list->next);
			test_list = test_list->next;
			Assert::IsNotNull(test_list->next);
			test_list = test_list->next;
			Assert::AreEqual(400, test_list->plane.flight_number);
			Assert::AreEqual("Kelowna", test_list->plane.city_origin);
			Assert::AreEqual("Prince George", test_list->plane.city_destination);
			Assert::AreEqual(4, test_list->plane.priority);
			Assert::AreEqual(600, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(20000, test_list->plane.cruising_altitude);
			Assert::AreEqual(100, test_list->plane.capacity);
			Assert::IsNotNull(test_list->next);
			test_list = test_list->next;
			Assert::AreEqual(100, test_list->plane.flight_number);
			Assert::AreEqual("Vancouver", test_list->plane.city_origin);
			Assert::AreEqual("Toronto", test_list->plane.city_destination);
			Assert::AreEqual(1, test_list->plane.priority);
			Assert::AreEqual(900, test_list->plane.maximum_speed_kph);
			Assert::AreEqual(36000, test_list->plane.cruising_altitude);
			Assert::AreEqual(350, test_list->plane.capacity);
			Assert::IsNull(test_list->next);
		}
	};

}