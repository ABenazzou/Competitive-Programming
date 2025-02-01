def custom_key2(piece):
    # sort by length
    length = len(piece)

    piece_order = {
        "K": 0,  
        "Q": 1,  
        "R": 2, 
        "B": 3,
        "N": 4,
    }

    char_priority = piece_order.get(piece[0], 5)
    # if pawn 5 else set prio

    # char prio -> row prio -> col prio
    if len(piece) == 2:

        return (char_priority, -int(piece[1]), piece[0])
    return (char_priority, -int(piece[2]), piece[1])


def custom_key(piece):
    # sort by length
    length = len(piece)
    
    piece_order = {
        "K": 0,  
        "Q": 1,  
        "R": 2, 
        "B": 3,
        "N": 4,
    }

    char_priority = piece_order.get(piece[0], 5)
    # if pawn 5 else set prio

    # char prio -> row prio -> col prio
    if len(piece) == 2:

        return (char_priority, int(piece[1]), piece[0])
    return (char_priority, int(piece[2]), piece[1])

board = []

for i in range(8):
    input() # skip header
    row = input()[1:-1].split("|")
    board.append(row)

input() # skip bottom row

board = board[::-1] # bottom up
black = []
white = []
for idxRow, row in enumerate(board):
    for idxCol, col in enumerate(row):
        if col in [":::", "..."]: continue

        char = col[1]
        colPosition = chr(idxCol + ord('a'))
        piece = colPosition + str(idxRow + 1)
        if char.upper() != 'P':
            piece = char.upper() + piece

        # pawns sorted easy
        # pieces same type -> white -> small row -> small col, black -> large row -> small col
        if char.isupper():
            l = white
#            white.append(piece)
        else:
            l = black
#            black.append(piece)

        l.append(piece)
white = sorted(white, key=custom_key)
black = sorted(black, key=custom_key2)
result = "White: " + ",".join(piece for piece in white) + "\nBlack: " + ",".join(piece for piece in black)
print(result)
