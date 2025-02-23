while (True):
        # naive eval
        i, op = list(input().split())
        if i == "0" and op == "0":
            break
        if len(i) == 1:
            i = int(i)
        elif i[:2] == "0x":
            i = int(i, 16)
        elif i[0] == "0":
            i = int(i, 8)
        else:
            i = int(i)

        op = int(op)
        res = 0
        for _ in range(op):
            operation, result = list(input().split())
            result = int(result)
            if (operation[0] == "i"):
                if result != i:
                    # apply operation to curr
                    i = result
                    if (operation == "i"):
                        pass
                    elif (operation[1] == "-"):
                        i -= 1
                    else:
                        i += 1
                else:
                    res += 1
                    if operation == "i":
                        pass
                    elif (operation[1] == "-"):
                        i -= 1
                    else:
                        i += 1
            elif (operation[0] == "-"):
                if result != i -  1:
                    i = result 
                else:
                    res += 1
                    i -= 1
            elif (operation[0] == "+"):
                  if result != i + 1:
                      i = result 
                  else:
                      res += 1
                      i += 1
        print(res)
