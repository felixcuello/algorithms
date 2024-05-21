# . divide and conquer
#    . divide
#    . conquer
# . three pointers


#  [3,2,4,120,0,3,3,4,5,6]
#
#                       p
#         t
#             c
#


def qs(a, head, tail)
  return if tail <= head

  p = tail
  s = head
  c = head

  while c < tail
    if a[c] <= a[p]
      a[s], a[c] = a[c], a[s]
      s += 1
    end
    c += 1
  end

  a[s], a[p] = a[p], a[s]

  qs(a, head, s-1)
  qs(a, s+1, tail)
end

def quicksort(array)
  qs(array, 0, array.count - 1)
  puts "Sorted => #{array.inspect}"
  array
end


a = [1,2,3,4]
puts quicksort(a) == a.sort

a = [3,2,4,120,0,3,3,4,5,6]
puts quicksort(a) == a.sort

a = [3]
puts quicksort(a) == a.sort

a = []
puts quicksort(a) == a.sort

a = [1,3,2]
puts quicksort(a) == a.sort

a = [1,1,1,1,1,1,1,1,1]
puts quicksort(a) == a.sort

a = [2,2,2,2,1,1,1,1]
puts quicksort(a) == a.sort




