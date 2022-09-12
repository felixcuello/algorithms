def generate_binary(n, string = "")
  if(string.length == n)
    puts string
  else
    generate_binary(n, "0" + string)
    generate_binary(n, "1" + string)
  end
end

generate_binary(5)
