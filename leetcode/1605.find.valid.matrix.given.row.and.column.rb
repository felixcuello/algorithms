# https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
#
# You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is
# the sum of the elements in the ith row and colSum[j] is the sum of the elements of the
# jth column of a 2D matrix.
#
# In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.
#
# Find any matrix of non-negative integers of size rowSum.length x colSum.length that 
# satisfies the rowSum and colSum requirements.
#
# Return a 2D array representing any matrix that fulfills the requirements.
# It's guaranteed that at least one matrix that fulfills the requirements exists.
#

# @param {Integer[]} row_sum
# @param {Integer[]} col_sum
# @return {Integer[][]}
def restore_matrix(row_sum, col_sum)
  rows = row_sum.count
  cols = col_sum.count

  rows.times do |row|
    col.times do |col|
    end
  end
end
