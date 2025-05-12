///retorna os índices referentes ao elementos do array num que somados são iguais ao target. Solução O(n), utilizando Hash.
use std::collections::HashMap;

pub fn two_sum_linear(nums: Vec<i32>, target: i32) -> Vec<i32>{
    let mut map = HashMap::new();

    for(i, &num) in nums.iter().enumerate(){
        let possible_target = target - num;

        if let Some(&possible_target_index) = map.get(&possible_target) {
            return vec![possible_target_index as i32, i as i32];
        }
        
        map.insert(num, i);        
    }

    vec![-1, -1]
}
