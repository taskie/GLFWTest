require 'rake/clean'

Compiler = 'g++'

Out = 'glfwtest'
task :default => Out

Sources = FileList['**/*.cpp']
Objects = Sources.ext('o')

HeaderFlags = '-I/usr/local/include'
LibraryFlags = '-static -lstdc++ -lmingw32 -m32 -mwindows -lm -lglfw -lopengl32 -lglu32 -llua -ltolua++ -lfreetype -lOpenAL32.dll -logg.dll -lvorbis.dll -lvorbisfile.dll'

CLEAN.include(Objects)

file Out => Objects do |t|
  begin
    sh "#{Compiler} #{t.prerequisites.join(' ')} #{LibraryFlags} -o #{Out}"
  rescue
  end
end

rule '.o' => '.cpp' do |t|
  sh "#{Compiler} -std=c++11 -Wall #{HeaderFlags} -DNDEBUG -c #{t.source} -o #{t.source.ext('o')}"
end
