require 'primes/version'
require 'primes/primes'
require 'primes/primes_ext'
require 'benchmark'

module Primes
  def self.benchmark(count)
    Benchmark.bmbm do |x|
      x.report('rb') { get_primes7(count) }
      x.report('cpp') { get_primes_native(count) }
    end
  end
end
