require 'primes/version'
require 'primes/primes'
require 'primes/primes_ext'
require 'benchmark/ips'

module Primes
  def self.benchmark(count)
    Benchmark.ips do |x|
      # x.report('Prime.each') { get_primes(count) }
      x.report('rb') { get_primes7(count) }
      x.report('cpp') { get_primes_native(count) }
      x.report('primesieve') { get_primesieve(count) }
      # x.report('count') { get_primesieve_count(count) }
      x.compare!
    end
  end
end
