def qs(a, head, tail)
  return if tail <= head

  c = head
  t = head
  p = tail

  while c < tail
    if a[c] <= a[p]
      a[c], a[t] = a[t], a[c]
      t += 1
    end
    c += 1
    @tc += 1
  end
  a[p], a[t] = a[t], a[p]

  qs(a, head, t-1)
  qs(a, t+1, tail)
end

def quicksort(array)
  qs(array, 0, array.count - 1)
  puts array.inspect
  array
end

@tc = 0
#a = [1,2,3,4,5]
a = [1,5,30,50,60,25,9]
  
puts quicksort(a) == a.sort
puts  "tc = #{@tc}"

