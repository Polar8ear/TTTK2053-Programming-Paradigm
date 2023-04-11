def main():
    # create a list of 3-tuple consisting of name, age and favourite beverage
    info_tuple = ("Chuo Ngiu Bing", 20, "Teh Tarik Ais Kurang Manis")
    (name, age, favourite_beverage) = info_tuple
    # Convert the tuple to dictionary
    info_dict = {
        "name": name,
        "age": age,
        "favouriteBeverage": favourite_beverage,
    }

    print('info_dict keys:')
    for key in info_dict.keys():
        print(f'  - {key}')


if __name__ == '__main__':
    main()
