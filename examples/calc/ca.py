
class Token:
    def __init__(self, type, value=None):
        self.type = type
        self.value = value

    def __repr__(self):
        return f'Token(type={self.type}, value={self.value})'


class Node:
    def __init__(self):
        self.left = None
        self.op = None
        self.right = None

    def __repr__(self):
        return f'Node(op={self.op})'


class Parser:
    def __init__(self, tokens):
        self.tokens = tokens
        self.pos = 0
        self.node = Node()


    def get_token(self):
        if self.pos >= len(self.tokens):
            return None
        tok = self.tokens[self.pos]
        self.pos += 1
        return tok


    def peek_token(self):
        if self.pos >= len(self.tokens):
            return None
        return self.tokens[self.pos]


    def parse_left(self):
        tok = self.get_token()
        return tok


    def parse_right(self, precedence=0):
        left = self.parse_left()
        peek = self.peek_token()
        if peek == None or peek.type < precedence:
            return left

        node = Node()
        node.left = left
        node.op = self.get_token()
        node.right = self.parse_right(node.op.type)
        return node


    def parse(self):
        left = None
        while self.peek_token() != None:
            left = self._parse(left)
        return left


    def _parse(self, node=None, precedence=0):
        self.node = Node()
        self.node.left = node or self.parse_left()
        self.node.op = self.get_token()
        self.node.right = self.parse_right(self.node.op.type)
        return self.node


class Evaluate:
    def eval(self, tree):
        if not tree:
            return 0

        if  isinstance(tree, Token):
            return tree.value
        
        if tree.op.value == '+':
            a = self.eval(tree.left)
            b = self.eval(tree.right)
            return a + b
        elif tree.op.value == '*':
            c = self.eval(tree.left)
            d = self.eval(tree.right)
            return  c * d
        elif tree.op.value == '-':
            e = self.eval(tree.left)
            f = self.eval(tree.right)
            return  e - f
        elif tree.op.value == '/':
            g = self.eval(tree.left)
            h = self.eval(tree.right)
            return  g / h


def tokenize_expression(expression):
    tokens = []
    number_buffer = []

    for char in expression:
        if char.isdigit() or (char == '.' and '.' not in number_buffer):
            number_buffer.append(char)
        else:
            if number_buffer:
                tokens.append(Token(1, float(''.join(number_buffer))))
                number_buffer = []
            if char == '+':
                tokens.append(Token(2, '+'))
            elif char == '*':
                tokens.append(Token(3, '*'))
            elif char == '-':
                tokens.append(Token(2, '-'))
            elif char == '/':
                tokens.append(Token(3, '/'))

    if number_buffer:
        tokens.append(Token(1, float(''.join(number_buffer))))

    return tokens


if __name__ == '__main__':
    # tokens = [
    #     Token(1, 1),
    #     Token(2, '+'),
    #     Token(1, 2),
    #     Token(2, '+'),
    #     Token(1, 3),
    #     Token(2, '+'),
    #     Token(1, 4),
    #     Token(3, '*'),
    #     Token(1, 5),
    #     Token(2, '+'),
    #     Token(1, 6),
    #     Token(3, '*'),
    #     Token(1, 7),
    # ]
    tokens = tokenize_expression(input('>>>'))
    p = Parser(tokens)
    tree = p.parse()
    ev = Evaluate()
    print(ev.eval(tree))
