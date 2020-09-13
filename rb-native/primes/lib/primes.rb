require 'primes/version'
require 'primes/primes'
require 'primes/primes_ext'
require 'benchmark/ips'

module Primes
  def self.benchmark(count)
    Benchmark.ips do |x|
      x.report('rb') { get_primes7(count) }
      x.report('cpp') { get_primes_native(count) }
      x.compare!
    end
  end
end
