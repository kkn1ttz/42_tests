class Game:
    def __init__(self, line):
        set_list = []
        index_and_cubes = line.split(': ')

        index = int(index_and_cubes[0].split(' ')[1])
        cubes_all = index_and_cubes[1].split['; ']
        for set in cubes_all:  # 7 blue, 1 red, 14 green
            set = {'blue': 0, 'red': 0, 'green': 0}
            sub_sets = set.split[', ']  # 7 blue
            for sub_set in sub_sets:
                value = sub_set.split[' '][0]  # 7
                color = sub_set.split[' '][1]  # blue
                set[color] = int(value)
            set_list.append(set)

        self.index = index
        self.cubes = set_list

    def is_possible(self, ref):
        result = 0
        for set in self.cubes:
            for key, value in set:
                result = ref[key] - value
                if (result < 0):
                    return False
        return True


cubes_ref = {"red": 12, "green": 13, "blue": 14}


def extract_from_file():
    game_list = []
    file_path = 'puzzles/avent_calendar/day2/puzzle_input'
    with open(file_path, 'r') as file:
        for line in file:
            game_list.append(Game(line))
    return game_list


def main():
    games_list = extract_from_file()
    sum = 0
    for game in games_list:
        if game.is_possible(cubes_ref):
            sum = sum + game.index
    print(sum)


if __name__ == "__main__":
    main()
