#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target){
    std::unordered_map<int, int> mapNumbers;//chave-valor, implementação hash visando que o algoritmo opere em O(n)

    for(int i = 0; i < nums.size(); i++){
        int possibleTarget = target - nums[i];//como target é o valor encontrado a partir da soma de dois valores de num
                                              //seu possível valor vai ser o complemento de algum valor do vetor menos o target
        if(mapNumbers.find(possibleTarget) != mapNumbers.end())//checa a existência do possível target no hash, se encontrado retorna a função
            return {mapNumbers[possibleTarget], i};

        mapNumbers[nums[i]] = i;//caso contrário adiciona o valor atribuído a nums[i] e o índice ao hash.
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
