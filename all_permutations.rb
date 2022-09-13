
# Context:
#
# The idea of all permutations is to make a backtracking call that make us create
# all the permutations of a given string.
# This is equivalent to say, that at each step of the process we can't reuse the
# letter we already used before, so we need to keep track of that.


# string  : is the given string
# current : is the current permutation
# used    : is a way to keep track of the used letters
def all_permutations(string, current = '', used = 0)
  sl = string.length

  # If the current string has the same letters as the given string
  # it means we found a permutation
  if sl == current.length
    puts current
    return
  end

  sl.times do |i|
    next if used & (1 << i) != 0 # This letter was used already

    all_permutations(string, current + string[i], used | (1 << i))
  end
end

all_permutations('abcdef')
