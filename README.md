# Bitwise Operators
4 different functions that return solutions to elementary operators, without using '+', '-', '*', or '/'.
Solutions are calculated using bolean operations:
- AND
- XOR
- Shift Right
- Shift left


## 1. Addition
1. Carrying digits: AND, then shift left 1 bit
2. Adding digits: XOR

Repeat steps until the 'carry' equals zero, then return the 'add'.
## 2. Subtraction
- Same as addition. For example: 10-3 = 10 - (+3).
- Use two's compliment on the subtrahend to make it negative. 
- Cast everything as signed.
## 3. Multiplication
- Shifting left 1 bit = multiplying number by 2; shifting right 1 bit = dividing number by 2.
- We need to keep both sides at an equilibrium. So if we shift 'x' 1 bit left, we must shift 'y' 1 bit right. 
- Keep shifting until you start losing bits from 'y'. Every bit you lose, you add your starting 'x' value to your final answer.
- Once 'y' gets to 1, return the shifted value of 'x'.
## 4. Division
- A value 'x' and a value 'y' is inputted.
- The 'y' value is shifted left until it is less than or equal to the current 'x' value.
- The answer is calculated by keeping track of the number of times 'y' is shifted, then squaring that. The square is added to any answer calculated previously.
- If x = y after shifting, return the answer.
- However, if x != y after shifting, the current 'x' value is replaced by subtracting the shifted 'y' value from 'x'.
- the 'y' value resets to the inputted value.
- The process continues.
- If x = y after subtracting and shifting 'y' back to its original value, the answer + 1 is returned.




   



