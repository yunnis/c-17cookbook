#pragma once
#include "base.h"

void print_aligned_demo(int val, size_t width, char fill_char = ' ')
{
    std::cout << "================\n";
    std::cout << std::setfill(fill_char);
    std::cout << std::left << std::setw(width) << val << '\n';
    std::cout << std::right << std::setw(width) << val << '\n';
    std::cout << std::internal << std::setw(width) << val << '\n';
}

void _7_6()
{
    print_aligned_demo(123456, 15);
    print_aligned_demo(123456, 15, '_');
    //hex
    std::cout<<std::hex<<std::showbase;
    print_aligned_demo(0x123abc, 15);
    //oct
    std::cout<<std::oct;
    print_aligned_demo(0123456, 15);
    // upper hex
    std::cout<< "A hex number with upper case letters: "
        <<std::hex<<std::uppercase<<0x123abc<<'\n';
    std::cout <<"A number: " << 100 <<'\n';
    // dec
    std::cout<<std::dec;
    std::cout << "Oops. now in decimal again: " << 100 << '\n';
    // boolean
    std::cout << "true/false values: " << true << ", " << false << '\n';
    std::cout << std::boolalpha << "true/false values: " << true << ", " << false << '\n';
    // float
    std::cout << "doubles: " << 12.3 << ", " << 12.0 << ", " << std::showpoint << 12.0 << '\n';
    // double
    std::cout << "scientific double: " << std::scientific << 123000000000.123 << '\n';
    std::cout << "fixed double: " << std::fixed << 123000000000.123 << '\n';
    // precise
    std::cout << "Very precise double: " << std::setprecision(10) << 0.0000000001 << '\n';
    std::cout << "Less precise double: " << std::setprecision(1) << 0.0000000001 << '\n';
}
