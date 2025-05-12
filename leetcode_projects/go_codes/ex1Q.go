package main

import "fmt"
//função que acha os dois valores no array que somados são iguais ao alvo
//implementação O(n²)
func twoSum(nums []int, target int) []int{
    for i := 0; i < len(nums) - 1; i++{
        for j := i + 1; j < len(nums); j++{
            if nums[i] + nums[j] == target{
                return []int{i, j}
            }
        }
    }

    return []int{-1, -1}
}

func main(){
    nums := []int{2, 7, 11, 15}
    target := 18

    fmt.Println(twoSum(nums, target))
}
