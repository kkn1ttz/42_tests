class Game:
    def __init__(self, line):
        set_list = []
        index_and_cubes = line.split(': ')

        index = int(index_and_cubes[0].split(' ')[1])
        cubes_all = index_and_cubes[1].split('; ')
        for set in cubes_all:  # 7 blue, 1 red, 14 green
            set_template = {'blue': 0, 'red': 0, 'green': 0}
            sub_sets = set.split(', ')  # 7 blue
            for sub_set in sub_sets:
                value = sub_set.split(' ')[0]  # 7
                color = sub_set.split(' ')[1]  # blue
                set_template[color] = int(value)
                print("set_template :", set_template)
            set_list.append(set_template)

        self.index = index
        self.cubes = set_list

    def is_possible(self, ref):
        for cube_set in self.cubes:
            for key, value in cube_set.items():
                result = ref[key] - value
                if result < 0:
                    return False
        return True

    def find_min_cubes(self):
        cubes_template = {"red": 0, "green": 0, "blue": 0}
        power = 1;
        for cube_set in self.cubes:
            for key, value in cube_set.items():
                if cubes_template[key] < value:
                    cubes_template[key] = value
        power = cubes_template["red"] * cubes_template["green"] * cubes_template["blue"]
        return power


cubes_ref = {"red": 12, "green": 13, "blue": 14}


def extract_from_file():
    game_list = []
    file_path = 'puzzles/avent_calendar/day2/puzzle_input'
    with open(file_path, 'r') as file:
        for line in file:
            line = line.rstrip();
            game_list.append(Game(line))
    return game_list


def main():
    games_list = extract_from_file()
    sum = 0
    for game in games_list:
        sum = sum + game.find_min_cubes()
    print(sum)


if __name__ == "__main__":
    main()