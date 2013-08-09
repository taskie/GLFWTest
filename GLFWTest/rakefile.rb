require 'rake/clean'

Compiler = 'g++'

Out = 'myshyp'
task :default => Out

Sources = FileList['**/*.cpp']
Objects = Sources.ext('o')

HeaderFlags = '-I/usr/local/include -I/usr/local/include/freetype'
LibraryFlags = '-static -lstdc++ -lmingw32 -m32 -mwindows -lm -lglfw -lopengl32 -lglu32 -ltolua++ -lfreetype -lOpenAL32.dll -logg.dll -lvorbis.dll -lvorbisfile.dll lua51.dll'

CLEAN.include(Objects)

file Out => Objects do |t|
  begin
    sh "#{Compiler} #{t.prerequisites.join(' ')} #{LibraryFlags} -o #{Out}"
  rescue
  end
end

rule '.o' => '.cpp' do |t|
  sh "#{Compiler} -std=c++11 -O3 -Wall #{HeaderFlags} -DNDEBUG -c #{t.source} -o #{t.source.ext('o')}"
end
