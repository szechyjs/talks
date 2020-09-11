require_relative 'lib/primes/version'

Gem::Specification.new do |spec|
  spec.name          = 'primes'
  spec.version       = Primes::VERSION
  spec.authors       = ['Jared Szechy']
  spec.email         = ['jared.szechy@gmail.com']

  spec.summary       = 'Demonstrate use of native extensions.'
  spec.homepage      = 'https://talks.szechy.dev/rb-native'
  spec.license       = 'MIT'
  spec.required_ruby_version = Gem::Requirement.new('>= 2.3.0')

  spec.metadata['homepage_uri'] = spec.homepage
  spec.metadata['source_code_uri'] = 'https://github.com/szechyjs/talks/tree/master/rb-native'

  # Specify which files should be added to the gem when it is released.
  # The `git ls-files -z` loads the files in the RubyGem that have been added into git.
  spec.files = Dir.chdir(File.expand_path('..', __FILE__)) do
    `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  end
  spec.bindir        = 'exe'
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.extensions    = %w[ext/primes/extconf.rb]
  spec.require_paths = ['lib']

  spec.add_dependency 'benchmark-ips'
end
