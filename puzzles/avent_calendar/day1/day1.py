def main():
    file_path = 'puzzles/avent_calendar/day1/callibration_document'
    floor = 0
    with open(file_path, 'r') as file:
        for line in file:
            for char_index, char in enumerate(line):
                if char == '(':
                    floor = floor + 1
                else:
                    floor = floor - 1
                if floor == -1:
                    print("floor: ",floor)
                    print("char: ", line[char_index], ", previous_char:", line[char_index-1])
                    print(char_index+1,"\n\n")

if __name__ == "__main__":
    main()