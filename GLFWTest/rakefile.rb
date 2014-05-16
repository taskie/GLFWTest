require 'rake/clean'

Compiler = 'icpc'

Out = 'myshyp'
task :default => Out

Sources = FileList['**/*.cpp']
Objects = Sources.ext('o')

HeaderFlags = '-I/usr/include -I/usr/include/freetype2 -I/usr/include/lua5.1'
statLibraryFlags = '-lopenal -lGL -lGLU -lXrandr -lX11 -pthread -lm -lglfw -ltolua++5.1 -lfreetype -logg -lvorbis -lvorbisfile -lpng -lz -Bstatic -lluajit-5.1'

CLEAN.include(Objects)

file Out => Objects do |t|
  begin
    sh "#{Compiler} #{t.prerequisites.join(' ')} #{LibraryFlags} -o #{Out}"
  rescue
  end
end

rule '.o' => '.cpp' do |t|
  sh "#{Compiler} -std=c++11 -O3 -xHOST -ip -fPIC -fma -no-prec-div -Wall #{HeaderFlags} -DNDEBUG -c #{t.source} -o #{t.source.ext('o')}"
end
