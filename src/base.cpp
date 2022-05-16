
#include "base.hpp"




int Base::get_int(std::string int_message)
{
    int returned_int;
    std::cout << int_message << "\n";
    std::cin >> returned_int;
    return returned_int;
}





std::string Base::get_str(std::string str_message)
{
    std::string returned_str;
    std::cout << str_message << "\n";
    std::getline (std::cin, returned_str);
    return returned_str;

}





bool Base::get_bool(std::string bool_message)
{
    int int_to_bool;
    bool returned_bool;
    std::cout << bool_message << "\n";
    std::string entered_bool_mess="Enter 1 for true and 0 for false.";
    std::cout << entered_bool_mess << "\n";
    std::cin >> int_to_bool;
    if (int_to_bool)
    {
        returned_bool=true;
    }
    else
    {
        returned_bool=false;
    };
    return returned_bool;

}




void Base::print_array(int array_len, int array[])
{
    for (int n=0; n<array_len; n++) 
    {
        int print_val=*array;
        array++;
        std::cout << print_val << ", ";
    }
    std::cout << "\n";
}