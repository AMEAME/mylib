require 'optparse'

option = { t: 100, f: 'ise_test.txt' }
OptionParser.new do |opt|
  opt.on('-t [VALUE]') { |v| option[:t] = v }
  opt.on('-f [VALUE]') { |v| option[:f] = v }
  opt.parse!(ARGV)
end

line = {}

print 'n: '
n = gets.to_i

loop do
  print 'k: '
  g = gets.to_s.chomp
  break if g == ''
  print 'v: '
  line[g] = gets.to_i
end

exit if line.empty?

code = Array.new(n) { line }

p code

code.map! do |l|
  l.each_with_object({}) { |(k, v), a| a[k] = rand(2**v); a }
end

p code

File.open(option[:f], 'w') do |f|
  code.each do |l|
    f.print "##{option[:t]}"
    l.each { |k, v| f.print " #{k} = #{v};" }
    f.puts
  end
end
