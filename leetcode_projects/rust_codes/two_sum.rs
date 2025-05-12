///retorna os índices referentes ao elementos do array num que somados são iguais ao target. Solução O(n²)
pub fn two_sum_quadratic(nums: Vec<i32>, target: i32) -> Vec<i32>{
    for i in 0..(nums.len() - 1){
        for j in i + 1..nums.len(){
            if nums[i] + nums[j] == target{
                return vec![i as i32, j as i32];
            }
        }
    }

    return vec![-1, -1]
}
