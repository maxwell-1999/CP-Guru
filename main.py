winning_combinations = {
    100: [['diamond', 'diamond', 'diamond']],
    45: [['crown', 'crown', 'crown']],
    20: [['cup', 'cup', 'cup'], ['cup', 'cup', 'crown']],
    12: [['coin', 'coin', 'coin'], ['coin', 'coin', 'crown']],
    10: [['gift', 'gift', 'gift'], ['gift', 'gift', 'crown']],
    5: [['thunderbolt', 'thunderbolt', 'thunderbolt']],
    3: [['thunderbolt', 'thunderbolt']],
    2: [['thunderbolt']],
}

all_winning_combinations = [['diamond', 'diamond', 'diamond'],
                   ['crown', 'crown', 'crown'],
                   ['cup', 'cup', 'cup'],
                   ['cup', 'cup', 'crown'],
                   ['coin', 'coin', 'coin'],
                   ['coin', 'coin', 'crown'],
                   ['gift', 'gift', 'gift'],
                   ['gift', 'gift', 'crown'],
                   ['thunderbolt', 'thunderbolt', 'thunderbolt'],
                   ['thunderbolt', 'thunderbolt'],
                   ['thunderbolt']]

slot_symbols = ['diamond', 'crown', 'cup', 'coin', 'gift', 'thunderbolt']
slot_symbols_v2 = ['diamond', 'crown', 'cup', 'coin', 'gift']

all_combinations = [
 ['diamond', 'crown', 'cup'], ['diamond', 'crown', 'coin'], ['diamond', 'crown', 'gift'], ['diamond', 'crown', 'thunderbolt'],
 ['diamond', 'cup', 'crown'], ['diamond', 'cup', 'coin'], ['diamond', 'cup', 'gift'], ['diamond', 'cup', 'thunderbolt'],
 ['diamond', 'coin', 'crown'], ['diamond', 'coin', 'cup'], ['diamond', 'coin', 'gift'], ['diamond', 'coin', 'thunderbolt'],
 ['diamond', 'gift', 'crown'], ['diamond', 'gift', 'cup'], ['diamond', 'gift', 'coin'], ['diamond', 'gift', 'thunderbolt'],
 ['diamond', 'thunderbolt', 'crown'], ['diamond', 'thunderbolt', 'cup'], ['diamond', 'thunderbolt', 'coin'], ['diamond', 'thunderbolt', 'gift'],
 ['cup', 'diamond', 'crown'], ['cup', 'diamond', 'coin'], ['cup', 'diamond', 'gift'], ['cup', 'diamond', 'thunderbolt'],
 ['cup', 'crown', 'diamond'], ['cup', 'crown', 'coin'], ['cup', 'crown', 'gift'], ['cup', 'crown', 'thunderbolt'],
 ['cup', 'coin', 'diamond'], ['cup', 'coin', 'crown'], ['cup', 'coin', 'gift'], ['cup', 'coin', 'thunderbolt'],
 ['cup', 'gift', 'diamond'], ['cup', 'gift', 'crown'], ['cup', 'gift', 'coin'], ['cup', 'gift', 'thunderbolt'],
 ['cup', 'thunderbolt', 'diamond'], ['cup', 'thunderbolt', 'crown'], ['cup', 'thunderbolt', 'coin'], ['cup', 'thunderbolt', 'gift'],
 ['gift', 'diamond', 'crown'], ['gift', 'diamond', 'cup'], ['gift', 'diamond', 'coin'], ['gift', 'diamond', 'thunderbolt'],
 ['gift', 'crown', 'diamond'], ['gift', 'crown', 'cup'], ['gift', 'crown', 'coin'], ['gift', 'crown', 'thunderbolt'],
 ['gift', 'cup', 'diamond'], ['gift', 'cup', 'crown'], ['gift', 'cup', 'coin'], ['gift', 'cup', 'thunderbolt'],
 ['gift', 'coin', 'diamond'], ['gift', 'coin', 'crown'], ['gift', 'coin', 'cup'], ['gift', 'coin', 'thunderbolt'],
 ['gift', 'thunderbolt', 'diamond'], ['gift', 'thunderbolt', 'crown'], ['gift', 'thunderbolt', 'cup'], ['gift', 'thunderbolt', 'coin'],
 ['coin', 'diamond', 'crown'], ['coin', 'diamond', 'cup'], ['coin', 'diamond', 'gift'], ['coin', 'diamond', 'thunderbolt'],
 ['coin', 'crown', 'diamond'], ['coin', 'crown', 'cup'], ['coin', 'crown', 'gift'], ['coin', 'crown', 'thunderbolt'],
 ['coin', 'cup', 'diamond'], ['coin', 'cup', 'crown'], ['coin', 'cup', 'gift'], ['coin', 'cup', 'thunderbolt'],
 ['coin', 'gift', 'diamond'], ['coin', 'gift', 'crown'], ['coin', 'gift', 'cup'], ['coin', 'gift', 'thunderbolt'],
 ['coin', 'thunderbolt', 'diamond'], ['coin', 'thunderbolt', 'crown'], ['coin', 'thunderbolt', 'cup'], ['coin', 'thunderbolt', 'gift'],
 ['crown', 'diamond', 'cup'], ['crown', 'diamond', 'coin'], ['crown', 'diamond', 'gift'], ['crown', 'diamond', 'thunderbolt'],
 ['crown', 'cup', 'diamond'], ['crown', 'cup', 'coin'], ['crown', 'cup', 'gift'], ['crown', 'cup', 'thunderbolt'],
 ['crown', 'coin', 'diamond'], ['crown', 'coin', 'cup'], ['crown', 'coin', 'gift'], ['crown', 'coin', 'thunderbolt'],
 ['crown', 'gift', 'diamond'], ['crown', 'gift', 'cup'], ['crown', 'gift', 'coin'], ['crown', 'gift', 'thunderbolt'],
 ['crown', 'thunderbolt', 'diamond'], ['crown', 'thunderbolt', 'cup'], ['crown', 'thunderbolt', 'coin'], ['crown', 'thunderbolt', 'gift'],
]


import random


def get_random_index(len_of_array, slotId):
    if len_of_array == 1:
        return 0
    index = slotId % len_of_array
    return index


def get_winning_combination_v2(multiplier, slotId):
    combinations = winning_combinations.get(multiplier, [])
    if len(combinations) == 0:
        combination = []
        while combination == []:
            index = get_random_index(len(all_combinations), slotId)
            combination = all_combinations[index]
            if combination in all_winning_combinations or combination[0] == "thunderbolt":
                combination = []
        return combination
    else:
        index = get_random_index(len(combinations), slotId)
        combination = combinations[index]
        while len(combination) < 3:
            index = get_random_index(len(slot_symbols_v2), slotId)  
            combination.append(slot_symbols_v2[index])
        return combination


def get_winning_combination_v4(multipliers, slotIds):
    outcomes = list()
    for muliplier, slotId in zip(multipliers, slotIds):
        outcomes.append(get_winning_combination_v2(int(muliplier), slotId))
    return outcomes




print(get_winning_combination_v2(2,28))