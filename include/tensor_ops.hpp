#pragma once
#include "base.hpp"
#include <torch/torch.h>


class Tensor_Ops : public Base
{
    public:
    std::string rand_or_randint_str="RAND";
    int num_of_dims, *dim_vals {NULL}, *randint_range {NULL};
    torch::Tensor rand;

    Tensor_Ops();
    int get_number_of_dims();
    void get_dim_vals(int num_dims, int array_to_mod[]);
    void build_rand_tensor(int num_dims, int dim_vals[], std::string rand_or_randint_str);
    std::string rand_or_randint(std::string rand_str);

};

/*int get_int(std::string message);*/
/*void print_array(int array_len, int array[]);*/