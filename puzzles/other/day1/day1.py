def find_start_finish_number(line):
    first_char = '0'
    second_char = '0'
    i = 0
    
    for char in line:
        if (char >= '0' and char <= '9'):
            if i == 0:
                first_char = char
                second_char = char
                i = i + 1
            else:
                second_char = char
    string_number = first_char + second_char
    print("string_number: "+string_number+"\n")
    return int(string_number)


def loop_file():
    file_path = 'day1\callibration_document'
    sum = 0
    with open(file_path, 'r') as file:
        for line in file:
            sum = sum + find_start_finish_number(line)
        print('\n')

    return sum


def main():
    print(loop_file())


if __name__ == "__main__":
    main()