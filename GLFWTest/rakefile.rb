require 'rake/clean'

Compiler = 'g++'

Out = 'myshyp'
task :default => Out

Sources = FileList['**/*.cpp']
Objects = Sources.ext('o')

HeaderFlags = '-I/usr/include -I/usr/include/freetype2 -I/usr/include/lua5.1'
LibraryFlags = '-lopenal -lGL -lGLU -lXrandr -lX11 -pthread -lm -lglfw -ltoluapp -lfreetype -logg -lvorbis -lvorbisfile -lpng -lz -Bstatic -lluajit-5.1'

CLEAN.include(Objects)

file Out => Objects do |t|
  sh "#{Compiler} #{t.prerequisites.join(' ')} #{LibraryFlags} -o #{Out}"
end

rule '.o' => '.cpp' do |t|
  sh "#{Compiler} -std=c++14 -O3 -Wall #{HeaderFlags} -DNDEBUG -c #{t.source} -o #{t.source.ext('o')}"
end
