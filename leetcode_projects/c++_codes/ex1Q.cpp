#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target){
    for(int i = 0; i < nums.size() - 1; i++){
        for(int j = 0; j < nums.size(); j++){
            if(nums[i] + nums[j] == target)//se alvo encontrado retorno as posições dos itens que somados chegam ao alvo
                return {i, j};
        }
    }

    return {-1, -1};
}

int main(){
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    std::cout << "índices: [" << result[0] << ", " << result[1] << "]\n";

    return 0;
}
