def combinations(str, current = '', i=0)
  if(str.length == i)
    puts current
    return
  end

  combinations(str, current + str[i], i+1)
  combinations(str, current, i+1)
end

combinations('felix')

