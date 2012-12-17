pkgs = ["../aps/font/Manager"]

pkgs.each do |pkg|
  name = pkg.split.last + "Glue"
  puts "tolua++ -n #{name} -o #{name}.cpp -H #{name}.h #{name}.tolua"
end