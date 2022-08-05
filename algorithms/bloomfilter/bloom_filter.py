import math
import mmh3
from bitarray import bitarray


class Bloom_filter(object):

    def __init__(self, items_count, fp_prob):
        self.fp_prob = fp_prob

        self.size = self.get_size(items_count, fp_prob)

        self.hash_count = self.get_hash_count(self.size, items_count)

        self.bit_array = bitarray(self.size)
        self.bit_array.setall(0)

    @classmethod
    def get_size(self, n, p):
        m = -(n * math.log(p)) / (math.log(2) ** 2)
        return int(m)

    @classmethod
    def get_hash_count(self, m, n):
        k = (m / n) * math.log(2)
        return int(k)

    def add(self, item):
        for i in range(self.hash_count):
            index = mmh3.hash(item, i) % self.size
            self.bit_array[index] = True
    
    def check(self, item):
        for i in range(self.hash_count):
            index = mmh3.hash(item, i) % self.size
            if not self.bit_array[index]:
                return False
        return True
