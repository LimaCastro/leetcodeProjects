'''
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

    2 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9
    Only one valid answer exists.
https://youtu.be/TytlS2HLq4I

Versão O(n)

'''

def twoSum(nums: int, target: int) -> int:
    if len(nums) < 2 or len(nums) > 10 ** 4:
        raise ValueError('O tamanho de nums deve estar entre 2 a 10⁴.')
    #Trecho que verifica o tamanho vetor nums

    for num in nums:
        if num < -10 ** 9 or num > 10 ** 9:
            raise ValueError('O valor dos elementos de num deve estar entre -10⁹ a 10⁹')
    #Trecho que verifica se o valor dos elementos de num são válidos

    if target < -10 ** 9 or target > 10 ** 9:
        raise ValueError('O valor de target está fora do range de -10⁹ a 10⁹')
    #Trecho que verifica se o valor de target é válido
    #Primeiro bloco: Verificação das exceptions

    tableNumbersAndIndex = {}
    #dicionário que armazenará valor e seu índice

    for i, num in enumerate(nums):
        possibleTarget = target - num

        if possibleTarget in tableNumbersAndIndex:
            return [tableNumbersAndIndex[possibleTarget], i]

        tableNumbersAndIndex[num] = i
    '''
    Como se sabe que o valor é correspondente a soma de 2 números do conjunto, faço uma subtração para encontrar o possível target. Caso esteja no dicionário retorno os índices, caso contrário adiciono o índice com o número no 
    dicionário     
    '''
    return [-1, -1]

def main():
    # Exemplos de uso:
    nums1 = [2, 7, 11, 15]
    target1 = 9
    print(twoSum(nums1, target1))  # Saída: [0, 1]

    nums2 = [3, 2, 4]
    target2 = 6
    print(twoSum(nums2, target2))  # Saída: [1, 2]

    nums3 = [3, 3]
    target3 = 6
    print(twoSum(nums3, target3))  # Saída: [0, 1]

    nums1 = [2, 7, 11, 15]
    target1 = 26
    print(twoSum(nums1, target1))

    nums1 = [2, 7, 11, 15]
    target1 = 22
    print(twoSum(nums1, target1))

    nums1 = [2, 7, 11, 15]
    target1 = -5
    print(twoSum(nums1, target1))
    # Seu código principal aqui

if __name__ == "__main__":
    main()

