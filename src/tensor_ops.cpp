#include "tensor_ops.hpp"


Tensor_Ops::Tensor_Ops()
{
    num_of_dims=get_number_of_dims();    
    dim_vals=new int[num_of_dims];
    get_dim_vals(num_of_dims, dim_vals);
    rand_or_randint_str=rand_or_randint(rand_or_randint_str);
    build_rand_tensor(num_of_dims, dim_vals, rand_or_randint_str);
    std::cout << "Rand:\n" << rand;
}





int Tensor_Ops::get_number_of_dims()
{
    int returned_int;
    std::string message_print="Please enter in the number of dims you like to have.";
    returned_int=Tensor_Ops::get_int(message_print);
    std::cout <<"Number of dims="<< returned_int << "\n\n";
    return returned_int;
}





void Tensor_Ops::get_dim_vals(int num_dims, int array_to_mod[])
{
    std::string message_print, init_message_print, dim_str;
    for (int n=0; n<num_dims; n++) 
    {
        dim_str=std::to_string(n);
        init_message_print="Please enter in the value for dim ";
        message_print= init_message_print+dim_str;
        *array_to_mod=Tensor_Ops::get_int(message_print);
        array_to_mod++;

    }
    std::cout <<"\nEntered dim vals=";
    print_array(num_of_dims, dim_vals);
}





void Tensor_Ops::build_rand_tensor(int num_dims, int dim_vals[], std::string rand_or_randint_str)
{
    bool is_avail;
    is_avail=torch::cuda::is_available();
    std::cout << "\nCUDA is available=" << is_avail << std::endl;
    auto device=torch::kCPU;
    if (is_avail)
    {
        device=torch::kCUDA;
    }
    auto options =
    torch::TensorOptions()
        .dtype(torch::kFloat32)
        .layout(torch::kStrided)
        .device(device)
        .requires_grad(false);
        
    
    if (num_dims==1)
    {
        if (rand_or_randint_str=="RAND")
            rand = torch::rand({dim_vals[0]}, options);
        else
        {
            rand = torch::randint(randint_range[0], randint_range[1], {dim_vals[0]}, options);
        }
    }
    else if (num_dims==2)
    {
        if (rand_or_randint_str=="RAND")
            rand = torch::rand({dim_vals[0],dim_vals[1]}, options);
        else
        {
            rand = torch::randint(randint_range[0], randint_range[1], {dim_vals[0],dim_vals[1]}, options);
        }
    }
    else if (num_dims==3)
    {
        if (rand_or_randint_str=="RAND")
            rand = torch::rand({dim_vals[0], dim_vals[1], dim_vals[2]}, options);
        else
        {
            rand = torch::randint(randint_range[0], randint_range[1], {dim_vals[0], dim_vals[1], dim_vals[2]}, options);
        }
    }
    else if (num_dims>=4)
    {
        std::cout << "Too many dims no tensor initialized.\n";
    }
}





std::string Tensor_Ops::rand_or_randint(std::string rand_str)
{
    std::string rand_return_str;
    int change_type;
    if(rand_str == "RAND") 
    {
        std::string mess = "\n  Current tensor creation type is RAND, do you want to change create type to RANDINT?\n  If you want to change enter 1\n  Else enter 0";
        change_type=get_int(mess);
        if (change_type==1)
        {
            rand_return_str="RANDINT";
            std::cout << "  OK tensor type now RANDINT, please enter values for the RANDINT range.\n";
            randint_range=new int[2];
            for(int n=0; n<2; n++)
            {
                std::string range_mess = "    Enter range val";
                int new_range_val=get_int(range_mess);
                randint_range[n]=new_range_val;
            }
            std::cout <<"\nEntered range vals=";
            print_array(2, randint_range);

        }
        else 
        {
            std::cout << "  OK tensor type RAND.\n";
        }
    }
    else
    {
        std::string mess = "\n  Current tensor creation type is RANDINT, do you want to change create type to RAND?\n  If you want to change enter 1\n  Else enter 0";
        change_type=get_int(mess);
        if (change_type==1)
        {
            rand_return_str="RAND";
            std::cout << "  OK tensor type now RAND.";
        }
        else 
        {
            std::cout << "  OK tensor type RANDINT.\n";
        }
    }
    return rand_return_str;
}







/*
int Tensor_Ops::get_int(std::string message)
{
    int returned_int;
    std::cout << message << "\n";
    std::cin >> returned_int;
    return returned_int;
}

void Tensor_Ops::print_array(int array_len, int array[])
{
    for (int n=0; n<array_len; n++) 
    {
        int print_val=*array;
        array++;
        std::cout << print_val << ", ";
    }
    std::cout << "\n";
}
*/
/*
int main() {

    bool is_avail;
    is_avail=torch::cuda::is_available();
    std::cout << is_avail << std::endl;
    auto device=torch::kCPU;
    if (is_avail)
    {
        device=torch::kCUDA;
    }
    std::cout << device << std::endl;
    auto options =
    torch::TensorOptions()
        .dtype(torch::kFloat32)
        .layout(torch::kStrided)
        .device(device)
        .requires_grad(false);

    torch::Tensor tensor = torch::rand({12, 10}, options);
    std::cout << tensor << std::endl;
}





#include <iostream>

void say_hello(){
    std::cout << "Hello, from ML_proj!\n";
}
*/

//#include "/home/ianbringe/Code/CPP/libtorch/include/torch/csrc/api/include/torch/torch.h"
//#include "/Code/CPP/libtorch/include/torch/csrc/api/include/torch/torch.h"
//#include </home/ianbringe/Code/CPP/pytorch/test_mod.ixx>
//import test_mod;