package main

import "fmt"
//função que acha os dois valores no array que somados são iguais ao alvo
//implementação O(n)
func twoSum(nums []int, target int) []int{
    mapIndex := make(map[int]int)//criação do dicionário

    for i, num := range nums{
        possibleTarget := target - num

        if idx, ok := mapIndex[possibleTarget]; ok{//verificação se a chave existe no dicionário e retorna caso encontre
            return []int{idx, i}
        }

        mapIndex[num] = i//adiciona o valor e o índice ao dicionário
    }

    return []int{-1, -1}
}

func main(){
    nums := []int{2, 7, 11, 15}
    target := 26

    fmt.Println(twoSum(nums, target))
}
