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

Solução O(n)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Nó que guarda a lista encadeada com a chave e o valor(Index)
typedef struct HashNode{
    int key;
    int value;
    struct HashNode* next;
} HashNode;

//tabela hash(array dos HashNodes)
typedef struct HashTable{
    HashNode** buckets;//Array de ponteiros para os nós.
    int size;//tamanho da tabela hash
} HashTable;

//índice para o hash (função do hash)
int hash(int key, int size){
    return abs(key) % size;
}

//criação da tabela hash
HashTable* createHashTable(int size){
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));

    table->size = size;
    table->buckets = (HashNode**)calloc(size, sizeof(HashNode*));

    return table;
}

//inserção na tabela hash
void insertHashTable(HashTable* table, int key, int value){
    int index = hash(key, table->size);

    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if(table->buckets[index] == NULL)
        table->buckets[index] = newNode;

    else{
        newNode->next = table->buckets[index];
        table->buckets[index] = newNode;
    }

    return;
}

//busca na tabela hash
int searchHashTable(HashTable* table, int key){
    int index = hash(key, table->size);

    HashNode* current = table->buckets[index];

    while(current != NULL){
        if(current->key = key)
            return current->value;

        current = current->next;
    }

    return -1;
}

//libera a memória
void removeHashTable(HashTable* table){
    for(int i = 0; i < table->size; i++){
        HashNode* current = table->buckets[i];

        while(current != NULL){
            HashNode* temp = current;

            current = current->next;

            free(temp);
        }
    }
    free(table->buckets);

    free(table);

    return;
}

void setNull(HashTable** table){
    if(table != NULL){
        removeHashTable(*table);

        *table = NULL;
    }

    return;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    HashTable* table = createHashTable(numsSize);

    int* result = (int*)malloc(2 * sizeof(int));
    
    *returnSize = 2;

    for(int i = 0; i < numsSize; i++){
        int possibleTarget = target - nums[i];

        int targetSearch = searchHashTable(table, possibleTarget);

        if(targetSearch != -1){
            result[0] = targetSearch;
            result[1] = i;

            setNull(&table);
            
            return result;
        }

        insertHashTable(table, nums[i], i);
    }

    *returnSize = 0;
    
    free(result);

    result = NULL;

    return NULL;
}

int main(){
    int nums[] = {2, 7, 11, 15}, target = 9;
    //int nums[] = {3, 2, 4}, target = 6;
    //int nums[] = {3, 3}, target = 6;//vetor e alvo.
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

