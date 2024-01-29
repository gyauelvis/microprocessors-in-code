# Function that converts a decimal integer to a binary integer using recursion.
# I should probably have handled decimal fractions as well, but for the sake of ... 
# ... how elegant the below solution is I am going to leave it and implement a complete solution ... 
# ... below it

def decToBin(n, cache=''):
    # When we have divided until we reach 1 the process must terminate
    if n % 2 == n: 
        return str(n) + cache
    
    cache = str(n % 2) + cache # Otherwise we add the new remainder to the other remainders
    return decToBin(n // 2, cache) # run the function again with the new quotient and previous remainders

def decToBinComplete(n):
    n = str(n)
    if '.' in n: 
        parts = n.split('.') # separate the integer and the fraction part
        integer = parts[0]
        fraction = '0.'+ parts[1]
        binInteger = decToBin(int(integer)) # obtain the binary integer
        remainder = float(fraction)
        cache = '.'
        # using the algorithm from class to calculate the fractional part ... 
        while remainder > 0: 
            result = float(remainder) * 2
            subtractor = int(result)
            remainder = result - subtractor
            cache += str(subtractor)
        return binInteger + cache + '0'
    else: 
        # If we do not have a fractional part then we can just... 
        # ... return the integer binary
        return decToBin(int(n))
        
        
print(decToBinComplete(5000.75))

