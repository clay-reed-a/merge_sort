require 'awesome_print'
require_relative 'merge'


def merge_sort arr 
   
  len = arr.length 
  if len > 1

    split_arr_a = arr[0, arr.length/2]
    split_arr_b = arr[arr.length/2, arr.length-1]

    result_a = merge_sort split_arr_a
    result_b = merge_sort split_arr_b

    sorted_arr = merge result_a, result_b 

    sorted_arr
  else
    arr 
  end 

end

nums = [1, 11, 6, 4, 2, 3, 9, 7]

ap nums 
ap merge_sort nums 