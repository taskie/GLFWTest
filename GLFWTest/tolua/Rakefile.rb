require 'rake/clean'

Sources = FileList['**/*.tolua']
CPPs = Sources.ext('cpp')

task :default => CPPs

rule '.cpp' => '.tolua' do |t|
	sh "tolua++ -o #{t.source.ext('cpp')} -H #{t.source.ext('h')} #{t.source}"
end