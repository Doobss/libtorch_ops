#pragma once
#include <torch/torch.h>
#include "base.hpp"

class Env : public Base
{
    public:
    int num_of_ents, num_of_env_dims, *env_dims {NULL};
    torch::Tensor env_space;

    Env();
    int get_number_of_dims();
    void get_env_dims(int num_dims, int array_to_mod[]);
    int get_num_ents();
    torch::Tensor build_env_space(int *env_dims);

};