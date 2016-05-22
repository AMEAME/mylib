exit if ARGV[0].nil?
file = ARGV[0]

unless File.exist?('./include/' + file + '.h')
  puts 'file not found.'
  exit
end

rows = File.readlines('./include/' + file + '.h').map { |l| l.chomp.split(' ') }

rows.select! do |l|
  l[1] ? l[1].include?('(') : false
end

rows.map! { |l| l.reduce('') { |a, e| a + ' ' + e } }

rows.each { |l| puts l }
