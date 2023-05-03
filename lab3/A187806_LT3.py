def printPythonBetween5and6():
    for i in range(1, 10 + 1):
        print(i)
        if i == 5:
            print("Python")

    print()


def printNumberStatistics():
    sum = 0.0
    product = 1.0

    NUMBERS_COUNT = 10

    for i in range(1, NUMBERS_COUNT + 1):
        while True:
            try:
                inputString = input(f"Please enter the no.{i} floating point number:\n")
                number = float(inputString)
                sum += number
                product *= number
                break
            except ValueError:
                print(
                    f"You've entered '{inputString}' that cant be converted to floating point number"
                )
            finally:
                print()

    print(f"{sum=}")
    print(f"{product=}")
    print(f"average = {sum/NUMBERS_COUNT}")
    print()


def printBurgerSummary(*ingredients):
    print("The burger has:")
    for ingredient in ingredients:
        print(f" - {ingredient}")
    print()


def main():
    printPythonBetween5and6()
    printNumberStatistics()
    printBurgerSummary("Bun", "Bun", "Bun")
    printBurgerSummary("Bun", "Meat Patty", "Cheese", "Bun")
    printBurgerSummary("Bun", "Cheese", "Egg", "Tomato Sauce", "Pickles", "Bun")


if __name__ == "__main__":
    main()
