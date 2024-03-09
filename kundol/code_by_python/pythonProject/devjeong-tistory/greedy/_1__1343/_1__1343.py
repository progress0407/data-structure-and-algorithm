def cover_board(board):
    # Replace every four 'X's with 'AAAA'
    board = board.replace('XXXX', 'AAAA')
    # Replace every two 'X's with 'BB'
    board = board.replace('XX', 'BB')

    # Check if there are any 'X's left, if so return -1
    if 'X' in board:
        return -1
    else:
        return board


# Test case from the example
if __name__ == '__main__':
    str = input()
