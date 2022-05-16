#include "ent.hpp"



Ent::Ent()
{
    name=get_name();
    if(!num_of_attrs)
    {
        std::string message_print="There are currently no attributes for this entity, would you like to add some?";
        bool returned_bool=get_bool(message_print);
        if (returned_bool)
        {
            std::string message_print="Ok, what is the name of the added attribute?";
            std::string returned_str=get_str(message_print);
            std::cout <<"Attribute name is "<< returned_str << "\n\n";
        }
        else
        {
            std::cout <<"No added attributes."<<"\n\n";
        }
    }
}





std::string Ent::get_name()
{
    std::string returned_name, mess="Please enter a name for this entity.";
    returned_name=get_str(mess);
    std::cout << returned_name << "\n";
    return returned_name;
}





