def main():
    # create a list of 3-tuple consisting of name, age and favourite beverage
    info_tuple = ("Chuo Ngiu Bing", 20, "Teh Tarik Ais Kurang Manis")

    # Convert the tuple to dictionary
    # Method 1, extracting using index
    (name, age, favourite_beverage) = info_tuple
    info_dict = {
        "name": name,
        "age": age,
        "favouriteBeverage": favourite_beverage,
    }

    # Method 2, extracting using zip
    info_key_tuple = ('name', 'age', 'favouriteBeverage')
    info_dict = zip(info_tuple, info_key_tuple)

    # Printing the result
    print('info_dict keys:')

    # Method 1, using spreading and printing
    print(*info_dict.keys(), sep=", ") # The asterisk will 'spread' the key instead of returning as an array

    # Method 2, using for loop
    # for key in info_dict.keys():
    #     print(f'  - {key}')



if __name__ == '__main__':
    main()
