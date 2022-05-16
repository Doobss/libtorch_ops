#pragma once
#include <string>
#include <iostream>

class Base
{
    public:
    Base(){}

    int get_int(std::string int_message);
    std::string get_str(std::string str_message);
    bool get_bool(std::string bool_message);
    void print_array(int array_len, int array[]);

};