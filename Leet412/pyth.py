class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        answer = []

        for i in range(1, n):
            if i % 15 == 0:
                answer.append("FizzBuzz")
            elif i % 3 == 0:
                answer.append("Fizz")
            elif i % 5 == 0:
                answer.append("Buzz")
            else:
                answer.append(i)
        
        return answer