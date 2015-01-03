def merge arr_a, arr_b 
  sorted_arr = []

  while !(arr_a.empty? || arr_b.empty?)
    a = arr_a.first 
    b = arr_b.first 
    if a < b 
      sorted_arr << arr_a.shift 
    else  
      sorted_arr <<  arr_b.shift 
    end  
  end 

  while !(arr_a.empty?) 
    sorted_arr << arr_a.shift  
  end 

  while !(arr_b.empty?)
    sorted_arr << arr_b.shift  
  end 

  sorted_arr
end 