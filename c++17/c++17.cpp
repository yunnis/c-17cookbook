// c++17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "2_1_remove_vector.h"
#include "2_2_o(1)_delete_unsort_vector.h"
#include "2_4_vector_sort_insert.h"
#include "2_5_map_try_emplace.h"
#include "2_7_change_map_key.h"
#include "4_3_concat_lambda.h"
#include "4_5_multicall_lambda.h"
#include "5_1_container_move.h"
#include "5_4_container_transform.h"
#include "6_1_word_search_tree.h"
#include "6_2_search_suggestion.h"
#include "7_1_string_operators.h"
#include "7_2_trim.h"
#include "7_3_string_view.h"
#include "7_6_formattinng_output.h"
#include "7_7_init_complex_obj_by_input_.h"
#include "8_7_variant_replace_union.h"
#include "9_8_async.h"
#include "9_9_producer_consumer.h"
#include "9_10_mul_producer_mul_consumer.h"
#include "9_12_small_auto_parallel_lib.h"
#include "10_1_std_path.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello World!\n";
    //_2_1();
    //_2_2();
    //_2_4();
    //_2_5();
    //_2_7();
    //_4_3();
    //_4_5();
    //_5_1();
    //_5_4();
    //_6_1();
    //_6_2();
    //_7_1();
    //_7_2();
    //_7_3();
    //_7_6();
    //_7_7();
    //_8_7();
    //_9_8();
    //_9_9();
    //_9_10();
    //_9_12();  Ä£°åÎÞ·¨±àÒë

    if (argc == 2)
    {
        _10_1(argv[1]);
    }
    else
    {
        std::cout << "main arg count: " << argc << '\n';
        char dir[] = "c:";
        _10_1(dir);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
