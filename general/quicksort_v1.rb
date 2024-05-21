
# quicksort is a very common algorithm
# the idea is to use "divide and conquer", a pivot, and a 3 pointers
#
# 1st. Select a pivot (p) element (elements lower than the pivot goes to the left, elements higher goes to the right)
# 2nd. Define 3 pointers:
#        s -> where the next small elements should go
#        c -> current element evaluated
#        p -> pivot pointer
def qs(a, head, tail)
  return if tail <= head

  p = tail
  s = head
  c = head

  # divide
  while c < tail
    if a[c] <= a[p]
      a[s], a[c] = a[c], a[s]
      s += 1
    end
    c += 1
  end

  # swap pivot , now the pivot is in the correct place
  a[p], a[s] = a[s], a[p]

  qs(a, head, s-1)
  qs(a, s+1, tail)
end

def quicksort(array)
  ac = array.count
  qs(array, 0, ac - 1) if ac > 1

  puts "array sorted => #{array}"
  array
end


puts quicksort([5,4,0,2,4,7,9,3,5]) == [5,4,0,2,4,7,9,3,5].sort
puts quicksort([3,2]) == [2,3]
puts quicksort([3,2,1]) == [1,2,3]
puts quicksort([]) == []
puts quicksort([3]) == [3]
