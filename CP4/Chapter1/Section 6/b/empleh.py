white = input().lstrip("White: ")
black = input().lstrip("Black: ")
white = [] if len(white) == 0 else white.split(",")
black = [] if len(black) == 0 else black.split(",")

board = []
for i in range(8):
    row = []
    for j in range(8):
        if (i % 2 == j % 2):
            row.append("...")
        else:
            row.append(":::")
    board.append(row)

# reverse to fill it without bothering with numbers
board = board[::-1]
for piece in white:
    row = int(piece[-1]) - 1
    col = ord(piece[-2]) - ord('a')
    char = "P" if len(piece) == 2 else piece[0].upper()
    board[row][col] = board[row][col][0] + char + board[row][col][0]

for piece in black:
    row = int(piece[-1]) - 1
    col = ord(piece[-2]) - ord('a')
    char = "p" if len(piece) == 2 else piece[0].lower()
    board[row][col] = board[row][col][0] + char + board[row][col][0]

# reverse again
board = board[::-1]

for row in board:
    print("+---+---+---+---+---+---+---+---+")
    line = "|".join(row)
    line = "|" + line + "|"
    print(line)

print("+---+---+---+---+---+---+---+---+")
        
