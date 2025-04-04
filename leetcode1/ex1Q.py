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

https://youtu.be/mKnWiHSPU2A

Solução O(n²)
'''
def twoSum(nums, target):
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

    for i in range (len(nums) - 1):
        for j in range (i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
'''    
Laço interno saindo de 0 a len(nums) - 1, porque se chego ao tamanho de 
nums é desnecessário, pois não há elemento diferente para ler. Laço externo 
vai de i + 1, a len(nums) para sempre ler um valor diferente. Se nums[i] + 
nums [j], for igual ao valor do target retorno os índices, caso não ache o 
valor rodando todo o vetor retorno -1, -1 para deixar claro que não há valor 
válido. Complexidade O(n²) GG.
'''
    return [-1, -1]

#numsTest1 = [7]
#numsTest2 = [7, 27, 1000000001, -9]

#targetTest1 = -1000000001

nums1 = [2, 7, 11, 15]
target1 = 9
print(twoSum(nums1, target1))

print()

nums1 = [2, 7, 11, 15]
target1 = 26
print(twoSum(nums1, target1))

print()

nums1 = [2, 7, 11, 15]
target1 = 22
print(twoSum(nums1, target1))

print()

nums1 = [2, 7, 11, 15]
target1 = -5
print(twoSum(nums1, target1))
