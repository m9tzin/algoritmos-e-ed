# Hash Table from Scratch
# Matheus Marinho

bucket_size = 10

class Hash(object):
    def __init__(self, bucket):
        self.__bucket = bucket
        self.__table = [[] for _ in range(bucket)]
    
    def hashFunction(self, key):
        return key % self.__bucket

    def insert(self, key):
        index = self.hashFunction(key)
        self.__table[index].append(key)
    
    def delete(self, key):
        index = self.hashFunction(key)
        if key not in self.__table[index]:
            return
        self.__table[index].remove(key)

    def printHash(self):
        for i in range(self.__bucket):
            print("[%d]" % i, end= '')
            for x in self.__table[i]:
                print(" --> %d" % x, end='')
            print()

# Main
if __name__ == "__main__":
    arr = [1, 5, 23, 10, 12]
    h = Hash(bucket_size)
    for x in arr:
        h.insert(x)
    h.printHash()