class Number:
    def __init__(self, value, start_col, start_row, length):
        self.value = value
        self.start_col = start_col
        self.start_row = start_row
        self.length = length

    def __str__(self):
        return f"{self.value}"
    
    @classmethod
    def list_str(cls, number_list):
        return "[" + ", ".join(str(number) for number in number_list) + "]"

    def scan_adjacent_elements(self, matrix):
        row = self.start_row

        offsets = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1),           (0, 1),
            (1, -1), (1, 0),  (1, 1)
        ]

        for col in range(self.start_col, self.start_col + self.length):
            for offset_row, offset_col in offsets:
                new_row, new_col = row + offset_row, col + offset_col
                try:
                    if is_symbol(matrix[new_row][new_col]):
                        return (self.value)
                except IndexError:
                    pass

        return (0)


def find_numbers(line, row):
    numbers = []
    i = 0
    while i < len(line):
        if str.isdecimal(line[i]):
            value = []
            start_col = i
            length = 0
            try:
                while is_number(line[i]):
                    value.append(line[i])
                    i += 1
                    length += 1
                number = Number(value=int(''.join(value)),
                                start_col=start_col, start_row=row, length=length)
                numbers.append(number)
            except IndexError:
                pass
        i += 1
    return numbers


def extract_from_file():
    engine_schematic = []
    numbers = []
    str_line = []
    file_path = 'puzzles/avent_calendar/day3/puzzle_input'
    with open(file_path, 'r') as file:
        for row, line in enumerate(file):
            line = line.rstrip()
            numbers += find_numbers(line, row)
            # for number in numbers:
            #     print(number)
            print()
            engine_schematic.append(line)
    return ([engine_schematic, numbers])


def is_symbol(char):
    symbols = set("~!@#$%^&*()_-+={}[]|\\:;\"'<>,?/`")
    return (char in symbols)


def is_number(char):
    number = set("0123456789")
    return (char in number)


def main():
    matrix, numbers = extract_from_file()
    for row in matrix:
        print(row)
    print()

    sum = 0
    for n in numbers:
        sum += n.scan_adjacent_elements(matrix)
        # n.scan_adjacent_elements(matrix)
    print(sum)


if __name__ == "__main__":
    main()
