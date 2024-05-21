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

def qsb(a, head, tail)
  return if tail <= head

  c = head
  t = head
  p = tail

  ((tail-head)/1).times do |i|
    @tc += 1
  end

  while c < tail
    if a[c] <= a[p]
      a[c], a[t] = a[t], a[c]
      t += 1
    end
    c += 1
    @tc += 1
  end
  a[p], a[t] = a[t], a[p]

  qsb(a, head, t-1)
  qsb(a, t+1, tail)
end

a = []
b = []

number_of_elements = 5000
number_of_elements.times { a << rand(100) }
number_of_elements.times { b << rand(100) }

puts "size = #{a.count}"
@tc = 0
qs(a, 0, a.count - 1)
puts "costo quicksort : #{@tc}"

@tc = 0
qsb(b, 0, a.count - 1)
puts "costo quicksort problema: #{@tc}"
