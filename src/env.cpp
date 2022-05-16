#include "env.hpp"


Env::Env()
{
    num_of_env_dims=get_number_of_dims();    
    env_dims=new int[num_of_env_dims];
    get_env_dims(num_of_env_dims, env_dims);
    num_of_ents=get_num_ents();
    env_space=build_env_space(env_dims);
    //using namespace torch::indexing;
    //std::cout << "Env space:\n" << env_space.index({Slice(0,6), 5, Slice()});
    std::cout << "Env space:\n" << env_space.sizes();
}





int Env::get_number_of_dims()
{
    int returned_int;
    std::string message_print="Please enter in the number of dims you want your world to have, (Max of 3).";
    returned_int=get_int(message_print);
    std::cout <<"Number of dims="<< returned_int << "\n\n";
    return returned_int;
}





void Env::get_env_dims(int num_of_env_dims, int array_to_mod[])
{
    std::string message_print, init_message_print, dim_str;
    for (int n=0; n<num_of_env_dims; n++) 
    {
        dim_str=std::to_string(n);
        init_message_print="Please enter in the value for dim ";
        message_print= init_message_print+dim_str;
        *array_to_mod=get_int(message_print);
        array_to_mod++;

    }
    std::cout <<"\nEntered dim vals=";
    print_array(num_of_env_dims, env_dims);
}





int Env::get_num_ents()
{
    int returned_int;
    std::string message_print="Please enter in the number of entities you want your world to have.";
    returned_int=Env::get_int(message_print);
    std::cout <<"Number of dims="<< returned_int << "\n\n";
    return returned_int;
}





torch::Tensor Env::build_env_space(int *env_dims)
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
        .dtype(torch::kInt16)
        .layout(torch::kStrided)
        .device(device)
        .requires_grad(false);

    torch::Tensor returned_space;
    if (num_of_env_dims==1)
    {
        returned_space = torch::zeros({env_dims[0]}, options);    
    }
    else if (num_of_env_dims==2)
    {
        returned_space = torch::zeros({env_dims[0],env_dims[1]}, options);
    }
    else if (num_of_env_dims==3)
    {
        returned_space = torch::zeros({env_dims[0], env_dims[1], env_dims[2]}, options);
    }
    else if (num_of_env_dims>=4)
    {
        std::cout << "Too many dims no tensor initialized.\n";
    }

    return returned_space;
};