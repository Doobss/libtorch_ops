#include <iostream>

#include "tensor_ops.hpp"
#include "ent.hpp"
#include "env.hpp"


int main() {

    Env env_0;
  
    return 0;
}

































/*


int get_number_of_dims()
{
    int returned_int;
    std::string message_print="Please enter in the number of dims you like to have.";
    std::cout << message_print << "\n";
    std::cin >> returned_int;
    std::cout <<"Number of dims="<< returned_int << "\n";
    return returned_int;
}


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
*/