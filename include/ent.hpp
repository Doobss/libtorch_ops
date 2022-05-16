#pragma once
#include "base.hpp"

class Ent : public Base
{
    public:
    std::string name="NONE";
    int num_of_attrs=0, *attr_vals{NULL}, *vec[3]={0,0,0};

    Ent();

    std::string get_name();
};