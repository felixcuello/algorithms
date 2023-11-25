def permutations(str, current = '', used = 0)
  if str.length == current.length
    puts current
    return
  end

  str.length.times do |i|
    next if (used & (1 << i)) != 0

    permutations(str, current + str[i], used | (1 << i))
  end
end

permutations('1234')
