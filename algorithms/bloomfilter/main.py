from bloom_filter import Bloom_filter

with open("malicious.txt") as f:
    sites = f.read().split("\n")
    number = len(sites)

FALSE_POSITIVE_RATE = 0.05
bloomf = Bloom_filter(number,FALSE_POSITIVE_RATE)

print("Size of bit array:{}".format(bloomf.size))
print("False positive Probability:{}".format(bloomf.fp_prob))
print("Number of hash functions:{}".format(bloomf.hash_count))

for site in sites:
    bloomf.add(site)

query = input("Enter the name of the site:\n")

if query:
    is_malicious = bloomf.check(query)
    if is_malicious:
        print("The site may be malicious")
    else:
        print("You are safe, the site is not malicious")
else:
    print("please enter a site")