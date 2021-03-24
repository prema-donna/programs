def isValidParen(s):
    stack = []
    parenMap = {")":"(", "}":"{", "]":"["}
    for char in s:
        if char in parenMap and parenMap[char] not in stack: #check if rbrac is first
            return False
        if char not in parenMap: #if lbrac is detected for the first time, add to stack
            stack.append(char)
        else:
            if parenMap[char] in stack[-1]: #if last stack entry is same as char, pop stack
                stack.pop(-1)
    if len(stack) == 0:
        print("{} is balanced".format(s))
        return True
    print("{} is not balanced".format(s))
    return False

parenString = input(str())
isValidParen(parenString)
