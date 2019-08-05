# You're given strings J representing the types of stones that are jewels,
#  and S representing the stones you have.  
# Each character in S is a type of stone you have.  
# You want to know how many of the stones you have are also jewels.

# The letters in J are guaranteed distinct, and all characters in J and S are letters. 
# Letters are case sensitive, so "a" is considered a different type of stone from "A".

def numJewelsInStones(J: str, S: str) -> int:
        j_hash = {}
        j_count = 0
        for j in J:
            j_hash[j] = True
        for s in S:
            if s in j_hash:
                j_count += 1
        return j_count