class MyQueue:
    def __init__(self):
        self.stack_in = [ ]
        self.stack_out = [ ]

    def push(self, x: int) -> None:
        self.stack_in.append(x)

    def pop(self) -> int:
        self._transfer()
        return self.stack_out.pop()

    def peek(self) -> int:
        self._transfer()
        return self.stack_out[-1]

    def empty(self) -> bool:
        return not self.stack_in and not self.stack_out

    def _transfer(self) -> None:
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())

queue = MyQueue()
queue.push(10)
queue.push(20)
print(queue.peek())  
print(queue.pop())   
print(queue.empty()) 
