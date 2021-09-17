

1. Say "Hello, World!" With Python

```python
print("Hello, World!")
```
2. Python If-Else

```python
if __name__ == '__main__':
    n = int(input().strip())
    if(n&1):
        print("Weird")
    elif(n&1==0 and (n>=6 and n<=20) ):
        print("Weird")
    else:
        print("Not Weird")

```
3. Arithmetic Operators

```python
if __name__ == '__main__':
    a = int(input())
    b = int(input())
    print(a+b)
    print(a-b)
    print(a*b)
```

4. Python: Division


```python
if __name__ == '__main__':
    a = int(input())
    b = int(input())
    print(a//b)
    print(a/b)
```

5. Loops
```python
if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        print(i**2)
```

6. Write a function

```python
def is_leap(year):
    leap = False
    
    # Write your logic here
    if(year%4==0 and year%400==0):
        leap = True
    elif(year%4==0 and year%100==0):
        leap = False
    elif(year%4==0):
        leap = True
    return leap
```

7. Print Function

```python
if __name__ == '__main__':
    n = int(input())
    ret = ''
    for i in range(1,1+n):
        ret +=str(i)
    print(ret)

```


8. String Split and Join

```python
def split_and_join(line):
    # write your code here
    line = line.split(" ")
    return "-".join(line)

```

9. What's Your Name?
```python
def print_full_name(first, last):
    # Write your code here
    
    # f-string
    print(f"Hello {first} {last}! You just delved into python.")
    # str.format
    # print("Hello {} {}! You just delved into python.".format(first, last))
    

```

10. Mutations

```python
def mutate_string(string, position, character):
    return string[:position] + character + string[position+1:]

```

11. Find a string

```python
def count_substring(string, sub_string):
    l , s= len(sub_string) , len(string)
    ret = 0
    for i in range( 1+ s-l):
        if sub_string == string[i:i+l]:
           ret +=1
    return ret

```
12. String Validators

```python
if __name__ == '__main__':
    s = input()
    print(any(c.isalnum() for c in s))
    print(any(c.isalpha() for c in s))
    print(any(c.isdigit() for c in s))
    print(any(c.islower() for c in s))
    print(any(c.isupper() for c in s))
    
```

13. Text Alignment

```python
#Replace all ______ with rjust, ljust or center. 

thickness = int(input()) #This must be an odd number
c = 'H'

#Top Cone
for i in range(thickness):
    print((c*i).rjust(thickness-1)+c+(c*i).ljust(thickness-1))

#Top Pillars
for i in range(thickness+1):
    print((c*thickness).center(thickness*2)+(c*thickness).center(thickness*6))

#Middle Belt
for i in range((thickness+1)//2):
    print((c*thickness*5).center(thickness*6))    

#Bottom Pillars
for i in range(thickness+1):
    print((c*thickness).center(thickness*2)+(c*thickness).center(thickness*6))    

#Bottom Cone
for i in range(thickness):
    print(((c*(thickness-i-1)).rjust(thickness)+c+(c*(thickness-i-1)).ljust(thickness)).rjust(thickness*6))
```

14. Text Wrap


```python
def wrap(string, max_width):
    ret =''
    for i in range(0, len(string),max_width):
        if(i+max_width-1>len(string)):
            ret += string[i:]            
        else:
            ret +=  string[i:i+max_width] + '\n'
    return ret

```

15. Designer Door Mat

16. String Formatting
```python 
def print_formatted(number):
    # your code goes here
    width = len("{0:b}".format(n))
    for i in range(1, number+1):
        for base in ('d', 'o', 'X', 'b'):
            print("{0:{width}{base}}".format(i, base=base, width=width), end=' ')
        print()
```


17. Alphabet Rangoli



18. Capitalize!

```python
def solve(s):

    ret =''
    l,r= 0,0
    while r<len(s):
        if(s[r]==' '):
            ret += s[l].upper()
            ret += s[l+1:r+1]
            l = r+1
        r+=1
    ret += s[l].upper()
    ret += s[l+1:r]
    return ret
```