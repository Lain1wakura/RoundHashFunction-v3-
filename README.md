# RoundHashFunction-v3-
The last verson (for now) of my round hash function. This is a rather slow function (for a hash), so, I wouldn't recommend it for using.  
HeaderHash.h hasn't also changed.  

Example of working:  
>Enter input text, salt, hash lenght and quantity of rounds: string10 salt 10 5  
>TMNXhTdLfdxxwpvYowPdbWWTTtvXVU  
>TMNXhTdLfdxxwpvYowPdbWWTTtvXVUOXNYWfkbfU  
>TMNXhTdLfdxxwpvYowPdbWWTTtvXVUOXNYWfkbfUGZzpLQmlcf  
>TMNXhTdLfdxxwpvYowPdbWWTTtvXVUOXNYWfkbfUGZzpLQmlcfpyMwGtnvVf  
>Final hash (you won't see 4 lines above, just to show how it works) - pyMwGtnvVf  

And here is how it works  
This is how it works:  
text + hash = hash1  
salt + hash = hash2  
-------------------  
hash1 + hash2 = hash3  
hash1 + hash2 + hash3 = hash4  
hash1 + hash2 + hash3 + hash4 = hash5  
...  

P.S. Example to make sure everything works correctly (using RoundHashFunction-v1-)  
TMNXhTdLfdxxwpvYowPdbWWTTtvXVU is TMNXhTdLfd xxwpvYowPd bWWTTtvXVU  
  
>Enter input text, hash lenght and quantity of rounds: TMNXhTdLfdxxwpvYowPd 10 0  
>bWWTTtvXVU  
