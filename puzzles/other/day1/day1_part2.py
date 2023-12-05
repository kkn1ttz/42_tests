class Digit:
    def __init__(self, start_index, value):
        self.start_index = start_index
        self.value = value
    

digits_dict = {
    "one": '1',
    "two": '2',
    "three": '3',
    "four": '4',
    "five": '5',
    "six": '6',
    "seven": '7',
    "eight": '8',
    "nine": '9'
}


def find_start_finish_number(line, digit_list):
    for index, char in enumerate(line):
        if (char >= '0' and char <= '9'):
            digit = Digit(start_index=index, value=char)
            digit_list.append(digit)
    return digit_list


def extract_all_digits(line):
    digits_list = []
    for key in digits_dict:
        value = digits_dict[key]
        start = 0
        while True:
            index = line.find(key, start)
            if index == -1:
                break
            digit = Digit(start_index=index, value=value)
            digits_list.append(digit)
            start = index + 1
            
    find_start_finish_number(line, digits_list)
    return digits_list

    
def make_int(digit_list):
    sorted_digit = sorted(digit_list, key=lambda x: x.start_index)
    
    min_value = min(enumerate(sorted_digit), key=lambda x: x[0])[1]
    max_value = max(enumerate(sorted_digit), key=lambda x: x[0])[1]
    string_number = min_value.value + max_value.value
    
    print("string_number:" + string_number)
    return int(string_number)


def loop_file():
    file_path = 'day1\callibration_document'
    sum = 0
    with open(file_path, 'r') as file:
        for line in file:
            sum = sum + make_int(digit_list=extract_all_digits(line))
        print('\n')

    return sum


def main():
    print(loop_file())


if __name__ == "__main__":
    main()
