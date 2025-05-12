/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

trad: Dado um vetor de números inteiros e um inteiro alvo, retorne o índice dos dois números que somados são iguais ao alvo.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

trad:Você pode assumir que cada entrada tem somente uma única solução, e você não pode utilizar o mesmo elemento duas vezes (ou seja, os dois índices devem ser diferentes).

You can return the answer in any order.

trad: Você pode retornar a resposta em qualquer ordem

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

trad: Limitações:

    2 <= nums.length <= 10⁴
    -10⁹ <= nums[i] <= 10⁹
    -10⁹ <= target <= 10⁹
    Only one valid answer exists.

https://youtu.be/mKnWiHSPU2A

Solução O(n²)

DICA: utilizar o const em códigos que não irei alterar a variável.
*/
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));//Alocação dinâmica de result, que vai ser 2. Pois tenho que retornar o índice das duas posições do vetor que alcanço o alvo
    *returnSize = 2;//valor atribuído a returnSize

    for(int i = 0; i < numsSize - 1; i++){//Laço externo rodando de 0 até o penúltimo elemento. Se chegarmos ao último elemento, não temos outro elemento para tentar encontrar o alvo
        for(int j = i + 1; j < numsSize; j++){//Laço interno que roda do elemento atual + 1 até o último elemento. Rodo desse jeito pois não posso utilizar o mesmo valor(número no mesmo índice) para chegar ao target. 
                                              //E como não preciso checar novamente o item analisado sempre discorro de atual + 1 em diante.
            if(nums[i] + nums[j] == target){//se o valor em nums na posição i + nums na posição j é igual ao target
                result[0] = i;//primeiro elemento será i
                result[1] = j;//segundo elemento será j
                return result;//retorno o vetor alocado dinâmicamente
            }
        }
    }

    *returnSize = 0;//não há elemento para retornar
    free(result);//libero o espaço de memória
    result = NULL;//faço ele receber NULL

    return NULL;//retorno NULL, pois não encontrei os elementos para se chegar ao alvo
}

int main(){
    //int nums[] = {2, 7, 11, 15}, target = 9;
    //int nums[] = {3, 2, 4}, target = 6;
    int nums[] = {3, 3}, target = 6;//vetor e alvo.
    int numsSize = sizeof(nums) / sizeof(nums[0]);//tamanho do vetor: número de bytes totais/número de bytes de um único elemento.
    int returnSize;//variável usada para alocar o tamanho do retorno em número de elementos.

    int* answer = twoSum(nums, numsSize, target, &returnSize);

    if(answer != NULL){
        printf("Index: [%d] [%d]\n", answer[0], answer[1]);
        free(answer);
        answer = NULL;
    }
    

    return 0;
}

